#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"

Stage::Stage()
{
}

Stage::~Stage()
{
}
void Stage::Start()
{
	m_hdc = GetDC(g_hWnd);

	m_pPlayer = new Player();
	m_pPlayer->Start();

	m_pEnemy = new Enemy();
	m_pEnemy->Start();

	ObjectManager::GetInstance()->AddObject(m_pEnemy);
}

int Stage::Update()
{
	if (m_pPlayer)
		m_pPlayer->Update();

	return 0;
}

void Stage::Render(HDC hdc)
{
	list<GameObject*>* EnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
	list<GameObject*>* BulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");


	if (m_pPlayer)
		m_pPlayer->Render(m_hdc);

	if (EnemyList != nullptr && EnemyList->empty())
	{

		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
			(*iter)->Render(m_hdc);
	}

	if (BulletList != nullptr && BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != EnemyList->end(); ++iter)
			(*iter)->Render(m_hdc);
	}
}

void Stage::Destroy()
{
}


