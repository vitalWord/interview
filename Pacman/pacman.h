#ifndef PACMAN_H
#define PACMAN_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QLabel>
#include <memory>
#include <QTimer>
#include "ThreadPool.h"

class GameMap;
class Pacman_creature;
class Monster_creature;

typedef std::shared_ptr<Monster_creature> MonsterPtr;
typedef std::shared_ptr<Pacman_creature> PacmanPtr;
typedef std::shared_ptr<QLabel> QLabelPtr;

namespace Ui {
class Pacman;
}

class Pacman : public QMainWindow
{
    Q_OBJECT
public:

	explicit Pacman(QWidget *parent = 0);
    ~Pacman();
private:
    void drawMap();
	void setLabels();
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
	void interaction();
	void setInterface();
private slots:
	void updateGame();
	void monsterBehaviourTimer();
	void on_startButton_clicked();
	void on_difficulty_valueChanged(int arg1);
	void on_restartButton_clicked();

private:
	const size_t CELL_SIZE = 25;
	const size_t WIDGET_SIZE_X = 600;
	const size_t WIDGET_SIZE_Y = 600;
	Ui::Pacman *ui;
    std::shared_ptr<GameMap> m_pmap;
    std::shared_ptr<Pacman_creature> m_pacman;
	std::vector<MonsterPtr> m_monsters;
	std::vector<std::vector<QLabelPtr> > m_mapLabels;
	QTimer *m_timer;
	QTimer *m_monsterTimer;
	size_t m_count;
	bool m_keyIsPressed;
	bool m_isUpdated;
	bool m_startPause;
	bool m_lostGameFlag;
	Qt::Key m_key;
	size_t m_score;
	size_t m_speed;
	ThreadPool m_pool;

};

#endif // PACMAN_H
