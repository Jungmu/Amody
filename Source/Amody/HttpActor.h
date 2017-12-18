// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Online/HTTP/Public/Http.h"
#include "HttpActor.generated.h"

UCLASS()
class AMODY_API AHttpActor : public AActor
{
	GENERATED_BODY()
private:
	// Sets default values for this actor's properties
	AHttpActor(const class FObjectInitializer& ObjectInitializer);

	static AHttpActor* instance;

public:	
	FHttpModule* Http;

	/* The actual HTTP call */
	UFUNCTION(BlueprintCallable)
		void MyHttpCall(FString url, FString data);

	/*Assign this function to call when the GET request processes sucessfully*/
	void OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	static AHttpActor* GetInstance();

};
