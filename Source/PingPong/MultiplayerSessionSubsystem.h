// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"
#include "Online/OnlineSessionNames.h"
#include "MultiplayerSessionSubsystem.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FServerCreateDelegate, bool, WasSuccessful);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FServerJoinDelegate, bool, WasSuccessful);
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
	void FindServer(FString serverName);

	void OnCreateSessionComplete(FName _SessionName, bool WasSuccessful);

	void OnDestroySessionComplete(FName _SessionName, bool WasSuccessful);

	void OnFindSessionsComplete(bool WasSuccessful);
	void OnJoinSessionsComplete(FName _SessionName, EOnJoinSessionCompleteResult::Type Result);
	void HandleNetworkFailure(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString);

	TSharedPtr<FOnlineSessionSearch> SessionSearch;

	FString serverNametoFind;
	FName SessionName;

	UPROPERTY(BlueprintAssignable)
	FServerCreateDelegate ServerCreateDel;
	
	UPROPERTY(BlueprintAssignable)
	FServerJoinDelegate ServerJoinDel;
private:
	IOnlineSessionPtr SessionInterface;
	FString SubsystemName;
};
