// CE made by ran.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CEGameInstance.generated.h"

UCLASS()
class CE_API UCEGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
    static UCEGameInstance *GetGameInstance(const UObject *InObject);

    void Init() override;
};
