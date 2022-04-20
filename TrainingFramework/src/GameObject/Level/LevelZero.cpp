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
	ike = std::make_shared<Ike>(2, 0); ike->setPosXY(9, 19); auto item2 = std::make_shared<IronSword>(30); ike->m_itemList.push_back(item2); ike->equip(item2);
	dorcas = std::make_shared<Dorcas>(2, 0); dorcas->setPosXY(9, 18); auto item = std::make_shared<IronAxe>(30); dorcas->m_itemList.push_back(item); dorcas->equip(item);
	serra = std::make_shared<Serra>(1, 0); serra->setPosXY(11, 13); auto item3 = std::make_shared<HealingStaff>(20); serra->m_itemList.push_back(item3); serra->equip(item3);
	serra->setCharName("???");
	auto item4 = std::make_shared<Food>(3); ike->m_itemList.push_back(item4);
	item4 = std::make_shared<Food>(3); dorcas->m_itemList.push_back(item4);
	item4 = std::make_shared<Food>(3); serra->m_itemList.push_back(item4);
	m_alliesList.push_back(ike);
	m_alliesList.push_back(dorcas);
	m_alliesList.push_back(serra);

	//enemy
	banditLeader = std::make_shared<EnemyBanditHeader>(3, 0); banditLeader->setPosXY(9, 1); item = std::make_shared<IronAxe>(30); banditLeader->m_itemList.push_back(item); banditLeader->equip(item);
	bandit1 = std::make_shared<EnemyBandit>(1, 0); bandit1->setPosXY(10, 13); item = std::make_shared<IronAxe>(30); bandit1->m_itemList.push_back(item); bandit1->equip(item);
	bandit2 = std::make_shared<EnemyBandit>(1, 0); bandit2->setPosXY(11, 14); item = std::make_shared<IronAxe>(30); bandit2->m_itemList.push_back(item); bandit2->equip(item);
	bandit3 = std::make_shared<EnemyBandit>(1, 0); bandit3->setPosXY(8, 2); item = std::make_shared<IronAxe>(30); bandit3->m_itemList.push_back(item); bandit3->equip(item);
	bandit4 = std::make_shared<EnemyBandit>(1, 0); bandit4->setPosXY(9, 5); item = std::make_shared<IronAxe>(30); bandit4->m_itemList.push_back(item); bandit4->equip(item);
	bandit5 = std::make_shared<EnemyBandit>(2, 0); bandit5->setPosXY(15, 8); item = std::make_shared<IronAxe>(30); bandit5->m_itemList.push_back(item); bandit5->equip(item);
	bandit6 = std::make_shared<EnemyBandit>(2, 0); bandit6->setPosXY(16, 2); item = std::make_shared<IronAxe>(30); bandit6->m_itemList.push_back(item); bandit6->equip(item);
	bandit7 = std::make_shared<EnemyBandit>(2, 0); bandit7->setPosXY(10, 2); item = std::make_shared<IronAxe>(30); bandit7->m_itemList.push_back(item); bandit7->equip(item);
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

void LevelZero::update()
{
	
}
