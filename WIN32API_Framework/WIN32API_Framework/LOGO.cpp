#include "LOGO.h"
#include "SceneManager.h"

LOGO::LOGO()
{
}

LOGO::~LOGO()
{
}
void LOGO::Start()
{
}

int LOGO::Update()
{
	if (GetAsyncKeyState('A'))
	{
		SceneManager::GetInstance()->SetScene(MENU);
	}
	return 0;
}

void LOGO::Render(HDC hdc)
{
	Rectangle(hdc, 500, 500, 600, 600);
}

void LOGO::Destroy()
{
}