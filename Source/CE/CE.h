// CE made by ran.

#pragma once

#include "CoreMinimal.h"

class CEGameModule : public FDefaultGameModuleImpl
{
public:
    void StartupModule() final;

    static CEGameModule* Get() { return GameModule; }

    void LoadGameResource();
    class UCEGameResource* GetGameResource() { return GameResource; }

private:
    static CEGameModule* GameModule;

    TObjectPtr<UCEGameResource> GameResource = nullptr;
};
