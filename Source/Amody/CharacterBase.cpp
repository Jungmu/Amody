// Copyright JJ 2017-

#include "CharacterBase.h"
#include "Classes/Kismet/KismetMathLibrary.h"

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
	
	lastUpdateTime = FApp::GetCurrentTime();
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (lastUpdateTime+1 < FApp::GetCurrentTime())
	{
		lastUpdateTime = FApp::GetCurrentTime();
		/*if (playerStats.hp < noneSaveStats.hpMax)
		{
			if (playerStats.hp + noneSaveStats.hpRecoveryForSecond > noneSaveStats.hpMax)
			{
				playerStats.hp = noneSaveStats.hpMax;
			}
			else
			{
				playerStats.hp = playerStats.hp + noneSaveStats.hpRecoveryForSecond;
			}
		}
		if (playerStats.mp < noneSaveStats.mpMax)
		{
			if (playerStats.mp + noneSaveStats.mpRecoveryForSecond > noneSaveStats.mpMax)
			{
				playerStats.mp = noneSaveStats.mpMax;
			}
			else
			{
				playerStats.mp = playerStats.mp + noneSaveStats.mpRecoveryForSecond;
			}
		}*/
	}	

}

 //Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
