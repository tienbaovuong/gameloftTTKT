#include "Level/LevelZero.h"


LevelZero::LevelZero()
	:LevelBase()
{
	//x and y
	startXPointer = 9;
	startYPointer = 19;
	xOffset = 2;
	yOffset = 9;

	//allies
	ike = std::make_shared<Ike>(2, 0); ike->setPosXY(9, 19);
	dorcas = std::make_shared<Dorcas>(2, 0); dorcas->setPosXY(9, 18);
	serra = std::make_shared<Serra>(1, 0); serra->setPosXY(11, 13);
	serra->setCharName("???");
	m_alliesList.push_back(ike);
	m_alliesList.push_back(dorcas);
	m_alliesList.push_back(serra);

	//enemy
	banditLeader = std::make_shared<EnemyBanditHeader>(3, 0); banditLeader->setPosXY(9, 1);
	bandit1 = std::make_shared<EnemyBandit>(1, 0); bandit1->setPosXY(10, 13);
	bandit2 = std::make_shared<EnemyBandit>(1, 0); bandit2->setPosXY(11, 14);
	bandit3 = std::make_shared<EnemyBandit>(1, 0); bandit3->setPosXY(8, 2);
	bandit4 = std::make_shared<EnemyBandit>(1, 0); bandit4->setPosXY(9, 5);
	bandit5 = std::make_shared<EnemyBandit>(2, 0); bandit5->setPosXY(15, 8);
	bandit6 = std::make_shared<EnemyBandit>(2, 0); bandit6->setPosXY(16, 2);
	bandit7 = std::make_shared<EnemyBandit>(2, 0); bandit7->setPosXY(10, 2);
	m_enemyList.push_back(bandit1);
	m_enemyList.push_back(bandit2);
	m_enemyList.push_back(bandit3);
	m_enemyList.push_back(bandit4);
	m_enemyList.push_back(bandit5);
	m_enemyList.push_back(bandit6);
	m_enemyList.push_back(bandit7);
	m_enemyList.push_back(banditLeader);
}

LevelZero::~LevelZero()
{
}
