// CE made by ran.

#include "CEEditor.h"

#include "Logging/LogMacros.h"

IMPLEMENT_GAME_MODULE(FCEEditor, CEEditor)

void FCEEditor::AddModuleListeners()
{
}

void FCEEditor::StartupModule()
{
	UE_LOG(LogClass, Log, TEXT("depart"));
}

void FCEEditor::ShutdownModule()
{
}