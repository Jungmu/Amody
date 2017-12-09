// Fill out your copyright notice in the Description page of Project Settings.

#include "UI_Manager.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

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
	{
		bOUTisEmpty = true;
	}
	else
	{
		bOUTisEmpty = false;
	}
}

void AUI_Manager::getItemInfoAtIndex(int index, bool &bOUTisEmpty, FItemInfo &OUTitemInfo, int &OUTamount)
{
	isSlotEmpty(index, bOUTisEmpty);
	OUTamount = inventorySlot[index].amount;
	if (inventorySlot[index].Item)
	{
		OUTitemInfo = inventorySlot[index].Item->itemInfo;
	}
	else
	{
		OUTitemInfo = FItemInfo();
	}
}

void AUI_Manager::useItemAtInventoryIndex(int index, bool &bOUTisSuccess)
{
	bool isEmpty = false;
	FItemInfo itemInfo;
	int amount;
	ACharacterBase* playerCharacter = Cast<ACharacterBase>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	getItemInfoAtIndex(index, isEmpty, itemInfo, amount);
	if (isEmpty)
	{
		bOUTisSuccess = false;
		return;
	}

	if (itemInfo.Category == EItemCategory::E_Consumeable)
	{
		switch (itemInfo.SubCategory)
		{
		case EItemCategory::E_Hp:
			playerCharacter->userData.hp += itemInfo.consumeEffectValue;
			break;
		case EItemCategory::E_Mp:
			playerCharacter->userData.mp += itemInfo.consumeEffectValue;
			break;
		default:
			break;
		}
		
	}
	else if (itemInfo.Category == EItemCategory::E_Equipment)
	{
		FActorSpawnParameters SpawnInfo;
		switch (itemInfo.SubCategory)
		{
		case EItemCategory::E_Wapwon:
			if (left)
			{				
				bool bIsSucceed;
				addItem(left, 1, bIsSucceed);
				left->Destroy();
			}
			left = GetWorld()->SpawnActor<AMasterItem>(FVector(0,0,0), FRotator(0,0,0), SpawnInfo);
			left->itemInfo = itemInfo;
			break;
		default:
			break;
		}
	}
		
	inventorySlot[index].amount--;
	if (inventorySlot[index].amount == 0)
	{
		inventorySlot[index].Item = nullptr;
	}
	bOUTisSuccess = true;
}

void AUI_Manager::searchEmptySlot(bool &bOUTisSuccess,int &OUTindex)
{
	for(int i = 0; i< inventorySlot.Num();i++)
	{
		if (inventorySlot[i].amount == 0)
		{
			bOUTisSuccess = true;
			OUTindex = i;
			return;
		}
	}
	bOUTisSuccess = false;
	OUTindex = 0;
}

void AUI_Manager::searchFreeStack(AMasterItem* item, bool &bOUTisSuccess, int &OUTindex)
{
	for (int i = 0; i < inventorySlot.Num(); i++)
	{
		if (inventorySlot[i].Item)
		{
			if (inventorySlot[i].Item->itemInfo.name == item->itemInfo.name && inventorySlot[i].amount < 99)
			{
				bOUTisSuccess = true;
				OUTindex = i;
				return;
			}
		}		
	}
	bOUTisSuccess = false;
	OUTindex = 0;
}

void AUI_Manager::addStackedItem(AMasterItem* item, int index,int amount, bool &bOUTisSuccess)
{
	int rest = 0;
	if (amount <= MaxItemCount)
	{
		inventorySlot[index].amount = amount;
		bOUTisSuccess = true;
		return;
	}
	else
	{
		inventorySlot[index].amount = MaxItemCount;
		rest = amount - MaxItemCount;
		addItem(item, rest, bOUTisSuccess);
	}
}

void AUI_Manager::addItem(AMasterItem* item, int amount, bool &bOUTisSuccess)
{
	if (amount == 0 || item == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("can't insert wrong Item."));
		bOUTisSuccess = false;
		return;
	}

	int index = 0;
	int rest = 0;
	bool isEmpty = false;	

	if (item->itemInfo.bIsCanStack)
	{
		searchFreeStack(item, isEmpty, index);
		if (isEmpty)
		{
			int sumAmount = inventorySlot[index].amount + amount;
			addStackedItem(item, index, sumAmount, bOUTisSuccess);
		}
		else
		{
			searchEmptySlot(isEmpty,index);
			if (isEmpty)
			{
				inventorySlot[index].Item = item;
				addStackedItem(item, index, amount, bOUTisSuccess);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("inventory is full ;"));
				bOUTisSuccess = false;
				return;
			}
		}
	}
	else
	{
		searchEmptySlot(isEmpty, index);
		if (isEmpty)
		{
			inventorySlot[index].Item = item;
			inventorySlot[index].amount = 1;
			amount--;
			if (amount > 0)
			{
				addItem(item, amount, bOUTisSuccess);
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("inventory is full ;"));
			bOUTisSuccess = false;
			return;
		}
	}
	bOUTisSuccess = true;
}

void AUI_Manager::getAmountAtIndex(int index, int &OUTamount)
{
	OUTamount = inventorySlot[index].amount;
}

void AUI_Manager::setVisibleMainUI() 
{
	MyMainMenu->SetVisibility(ESlateVisibility::Visible);
}
