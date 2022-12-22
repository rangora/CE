// CE made by ran.

#pragma once

#include "CEEnum.h"
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "CEGameResource.generated.h"

USTRUCT(BlueprintType)
struct FCharacterModelRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    ECharaType CharaType;

    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<USkeletalMesh> SkeletalMesh = nullptr;

    UPROPERTY(EditAnywhere)
    TSoftObjectPtr<UAnimBlueprint> AnimBlueprint = nullptr;
};

UCLASS()
class CE_API UCEGameResource : public UObject
{
	GENERATED_BODY()
public:
    UCEGameResource(const FObjectInitializer& ObjectInitializer);

    FCharacterModelRow* GetCharacterModelRow(const FName& InKey);

private:
    static const FName CharacterModelDataTablePath;

    UPROPERTY(EditDefaultsOnly, Category = "Character")
    TSoftObjectPtr<UDataTable> CharacterModelDataTable = nullptr;
};
