// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GOAP.h"
#include "CoreMinimal.h"


#ifndef ASTAR_H
#define ASTAR_H

#ifdef __cplusplus

extern "C"
{
#endif // __cplusplus

#ifndef LOGI
#ifdef __cplusplus
#include <cstdio>
#else
#include <stdio.h>
#endif
#define LOGI(...) { printf( __VA_ARGS__ ); printf("\n"); }
#define LOGW(...) { printf( "WRN " __VA_ARGS__ ); printf("\n"); }
#define LOGE(...) { printf( "ERR " __VA_ARGS__ ); printf("\n"); }
#endif

	/**
	*
	*/
	class GOAP_FRAMEWORK_API AStar
	{
	public:
		struct astarnode;

		//!< A node in our network of world states.
		struct astarnode
		{
			GOAP::worldstate_t ws;		// The state of the world at this node.
			int g;				// The cost so far.
			int h;				// The heuristic for remaining cost (don't overestimate!)
			int f;				// g+h combined.
			const char* actionname;		// How did we get to this node?
			GOAP::worldstate_t parentws;		// Where did we come from?
		};

		typedef struct astarnode astarnode_t;

		int astar_plan
		(
			GOAP::actionplanner_t* ap, 		// the goap action planner that holds atoms and action repertoire
			GOAP::worldstate_t start, 		// the current world state
			GOAP::worldstate_t goal, 		// the desired world state
			const char** plan,              // for returning all actions that make up plan
			GOAP::worldstate_t* worldstates,      // for returning intermediate world states
			int* plansize                   // in: size of plan buffer, out: size of plan (in nr of steps)
		);

		AStar();
		~AStar();

	};

#ifdef __cplusplus
}
#endif

#endif
