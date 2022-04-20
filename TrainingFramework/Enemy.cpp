#include "Character/Enemy.h"

Enemy::Enemy(GLint level, GLint exp)
	:Character(level, exp)
{
	this->m_isEnemy = true;
}

Enemy::~Enemy()
{
}

void Enemy::Update(GLfloat deltatime)
{
    if (!m_stackMove.empty()) {
        m_time += deltatime;
        if (m_time > 0.15) {
            auto temp = m_stackMove.top();
            m_stackMove.pop();
            switch (temp.direction)
            {
            case 1:
                this->fieldAnimation->SetCurrentAction(1);
                break;
            case 2:
                this->fieldAnimation->SetCurrentAction(3);
                break;
            case 3:
                this->fieldAnimation->SetCurrentAction(2);
                break;
            case 4:
                this->fieldAnimation->SetCurrentAction(0);
                break;
            }
            this->m_posX = temp.x;
            this->m_posY = temp.y;
            m_time = 0;
            if (!m_stackMove.empty()) {
                m_disableButton = false;
                m_isFinishTurn = true;
            }
        }
    }
    else {
        m_disableButton = false;
    }
}

bool Enemy::AI(std::shared_ptr<MapSquare>** mapMatrix)
{
    calculateMovementMap(mapMatrix);
    for (int i = 0; i < Globals::mapWidth; i++) {
        for (int j = 0; j < Globals::mapHeight; j++) {
            m_attackMap[i][j].mark = false;
        }
    }
    for (int i = 0; i < Globals::mapWidth; i++) {
        for (int j = 0; j < Globals::mapHeight; j++) {
            if (m_movementMap[i][j].mark) {
                if (i - 1 >= 0) {
                    if (!m_attackMap[i - 1][j].mark) {
                        m_attackMap[i - 1][j].mark = true;
                        m_attackMap[i - 1][j].preX = i;
                        m_attackMap[i - 1][j].preY = j;
                    }
                }
                if (i + 1 <= Globals::mapWidth) {
                    if (!m_attackMap[i + 1][j].mark) {
                        m_attackMap[i + 1][j].mark = true;
                        m_attackMap[i + 1][j].preX = i;
                        m_attackMap[i + 1][j].preY = j;
                    }
                }
                if (j - 1 >= 0) {
                    if (!m_attackMap[i][j - 1].mark) {
                        m_attackMap[i][j - 1].mark = true;
                        m_attackMap[i][j - 1].preX = i;
                        m_attackMap[i][j - 1].preY = j;
                    }
                }
                if (j + 1 <= Globals::mapHeight) {
                    if (!m_attackMap[i][j + 1].mark) {
                        m_attackMap[i][j + 1].mark = true;
                        m_attackMap[i][j + 1].preX = i;
                        m_attackMap[i][j + 1].preY = j;
                    }
                }
            }
        }
    }


    int recordDmg = -1;

    for (int i = 0; i < Globals::mapWidth; i++) {
        for (int j = 0; j < Globals::mapHeight; j++) {
            if (m_attackMap[i][j].mark) {
                //search for best target
                auto temp = mapMatrix[i][j]->getCharacter();
                if (temp != nullptr) {
                    if (!temp->isEnemy()) {
                        int dmg = this->m_power - temp->getDef() - mapMatrix[i][j]->getDefense();
                        if (dmg < 0) dmg = 0;
                        if (recordDmg < dmg) {
                            recordDmg = dmg;
                            target = temp;
                            this->targetPosX = i;
                            this->targetPosY = j;
                        }
                    }
                }
            }
        }
    }
    if (recordDmg >= 0) {
        int x = m_attackMap[targetPosX][targetPosY].preX;
        int y = m_attackMap[targetPosX][targetPosY].preY;
        targetPosX = x;
        targetPosY = y;
        if (x == this->m_posX && y == this->m_posY) {
            this->m_isFinishTurn = true;
        }
        return true;
    }
    else {
        this->m_isFinishTurn = true;
        target = nullptr;
        return false;
    }
}


