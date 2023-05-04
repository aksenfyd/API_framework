#pragma once
#include "Scene.h"

class GameObject;
class Stage
{
private:
	HDC m_hdc;
	GameObject* m_pPlayer;
	GameObject* m_pEnemy;
public:
	virtual void Start()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	Stage();
	virtual ~Stage();
};

