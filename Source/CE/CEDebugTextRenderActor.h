// CE made by ran.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TextRenderActor.h"
#include "CEDebugTextRenderActor.generated.h"

UCLASS()
class CE_API ACEDebugTextRenderActor : public ATextRenderActor
{
	GENERATED_BODY()
public:
	ACEDebugTextRenderActor();
	void Tick(float DeltaTime) final;

	void SetText(const FString& InString);

	float LifeTime = 3.f;
    FVector MovingDirection = FVector(0.f, 0.f, 50.f);
};
