// Fill out your copyright notice in the Description page of Project Settings.

#include "CharacterBase.h"


// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterBase::getSpeed(float &OUTspeed)
{
	OUTspeed = userData.speed;
}

void ACharacterBase::getHp(float &OUThp)
{
	OUThp = userData.hp;
}

void ACharacterBase::setHp(float hp)
{
	if (userData.maxHp < hp)
	{
		hp = userData.maxHp;
	}

	userData.hp = hp;
}

void ACharacterBase::getMp(float &OUTmp)
{
	OUTmp = userData.mp;
}

void ACharacterBase::setMp(float mp)
{
	if (userData.maxMp < mp)
	{
		mp = userData.maxMp;
	}

	userData.mp = mp;
}


void ACharacterBase::setUpUserData()
{
	FUserSetupData setUpData;

	userData.maxHp = userData.health * setUpData.hpPerHealth;
	userData.maxMp = userData.energy * setUpData.mpPerEnergy;

	userData.maxDamage = userData.strength * setUpData.maxDamagePerStr;
	userData.minDamage = userData.agility * setUpData.minDamagePerAgil;
	userData.magicDamage = userData.intelligence * setUpData.magicDamagePerint;
}