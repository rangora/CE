// CE made by ran.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CEGridManager.generated.h"

UCLASS()
class CE_API ACEGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	struct FCEGirdData
    {
    };

	ACEGridManager();
	void BeginPlay() final;
	void Tick(float DeltaTime) final;

	void Init();
	void GridUnfold();
    void GriFold();

	bool IsUnfold = false;
	
	TArray<FCEGirdData> GridData;

	TObjectPtr<UInstancedStaticMeshComponent> GridInstanceComponent = nullptr;
};
