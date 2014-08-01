#include "gamemap.h"
#include <string>

#include <QFile>
#include <QTextStream>

GameMap::GameMap() : m_level(0)
{
	m_wall_icon = QPixmap(":/wall.png");
	m_gold_icon = QPixmap(":/gold.png");
	m_finish_icon = QPixmap(":/finish.png");

	levelFiles.push_back(":/level1.txt");
	levelFiles.push_back(":/level2.txt");
}

void GameMap::loadMap()
{
	if(map.size()) map.clear();
	std::vector<std::string> vecStr;
	QString levelString(levelFiles[m_level]);
	QFile file(levelString);
	file.open(QIODevice::ReadOnly | QIODevice::Text);

	QTextStream in(&file);
	QString line = in.readLine();;
	while (!line.isNull())
	{
		vecStr.push_back(line.toStdString());
		line = in.readLine();
	}

	map.resize(vecStr.size());
	for(size_t i = 0; i < vecStr.size(); i++)
		for(size_t j = 0; j < vecStr[i].size(); j++)
		{
			map[i].push_back(MAP_OBJECTS((int)(vecStr[i][j] - '0')));
			switch(map[i][j])
			{
				case START: m_startPoint.x=j;
							m_startPoint.y=i;
							break;
				case FINISH: m_finishPoint.x=j;
							 m_finishPoint.y=i;
							 break;
				case MONSTER: m_mnstrPoints.push(Point(j,i));
							  break;
				default: break;
			}
		}
}

MAP_OBJECTS GameMap::getCell(const size_t j,const size_t i) const
{
    return map[i][j];
}

void GameMap::setCell(const size_t j,const size_t i, MAP_OBJECTS val)
{
	map[i][j] = val;
}

size_t GameMap::mapSizeY() const
{
    return map.size();
}


size_t GameMap::mapSizeX() const
{
	return map[0].size();
}

size_t GameMap::monstersAmount() const
{
	return m_mnstrPoints.size();
}

Point GameMap::startPoint() const
{
    return m_startPoint;
}


Point GameMap::finishPoint() const
{
	return m_finishPoint;
}

Point GameMap::startPointMonster()
{
	Point temp = m_mnstrPoints.top();
	m_mnstrPoints.pop();
	return temp;
}

GameMap::~GameMap(){}

void GameMap::levelUp()
{
	if(m_level < (levelFiles.size()-1))
		m_level++;
}
