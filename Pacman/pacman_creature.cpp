#include "pacman_creature.h"


Pacman_creature::Pacman_creature(GameMapPtr pmap, QPixmap image, QWidget* parent)
    : Creature(pmap, image , parent )
{
    m_x = m_pmap->startPoint().x;
	m_y = m_pmap->startPoint().y;
}

QPixmap Pacman_creature::rotateFaceDirection(Qt::Key key)
{
	QTransform transform;
	QPixmap tempPixmap(m_creature_image);
	switch (key)
	{
		case Qt::Key_Left:
		transform.rotate(180);
		tempPixmap = tempPixmap.transformed(transform);
			break;
		case Qt::Key_Up:
			transform.rotate(-90);
			tempPixmap = tempPixmap.transformed(transform);
			break;
		case Qt::Key_Down:
			transform.rotate(90);
			tempPixmap = tempPixmap.transformed(transform);
			break;
		default: break;
	}
	return tempPixmap;
}

void Pacman_creature::drawCreature(QPixmap image)
{
	m_label->setPixmap(image);
	m_label->move(m_x*CELL_SIZE, m_y*CELL_SIZE);
}
