#ifndef CREATURE_H
#define CREATURE_H

#include "gamemap.h"
#include <QPixmap>
#include <QLabel>
#include <memory>

typedef std::shared_ptr<QLabel> QLabelPtr;
// Creature class to handle move-events and containing
//data for displaying on main window
class Creature
{
public:
    const size_t CELL_SIZE = 25;
    Creature(GameMapPtr pmap, QPixmap image, QWidget* parent );
    virtual ~Creature();
	void move(const int dx,const int dy);
	void move(const Point& point);
	void setPosition(const size_t x,const size_t y);
	void setPosition(const Point& point);
	virtual void drawCreature();
    Point getPosition() const;

protected:
    size_t m_x;
    size_t m_y;
    GameMapPtr m_pmap;
    QPixmap m_creature_image;
	QLabelPtr m_label;
};

#endif // CREATURE_H
