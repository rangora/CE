// CE made by ran.

#include "CEGameMode.h"
#include "Character/CECharacter.h"
#include "UObject/ConstructorHelpers.h"

// Test
#include "CE/CEGameInstance.h"
#include "CE/CEGameResource.h"
//

ACEGameMode::ACEGameMode() {}

void ACEGameMode::StartPlay()
{
    Super::StartPlay();

	// Test
    const FVector SpawnLocation(900.f, 900.f, 500.f);
    const FName Key(TEXT("1"));

    FTransform Trans{SpawnLocation};

    SpawnActor(ESpawnType::Character, Key, Trans);
    //
}

AActor* ACEGameMode::SpawnActor(const ESpawnType InType, const FName& InId, const FTransform& InTransform)
{
    AActor* Ret = nullptr;

    switch (InType)
    {
        case ESpawnType::Character:
        {
            Ret = SpawnCharacterActor(InId, InTransform);
        }
        break;
        default:
        {
            ensure(false);
        }
    }

    return Ret;
}

AActor* ACEGameMode::SpawnCharacterActor(const FName& InId, const FTransform& InTransform)
{
    UCEGameInstance* Instance = UCEGameInstance::GetGameInstance(this);
    UCEGameResource& GameResource = Instance->GetGameResource();

    auto Row = GameResource.GetCharacterModelRow(InId);
    if (Row == nullptr)
    {
        ensure(false);
        UE_LOG(LogClass, Warning, TEXT("CharacterModel %s번 row가 유효하지 않습니다."), *InId.ToString());
        return nullptr;
    }

    UClass* CharaClass = Row->CharacterClass.Get();
    ECharaType CharaType = Row->CharaType;
    if (!IsValid(CharaClass))
    {
        ensure(false);
        UE_LOG(LogClass, Warning, TEXT("CharacterModel %s번 row의 CharacterClass가 유효하지 않습니다."), *InId.ToString());
        return nullptr;
    }

    ACECharacter* SpawnedChara = GetWorld()->SpawnActor<ACECharacter>(CharaClass, InTransform);
    if (!IsValid(SpawnedChara))
    {
        ensure(false);
        UE_LOG(LogClass, Warning, TEXT("CharacterModel %s번 row 스폰에 실패했습니다."), *InId.ToString());
        return nullptr;
    }

    SpawnedChara->InitWhenSpawned(InId, CharaType);

    return SpawnedChara;
}