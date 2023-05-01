#include "MainUpdate.h"

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
}


void MainUpdate::Start()
{
	m_hdc = GetDC(g_hWnd);

	rcPoint.left = 100;
	rcPoint.top = 100;

	rcPoint.right = 200;
	rcPoint.bottom = 200;

	StartX = 100;
	StartY = 100;
	
	EndX = 200;
	EndY = 200;

	SBulletX = 20, SBulletY = 20;
	EBulletX = 40, EBulletY = 40;
}

void MainUpdate::Update()
{
	if (GetAsyncKeyState(VK_UP))
	{
		StartY -= 0.01;
		EndY -= 0.01;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		StartY += 0.01;
		EndY += 0.01;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		StartX -= 0.01;
		EndX -= 0.01;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		StartX += 0.01;
		EndX += 0.01;

	}

	if (GetAsyncKeyState(VK_SPACE))
	{
		shoot = true;

	}

	

}

void MainUpdate::Render()
{
	/*Rectangle(m_hdc,
		50, 50, 1280, 500);*/
	Rectangle(m_hdc,
		StartX, StartY, EndX, EndY);

	if (shoot)
	{
	SBulletX += 0.01;
	EBulletX += 0.01;
	}


	Rectangle(m_hdc,
		SBulletX, SBulletY, EBulletX, EBulletY);
	
}

void MainUpdate::Destroy()
{
}
