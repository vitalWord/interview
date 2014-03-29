#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include <stack>
#include <QPixmap>
#include <memory>

// types of map containment
enum MAP_OBJECTS {SPACE=0,WALL,GOLD, START,FINISH,MONSTER};

struct Point
{
    size_t x;
    size_t y;
    Point() :x(0),y(0){}
    Point(size_t x,size_t y) : x(x),y(y){}
    Point(const Point& obj)
    {
        x=obj.x;
        y=obj.y;
    }
    Point& operator=(const Point& obj)
    {
        x=obj.x;
        y=obj.y;
        return *this;
    }
	bool operator ==(const Point& obj)
	{
		return (obj.x==this->x && obj.y==this->y);
	}
};

// Game map containing its elements for filling cells
// and displaying on main window
class GameMap
{
public:
    GameMap();
	MAP_OBJECTS getCell(const size_t i,const size_t j) const; //returns map cell containment
	void loadMap();
	size_t mapSizeY() const;
	size_t mapSizeX() const;
	size_t monstersAmount() const; //call once when initializing monsters
	void setCell(const size_t i,const size_t j, MAP_OBJECTS); //used by pacman creature to change cell
    Point startPoint() const;// returns start and finish
    Point finishPoint() const;// coordinates
	Point startPointMonster();// returns st.point from stack to monster obj
	~GameMap();
	void levelUp();
private:
    std::vector<std::vector<MAP_OBJECTS> > map;
    Point m_startPoint;
    Point m_finishPoint;
	std::stack<Point> m_mnstrPoints;
    QPixmap m_wall_icon;
	QPixmap m_gold_icon;
	QPixmap m_finish_icon;
	size_t m_level;
	std::vector<QString> levelFiles;
};

typedef std::shared_ptr<GameMap> GameMapPtr;
#endif // GAMEMAP_H
