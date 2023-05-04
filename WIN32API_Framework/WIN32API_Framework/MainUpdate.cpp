#include "MainUpdate.h"
#include "Scene.h"


MainUpdate::MainUpdate() : m_pPlayer(NULL)
{
}

MainUpdate::~MainUpdate()
{
	Destroy();
}


void MainUpdate::Start()
{
	
}

void MainUpdate::Update()
{

	

	
}

void MainUpdate::Render()
{
	Rectangle(m_hdc, 0, 0, WIDTH, HEIGHT);
	
}

void MainUpdate::Destroy()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}

}
