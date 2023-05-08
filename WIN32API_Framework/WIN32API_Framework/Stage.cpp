#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectManager.h"

Stage::Stage() : m_pPlayer(nullptr), EnemyList(nullptr), BulletList(nullptr)
{
	
}

Stage::~Stage()
{
	Destroy();
}
void Stage::Start()
{

	m_pPlayer = (new Player)->Start();
	
	ObjectManager::GetInstance()->AddObject(
	(new Enemy)->Start());

	EnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");
}

int Stage::Update()
{
	if (m_pPlayer)
		m_pPlayer->Update();

	if (EnemyList != nullptr && EnemyList->empty())
	{

		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
			(*iter)->Update();
	}
	
	if (BulletList != nullptr && BulletList->empty())
	{

		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
			(*iter)->Update();
	}
	else
		BulletList = ObjectManager::GetInstance()->GetObjectList("Bullet");

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
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
			(*iter)->Render(m_hdc);
	}
}

void Stage::Destroy()
{
	if (m_pPlayer)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}
	if (EnemyList != nullptr && EnemyList->empty())
	{

		for (list<GameObject*>::iterator iter = EnemyList->begin(); iter != EnemyList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		EnemyList->clear();
	}

	if (BulletList != nullptr && BulletList->empty())
	{
		for (list<GameObject*>::iterator iter = BulletList->begin(); iter != BulletList->end(); ++iter)
		{
			delete (*iter);
			(*iter) = nullptr;
		}
		BulletList->clear();
	}
}


