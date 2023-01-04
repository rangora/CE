// CE made by ran.

#include "CEGameInstance.h"

UCEGameInstance* UCEGameInstance::GetGameInstance(const UObject* InObject)
{
    UWorld* World = IsValid(InObject) ? InObject->GetWorld() : nullptr;

    return IsValid(World) ? Cast<UCEGameInstance>(World->GetGameInstance()) : nullptr;
}

void UCEGameInstance::Init()
{
    Super::Init();
}