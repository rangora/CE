// CE made by ran.

#include "CEDebugManager.h"

#include "CE/CEDebugTextRenderActor.h"

AActor* CEDebug::SpawnTextRenderActor(const UObject& InObject, const FVector& InLoc, const FString InText,
                                      const float InScale, const float InLifeTime, const bool bInBillboardMode)
{
#if !(UE_BUILD_SHIPPING || UE_BUILD_TEST)
    FActorSpawnParameters SpawnInfo;
    ACEDebugTextRenderActor* TextActor =
        InObject.GetWorld()->SpawnActor<ACEDebugTextRenderActor>(InLoc, FRotator(0.f, -180.f, 0.f), SpawnInfo);
    if (!IsValid(TextActor))
    {
        return nullptr;
    }

    TextActor->SetText(InText);
    TextActor->SetActorScale3D(FVector(InScale));
    TextActor->LifeTime = InLifeTime;

    return TextActor;
#endif

    return nullptr;
}
