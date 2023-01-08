// CE made by ran.

#include "CEDebugTextRenderActor.h"

#include "Components/TextRenderComponent.h"

ACEDebugTextRenderActor::ACEDebugTextRenderActor()
{
	PrimaryActorTick.bCanEverTick = true;

    GetTextRender()->SetText(FText::FromName(TEXT("DefaultText")));
}


void ACEDebugTextRenderActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!GetWorld())
    {
        Destroy();
        return;
	}

#if WITH_EDITOR
    const FVector CurrentPos = GetActorLocation();
    const FVector MovePos = CurrentPos + MovingDirection * DeltaTime;
    SetActorLocation(MovePos);
#endif

    LifeTime -= DeltaTime;
    if (LifeTime <= 0.f && !IsPendingKill())
    {
        Destroy();
    }
}

void ACEDebugTextRenderActor::SetText(const FString& InString)
{
    GetTextRender()->SetText(FText::FromString(InString));
    GetTextRender()->SetHorizontalAlignment(EHTA_Center);
}

