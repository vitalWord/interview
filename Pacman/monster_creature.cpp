#include "monster_creature.h"
#include <fstream>

enum GRAPH_OBJ {BAD =-1 , BLANK =-2};

Monster_creature::Monster_creature(GameMapPtr pmap, QPixmap image, QWidget* parent)
	: Creature(pmap, image , parent ) , flag(false)
{
	m_movePoint = Point(m_pmap->startPointMonster());
	setPosition(m_movePoint);
}


Point Monster_creature::persuitPacman(const Point &point)
{

	size_t SIZE = m_pmap->mapSizeY();
	std::vector<std::vector<int> > graph(m_pmap->mapSizeY());
	std::vector<Point> path;
	Point start(m_x,m_y) ,end(point);
	Point current(point);

	if(start==end) return end;
	//graph init
	for(size_t i=0; i < m_pmap->mapSizeY(); ++i)
		for(size_t j=0; j < m_pmap->mapSizeX(); ++j)
		{
			if(m_pmap->getCell(j,i) == WALL)
				graph[i].push_back(BAD);
			else graph[i].push_back(BLANK);
		}

	//wave expansion
	int dx[4] = {1, 0, -1, 0};//shifts
	int dy[4] = {0, 1, 0, -1};//up,down,left,right
	int d = 0;
	bool stop=false;

	graph[start.y][start.x] = 0;
	while(!stop && graph[point.y][point.x] == BLANK)
	{
		stop=true;
		for(size_t y=0; y < SIZE; ++y)
			for(size_t x=0; x < SIZE; ++x)
				if(graph[y][x] == d)
					for(size_t k = 0; k < 4; ++k) //marking all unmarked neighbours
						if(graph[y + dy[k]][x + dx[k]] == BLANK)
						{
							graph[y+dy[k]][x+dx[k]] = d+1; //wave expansion
							stop = false;
						}
		++d;
	}
	if (graph[point.y][point.x] == BLANK) return Point();

	//writing backpath
	while(d>0)
	{
		path.push_back(current);
		d--;


		for(size_t k=0; k < 4; ++k)
			if(graph[current.y + dy[k]][current.x + dx[k]] == d)
			{
				current.x += dx[k];
				current.y += dy[k];
				break;
			}
	}
	//path.push_back(start); //not using in this impl
	return path.back();
}
