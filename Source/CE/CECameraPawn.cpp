// CE made by ran.

#include "CECameraPawn.h"

#include "Camera/CameraComponent.h"
#include "Engine/GameViewportClient.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "CEGameInstance.h"

ACECameraPawn::ACECameraPawn()
{
    PrimaryActorTick.bCanEverTick = true;
    SetActorTickEnabled(false);

    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CameraPawn SceneComp"));
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraPawn springArmComp"));
    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraPawn CameraComp"));
    FloatingPawnComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("CameraPawn FloatingComp"));

    SpringArmComponent->SetupAttachment(RootComponent);
    CameraComponent->SetupAttachment(SpringArmComponent);

    SpringArmComponent->TargetArmLength = 1200.f;
    SpringArmComponent->SetWorldRotation(FRotator(-50.f, 0.f, 0.f));
}

void ACECameraPawn::Tick(float Delta)
{
    const float ViewportScale = UWidgetLayoutLibrary::GetViewportScale(ViewportClient);
    const FVector2D MousePosition = UWidgetLayoutLibrary::GetMousePositionOnViewport(this);
    FVector2D ViewportSize = FVector2D::ZeroVector;

    ViewportClient->GetViewportSize(ViewportSize);

    const float XAxisPosition = MousePosition.X * ViewportScale;
    const float YAxisPosition = MousePosition.Y * ViewportScale;

    MouseMoveOnAxis(XAxisPosition, ViewportSize.X, FVector(0.f, -1.0f, 0.f));
    MouseMoveOnAxis(YAxisPosition, ViewportSize.Y, FVector(1.f,  0.0f, 0.f));
}

void ACECameraPawn::BeginPlay()
{
    Super::BeginPlay();

    const UCEGameInstance* GameInstance = UCEGameInstance::GetGameInstance(this);

    ViewportClient = GameInstance->GetGameViewportClient();
    if (!IsValid(ViewportClient))
    {
        ensure(false);
    }

    this->SetActorTickEnabled(true);
}

void ACECameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    check(PlayerInputComponent);
    PlayerInputComponent->BindAxis("Move Forward / Backward", this, &ACECameraPawn::MoveForward);
    PlayerInputComponent->BindAxis("Move Right / Left", this, &ACECameraPawn::MoveRight);
}

void ACECameraPawn::MoveForward(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void ACECameraPawn::MoveRight(float Value)
{
    if ((Controller != nullptr) && (Value != 0.0f))
    {
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

        AddMovementInput(Direction, Value);
    }
}

void ACECameraPawn::MouseMoveOnAxis(const float InPositionOnAxis, const float InAxisLength, const FVector& InAxis)
{
    const float a = InAxisLength - InPositionOnAxis;
    if (a < 2)
    {
        AddMovementInput(InAxis, -1.f);
    }
    else
    {
        const float b = InAxisLength - 1;
        if (a > b)
        {
            AddMovementInput(InAxis, 1.f);
        }
    }
}