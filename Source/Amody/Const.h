// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Const.generated.h"
/**
 * 
 */
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EItemCategory : uint8
{
	E_Consumeable 	UMETA(DisplayName = "Consumeable"),
	E_Equipment 	UMETA(DisplayName = "Equipment"),
	E_Useable		UMETA(DisplayName = "Useable")
};

USTRUCT(BlueprintType)
struct FItemInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		FString name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		UTexture2D* itemIcon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		bool bIsCanUse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		bool bIsCanStack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		EItemCategory Category;
};

USTRUCT(BlueprintType)
struct FUserData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float hp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float mp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float maxHp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float maxMp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float maxDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float minDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float magicDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int strength;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int agility;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int intelligence;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int energy;
};

USTRUCT(BlueprintType)
struct FUserSetupData
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UserData")
		float maxDamagePerStr = 4.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UserData")
		float minDamagePerAgil = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UserData")
		float defencePerAgil = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UserData")
		float attackRatingPerAgil = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UserData")
		float magicDamagePerint = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UserData")
		float hpPerHealth = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UserData")
		float hpRecoverPerHealth = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UserData")
		float mpPerEnergy = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UserData")
		float mpRecoverPerEnergy = 1.0f;
};

