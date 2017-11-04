// Copyright JJ 2017-

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerCharacterController.generated.h"

/**
 * 
 */
UCLASS()
class AMODY_API APlayerCharacterController : public APlayerController
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float touchX;

	UPROPERTY(EditAnywhere)
	float touchY;

	UPROPERTY(EditAnywhere)
	bool bIsTouchPressed;

	UPROPERTY(EditAnywhere)
	UTouchInterface* joyStick;
	
};
