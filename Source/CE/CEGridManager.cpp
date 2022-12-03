// CE made by ran.

#include "CEGridManager.h"

#include "Components/InstancedStaticMeshComponent.h"

#include "CEConst.h"

ACEGridManager::ACEGridManager()
{
	PrimaryActorTick.bCanEverTick = false;
	
	auto SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
    if (IsValid(SceneComponent))
    {
        RootComponent = SceneComponent;
	}

	GridInstanceComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("GridInstanceComp"));
	if (IsValid(GridInstanceComponent))
	{
        GridInstanceComponent->SetMobility(EComponentMobility::Movable);
		GridInstanceComponent->SetupAttachment(RootComponent);
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube"));
    if (CubeMesh.Succeeded())
    {
		GridInstanceComponent->SetStaticMesh(CubeMesh.Object);
    }
}

void ACEGridManager::BeginPlay()
{
	Super::BeginPlay();

	GridUnfold();
}

void ACEGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACEGridManager::Init()
{
    GridData.Reserve(CEConst::GRID_SIZE);
}

void ACEGridManager::GridUnfold()
{
    if (IsUnfold)
    {
        ensure(false);
        return;
    }

	TArray<FTransform> GridInstanceTransform;

	for (int32 Row = 0; Row < CEConst::GRID_ROW; ++Row)
    {
        for (int32 Col = 0; Col < CEConst::GRID_COLUMN; ++Col)
        {
            FTransform GridTransform(FRotator3d::ZeroRotator,
                                     FVector3d(CEConst::GRID_INTERVAL * Row, CEConst::GRID_INTERVAL * Col, 0.f),
                                     FVector3d(0.5f, 0.5f, 0.5f));
            GridInstanceTransform.Add(GridTransform);
        }
	}

	GridInstanceComponent->AddInstances(GridInstanceTransform, false);
}

void ACEGridManager::GriFold()
{
}

