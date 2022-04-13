#include "Character.h"
#include <queue>

Character::Character(GLint level, GLint exp)
    :CharacterBase(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderTexture, AssetManager::GetInstance()->IkeField), m_name("unknown"), m_level(level),m_exp(exp), m_healthPoint(1), m_strength(0)
    , m_magic(0), m_defense(0), m_resistance(0), m_movement(5), m_minRange(1), m_maxRange(1), m_characterType("unknown"), m_power(0), bonusHitRate(0)
    , m_hitRate(100), m_evasion(0), m_critRate(5), m_posX(0), m_posY(0), fieldAnimation(nullptr), m_isFinishTurn(false), m_isEnemy(false)
    , m_time(0), m_disableButton(false)
{
    m_movementMap = new MoveList* [Globals::mapWidth];
    for (int i = 0; i < Globals::mapWidth; i++) {
        m_movementMap[i] = new MoveList[Globals::mapHeight];
        for (int j = 0; j < Globals::mapHeight; j++) {
            m_movementMap[i][j].x = i;
            m_movementMap[i][j].y = j;
        }
    }
    //fieldAnimation = std::make_shared<SpriteAnimation>(AssetManager::GetInstance()->model2D, AssetManager::GetInstance()->shaderAnimation, AssetManager::GetInstance()->IkeField, 3, 4, 0, 0.3f);
    //calculateStat();
}


Character::~Character()
{
    //for (int i = 0; i < Globals::mapWidth; i++) {
    //    delete m_movementMap[i];
    //}
    //delete m_movementMap;
}

void Character::Update(GLfloat deltatime)
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
            
        }
    }
    else {
        m_disableButton = false;
    }
}

void Character::move(GLint x, GLint y)
{
    m_disableButton = true;
    while(x != m_posX || y != m_posY) {
        auto temp = m_movementMap[x][y];
        m_stackMove.push(temp);
        //printf("%d, %d\n", x, y);
        x = temp.preX;
        y = temp.preY;
    }
}

void Character::calculateStat()
{
    this->m_maxHealthPoint = m_maxHealthPoint + m_hpGrwth * m_level;
    this->m_healthPoint = m_maxHealthPoint;
    this->m_strength = m_strength + m_strGrwth * m_level;
    this->m_defense = m_defense + m_defGrwth * m_level;
    this->m_magic = m_magic + m_magGrwth * m_level;
    this->m_resistance = m_resistance + m_resGrwth * m_level;
}

bool Character::isEquippable(std::shared_ptr<Item> equipment)
{
    return false;
}

std::shared_ptr<Sprite2D> Character::getSecondFace()
{
    return this->secondFace;
}

std::shared_ptr<SpriteAnimation> Character::getFieldAnimation()
{
    return this->fieldAnimation;
}

void Character::setFieldAnimation(std::shared_ptr<SpriteAnimation> animation)
{
    this->fieldAnimation = animation;
}

GLint Character::getPosX()
{
    return this->m_posX;
}

GLint Character::getPosY()
{
    return this->m_posY;
}

void Character::setPosXY(GLint x, GLint y)
{
    this->m_posX = x;
    this->m_posY = y;
}

bool Character::getFinishTurn()
{
    return this->m_isFinishTurn;
}

void Character::setFinishTurn(bool finish)
{
    this->m_isFinishTurn = finish;
}

GLint Character::getMove()
{
    return this->m_movement;
}

std::string Character::getCharName()
{
    return this->m_name;
}

void Character::setCharName(std::string name)
{
    this->m_name = name;
}

bool Character::isEnemy()
{
    return this->m_isEnemy;
}

bool Character::isPhysical()
{
    if (this->m_characterType == "Priest") {
        return false;
    }
    else return true;
}

bool Character::getDisableButton()
{
    return this->m_disableButton;
}

bool Character::getAlive()
{
    return this->m_isAlive;
}

void Character::die()
{
    m_isAlive = false;
}

void Character::resetMovementMap()
{
    for (int i = 0; i < Globals::mapWidth; i++) {
        for (int j = 0; j < Globals::mapHeight;j++) {
            m_movementMap[i][j].mark = false;
            m_movementMap[i][j].expdMark = false;
            m_movementMap[i][j].atkMark = false;
        }
    }
}

void Character::calculateMovementMap(std::shared_ptr<MapSquare>** mapMatrix)
{
    //pain peko
    resetMovementMap();
    std::queue<MoveList> q;
    m_movementMap[m_posX][m_posY].mark = true;
    m_movementMap[m_posX][m_posY].move = 0;
    q.push(m_movementMap[m_posX][m_posY]);

    while (!q.empty()) {
        MoveList top = q.front();
        q.pop();
        //printf("%d - %d : %d pre: %d - %d\n", top.x, top.y, top.move, top.preX, top.preY);
        //if (top.move == m_movement) continue;
        //go left
        if (top.x) {
            if(!m_movementMap[top.x-1][top.y].expdMark)
                if (mapMatrix[top.x - 1][top.y]->getCharacter() == nullptr && mapMatrix[top.x - 1][top.y]->getPassable()) {
                    m_movementMap[top.x - 1][top.y].setStat(top.move+1,top.x,top.y,true, true, 1);
                    if (m_movementMap[top.x - 1][top.y].move > m_movement) m_movementMap[top.x - 1][top.y].mark = false;
                    q.push(m_movementMap[top.x-1][top.y]);
                }
        }

        //go up
        if (top.y) {
            if (!m_movementMap[top.x][top.y - 1].expdMark)
                if (mapMatrix[top.x][top.y - 1]->getCharacter() == nullptr && mapMatrix[top.x][top.y - 1]->getPassable()) {
                    m_movementMap[top.x][top.y - 1].setStat(top.move+1, top.x, top.y, true, true, 2);
                    if (m_movementMap[top.x][top.y - 1].move > m_movement) m_movementMap[top.x][top.y - 1].mark = false;
                    q.push(m_movementMap[top.x][top.y - 1]);
                }
        }

        //go right
        if (top.x < Globals::mapWidth - 1) {
            if (!m_movementMap[top.x + 1][top.y].expdMark)
                if (mapMatrix[top.x + 1][top.y]->getCharacter() == nullptr && mapMatrix[top.x + 1][top.y]->getPassable()) {
                    m_movementMap[top.x + 1][top.y].setStat(top.move + 1, top.x, top.y, true, true,3);
                    if (m_movementMap[top.x + 1][top.y].move > m_movement) m_movementMap[top.x + 1][top.y].mark = false;
                    q.push(m_movementMap[top.x + 1][top.y]);
                }
        }

        //go down
        if (top.y < Globals::mapHeight - 1) {
            if (!m_movementMap[top.x][top.y + 1].expdMark)
                if (mapMatrix[top.x][top.y + 1]->getCharacter() == nullptr && mapMatrix[top.x][top.y + 1]->getPassable()) {
                    m_movementMap[top.x][top.y + 1].setStat(top.move + 1, top.x, top.y, true, true,4);
                    if (m_movementMap[top.x][top.y + 1].move > m_movement) m_movementMap[top.x][top.y + 1].mark = false;
                    q.push(m_movementMap[top.x][top.y + 1]);
                }
        }
    }
}

void Character::calculateAttackMap(std::shared_ptr<MapSquare>** mapMatrix)
{
    resetMovementMap();
    std::queue<MoveList> q;
    m_movementMap[m_posX][m_posY].atkMark = true;
    m_movementMap[m_posX][m_posY].move = 0;
    q.push(m_movementMap[m_posX][m_posY]);

    while (!q.empty()) {
        MoveList top = q.front();
        q.pop();
        //printf("%d - %d : %d range: %d - %d\n", top.x, top.y, top.move, top.preX, top.preY);
        if (top.move == m_maxRange) continue;
        //go left
        if (top.x) {
            if (!m_movementMap[top.x - 1][top.y].atkMark)
            {
                m_movementMap[top.x - 1][top.y].setAtk(top.move + 1, true);
                q.push(m_movementMap[top.x - 1][top.y]);
            }
        }

        //go up
        if (top.y) {
            if (!m_movementMap[top.x][top.y - 1].atkMark)
            {
                m_movementMap[top.x][top.y - 1].setAtk(top.move + 1, true);
                q.push(m_movementMap[top.x][top.y - 1]);
            }
        }

        //go right
        if (top.x < Globals::mapWidth - 1) {
            if (!m_movementMap[top.x + 1][top.y].atkMark)
            {
                m_movementMap[top.x + 1][top.y].setAtk(top.move + 1, true);
                q.push(m_movementMap[top.x + 1][top.y]);
            }
        }

        //go down
        if (top.y < Globals::mapHeight - 1) {
            if (!m_movementMap[top.x][top.y + 1].atkMark)
            {
                m_movementMap[top.x][top.y + 1].setAtk(top.move + 1, true);
                q.push(m_movementMap[top.x][top.y + 1]);
            }
        }
    }

    m_movementMap[m_posX][m_posY].atkMark = false;
}


MoveList** Character::getMovementMap()
{
    return this->m_movementMap;
}

GLint Character::getLevel()
{
    return this->m_level;
}

GLint Character::getExp()
{
    return this->m_exp;
}

GLint Character::getHealthPoint()
{
    return this->m_healthPoint;
}

void Character::setHealthPoint(GLint hp)
{
    if (hp <= 0) {
        hp = 0;
        m_isAlive = false;
    }
    if (hp > m_maxHealthPoint) {
        hp = m_maxHealthPoint;
    }
    this->m_healthPoint = hp;
}

GLint Character::getMaxHealth()
{
    return this->m_maxHealthPoint;
}

GLint Character::getStrength()
{
    return this->m_strength;
}

GLint Character::getMagic()
{
    return this->m_magic;
}

GLint Character::getDef()
{
    return this->m_defense;
}

GLint Character::getRes()
{
    return this->m_resistance;
}

GLint Character::getPower()
{
    return this->m_power;
}

GLint Character::getHitRate()
{
    return this->m_hitRate;
}

GLint Character::getEvasion()
{
    return this->m_evasion;
}

GLint Character::getCritRate()
{
    return this->m_critRate;
}

std::shared_ptr<Item> Character::getEquipment()
{
    return this->m_equipment;
}

void Character::equip(std::shared_ptr<Item> equipment)
{
    if (this->getEquipment() == nullptr) {
        if (isEquippable(equipment)) {
            this->m_equipment = equipment;
            this->m_hitRate = this->m_hitRate + equipment->getHitRate();
            this->m_critRate = this->m_critRate + equipment->getCritRate();
            if (isPhysical()) {
                this->m_power = this->m_strength + equipment->getPower() - this->m_equipment->getPower();
            }
            else {
                this->m_power = this->m_magic + equipment->getPower() - this->m_equipment->getPower();
            }
            this->m_minRange = equipment->getMinRange();
            this->m_maxRange = equipment->getMaxRange();
        }
    }
    else {
        if (isEquippable(equipment)) {
            this->m_hitRate = this->m_hitRate + equipment->getHitRate() - this->m_equipment->getHitRate();
            this->m_critRate = this->m_critRate + equipment->getCritRate() - this->m_equipment->getCritRate();
            if (isPhysical()) {
                this->m_power = this->m_strength + equipment->getPower() - this->m_equipment->getPower();
            }
            this->m_equipment = equipment;
            this->m_minRange = equipment->getMinRange();
            this->m_maxRange = equipment->getMaxRange();
        }
    }
}

void Character::unequip(std::shared_ptr<Item> equipment)
{
    this->m_equipment = nullptr;
    this->m_hitRate = this->m_hitRate - equipment->getHitRate();
    this->m_critRate = this->m_critRate - equipment->getCritRate();
    this->m_power = this->m_power - equipment->getPower();
}

void Character::use(std::shared_ptr<Item> item, std::shared_ptr<Character> character)
{
    item->effect(character);
}

GLint Character::inventorySpace()
{
    int i = 0;
    for (auto it : m_itemList) {
        i++;
    }
    return i;
}

bool Character::addItem(std::shared_ptr<Item> item)
{
    if (inventorySpace() == 5) return false;
    else {
        m_itemList.push_back(item);
        return true;
    }
}



MoveList::MoveList(GLint x, GLint y, GLint move, GLint preX, GLint preY, bool mark)
    : x(x), y(y), move(move), preX(preX), preY(preY), mark(mark), expdMark(false), atkMark(false), direction(4)
{
}

MoveList::~MoveList()
{
}

void MoveList::setStat(GLint movE, GLint previousX, GLint previousY, bool marker, bool expandMark,GLint direction)
{
    this->move = movE;
    this->preX = previousX;
    this->preY = previousY;
    this->mark = marker;
    this->expdMark = expandMark;
    this->direction = direction;
}

void MoveList::setAtk(GLint range, bool atkMark)
{
    this->move = range;
    this->atkMark = atkMark;
}

