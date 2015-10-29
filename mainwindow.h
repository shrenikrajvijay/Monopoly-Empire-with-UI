#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Board.h"
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVector>
#include "Player.h"
#include "Dice.h"
#include <QGraphicsScene>
#include <QPaintEvent>
#include "EmpireDeck.h"
class QComboBox;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    QPushButton * yesButton;
    QPushButton * noButton;
    QWidget * swap_w;
    QComboBox * swap1;
    QComboBox * swap2;
    int peep;
    int round;
    int swap1choose;

//    QPushButton* rivalButton;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void NotInJail();
    void turnSwitchOn();
    void turnSwitchOff();
    void GameOver();
//    void paintEvent(QPaintEvent( *e));
    void redrawMoney();
    void checkWinner();
    void chooseSwap2();
    Ui::MainWindow* getUi();
    QPushButton* getRollButton();
    Board* getBoard();
    vector<Player*>* getPlayers();
    QGraphicsScene* getScene();
    QGraphicsScene* getTowerScene();
    QGraphicsItem* getECard();
    QGraphicsScene* getCardScene();
    EmpireDeck* getEDeck();

private slots:
    void on_comboBox_p_currentIndexChanged(int index);
    void on_pushButton_p_clicked();
    void onNameConfirm_clicked();
    void yes();
    void no();
    void getNumPlayers();
    void roll();
    void delay();
    void chooseSwap1();
    void chooseSwap3();
    void rivalTax();
    void casinoNight();
    void exchangeCash();


protected:
    QGraphicsScene * scene;
    QGraphicsScene * tower_scene;

private:
    Ui::MainWindow *ui;
    Board * board;
    vector<Player*>* player;
    QPushButton * opButton;
    QList<QLabel *> labels;
    QList<QLineEdit*> edits;
    QList<QPushButton*> roll_section;
    QPushButton * button_roll;
    QList<QLineEdit*> display_money;
    QVector<QLineEdit*> money;
    QVector<QGraphicsView*> cardArea;
    QVector<QGraphicsScene*> cardScene;

    QWidget * w_name;
    QWidget * d_name;
    bool roundloop;
//    Player ** player;
    int round_for_double;
    int ans;
    Dice dice;
    int single_die;
    int swap2choose;

    EmpireDeck* eDeck;

//    QComboBox * comboBox;

};

#endif // MAINWINDOW_H
