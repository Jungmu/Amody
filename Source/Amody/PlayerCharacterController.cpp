// Copyright JJ 2017-

#include "PlayerCharacterController.h"

// Called every frame
void APlayerCharacterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	GetInputTouchState(ETouchIndex::Touch1, touchX, touchY, bIsTouchPressed);

	if (bIsTouchPressed)
	{
		
	}
	else
	{

	}
}


// Called when the game starts or when spawned
void APlayerCharacterController::BeginPlay()
{
	Super::BeginPlay();

}