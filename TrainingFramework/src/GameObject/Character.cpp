#include "Character.h"
#include <queue>

Character::Character(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture)
    :Sprite2D(-1, model, shader, texture), m_name("Ike"), m_level(1), m_healthPoint(1), m_strength(0)
    , m_magic(0), m_defense(0), m_resistance(0), m_movement(5), m_characterType("unknown"), m_power(0)
    , m_hitRate(100), m_evasion(0), m_critRate(5), m_posX(0), m_posY(0), fieldAnimation(nullptr), m_isFinishTurn(false)
    , m_time(0)
{
    m_movementMap = new MoveList* [Globals::mapWidth];
    for (int i = 0; i < Globals::mapWidth; i++) {
        m_movementMap[i] = new MoveList[Globals::mapHeight];
        for (int j = 0; j < Globals::mapHeight; j++) {
            m_movementMap[i][j].x = i;
            m_movementMap[i][j].y = j;
        }
    }
}


Character::~Character()
{
    for (int i = 0; i < Globals::mapWidth; i++) {
        delete m_movementMap[i];
    }
    delete m_movementMap;
}

void Character::Update(GLfloat deltatime)
{
    if (!m_stackMove.empty()) {
        m_time += deltatime;
        if (m_time > 0.25) {
            auto temp = m_stackMove.top();
            m_stackMove.pop();
            switch (temp.direction)
            {
            case 1:
                this->fieldAnimation->SetCurrentAction(3);
                break;
            case 2:
                this->fieldAnimation->SetCurrentAction(1);
                break;
            case 3:
                this->fieldAnimation->SetCurrentAction(0);
                break;
            case 4:
                this->fieldAnimation->SetCurrentAction(2);
                break;
            }
            this->m_posX = temp.x;
            this->m_posY = temp.y;
            m_time = 0;
        }
    }
}

void Character::move(GLint x, GLint y)
{
    while(x != m_posX || y != m_posY) {
        auto temp = m_movementMap[x][y];
        m_stackMove.push(temp);
        //printf("%d, %d\n", x, y);
        x = temp.preX;
        y = temp.preY;
    }
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

void Character::resetMovementMap()
{
    for (int i = 0; i < Globals::mapWidth; i++) {
        for (int j = 0; j < Globals::mapHeight;j++) {
            m_movementMap[i][j].mark = false;
            //m_movementMap[i][j].move = 0;
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
        if (top.move == m_movement) continue;
        //go left
        if (top.x) {
            if(!m_movementMap[top.x-1][top.y].mark)
                if (mapMatrix[top.x - 1][top.y]->getCharacter() == nullptr && mapMatrix[top.x - 1][top.y]->getPassable()) {
                    m_movementMap[top.x - 1][top.y].setStat(top.move+1,top.x,top.y,true, 1);
                    q.push(m_movementMap[top.x-1][top.y]);
                }
        }

        //go up
        if (top.y) {
            if (!m_movementMap[top.x][top.y - 1].mark)
                if (mapMatrix[top.x][top.y - 1]->getCharacter() == nullptr && mapMatrix[top.x][top.y - 1]->getPassable()) {
                    m_movementMap[top.x][top.y - 1].setStat(top.move+1, top.x, top.y, true, 2);
                    q.push(m_movementMap[top.x][top.y - 1]);
                }
        }

        //go right
        if (top.x < Globals::mapWidth - 1) {
            if (!m_movementMap[top.x + 1][top.y].mark)
                if (mapMatrix[top.x + 1][top.y]->getCharacter() == nullptr && mapMatrix[top.x + 1][top.y]->getPassable()) {
                    m_movementMap[top.x + 1][top.y].setStat(top.move + 1, top.x, top.y, true, 3);
                    q.push(m_movementMap[top.x + 1][top.y]);
                }
        }

        //go down
        if (top.y < Globals::mapHeight - 1) {
            if (!m_movementMap[top.x][top.y + 1].mark)
                if (mapMatrix[top.x][top.y + 1]->getCharacter() == nullptr && mapMatrix[top.x][top.y + 1]->getPassable()) {
                    m_movementMap[top.x][top.y + 1].setStat(top.move + 1, top.x, top.y, true, 4);
                    q.push(m_movementMap[top.x][top.y + 1]);
                }
        }
    }
}

MoveList** Character::getMovementMap()
{
    return this->m_movementMap;
}



MoveList::MoveList(GLint x, GLint y, GLint move, GLint preX, GLint preY, bool mark)
    : x(x), y(y), move(move), preX(preX), preY(preY), mark(mark), direction(4)
{
}

MoveList::~MoveList()
{
}

void MoveList::setStat(GLint movE, GLint previousX, GLint previousY, GLint marker, GLint direction)
{
    this->move = movE;
    this->preX = previousX;
    this->preY = previousY;
    this->mark = marker;
    this->direction = direction;
}
