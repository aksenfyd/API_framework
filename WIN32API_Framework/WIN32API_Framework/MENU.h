#pragma once
#include "Scene.h"
class MENU
{
public:
	virtual void Start()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC hdc)PURE;
	virtual void Destroy()PURE;
public:
	MENU();
	virtual ~MENU();
};

