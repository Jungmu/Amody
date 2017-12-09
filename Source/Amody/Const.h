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
	E_Useable		UMETA(DisplayName = "Useable"),

	E_Wapwon		UMETA(DisplayName = "Wapwon"),
	E_Head		UMETA(DisplayName = "Head"),
	E_Body		UMETA(DisplayName = "Body"),
	E_Hand		UMETA(DisplayName = "Hand"),
	E_Foot		UMETA(DisplayName = "Foot"),
	E_Ring		UMETA(DisplayName = "Ring"),
	E_Amulet		UMETA(DisplayName = "Amulet"),
	E_Bracelet		UMETA(DisplayName = "Bracelet"),

	E_Hp		UMETA(DisplayName = "Hp"),
	E_Mp		UMETA(DisplayName = "Mp")
};

USTRUCT(BlueprintType)
struct FItemOption
{
	GENERATED_USTRUCT_BODY()

	int optionKey;
	FString optionName;
	float value;
};

USTRUCT(BlueprintType)
struct FItemInfo
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		UStaticMesh* staticMesh;

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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		EItemCategory SubCategory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		int consumeEffectValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ItemInfo")
		TArray<FItemOption> optionList;

};

USTRUCT(BlueprintType)
struct FUserData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int level = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int exp = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float speed = 0.4f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float hp = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float mp = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float hpRecover = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float mpRecover =0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float maxHp = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float maxMp = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float maxDamage = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float minDamage = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float magicDamage = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float defence = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		float attackRating = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int strength = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int agility = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int intelligence = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int health = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int energy = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UserData")
		int point = 10;
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

