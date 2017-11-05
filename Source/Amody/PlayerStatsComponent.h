// Copyright JJ 2017-

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerStatsComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AMODY_API UPlayerStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerStatsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		int level = 1;
	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		int requireExp = 100;
	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		int strength = 10;
	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		int agility = 10;
	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		int intelligence = 10;
	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		int vitality = 10;
	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		int energy = 10;

	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		int damagePerStrength = 2;
	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		int attackRatePerAgiliy = 5;
	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		int attackRatePerDefence = 5;
	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		int magicDamagePerIntelligence = 2;
	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		int hpPerVitality = 20;
	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		float hpRecoverPerVitality = 0.2f;
	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		int mpPerEnerge = 10;
	UPROPERTY(BlueprintReadOnly, Category = PlayerStats)
		float mpRecoverPerEnerge = 0.1f;

	float hp = 100.f;
	float mp = 50.f;

	int hitRecover = 1;
	float moveSpeed = 1.0f;
	float attackSpeed = 1.0f;

	float hpMax = 100.0f;
	float mpMax = 50.0f;
	float hpRecoveryForSecond = 1.0f;
	float mpRecoveryForSecond = 1.0f;

	int minAttackDamage = 1;
	int maxAttackDamage = 10;
	int magicDamage = 5;
	int attackRate = 10;

	int defense = 10;
	int blocking = 0;

	int attributeAttack = 0;
	int attributeDefense = 0;

	int hpAbsorb = 0;
	int mpAbsorb = 0;

	int magicChance = 0;
	
	
};