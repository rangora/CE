// CE made by ran.

#include "CEMainController.h"

#include "CE/Character/CECharacter.h"

void ACEMainController::Tick(float InDelta)
{
    Super::Tick(InDelta);

    if (IsInputKeyDown(TEXT("RightMouseButton")))
    {
        FHitResult Result;
        TArray<TEnumAsByte<EObjectTypeQuery>> HitObjectTypes;
        HitObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));

        const bool bHit = GetHitResultUnderCursorForObjects(HitObjectTypes, true, Result);
        if (bHit)
        {
            const FVector HitLocation = Result.ImpactPoint;
            for (const auto Chara : SelectedCharacters)
            {
                Chara->MoveTo(HitLocation);
            }
        }
    }
}

void ACEMainController::SetupInputComponent()
{
    Super::SetupInputComponent();

    SetShowMouseCursor(true);

    FInputModeGameAndUI InputMode;
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
    SetInputMode(InputMode);
}
