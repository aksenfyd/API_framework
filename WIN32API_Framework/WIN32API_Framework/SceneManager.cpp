#include "SceneManager.h"

#include "LOGO.h"
#include "MENU.h"
#include "Stage.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr)
{
}

SceneManager::~SceneManager()
{
}
void SceneManager::SetScene(SCENEID _State)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_State)
	{

	case LOGO:
		SceneState = new LOGO;
		break;

	case MENU:
		SceneState = new MENU;
		break;

	case STAGE:
		SceneState = new STAGE;
		break;

	}
	SceneState->Start();
}

void SceneManager::Update()
{
	SceneState->Update();

}

void SceneManager::Render(HDC hdc)
{
	SceneState->Render(hdc);

}

void SceneManager::Destroy()
{
	delete SceneState;
	SceneState = nullptr;
}

