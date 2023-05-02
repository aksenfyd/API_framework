#pragma once
#include "Include.h"

class GameObject;
class MainUpdate
{
private:
	HDC m_hdc;

	RECT rcPoint;
	GameObject* m_pPlayer;

	/*float StartX, StartY;
	float EndX, EndY;
	
	float SBulletX, SBulletY;
	float EBulletX, EBulletY;

	bool shoot;*/

public:
	void Start();
	void Update();
	void Render();
	void Destroy();

public:
	MainUpdate();
	~MainUpdate();
};

