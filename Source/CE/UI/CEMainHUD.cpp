// CE made by ran.

#include "CEMainHUD.h"

#include "CE/CEMainController.h"
#include "CE/Character/CECharacter.h"
#include "CE/CEDebugManager.h"

ACEMainHUD::ACEMainHUD(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
    PrimaryActorTick.bCanEverTick = true;
}

void ACEMainHUD::BeginPlay()
{
    Super::BeginPlay();

    Controller = Cast<ACEMainController>(GetOwningPlayerController());

    check(Controller);
}

void ACEMainHUD::DrawHUD()
{
    Super::DrawHUD();

    if (Controller->IsInputKeyDown(TEXT("LeftMouseButton")))
    {
        const FVector2D Offset{25.f, 25.f};
        double X = 0.0, Y = 0.0;
        Controller->GetMousePosition(X, Y);

        const FVector2D Point1{FVector2D{X, Y} - Offset};
        const FVector2D Point2{FVector2D{X, Y} + Offset};

        TArray<ACECharacter*> Actors;
        GetActorsInSelectionRectangle<ACECharacter>(Point1, Point2, Actors);

        Controller->SelectedCharacters.Empty();
        for (const auto Chara : Actors)
        {
            Controller->SelectedCharacters.Add(Chara);
            // 임시 Select 표시
            CEDebug::SpawnTextRenderActor(*Chara, Chara->GetActorLocation(), TEXT("Selected"));
        }
    }

#if WITH_EDITOR
    // 임시 디버그 메시지 테스트.
    if (false)
    {
        DrawMessageOnCanvas_WithEditor();
    }
#endif
}

void ACEMainHUD::DrawMessageOnCanvas_WithEditor()
{
    FString Str(TEXT("TestMessage"));
    DrawText(Str, FLinearColor::White, 20.f, 200.f, GEngine->GetMediumFont());
}
