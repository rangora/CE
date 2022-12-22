// CE made by ran.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CECharacter.generated.h"

UCLASS(config=Game)
class ACECharacter : public ACharacter
{
    GENERATED_BODY()
public:
	ACECharacter();

	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) final;

	void Init();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

	UPROPERTY(EditDefaultsOnly)
    FName CharaterModeId = FName();
};

