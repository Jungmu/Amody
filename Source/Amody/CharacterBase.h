// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Const.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "userData")
		UStaticMesh* wapwon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "userData")
		bool isAttack = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "userData")
		bool isUiOpen = false;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
		//AUI_Manager* uiManager;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "userData")
		FUserData userData;

	UFUNCTION(BlueprintCallable, Category = "userData")
		void getSpeed(float &OUTspeed);

	UFUNCTION(BlueprintCallable, Category = "userData")
		void getHp(float &OUThp);

	UFUNCTION(BlueprintCallable, Category = "userData")
		void getHpPercent(float &OUThp);

	UFUNCTION(BlueprintCallable, Category = "userData")
		void setHp(float hp);
	
	UFUNCTION(BlueprintCallable, Category = "userData")
		void addHp(float hp);

	UFUNCTION(BlueprintCallable, Category = "userData")
		void getMp(float &OUTmp);

	UFUNCTION(BlueprintCallable, Category = "userData")
		void getMpPercent(float &OUThp);

	UFUNCTION(BlueprintCallable, Category = "userData")
		void setMp(float mp);

	UFUNCTION(BlueprintCallable, Category = "userData")
		void addMp(float mp);

	UFUNCTION(BlueprintCallable, Category = "userData")
		void setUpUserData();
};
