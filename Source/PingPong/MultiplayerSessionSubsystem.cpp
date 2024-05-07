// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiplayerSessionSubsystem.h"
#include "OnlineSubsystem.h"



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
	serverNametoFind = "";
}

void UMultiplayerSessionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	PrintString("MSS Initialize");
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
	if (OnlineSubsystem)
	{
		SubsystemName = OnlineSubsystem->GetSubsystemName().ToString();
		PrintString(SubsystemName);

		SessionInterface = OnlineSubsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			PrintString("Session interface is valid!");
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UMultiplayerSessionSubsystem::OnCreateSessionComplete);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UMultiplayerSessionSubsystem::OnDestroySessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UMultiplayerSessionSubsystem::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &UMultiplayerSessionSubsystem::OnJoinSessionsComplete);
		}
	}
}

void UMultiplayerSessionSubsystem::Deinitialize()
{
	UE_LOG(LogTemp, Warning, TEXT("MSS DeInitialize"));
}

void UMultiplayerSessionSubsystem::CreateServer(FString serverName)
{
	if (serverName.IsEmpty())
	{
		PrintString("Server name is empty!");
		return;
	}
	SessionName = ("PingPongSession");
	FOnlineSessionSettings sessionSettings;


	FNamedOnlineSession* sessionCheck = SessionInterface->GetNamedSession(SessionName);
	if (sessionCheck)
	{
		PrintString("Destroying Session");
		SessionInterface->DestroySession(SessionName);
	}

	sessionSettings.bAllowJoinInProgress = true;
	sessionSettings.bIsDedicated = false;
	sessionSettings.bShouldAdvertise = true;
	sessionSettings.NumPublicConnections = 2;
	sessionSettings.bUseLobbiesIfAvailable = true;
	sessionSettings.bUsesPresence = true;
	sessionSettings.bAllowJoinViaPresence = true;

	sessionSettings.Set(FName("SERVER_NAME"), serverName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

	if (SubsystemName == "NULL")
	{
		sessionSettings.bIsLANMatch = true;
	}
	else
		sessionSettings.bIsLANMatch = false;

	SessionInterface->CreateSession(0, SessionName, sessionSettings);
}

void UMultiplayerSessionSubsystem::JoinServer(FString serverName)
{
	if (serverName.IsEmpty())
	{
		PrintString("Server name is empty!");
		return;
	}
	SessionSearch = MakeShareable(new FOnlineSessionSearch());

	if (SubsystemName == "NULL")
	{
		SessionSearch->bIsLanQuery = true;
	}
	else
	{
		SessionSearch->bIsLanQuery = false;
	}
	SessionSearch->MaxSearchResults = 9999;
	SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);
	serverNametoFind = serverName;

	SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
}

void UMultiplayerSessionSubsystem::OnCreateSessionComplete(FName SessionName, bool WasSuccessful)
{
	PrintString(FString::Printf(TEXT("OnCreateSessionComplete: %d"), WasSuccessful));
	PrintString("Session Callback");
	if (WasSuccessful)
	{
		GetWorld()->ServerTravel("/Game/FirstPerson/Maps/FirstPersonMap?listen");
	}
}

void UMultiplayerSessionSubsystem::OnDestroySessionComplete(FName SessionName, bool WasSuccessful)
{
	PrintString(FString::Printf(TEXT("OnDestroySessionComplete: %d"), WasSuccessful));

}

void UMultiplayerSessionSubsystem::OnFindSessionsComplete(bool WasSuccessful)
{
	if (!WasSuccessful) return;
	if (serverNametoFind.IsEmpty())
	{
		return;
	}
	PrintString(FString::Printf(TEXT("OnFindSessionComplete: %d"), WasSuccessful));
	TArray<FOnlineSessionSearchResult> Results = SessionSearch->SearchResults;
	FOnlineSessionSearchResult* CorrectResult = 0;
	if (Results.Num() > 0)
	{
		FString SearchResults = FString::Printf(TEXT("%d sessions found"), Results.Num());
		PrintString(SearchResults);
		for (FOnlineSessionSearchResult Result : Results)
		{
			if (Result.IsValid())
			{
				FString ResultName = "None";
				Result.Session.SessionSettings.Get(FName("SERVER_NAME"), ResultName);

				FString msg2 = FString::Printf(TEXT("ServerName: %s"), *ResultName);
				PrintString(msg2);

				if (ResultName.Equals(serverNametoFind))
				{
					CorrectResult = &Result;
					FString msg2 = FString::Printf(TEXT("Found Server: %s"), *ResultName);
					PrintString(msg2);
					break;
				}
			}
		}
		if (CorrectResult)
		{
			SessionInterface->JoinSession(0, SessionName, *CorrectResult);
		}
		else
		{
			PrintString(FString::Printf(TEXT("Couldnt Find Server: %s"), *serverNametoFind));
			serverNametoFind = "";

		}
	}
	else
		PrintString("No Sessions Found");
}

void UMultiplayerSessionSubsystem::OnJoinSessionsComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (Result == EOnJoinSessionCompleteResult::Success)
	{
		FString msg2 = FString::Printf(TEXT("Successfully joined: %s"), *SessionName.ToString());
		PrintString(msg2);
		FString Address = "";
		bool success = SessionInterface->GetResolvedConnectString(SessionName, Address);
		if (success)
		{
			PrintString(FString::Printf(TEXT("Address: %s"), *Address));

			APlayerController *PController = GetGameInstance()->GetFirstLocalPlayerController();
			if (PController)
			{
				PController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
			}
		}
	}
	else
	{
		PrintString("OnJoinSessionComplete Failed");
	}
}
