// CE made by ran.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CE/CEEnum.h"
#include "CECharacter.generated.h"

UCLASS(config=Game)
class ACECharacter : public ACharacter
{
    GENERATED_BODY()
public:
	ACECharacter();

	void BeginDestroy() final;
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) final;

	void InitWhenSpawned(const FName& InModelId, const ECharaType InCharaType);
    void MoveTo(const FVector& InDest);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

private:
	UPROPERTY(EditDefaultsOnly)
    FName CharacterModelId = FName();

	ECharaType CharaType = ECharaType::None;
};

