// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerSessionSubsystem.h"

void PrintString(const FString& debugText)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, debugText);
	}
}

UMultiplayerSessionSubsystem::UMultiplayerSessionSubsystem()
{
	PrintString("MSS Constructor");
}

void UMultiplayerSessionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	PrintString("MSS Initialize");
}

void UMultiplayerSessionSubsystem::Deinitialize()
{
	UE_LOG(LogTemp, Warning, TEXT("MSS DeInitialize"));
}
