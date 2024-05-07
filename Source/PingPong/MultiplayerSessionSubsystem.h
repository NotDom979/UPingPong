// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"
#include "Online/OnlineSessionNames.h"
#include "MultiplayerSessionSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONG_API UMultiplayerSessionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UMultiplayerSessionSubsystem();

	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable)
	void CreateServer(FString serverName);

	UFUNCTION(BlueprintCallable)
	void JoinServer(FString serverName);

	void OnCreateSessionComplete(FName SessionName, bool WasSuccessful);

	void OnDestroySessionComplete(FName SessionName, bool WasSuccessful);

	void OnFindSessionsComplete(bool WasSuccessful);
	void OnJoinSessionsComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	TSharedPtr<FOnlineSessionSearch> SessionSearch;

	FString serverNametoFind;
	FName SessionName;
private:
	IOnlineSessionPtr SessionInterface;
	FString SubsystemName;
};
