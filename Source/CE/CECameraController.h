// CE made by ran.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CECameraController.generated.h"

UCLASS()
class CE_API ACECameraController : public APlayerController
{
    GENERATED_BODY()
public:
    void SetupInputComponent() override;
};
