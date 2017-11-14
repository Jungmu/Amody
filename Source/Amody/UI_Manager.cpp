// Fill out your copyright notice in the Description page of Project Settings.

#include "UI_Manager.h"
#include "Blueprint/UserWidget.h"

// Sets default values
AUI_Manager::AUI_Manager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUI_Manager::BeginPlay()
{
	Super::BeginPlay();
	
	if (wMainMenu) // Check if the Asset is assigned in the blueprint.
	{
		MyMainMenu = CreateWidget<UUserWidget>(GetWorld(), wMainMenu);

		if (MyMainMenu)
		{
			MyMainMenu->AddToViewport();
		}

	}
	if (wPlayerUI) // Check if the Asset is assigned in the blueprint.
	{
		PlayerUI = CreateWidget<UUserWidget>(GetWorld(), wPlayerUI);

		if (PlayerUI)
		{
			PlayerUI->AddToViewport();
		}

	}

	inventorySlot.SetNum(AmountOfSlot);
}

// Called every frame
void AUI_Manager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUI_Manager::isSlotEmpty(int index, bool &bOUTisEmpty)
{

}

void AUI_Manager::getItemInfoAtIndex(int index, bool &bOUTisEmpty, FItemInfo &OUTitemInfo, int &OUTamount)
{

}

void AUI_Manager::searchEmptySlot(bool &bOUTisSuccess,int &OUTindex)
{

}

void AUI_Manager::searchFreeStack(AMasterItem* item, bool &bOUTisSuccess, int &OUTindex)
{

}

void AUI_Manager::addItem(AMasterItem* item, int amount, bool &bOUTisSuccess, int &OUTrest)
{

}

void AUI_Manager::getAmountAtIndex(int index, int &OUTamount)
{

}