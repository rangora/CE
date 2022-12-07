// CE made by ran.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CECameraPawn.generated.h"

UCLASS()
class CE_API ACECameraPawn : public APawn
{
    GENERATED_BODY()

public:
    ACECameraPawn();
    void Tick(float Delta) final;
    void BeginPlay() final;
    void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) final;

    void MoveForward(float Value);
    void MoveRight(float Value);
    void MouseMoveOnAxis(const float InPositionOnAxis, const float InAxisLength, const FVector& InAxis);

    FVector2D CameraLocation = FVector2D::ZeroVector;

    UPROPERTY()
    TObjectPtr<class USpringArmComponent> SpringArmComponent = nullptr;

    UPROPERTY()
    TObjectPtr<class UCameraComponent> CameraComponent = nullptr;

    UPROPERTY()
    TObjectPtr<class UFloatingPawnMovement> FloatingPawnComponent = nullptr;

    UPROPERTY()
    TObjectPtr<class UGameViewportClient> ViewportClient = nullptr;
};
