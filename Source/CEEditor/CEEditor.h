// CE made by ran.

#pragma once

#include "UnrealEd.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Editor/LevelEditor/Public/LevelEditor.h"
#include "Editor/PropertyEditor/Public/PropertyEditing.h"
#include "IAssetTypeActions.h"
#include "CEModuleInterface.h"

class FCEEditor : public ICEEditorModuleInterface
{
public:
    virtual void StartupModule();
    virtual void ShutdownModule();

    virtual void AddModuleListeners();
};