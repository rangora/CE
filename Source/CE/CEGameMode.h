// CE made by ran.

#pragma once

#include "CoreMinimal.h"
#include "CEEnum.h"
#include "GameFramework/GameModeBase.h"
#include "CEGameMode.generated.h"

UCLASS(minimalapi)
class ACEGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACEGameMode();

	void StartPlay() final;

	AActor* SpawnActor(const ESpawnType InType, const FName& InId, const FTransform& InTransform);

private:
    AActor* SpawnCharacterActor(const FName& InId, const FTransform& InTransform);
};