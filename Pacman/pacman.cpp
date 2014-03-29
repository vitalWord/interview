#include "pacman.h"
#include "ui_pacman.h"
#include "pacman_creature.h"
#include "gamemap.h"
#include "monster_creature.h"
#include <QMessageBox>
#include <fstream>

Pacman::Pacman(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::Pacman)
    ,m_pmap(new GameMap)
	,m_timer(new QTimer(this))
	,m_monsterTimer(new QTimer(this))
	,m_count(20)
	,m_keyIsPressed(false)
	,m_isUpdated(true)
	,m_startPause(true)
	,m_lostGameFlag(false)
	,m_key(Qt::Key_0)
	,m_score(0)
	,m_speed(5)
	,m_pool(4)
{

    ui->setupUi(this);

	m_pmap->loadMap();
	m_pacman = PacmanPtr (new Pacman_creature(
												 m_pmap
												,QPixmap(":/pacman.png")
												,this));

	size_t tempSize = m_pmap->monstersAmount();
	for(size_t i=0; i<tempSize; ++i)
		m_monsters.push_back(MonsterPtr(new  Monster_creature(
											m_pmap
										   ,QPixmap(":/monster.png")
										   ,this)));
	setLabels();
	setInterface();
	drawMap();
	m_pacman->drawCreature(m_pacman->rotateFaceDirection(Qt::Key_0));

	for(size_t i=0; i<m_monsters.size(); ++i)
		m_monsters[i]->drawCreature();

	//Setting timer, so speed of pacman and mosters are equal
	connect(m_timer, SIGNAL(timeout()), this, SLOT(updateGame()));
	connect(m_monsterTimer, SIGNAL(timeout()), this, SLOT(monsterBehaviourTimer()) );
}

void Pacman::drawMap()
{
    size_t size_x = m_pmap->mapSizeX();
    size_t size_y = m_pmap->mapSizeY();

    for(size_t i=0; i < size_x; ++i)
        for(size_t j=0; j< size_y; ++j)
			switch(m_pmap->getCell(j,i))
            {
                case WALL:
                    m_mapLabels[i][j]->setPixmap(QPixmap(":/wall.png"));
                    break;
				case FINISH:
					m_mapLabels[i][j]->setPixmap(QPixmap(":/finish.png"));
					break;
				case GOLD:
					m_mapLabels[i][j]->setPixmap(QPixmap(":/gold.png"));
					break;
				case SPACE:
					m_mapLabels[i][j]->clear();
                default: break;
			}
}

void Pacman::setLabels()
{

	size_t size_x = m_pmap->mapSizeX();
	size_t size_y = m_pmap->mapSizeY();
	if(m_mapLabels.size())
		m_mapLabels.clear();
	m_mapLabels.resize(size_x);
	for(size_t i=0; i < size_y; ++i)
		for(size_t j=0; j< size_x; ++j)
			{
				m_mapLabels[i].push_back( QLabelPtr(new QLabel(this)));
				m_mapLabels[i][j]->resize(CELL_SIZE,CELL_SIZE);
				m_mapLabels[i][j]->move(j*CELL_SIZE,i*CELL_SIZE);
				m_mapLabels[i][j]->show();
			}
}

void Pacman::keyPressEvent(QKeyEvent * event)
{
	m_keyIsPressed = true;
	m_isUpdated = false;
	m_key = (Qt::Key)event->key();
}

void Pacman::keyReleaseEvent(QKeyEvent * event)
{
	m_keyIsPressed = false;
}

void Pacman::interaction()
{
	int x = m_pacman->getPosition().x;
	int y = m_pacman->getPosition().y;
	//monster interaction
	for(size_t i=0; i < m_monsters.size(); ++i)
		if( m_pacman->getPosition() == m_monsters[i]->getPosition())
		{
			m_timer->stop();
			m_lostGameFlag = true;
			ui->startButton->setDisabled(true);
			QMessageBox::information(this, "GAME INFO", "YOU LOST!!!");
			break;
		}
	//pacman-map interaction
	switch(m_pmap->getCell(x,y))
	{
		case GOLD:
			m_pmap->setCell(x,y,SPACE);
			m_score+=50;
			ui->ScoreBox->setText(QString::number(m_score,10));
			break;
		case FINISH:
			if(m_score > 1000)
			{
				m_timer->stop();
				QMessageBox::information(this, "GAME INFO", "YOU WON!!!");
				m_pmap->levelUp();
			}
			break;
		default: break;
	}
}

void Pacman::setInterface()
{
	size_t size_x = m_pmap->mapSizeX();
	size_t size_y = m_pmap->mapSizeY();
	setMaximumSize(size_x*CELL_SIZE, size_y*CELL_SIZE+50);
	ui->label_2->move(10,CELL_SIZE*size_x+10);
	ui->difficulty->move(60,CELL_SIZE*size_x+10);
	ui->startButton->move(100,CELL_SIZE*size_x+10);
	ui->restartButton->move(160,CELL_SIZE*size_x+10);
	ui->label->move(270,CELL_SIZE*size_x+10);
	ui->ScoreBox->move(340,CELL_SIZE*size_x+10);
}

void Pacman::updateGame()
{
	if(m_keyIsPressed || !m_isUpdated)
	switch (m_key)
	{
		case Qt::Key_Right:
			m_pacman->move(1,0);
			break;
		case Qt::Key_Left:
			m_pacman->move(-1,0);
			break;
		case Qt::Key_Up:
			m_pacman->move(0,1);
			break;
		case Qt::Key_Down:
			m_pacman->move(0,-1);
			break;
		default: break;
	}
	m_isUpdated = true;
	m_pacman->drawCreature(m_pacman->rotateFaceDirection(m_key));

	//monster behaviour logic
	Point temp , pacmanPoint;

	std::vector<std::future<Point> > nextPoints; //results of next points
	pacmanPoint = m_pacman->getPosition();

	if(m_count)
	{
		for(size_t i=0; i < m_monsters.size(); ++i)
			nextPoints.push_back( m_pool.enqueue( &Monster_creature::persuitPacman, m_monsters[i], pacmanPoint ));
		m_count--;
	}
	else
	{
		for(size_t i=0; i < m_monsters.size(); ++i)
		{
			if(m_monsters[i]->getPosition() == m_monsters[i]->m_movePoint || m_monsters[i]->flag)
			{
				nextPoints.push_back( m_pool.enqueue( &Monster_creature::persuitPacman, m_monsters[i], pacmanPoint ));
				m_monsters[i]->flag = true;
			}
			else
				nextPoints.push_back(m_pool.enqueue( &Monster_creature::persuitPacman, m_monsters[i], m_monsters[i]->m_movePoint ));
		}
	}


	for(size_t i=0; i < m_monsters.size(); ++i)
		m_monsters[i]->move(nextPoints[i].get() );

	for(size_t i=0; i < m_monsters.size(); ++i)
		m_monsters[i]->drawCreature();


	interaction();
	drawMap();
}

void Pacman::monsterBehaviourTimer()
{
	m_count = size_t(m_pmap->mapSizeX()*1.8);
	for(size_t i = 0; i < m_monsters.size(); ++i)
		m_monsters[i]->flag = false;
}

Pacman::~Pacman()
{
    delete ui;
}




void Pacman::on_startButton_clicked()
{
	if(m_startPause)
	{
		m_timer->start(500-m_speed*50);
		m_monsterTimer->start(12000);
		ui->startButton->setText("PAUSE");
		m_startPause = false;
	}
	else
	{
		m_timer->stop();
		m_monsterTimer->stop();
		ui->startButton->setText("START");
		m_startPause = true;
	}

}

void Pacman::on_difficulty_valueChanged(int arg1)
{
	m_speed = arg1;
}

void Pacman::on_restartButton_clicked()
{
	m_timer->stop();
	m_monsterTimer->stop();
	m_count = size_t(m_pmap->mapSizeX()*1.4);
	m_lostGameFlag = false;
	ui->startButton->setDisabled(false);
	m_pmap->loadMap();

	m_monsters.clear();
	size_t tempSize = m_pmap->monstersAmount();
	for(size_t i=0; i<tempSize; ++i)
		m_monsters.push_back(MonsterPtr(new  Monster_creature(
											m_pmap
										   ,QPixmap(":/monster.png")
										   ,this)));
	setLabels();
	drawMap();
	setInterface();
	m_pacman->setPosition(m_pmap->startPoint());

	m_score = 0;
	ui->ScoreBox->setText(QString::number(m_score,10));
	m_timer->start(500-m_speed*50);
	m_monsterTimer->start(12000);
}
