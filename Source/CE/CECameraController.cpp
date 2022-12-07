// CE made by ran.

#include "CECameraController.h"

void ACECameraController::SetupInputComponent()
{
    Super::SetupInputComponent();

    SetShowMouseCursor(true);

    FInputModeGameAndUI InputMode;
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
    SetInputMode(InputMode);

}
