// Fill out your copyright notice in the Description page of Project Settings.

#define _CRT_SECURE_NO_WARNINGS
#if defined( _MSC_VER )

#endif

#ifndef snprintf
#define snprintf _snprintf
#endif


#include "GOAP.h"
#include "AStar.h"

#include <string.h>
#include <stdio.h>

GOAP::GOAP()
{
}

GOAP::~GOAP()
{
}

static int idx_for_atomname(GOAP::actionplanner_t* ap, const char* atomname)
{
	int idx;
	for (idx = 0; idx < ap->numatoms; ++idx)
		if (!strcmp(ap->atm_names[idx], atomname)) return idx;

	if (idx < MAXATOMS)
	{
		ap->atm_names[idx] = atomname;
		ap->numatoms++;
		return idx;
	}

	return -1;
}


static int idx_for_actionname(GOAP::actionplanner_t* ap, const char* actionname)
{
	int idx;
	for (idx = 0; idx < ap->numactions; ++idx)
		if (!strcmp(ap->act_names[idx], actionname)) return idx;

	if (idx < MAXACTIONS)
	{
		ap->act_names[idx] = actionname;
		ap->act_costs[idx] = 1; // default cost is 1
		ap->numactions++;
		return idx;
	}

	return -1;
}


void GOAP::goap_actionplanner_clear(GOAP::actionplanner_t* ap)
{
	ap->numatoms = 0;
	ap->numactions = 0;
	for (int i = 0; i < MAXATOMS; ++i)
	{
		ap->atm_names[i] = 0;
	}
	for (int i = 0; i < MAXACTIONS; ++i)
	{
		ap->act_names[i] = 0;
		ap->act_costs[i] = 0;
		goap_worldstate_clear(ap->act_pre + i);
		goap_worldstate_clear(ap->act_pst + i);
	}
}


void GOAP::goap_worldstate_clear(GOAP::worldstate_t* ws)
{
	ws->values = 0LL;
	ws->dontcare = -1LL;
}


bool GOAP::goap_worldstate_set(GOAP::actionplanner_t* ap, GOAP::worldstate_t* ws, const char* atomname, bool value)
{
	const int idx = idx_for_atomname(ap, atomname);
	if (idx == -1) return false;
	ws->values = value ? (ws->values | (1LL << idx)) : (ws->values & ~(1LL << idx));
	ws->dontcare &= ~(1LL << idx);
	return true;
}



bool GOAP::goap_set_pre(GOAP::actionplanner_t* ap, const char* actionname, const char* atomname, bool value)
{
	const int actidx = idx_for_actionname(ap, actionname);
	const int atmidx = idx_for_atomname(ap, atomname);
	if (actidx == -1 || atmidx == -1) return false;
	goap_worldstate_set(ap, ap->act_pre + actidx, atomname, value);
	return true;
}


bool GOAP::goap_set_pst(GOAP::actionplanner_t* ap, const char* actionname, const char* atomname, bool value)
{
	const int actidx = idx_for_actionname(ap, actionname);
	const int atmidx = idx_for_atomname(ap, atomname);
	if (actidx == -1 || atmidx == -1) return false;
	goap_worldstate_set(ap, ap->act_pst + actidx, atomname, value);
	return true;
}


bool GOAP::goap_set_cost(GOAP::actionplanner_t* ap, const char* actionname, int cost)
{
	const int actidx = idx_for_actionname(ap, actionname);
	if (actidx == -1) return false;
	ap->act_costs[actidx] = cost;
	return true;
}


void GOAP::goap_worldstate_description(const GOAP::actionplanner_t* ap, const GOAP::worldstate_t* ws, char* buf, int sz)
{
	int added = 0;
	for (int i = 0; i < MAXATOMS; ++i)
	{
		if ((ws->dontcare & (1LL << i)) == 0LL)
		{
			const char* val = ap->atm_names[i];
			char upval[128];
			size_t j;
			for (j = 0; j < strlen(val); ++j)
				upval[j] = (val[j] - 32);
			upval[j++] = 0;
			const bool set = ((ws->values & (1LL << i)) != 0LL);
			added = snprintf(buf, sz, "%s,", set ? upval : val);
			buf += added; sz -= added;
		}
	}
}


void GOAP::goap_description(GOAP::actionplanner_t* ap, char* buf, int sz)
{
	int added = 0;
	for (int a = 0; a < ap->numactions; ++a)
	{
		added = snprintf(buf, sz, "%s:\n", ap->act_names[a]);
		sz -= added; buf += added;

		GOAP::worldstate_t pre = ap->act_pre[a];
		GOAP::worldstate_t pst = ap->act_pst[a];
		for (int i = 0; i < MAXATOMS; ++i)
			if ((pre.dontcare & (1LL << i)) == 0LL)
			{
				bool v = (pre.values & (1LL << i)) != 0LL;
				added = snprintf(buf, sz, "  %s==%d\n", ap->atm_names[i], v);
				sz -= added; buf += added;
			}
		for (int i = 0; i < MAXATOMS; ++i)
			if ((pst.dontcare & (1LL << i)) == 0LL)
			{
				bool v = (pst.values & (1LL << i)) != 0LL;
				added = snprintf(buf, sz, "  %s:=%d\n", ap->atm_names[i], v);
				sz -= added; buf += added;
			}
	}
}


static GOAP::worldstate_t goap_do_action(GOAP::actionplanner_t* ap, int actionnr, GOAP::worldstate_t fr)
{
	const GOAP::worldstate_t pst = ap->act_pst[actionnr];
	const bfield_t unaffected = pst.dontcare;
	const bfield_t affected = (unaffected ^ -1LL);

	fr.values = (fr.values & unaffected) | (pst.values & affected);
	fr.dontcare &= pst.dontcare;
	return fr;
}


int GOAP::goap_get_possible_state_transitions(GOAP::actionplanner_t* ap, GOAP::worldstate_t fr, GOAP::worldstate_t* to, const char** actionnames, int* actioncosts, int cnt)
{
	int writer = 0;
	for (int i = 0; i < ap->numactions && writer < cnt; ++i)
	{
		// see if precondition is met
		const GOAP::worldstate_t pre = ap->act_pre[i];
		const bfield_t care = (pre.dontcare ^ -1LL);
		const bool met = ((pre.values & care) == (fr.values & care));
		if (met)
		{
			actionnames[writer] = ap->act_names[i];
			actioncosts[writer] = ap->act_costs[i];
			to[writer] = goap_do_action(ap, i, fr);
			++writer;
		}
	}
	return writer;
}
