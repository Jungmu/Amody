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
		int Speed;
	
};

