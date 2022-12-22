// CE made by ran.

#include "CEGameResource.h"

const FName UCEGameResource::CharacterModelDataTablePath = FName(TEXT("DataTable'/Game/DataTable/CharacterModelTable.CharacterModelTable'"));

UCEGameResource::UCEGameResource(const FObjectInitializer& ObjectInitializer)
{
    CharacterModelDataTable =
        StaticLoadObject(UDataTable::StaticClass(), nullptr, *CharacterModelDataTablePath.ToString());
}

FCharacterModelRow* UCEGameResource::GetCharacterModelRow(const FName& InKey)
{
    FCharacterModelRow* Ret = nullptr;

    UDataTable* DataTable = CharacterModelDataTable.LoadSynchronous();
    if (IsValid(DataTable))
    {
        Ret = DataTable->FindRow<FCharacterModelRow>(InKey, TEXT("Get character model row"));
    }

    return Ret;
}
