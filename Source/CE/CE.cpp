// CE made by ran.

#include "CE.h"

#include "Framework/Application/SlateApplication.h"
#include "Modules/ModuleManager.h"

#include "CE/CEGameResource.h"

IMPLEMENT_PRIMARY_GAME_MODULE(CEGameModule, CE, "CE");

CEGameModule* CEGameModule::GameModule = nullptr;

void CEGameModule::StartupModule()
{
    FDefaultGameModuleImpl::StartupModule();

    if (FSlateApplication::IsInitialized())
    {
        // LoadScreen
    }

    GameModule = this;

    LoadGameResource();
}

void CEGameModule::LoadGameResource()
{
    if (!IsValid(GameResource))
    {
        GameResource = NewObject<UCEGameResource>(GetTransientPackage(), UCEGameResource::StaticClass());
    }

    if (ensure(GameResource))
    {
        GameResource->AddToRoot();
    }
}
