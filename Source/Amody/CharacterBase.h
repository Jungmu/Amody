// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI_Manager.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS()
class AMODY_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isAttack = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isUiOpen = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AUI_Manager* uiManager;
		
};
