// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"


DECLARE_LOG_CATEGORY_EXTERN(Styx_LOG, Log, All);


static enum class log_categories{
	DISPLAY,
	WARNING,
	ERROR
};

/**
 * 
 */
class GOAPFRAMEWORK_API StyxLog
{
private:
	uint64 output_message_counter = 0;
	uint64 in_game_preview_message_counter = 0;


public:
	FString MyName;

	FString getMyName();
	void setMyName(FString new_name);

	void send_to_Output_logger(FString message, log_categories category);
	void send_to_GamePreviewLogger(FString message, log_categories category, float screen_time);

	StyxLog();
	~StyxLog();
};
