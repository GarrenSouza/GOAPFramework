// Fill out your copyright notice in the Description page of Project Settings.
#include "StyxLog.h"
#include "EngineGlobals.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

DEFINE_LOG_CATEGORY(Styx_LOG);

FString StyxLog::getMyName()
{
	return MyName;
}

void StyxLog::setMyName(FString new_name)
{
	MyName = new_name;
}

void StyxLog::send_to_Output_logger(FString message, log_categories category)
{
	switch (category)
	{
	case log_categories::DISPLAY:
		UE_LOG(Styx_LOG, Display, TEXT("> %s [%d] | %s"), *(StyxLog::MyName), output_message_counter, *message);
		break;
	case log_categories::WARNING:
		UE_LOG(Styx_LOG, Warning, TEXT("> %s [%d] | %s"), *(StyxLog::MyName), output_message_counter, *message);
		break;
	case log_categories::ERROR:
		UE_LOG(Styx_LOG, Error, TEXT("> %s [%d] | %s"), *(StyxLog::MyName), output_message_counter ,*message);
		break;
	default:
		UE_LOG(Styx_LOG, Error, TEXT("> %s [%d] | You missed something buddy! (And is a log category thing for sure)"), *(StyxLog::MyName), output_message_counter);
		break;
	}
	output_message_counter++;
}

void StyxLog::send_to_GamePreviewLogger(FString message, log_categories category, float screen_time)
{
	switch (category)
	{
	case log_categories::DISPLAY:
		GEngine->AddOnScreenDebugMessage(-1, screen_time, FColor::White, FString::Printf(TEXT("> %s [%d] | %s"), *(StyxLog::MyName), in_game_preview_message_counter,  *message));
		break;
	case log_categories::WARNING:
		GEngine->AddOnScreenDebugMessage(-1, screen_time, FColor::Yellow, FString::Printf(TEXT("> %s [%d] | %s"), *(StyxLog::MyName), in_game_preview_message_counter, *message));
		break;
	case log_categories::ERROR:
		GEngine->AddOnScreenDebugMessage(-1, screen_time, FColor::Red, FString::Printf(TEXT("> %s [%d] | %s"), *(StyxLog::MyName), in_game_preview_message_counter, *message));
		break;
	default:
		GEngine->AddOnScreenDebugMessage(-1, screen_time, FColor::Red, FString::Printf(TEXT("> %s [%d] | You missed something buddy! (And is a log category thing for sure)"), *(StyxLog::MyName), this->output_message_counter));
		break;
	}
	in_game_preview_message_counter++; 
}

StyxLog::StyxLog()
{
}

StyxLog::~StyxLog()
{
}