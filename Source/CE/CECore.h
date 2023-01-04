// CE made by ran.

#include "CoreMinimal.h"

class ACEGameMode;
class UCEGameResource;

namespace CECore
{
    ACEGameMode* GetGameMode(const UObject& InObject);
    UCEGameResource* GetGameResource();
};