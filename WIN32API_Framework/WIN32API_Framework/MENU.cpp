#include "MENU.h"
#include "SceneManager.h"

MENU::MENU()
{
}

MENU::~MENU()
{
}
void MENU::Start()
{
}

int MENU::Update()
{
	if (GetAsyncKeyState('S'))
	{
		SceneManager::GetInstance()->SetScene(STAGE);
	}
	return 0;
}

void MENU::Render(HDC hdc)
{
	Ellipse(hdc, 500, 500, 600, 600);
}

void MENU::Destroy()
{
}