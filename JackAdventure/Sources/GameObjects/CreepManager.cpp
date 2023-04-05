#include "CreepManager.h"
#include <cstdlib>
CreepManager::CreepManager()
{
	m_CreepNum = 20;
	m_TimeSpwanCreep = 2.f;
	m_currentTime = 0.f;
	//rand() % (max – min + 1) + min

}

CreepManager::~CreepManager()
{
	for (auto it : m_ListCreepGirl) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_ListCreepGirl.clear();
	for (auto it : m_Listtachmon) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_Listtachmon.clear();
	for (auto it : m_ListCreepGirlunder) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_ListCreepGirlunder.clear();

	for (auto it : m_ListCreepBat) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_ListCreepBat.clear();
	for (auto it : m_ListCreepBatunder) {
		if (it != nullptr) {
			delete it;
		}
	}
	m_ListCreepBatunder.clear();
}

void CreepManager::Init(CollisionManager &collisionManager)
{
	
	for (int i = 0; i < m_CreepNum; i++) {
		CreepGirl* creepR = new CreepGirl();
		creepR->Init();
		creepR->getHitBox()->setAlive(false);
		m_ListCreepGirl.push_back(creepR);
		collisionManager.addObj(creepR->getHitBox());

		CreepGirlunder* creepRu = new CreepGirlunder();
		creepRu->Init();
		creepRu->getHitBox()->setAlive(false);
		m_ListCreepGirlunder.push_back(creepRu);
		collisionManager.addObj(creepRu->getHitBox());

		Creeptachmonunder* creepMu = new Creeptachmonunder();
		creepMu->Init();
		creepMu->getHitBox()->setAlive(false);
		m_Listtachmonunder.push_back(creepMu);
		collisionManager.addObj(creepMu->getHitBox());

		Creeptachmon* creepM = new Creeptachmon();
		creepM->Init();
		creepM->getHitBox()->setAlive(false);
		m_Listtachmon.push_back(creepM);
		collisionManager.addObj(creepM->getHitBox());

		
		CreepBat* creepB = new CreepBat();
		creepB->Init();
		creepB->getHitBox()->setAlive(false);
		m_ListCreepBat.push_back(creepB);
		collisionManager.addObj(creepB->getHitBox());

		CreepBatunder* creepC = new CreepBatunder();
		creepC->Init();
		creepC->getHitBox()->setAlive(false);
		m_ListCreepBatunder.push_back(creepC);
		collisionManager.addObj(creepC->getHitBox());
		
	}
}

void CreepManager::Update(float deltaTime)
{
	m_currentTime += deltaTime;
	if (m_currentTime > m_TimeSpwanCreep) {
		//  tao ham random de spawn
		//
		SpawnBat();
		SpawnBatunder();
		int randomvalue = rand() % 5;
		if(randomvalue <= 3){
			SpawnGirl();
		}
		else
			Spawntachmon();
		randomvalue = rand() % 6;
		if(randomvalue<=3)
			SpawnGirlunder();
		else 
			Spawntachmonunder();

		m_currentTime = 0.f;
	}
	for (auto creep : m_ListCreepGirl) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_Listtachmon) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_Listtachmonunder) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_ListCreepBat) {
		creep->Update(deltaTime);
	}

	for (auto creep : m_ListCreepBatunder) {
		creep->Update(deltaTime);
	}
	for (auto creep : m_ListCreepGirlunder) {
		creep->Update(deltaTime);
	}
}

void CreepManager::Render(sf::RenderWindow* window)
{
	for (auto creep : m_ListCreepGirl) {
		creep->Render(window);
	}
	for (auto creep : m_Listtachmon) {
		creep->Render(window);
	}
	for (auto creep : m_Listtachmonunder) {
		creep->Render(window);
	}
	for (auto creep : m_ListCreepGirlunder) {
		creep->Render(window);
	}
	for (auto creep : m_ListCreepBat) {
		creep->Render(window);
	}
	for (auto creep : m_ListCreepBatunder) {
		creep->Render(window);
	}
	
}

void CreepManager::SpawnGirl()
{
	Creep* creep = nullptr;
	for (auto it : m_ListCreepGirl) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(sf::Vector2f(screenWidth + rand()%(150-50+1)+50, groundY-25));
	creep->getHitBox()->setVelocity(sf::Vector2f(200+rand()%100,0));
	creep->Reset();
}

void CreepManager::SpawnGirlunder()
{
	Creep* creep = nullptr;
	for (auto it : m_ListCreepGirlunder) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(sf::Vector2f(screenWidth + rand() % (150 - 50 + 1) + 50, groundY + 25));
	creep->getHitBox()->setVelocity(sf::Vector2f(200 + rand() % 100, 0));
	creep->Reset();
}

void CreepManager::Spawntachmon()
{
	Creep* creep = nullptr;
	for (auto it : m_Listtachmon) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(sf::Vector2f(screenWidth + rand() % (150 - 50 + 1) + 50, groundY - 25));
	creep->getHitBox()->setVelocity(sf::Vector2f(200 + rand() % 100, 0));
	creep->Reset();
}

void CreepManager::Spawntachmonunder()
{
	Creep* creep = nullptr;
	for (auto it : m_Listtachmonunder) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(sf::Vector2f(screenWidth + rand() % (150 - 50 + 1) + 50, groundY + 25));
	creep->getHitBox()->setVelocity(sf::Vector2f(200 + rand() % 100, 0));
	creep->Reset();
}

void CreepManager::SpawnBat()
{
	Creep* creep = nullptr;
	for (auto it : m_ListCreepBat) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(sf::Vector2f(screenWidth + rand() % (250 - 110 + 1) + 60, groundY-(rand()%(200 - 100 + 1) + 100)));
	creep->Reset();
}

void CreepManager::SpawnBatunder()
{
	Creep* creep = nullptr;
	for (auto it : m_ListCreepBatunder) {
		if (it->getHitBox()->isAlive() == false && it->isStop() == true) {
			creep = it;
			break;
		}
	}
	if (creep == nullptr) return;
	creep->getHitBox()->setAlive(true);
	creep->setStartPoint(sf::Vector2f(screenWidth + rand() % (150 - 50 + 1) + 10, groundY + (rand() % (200 - 100 + 1)+100 )));
	creep->Reset();
}

