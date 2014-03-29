#ifndef MONSTER_CREATURE_H
#define MONSTER_CREATURE_H
#include "creature.h"

class Monster_creature: public Creature
{
public:
	Monster_creature(GameMapPtr pmap, QPixmap image, QWidget* parent);
	Point persuitPacman(const Point &point);//finds path to point, and returns its first point
	virtual ~Monster_creature(){}
	Point m_movePoint;
	bool flag;
};

#endif // MONSTER_CREATURE_H
