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

	if (wMainMenu) // main popup widget
	{
		MyMainMenu = CreateWidget<UUserWidget>(GetWorld(), wMainMenu);

		if (MyMainMenu)
		{
			MyMainMenu->AddToViewport(10);
		}

	}
	if (wPlayerUI) // Hp,Mp bar and character Face ... 
	{
		PlayerUI = CreateWidget<UUserWidget>(GetWorld(), wPlayerUI);

		if (PlayerUI)
		{
			PlayerUI->AddToViewport(0);
		}

	}
	
}

// Called every frame
void AUI_Manager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AUI_Manager::isSlotEmpty(int index, bool &bOUTisEmpty)
{
	if (inventorySlot[index].amount == 0)
		bOUTisEmpty = true;
	else
		bOUTisEmpty = false;
}

void AUI_Manager::getItemInfoAtIndex(int index, bool &bOUTisEmpty, FItemInfo &OUTitemInfo, int &OUTamount)
{
	isSlotEmpty(index, bOUTisEmpty);
	OUTamount = inventorySlot[index].amount;
	if (inventorySlot[index].Item)
		OUTitemInfo = inventorySlot[index].Item->itemInfo;
	else
		OUTitemInfo = FItemInfo();
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

void AUI_Manager::setVisibleMainUI() 
{
	MyMainMenu->SetVisibility(ESlateVisibility::Visible);
}