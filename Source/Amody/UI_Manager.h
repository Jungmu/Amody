// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Const.h"
#include "MasterItem.h"
#include "GameFramework/Actor.h"
#include "UI_Manager.generated.h"

USTRUCT(BlueprintType)
struct FInventorySlot
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		AMasterItem* Item = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		int amount = 0;

};

UCLASS()
class AMODY_API AUI_Manager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUI_Manager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slot")
		int AmountOfSlot = 150;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		int MaxItemCount = 99;

	// Reference UMG Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets" ,meta = (ExposeOnSpawn))
		TSubclassOf<class UUserWidget> wMainMenu;

	// Variable to hold the widget After Creating it.
	UUserWidget* MyMainMenu;

	// Reference UMG Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets" ,meta = (ExposeOnSpawn))
		TSubclassOf<class UUserWidget> wPlayerUI;

	// Variable to hold the widget After Creating it.
	UUserWidget* PlayerUI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
		TArray<FInventorySlot> inventorySlot;

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void isSlotEmpty(int index,  bool &bOUTisEmpty);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void getItemInfoAtIndex(int index, bool &bOUTisEmpty, FItemInfo &OUTitemInfo, int &OUTamount);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void searchEmptySlot(bool &bOUTisSuccess, int &OUTindex);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void searchFreeStack(AMasterItem* item, bool &bOUTisSuccess, int &OUTindex);

	void addStackedItem(AMasterItem* item,int index, int amount, bool &bOUTisSuccess);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void addItem(AMasterItem* item,int amount, bool &bOUTisSuccess);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
		void getAmountAtIndex(int index, int &OUTamount);

	UFUNCTION(BlueprintCallable, Category = "CommonUI")
		void setVisibleMainUI();
};
