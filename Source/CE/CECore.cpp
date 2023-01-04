// CE made by ran.

#include "CECore.h"

#include "CE.h"
#include "CEGameMode.h"
#include "CEGameResource.h"

ACEGameMode* CECore::GetGameMode(const UObject& InObject)
{
    ACEGameMode* Ret = nullptr;

    if (const UWorld* World = InObject.GetWorld(); IsValid(World))
    {
        Ret = Cast<ACEGameMode>(World->GetAuthGameMode());
    }

    return Ret;
}

UCEGameResource* CECore::GetGameResource()
{
    UCEGameResource* Ret = nullptr;

    if (auto GameModule = CEGameModule::Get(); ensure(GameModule))
    {
        Ret = GameModule->GetGameResource();
    }

    return Ret;
}
