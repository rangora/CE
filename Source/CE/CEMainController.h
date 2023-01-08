// CE made by ran.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CEMainController.generated.h"

UCLASS()
class CE_API ACEMainController : public APlayerController
{
	GENERATED_BODY()

public:
    void Tick(float InDelta) final;
    void SetupInputComponent() override;

    TArray<class ACECharacter*> SelectedCharacters;
};
