// Copyright JJ 2017-

#pragma once

#include "CoreMinimal.h"
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

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	PlayerStats playerStats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerStats)
	NoneSaveStats noneSaveStats;	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerStatsSetup)
	PlayerStatsSetup playerStatsSetup;*/
	
private:
	double lastUpdateTime;
};

//USTRUCT(BlueprintType)
//struct PlayerStats
//{
//	GENERATED_USTRUCT_BODY()
//
//		int level = 1;
//	int requireExp = 100;
//	int strength = 10;
//	int agility = 10;
//	int intelligence = 10;
//	int vitality = 10;
//	int energy = 10;
//	float hp = 100.f;
//	float mp = 50.f;
//};
//
//USTRUCT(BlueprintType)
//struct NoneSaveStats
//{
//	GENERATED_USTRUCT_BODY()
//
//		int hitRecover = 1;
//	float moveSpeed = 1.0f;
//	float attackSpeed = 1.0f;
//
//	float hpMax = 100.0f;
//	float mpMax = 50.0f;
//	float hpRecoveryForSecond = 1.0f;
//	float mpRecoveryForSecond = 1.0f;
//
//	int minAttackDamage = 1;
//	int maxAttackDamage = 10;
//	int magicDamage = 5;
//	int attackRate = 10;
//
//	int defense = 10;
//	int blocking = 0;
//
//	int attributeAttack = 0;
//	int attributeDefense = 0;
//
//	int hpAbsorb = 0;
//	int mpAbsorb = 0;
//
//	int magicChance = 0;
//};
//
//USTRUCT(BlueprintType)
//struct PlayerStatsSetup
//{
//	GENERATED_USTRUCT_BODY()
//
//		int damagePerStrength = 2;
//	int attackRatePerAgiliy = 5;
//	int attackRatePerDefence = 5;
//	int magicDamagePerIntelligence = 2;
//	int hpPerVitality = 20;
//	float hpRecoverPerVitality = 0.2f;
//	int mpPerEnerge = 10;
//	float mpRecoverPerEnerge = 0.1f;
//};