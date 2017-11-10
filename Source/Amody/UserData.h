// Copyright JJ 2017-

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UserData.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AMODY_API UUserData : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUserData();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly, Category = PlayerSetup)
		float DamagePerStrength = 1.0f;
	UPROPERTY(BlueprintReadOnly, Category = PlayerSetup)
		float attackRatePerAgility = 1.0f;
	UPROPERTY(BlueprintReadOnly, Category = PlayerSetup)
		float defencePerAgility = 1.0f;
	UPROPERTY(BlueprintReadOnly, Category = PlayerSetup)
		float magicDamagePerIntelligence = 1.0f;
	UPROPERTY(BlueprintReadOnly, Category = PlayerSetup)
		float hpPerVitality = 10.0f;
	UPROPERTY(BlueprintReadOnly, Category = PlayerSetup)
		float hpRecoverPerVitality = 0.01f;
	UPROPERTY(BlueprintReadOnly, Category = PlayerSetup)
		float mpPerEnergy = 5.0f;
	UPROPERTY(BlueprintReadOnly, Category = PlayerSetup)
		float mpRecoverPerEnergy = 0.01f;
		
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int level = 1;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int exp = 0;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int hp = 100;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int mp = 50;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int strength = 10;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int agility = 10;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int intelligence = 10;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int vitality = 10;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int energy = 10;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int statsPoint = 10;

	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int hitRecover = 1;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		float moveSpeed = 0.3f;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		float attackSpeed = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int hpMax = 100;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int mpMax = 50;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		float hpRecoveryForSecond = 1.0f;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		float mpRecoveryForSecond = 1.0f;

	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int minAttackDamage = 1;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int maxAttackDamage = 10;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int magicDamage = 5;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int attackRate = 10;

	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int defense = 10;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int blockRate = 0;

	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int fireAttack = 0;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int iceAttack = 0;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int lightningAttack = 0;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int poisonAttack = 0;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int attributeDefense = 0;

	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int hpAbsorb = 0;
	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int mpAbsorb = 0;

	UPROPERTY(BlueprintReadWrite, Category = PlayerStats)
		int magicChance = 0;
};
