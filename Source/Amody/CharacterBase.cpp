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

void ACharacterBase::getHpPercent(float &OUThp)
{
	OUThp = userData.hp / userData.maxHp;
}

void ACharacterBase::setHp(float hp)
{
	if (userData.maxHp < hp)
	{
		userData.hp = userData.maxHp;
	}
	else if (hp < 0)
	{
		userData.hp = 0;
	}
	else
	{
		userData.hp = hp;
	}
}

void ACharacterBase::addHp(float hp)
{
	setHp(userData.hp + hp);
}

void ACharacterBase::getMp(float &OUTmp)
{
	OUTmp = userData.mp;
}

void ACharacterBase::getMpPercent(float &OUTmp)
{
	OUTmp = userData.mp / userData.maxMp;
}

void ACharacterBase::setMp(float mp)
{
	if (userData.maxMp < mp)
	{
		userData.mp = userData.maxMp;
	}
	else if (mp < 0)
	{
		userData.mp = 0;
	}
	else
	{
		userData.mp = mp;
	}
}

void ACharacterBase::addMp(float mp)
{
	setMp(userData.mp + mp);
}


void ACharacterBase::setUpUserData()
{
	FUserSetupData setUpData;	
		
	userData.maxHp = userData.health * setUpData.hpPerHealth;
	userData.maxMp = userData.energy * setUpData.mpPerEnergy;
	userData.hpRecover = userData.health * setUpData.hpRecoverPerHealth;
	userData.mpRecover = userData.energy * setUpData.mpRecoverPerEnergy;

	userData.maxDamage = userData.strength * setUpData.maxDamagePerStr;
	userData.minDamage = userData.agility * setUpData.minDamagePerAgil;
	userData.magicDamage = userData.intelligence * setUpData.magicDamagePerint;
	userData.defence = userData.agility * setUpData.defencePerAgil;
	userData.attackRating = userData.agility * setUpData.attackRatingPerAgil;

	if (userData.maxHp < userData.hp)
	{
		userData.hp = userData.maxHp;
	}
	if (userData.maxMp < userData.mp)
	{
		userData.mp = userData.maxMp;
	}

	if (userData.level == 1)
	{
		userData.hp = userData.maxHp;
		userData.mp = userData.maxMp;
	}
}