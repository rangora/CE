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
    static UCEGameInstance* GetGameInstance(const UObject *InObject);
    class UCEGameResource& GetGameResource();

    void Init() override;

private:
    TObjectPtr<UCEGameResource> GameResource = nullptr;
};
