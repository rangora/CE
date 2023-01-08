// CE made by ran.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CEDebugManager.generated.h"

namespace CEDebug
{
    AActor* SpawnTextRenderActor(const UObject& InObject, const FVector& InLoc, const FString InText,
                                 const float InScale = 2.f, const float InLifeTime = 3.f, const bool bInBillboardMode = true);
}

UCLASS()
class CE_API UCEDebugManager : public UObject
{
	GENERATED_BODY()
};
