#ifndef PACMAN_CREATURE_H
#define PACMAN_CREATURE_H
#include "creature.h"




class Pacman_creature: public Creature
{
public:
    Pacman_creature(GameMapPtr pmap, QPixmap image, QWidget* parent );
	QPixmap rotateFaceDirection(Qt::Key);
	virtual void drawCreature(QPixmap);//draws rotated face pixmap
	virtual ~Pacman_creature(){}
};

#endif // PACMAN_CREATURE_H
