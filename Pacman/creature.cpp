#include "creature.h"
#include "gamemap.h"

Creature::Creature(GameMapPtr pmap,QPixmap image, QWidget* parent )
    :m_x(0)
    ,m_y(0)
    ,m_pmap(pmap)
    ,m_creature_image(image)
    ,m_label(new QLabel(parent))
{
    m_label->setPixmap(m_creature_image);
    m_label->setScaledContents(true);
	m_label->resize(CELL_SIZE,CELL_SIZE);
	m_label->show();

}

Creature::~Creature(){}

void Creature::move(const int dx,const int dy)
{
	if(m_pmap->getCell(m_x+dx,m_y-dy) != WALL  )
    {
        m_x += dx;
        m_y -= dy;
	}
}

void Creature::move(const Point &point)
{
	move(point.x - m_x, m_y - point.y );
}

void Creature::setPosition(const size_t x,const size_t y)
{
    m_x = x;
	m_y = y;
}

void Creature::setPosition(const Point &point)
{
	m_x = point.x;
	m_y = point.y;
}

void Creature::drawCreature()
{
    m_label->move(m_x*CELL_SIZE, m_y*CELL_SIZE);
}

Point Creature::getPosition() const
{
    return Point(m_x,m_y);
}

