// CE made by ran.

#include "CECharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "CE/CEGameInstance.h"
#include "CE/CEGameResource.h"

ACECharacter::ACECharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	TurnRateGamepad = 50.f;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void ACECharacter::BeginDestroy()
{
    Super::BeginDestroy();
}

void ACECharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
}

void ACECharacter::InitWhenSpawned(const FName& InModelId, const ECharaType InCharaType)
{
    CharaType = InCharaType;
    CharacterModelId = InModelId;
}
