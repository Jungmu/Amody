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
	
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*float moveY = InputComponent->GetAxisValue("MoveY");
	float moveX = InputComponent->GetAxisValue("MoveX");

	FRotator rotator = UKismetMathLibrary::MakeRotFromX(FVector(moveX, moveY, 0.f));

	SetActorRotation(rotator);*/
}

 //Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//InputComponent->BindAxis("MoveY", this, &ACharacterBase::MoveForward);
	//InputComponent->BindAxis("MoveX", this, &ACharacterBase::MoveForward);
}
//
//void ACharacterBase::MoveForward(float amount) 
//{
//	if (Controller && amount)
//	{		
//		AddMovementInput(GetActorForwardVector(),FMath::Abs(amount)*MoveSpeed*FApp::GetDeltaTime());
//	}
//	
//}