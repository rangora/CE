// CE made by ran.

#include "CECore.h"

#include "CEGameMode.h"

ACEGameMode* CECore::GetGameMode(const UObject& InObject)
{
    ACEGameMode* Ret = nullptr;

    if (const UWorld* World = InObject.GetWorld(); IsValid(World))
    {
        Ret = Cast<ACEGameMode>(World->GetAuthGameMode());
    }

    return Ret;
}
