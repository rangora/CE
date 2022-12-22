// CE made by ran.

#include "CEGameInstance.h"

#include "CEGameResource.h"

UCEGameInstance* UCEGameInstance::GetGameInstance(const UObject* InObject)
{
    UWorld* World = IsValid(InObject) ? InObject->GetWorld() : nullptr;

    return IsValid(World) ? Cast<UCEGameInstance>(World->GetGameInstance()) : nullptr;
}

UCEGameResource& UCEGameInstance::GetGameResource()
{
    return *GameResource;
}

void UCEGameInstance::Init()
{
    Super::Init();

    GameResource = NewObject<UCEGameResource>();
    if (!IsValid(GameResource))
    {
        ensure(false);
        UE_LOG(LogClass, Error, TEXT("GameResource obejct create failed."));
    }
}