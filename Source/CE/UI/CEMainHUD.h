// CE made by ran.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CEMainHUD.generated.h"

UCLASS()
class CE_API ACEMainHUD : public AHUD
{
	GENERATED_BODY()
public:
    ACEMainHUD(const FObjectInitializer& ObjectInitializer);
    
    void BeginPlay() final;
    void DrawHUD() final;

#if WITH_EDITOR
    void DrawMessageOnCanvas_WithEditor();
#endif

    UPROPERTY()
    TObjectPtr<class ACEMainController> Controller = nullptr;
};
