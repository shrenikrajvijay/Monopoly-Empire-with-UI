#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "Board.h"
#include <QLineEdit>
#include  <vector>
#include <QTime>
#include "ansthread.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPen>
#include "token.h"
#include "TowerView.h"
#include <QVBoxLayout>
#include "clickboxsize1.h"
#include <QSound>
#include "EmpireCard.h"
class QLineEdit;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{



    // Initiate Dice
    dice;

    // Initiate Round
//    round = -1;
    round_for_double=-1;

    // Initiate the Interface
    ui->setupUi(this);

    // Set the Initial Appear of the GUI
    ui->console->setText("Welcome to Monopoly Empire!");
    ui->label_p->setText("2 Players Selected" );
    ui->comboBox_p->addItem("2",QVariant(2) );
    ui->comboBox_p->addItem("3",QVariant(3) );
    ui->comboBox_p->addItem("4",QVariant(4) );

    // Set the Views of the Tower and BoardSpace
    scene = new QGraphicsScene(0,0,630,525);
    tower_scene = new QGraphicsScene(0,0,200,600);
    ui->towerView->setScene(tower_scene);
    ui->towerView->centerOn(0, 600);
    ui->boardView->setScene(scene);

    eDeck = new EmpireDeck(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

/**
 *   Tells the User How many Players the user is currently selecting in the ComboBox
 **/
void MainWindow::on_comboBox_p_currentIndexChanged(int index)
{
    ui->label_p->setText(QString( "%1 Players Selected").arg(index+2));
}

/**
 *   Set up a field to input names
 *
 **/
void MainWindow::on_pushButton_p_clicked()
{
    // Important to setting up the board and game
    getNumPlayers();

    // Deletes the Layers for inputing amount of players from combo Box
    delete ui->label_p;
    delete ui->comboBox_p;
    delete ui->pushButton_p;

    // Set up Grid for Users to add their names
    w_name = new QWidget(this); // Added parent widget
    QGridLayout * grid_name = new QGridLayout;

    // Set up Button to confirm Names
    QPushButton * button_nameConfirm = new QPushButton("Confirm Names");

    // Applying Grid
    for (int i = 0 ; i< peep; i++ ) {
        // Field to Enter Name
        QLineEdit * line = new QLineEdit;
        // Label is for specifying Player number
        QLabel * label = new QLabel;
        // Tell Label to set text
        label->setText(QString("Player %1").arg(i+1));

        // Add according to gride structure to get a labels on top and name fields on bottom
        grid_name->addWidget(label,0,i);
        grid_name->addWidget(line,1,i);
    }

    // Add another layer to separate Grid from a confirm button
    QVBoxLayout * name_set = new QVBoxLayout;
    name_set->addLayout(grid_name);
    name_set->addWidget( button_nameConfirm );
    w_name->setLayout(name_set);
    ui->horizontalLayout->addWidget(w_name);

    labels = w_name->findChildren<QLabel *>();
    edits = w_name->findChildren<QLineEdit*>();

    connect( button_nameConfirm, SIGNAL( clicked() ), this, SLOT(onNameConfirm_clicked() ) );


}

/** Important Function to intialize the board
 **/
void MainWindow::getNumPlayers() {
   // Selects Amounts of Players for the Game
   peep = (ui->comboBox_p->itemData(ui->comboBox_p->currentIndex()).toInt());
   // Intialize board with selected number of players
   board= new Board( peep );
   // Grab the player array for Name Labeling for the money field
   player = board->getPlayer();

}



/**  Set up the player name and money field, intitalizes the scenes for both
 *   views: tower and boardspace
 *
 **/

void MainWindow::onNameConfirm_clicked() {

        qDebug() << QString::fromStdString(board->spaces[0]->title);
        vector<string> string_of_players;

        d_name = new QWidget(this); // Added parent widget
        QVBoxLayout * display_name = new QVBoxLayout;





        for ( int i = 0; i<peep; i++ ) {
            QHBoxLayout * group_name_money = new QHBoxLayout;
            display_name->addLayout(group_name_money);
            QLineEdit * line = new QLineEdit;
            QLabel * label = new QLabel;

            label->setFixedWidth(65);
            line->setDisabled(true);
            group_name_money->addWidget(label);
            group_name_money->addWidget(line);
            money.push_back(line);

            label->setText( edits.at(i)->text() + " $" );
            QString string_name = edits.at(i)->text();
            qDebug() << string_name;
            string tmp = string_name.toStdString();
            string_of_players.push_back( tmp );
        }

        display_money = d_name->findChildren<QLineEdit*>();
        for ( int i = 0; i<peep;i++ ) {
            money.at(i)->setText( QString::number(1000) ) ;
        }
        d_name->setLayout( display_name );
        ui->display->addWidget( d_name );
        board->addNames( string_of_players );


    delete w_name;

    button_roll = new QPushButton("ROLL");

    button_roll->setFixedHeight(118);



    button_roll->setStyleSheet("QPushButton:pressed { background-color: red; }");

    button_roll->setAutoFillBackground(true);
    button_roll->setStyleSheet("background-color: green;border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 6px; ");



    connect( button_roll, SIGNAL(clicked() ), this, SLOT(roll()));
    ui->set_playerBox->addWidget( button_roll ); // Specify where to include the button

    Token* token = new Token(board,2);
    scene->addItem(token);
//    ClickBoxSize1* c1 = new ClickBoxSize1(board);
    QGraphicsItem* Go_area = new ClickBoxSize1(515,430,113,93,0,this);
    scene->addItem(Go_area);
    QGraphicsItem* Jail_area = new ClickBoxSize1(515,1,113,94,27,this);
    scene->addItem(Jail_area);

    QGraphicsItem* Nerf_area = new ClickBoxSize1(466,430,48,93,1,this);
    scene->addItem(Nerf_area);
    QGraphicsItem* Macdonalds_area = new ClickBoxSize1(466,1,48,94,26,this);
    scene->addItem(Macdonalds_area);

    QGraphicsItem* Rival_area = new ClickBoxSize1(415,430,48,93,2,this);
    scene->addItem(Rival_area);
    QGraphicsItem* Ducati_area = new ClickBoxSize1(415,1,48,94,25,this);
    scene->addItem(Ducati_area);

    QGraphicsItem* Transformers_area = new ClickBoxSize1(366,430,47,93,3,this);
    scene->addItem(Transformers_area);
    QGraphicsItem* Empire2_area = new ClickBoxSize1(366,1,47,94,24,this);
    scene->addItem(Empire2_area);

    QGraphicsItem* Empire1_area = new ClickBoxSize1(316,430,46,93,4,this);
    scene->addItem(Empire1_area);
    QGraphicsItem* XGames_area = new ClickBoxSize1(316,1,46,94,23,this);
    scene->addItem(XGames_area);

    QGraphicsItem* Spotify_area = new ClickBoxSize1(266,430,47,93,5,this);
    scene->addItem(Spotify_area);
    QGraphicsItem* Ebay_area = new ClickBoxSize1(266,1,47,94,22,this);
    scene->addItem(Ebay_area);

    QGraphicsItem* Chance1_area = new ClickBoxSize1(216,430,48,93,6,this);
    scene->addItem(Chance1_area);
    QGraphicsItem* Chance3_area = new ClickBoxSize1(216,1,48,94,21,this);
    scene->addItem(Chance3_area);

    QGraphicsItem* Beats_area = new ClickBoxSize1(166,430,48,93,7,this);
    scene->addItem(Beats_area);
    QGraphicsItem* Chevrolet_area = new ClickBoxSize1(166,1,48,94,20,this);
    scene->addItem(Chevrolet_area);

    QGraphicsItem* Fender_area = new ClickBoxSize1(116,430,48,93,8,this);
    scene->addItem(Fender_area);
    QGraphicsItem* Paramount_area = new ClickBoxSize1(116,1,48,94,19,this);
    scene->addItem(Paramount_area);

    QGraphicsItem* Visiting_area = new ClickBoxSize1(1,430,114,93,9,this);
    scene->addItem(Visiting_area);
    QGraphicsItem* FreeParking_area = new ClickBoxSize1(1,1,114,94,18,this);
    scene->addItem(FreeParking_area);

    QGraphicsItem* JetBlue_area = new ClickBoxSize1( 1,388,114,39,10,this);
    scene->addItem(JetBlue_area);
    QGraphicsItem* CocaCola_area = new ClickBoxSize1( 515,388,113,39,35,this);
    scene->addItem(CocaCola_area);

    QGraphicsItem* EA_area = new ClickBoxSize1( 1,346,114,39,11,this);
    scene->addItem(EA_area);
    QGraphicsItem* TowerTax_area = new ClickBoxSize1( 515,346,113,39,34,this);
    scene->addItem(TowerTax_area);

    QGraphicsItem* ElecComp_area = new ClickBoxSize1( 1,304,114,40,12,this);
    scene->addItem(ElecComp_area);
    QGraphicsItem* Samsung_area = new ClickBoxSize1( 515,304,113,40,33,this);
    scene->addItem(Samsung_area);


    QGraphicsItem* Hasbros_area = new ClickBoxSize1( 1,261,114,41,13,this);
    scene->addItem(Hasbros_area);
    QGraphicsItem* Chance4_area = new ClickBoxSize1( 515,261,113,41,32,this);
    scene->addItem(Chance4_area);


    QGraphicsItem* UnderArmour_area = new ClickBoxSize1( 1,221,114,40,14,this);
    scene->addItem(UnderArmour_area);
    QGraphicsItem* Nestle_area = new ClickBoxSize1( 515,221,113,40,31,this);
    scene->addItem(Nestle_area);


    QGraphicsItem* Chance2_area = new ClickBoxSize1( 1,180,114,39,15,this);
    scene->addItem(Chance2_area);
    QGraphicsItem* WaterWorks_area = new ClickBoxSize1( 515,180,113,39,30,this);
    scene->addItem(WaterWorks_area);


    QGraphicsItem* Carnival_area = new ClickBoxSize1( 1,138,114,40,16,this);
    scene->addItem(Carnival_area);
    QGraphicsItem* XBox_area = new ClickBoxSize1( 515,138,113,40,29,this);
    scene->addItem(XBox_area);


    QGraphicsItem* Yahoo_area = new ClickBoxSize1( 1,95,114,41,17,this);
    scene->addItem(Yahoo_area);
    QGraphicsItem* Intel_area = new ClickBoxSize1( 515,95,113,41,28,this);
    scene->addItem(Intel_area);


//    QGraphicsItem* Rival_area = new ClickBoxSize1(270,430,48,93,5,this);
//    scene->addItem(Rival_area);
//    rec->setFlag(QGraphicsItem::ItemIsMovable);
//    rec->setFlag(QGraphicsItem::ItemIsSelectable);
//    rec->acceptedMouseButtons();
    TowerView* towers = new TowerView(board);
    tower_scene->addItem(towers);


    QString msg;
    msg += "The game is set for " + QString::number(peep) + " PLayers: \n";

    for ( int i =0; i<peep-1;i++) {
        msg += QString::fromStdString( board->getPlayer()->at(i)->getName() +"\n" );
    }
    msg += QString::fromStdString( board->getPlayer()->at(peep-1)->getName() );

      ui->console->setText( msg );
   yesButton = new QPushButton("Button1");
   yesButton->setMinimumHeight(59);





   noButton = new QPushButton("Button2");
   noButton->setMinimumHeight(59);

   connect( yesButton, SIGNAL( clicked() ), this, SLOT( yes() ) );
   connect( noButton, SIGNAL( clicked() ), this, SLOT( no() ) );
   yesButton->hide();
   noButton->hide();


   ui->top_command->addWidget(yesButton);
   ui->top_command->addWidget(noButton);


   for( int x=0; x<peep; x++ ) {
      cardArea.push_back(new QGraphicsView() );
      cardScene.push_back(new QGraphicsScene(0,0,290,1000) );
      cardArea.at(x)->setScene(cardScene.at(x));
      ui->CardSpace->addWidget( cardArea.at(x) );
      cardScene.at(x)->addItem( eDeck->getCard() );
      QGraphicsItem* tmp= eDeck->getCard();
      cardScene.at(x)->addItem( tmp );

      cardArea.at(x)->centerOn(0,0);
      if ( x != 0 ) {
          cardArea.at(x)->hide();
      }
      tmp->moveBy(0,190);
   }

   qDebug() << "CARD SIZE IS: " + QString::number( cardScene.at(0)->items().size() );



}





void MainWindow::redrawMoney()
{
    qDebug() << "CALLED redrawMoney";
    for( int i=0 ; i<peep; i++) {
        money.at(i)->setText( QString::number( player->at(i)->getMoney() ) );
    }
}

void MainWindow::roll(){



//    QString path = QCoreApplication::applicationDirPath();
//    path.append("\roll.wav");
    QSound::play("/Users/Anh/CSULB/SoftwareEng/GUIVersion/roll.wav");
    round_for_double++;
    round = round_for_double;
    round = round % board->peeps;

    redrawMoney();
//    if ( player->at(round)->get );


    for( int x=0; x<peep; x++ ) {

       if ( x != round ) {
           cardArea.at(x)->hide();
       }
    }
    int place_card=0;
    for ( int x=0; x<cardScene.at(round)->items().size(); x++ ) {
        cardScene.at(round)->items().at(x)->setPos(0,place_card);
        place_card+=190;
    }


    cardArea.at(round)->show();


    if ( player->at(round)->getAction() != NULL ) {
        player->at(round)->setAction(NULL);
    }


  qDebug() << "IT WORKED";
  Ownable * electric_space = dynamic_cast<Ownable*>( board->spaces.at(12) );


  qDebug() << QString::number(electric_space->owned) + "ELECTRIC OWNED";

//    yesButton->setText("Buy");
//     noButton->setText("Pass");
//     turnSwitchOff();
//      board->spaces.at(3)->buyProperty(*player->at(round));

  //  board->spaces.at(12)->landOn(*player->at(round));
//  ui->console->append( QString::fromStdString( player->at(round)->getSpaces().at(12) ->print() ) );


  qDebug() << "ROUND IS: " + QString::number(round);
//  ui->console->hide();
    turnSwitchOn();
//  roll_section.at(0)->setEnabled(false);
          QString msg;
          ans=-1;
//          ansThread tmp_Thread(100,this);
//          connect(threads[0], SIGNAL(valueChanged(int))
//                  , this, SLOT(test(int)));

          if (player->at(round)->isInJail() >= 1 ) {
              yesButton->setText("Pay Fine");
              noButton->setText("Try Your Luck");
              turnSwitchOff();
//            msg += QString::fromStdString( player->at(round)->isInJail() + " ISS THIS THE CORRECT VALUE????????\n");
              msg += QString::fromStdString( player->at(round)->getName() + " is in jail.\n" );
              msg += QString::fromStdString("Do you want to pay 100 for bail ?: Press 1 \nDo you want to try to roll a double?: Press 2 \n");
              ui->console->setText(msg);
              qDebug() << msg;
//              cin >> ans;

          }
          qDebug() << QString::number( player->at( round )->isInJail() ) + "ARE YOU STILL IN JAIl" ;
          if ( player->at(round)->isInJail() < 1 ) {
              NotInJail();
          }
         redrawMoney();

         scene->update();
         tower_scene->update();

         checkWinner();
}

void MainWindow::turnSwitchOn()
{
    yesButton->setEnabled(false);
    noButton->setEnabled(false);
    button_roll->setEnabled(true);
    button_roll->setStyleSheet("background-color: green;border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 6px; ");
    yesButton->hide();
    noButton->hide();
}

void MainWindow::turnSwitchOff()
{
    yesButton->setEnabled(true);
    noButton->setEnabled(true);
    button_roll->setStyleSheet("background-color: red;border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 6px; ");
    button_roll->setEnabled(false);
    yesButton->show();
    noButton->show();
}

void MainWindow::GameOver()
{
    QSound::play("/Users/Anh/CSULB/SoftwareEng/GUIVersion/firework.wav");
    yesButton->setEnabled(false);
    noButton->setEnabled(false);
    button_roll->setStyleSheet("background-color: red;border-style: outset;border-width: 2px;border-radius: 10px;border-color: beige;font: bold 14px;min-width: 10em;padding: 6px; ");
    button_roll->setEnabled(false);
    yesButton->hide();
    noButton->hide();
}

void MainWindow::checkWinner() {
    QString msg;
    if ( player->at(round)->getTower()->getHeight() > 16 ) {
        msg += "GAME OVER!\n" + QString::fromStdString( player->at(round)->getName() ) + " won the game.";
        ui->console->setText(msg);
        GameOver();
    }
}

void MainWindow::yes(){
    if ( yesButton->text() == "Pay Fine" ) {
        qDebug() << "YESBUTTON CALLED";
        if ( player->at(round)->isInJail() >= 1 ) {
            ui->console->append( QString::fromStdString( player->at(round)->getName() + " paid 100 for bail\n" ) ) ;
            qDebug() << QString::fromStdString( player->at(round)->getName() + " paid 100 for bail\n" ) ;
            player->at(round)->changeMoney(-100);
            while ( player->at(round)->isInJail() != 0 ) {
                player->at(round)->setJail( -1 );
            }
            turnSwitchOn();

        }
        qDebug() << "YES BUTTON ENDED";
    }
    if ( yesButton->text() == "Buy") {

        qDebug() << "BUYING PROPERTY";
//        Ownable * ownable_space = dynamic_cast<Ownable*>( player->at(round)->getSpaces().at( player->at(round)->getPosition() ) );
//        ownable_space->buyYes( *player->at(round) );
//        qDebug() << QString::number( player->at(round)->getPosition() ) + "WTTTTFF" ;
        board->spaces.at(player->at(round)->getPosition())->buyProperty(*player->at(round));
        qDebug() << "BOUGHT PROPERTY";
        ui->console->append( "You bought " + QString::fromStdString( board->spaces.at(player->at(round)->getPosition())->title )  );
        turnSwitchOn();
        tower_scene->update();
        checkWinner();

    }



    if ( yesButton->text() == "Swap") {
        swap_w = new QWidget(this);
        QHBoxLayout* swap_v = new QHBoxLayout;
        swap1 = new QComboBox();
        QPushButton* swap_p = new QPushButton;
        swap_p->setText("Choose");
        swap_v->addWidget(swap1);
        swap_v->addWidget(swap_p);
        swap_w->setLayout(swap_v);
        ui->top_command->addWidget(swap_w);
        yesButton->hide();
        noButton->hide();
        for( int x=0; x<peep; x++ ) {
            if ( !player->at(x)->getTower()->Top_BillBoard.empty() ) {
                swap1->addItem( QString::fromStdString( player->at(x)->getName() ), QVariant(player->at(x)->getId()) );
            }

        }
        swap1->show();
        connect( swap_p, SIGNAL( clicked() ), this, SLOT( chooseSwap1() ) );

    }
    redrawMoney();

}

void MainWindow::rivalTax() {

    swap1choose = ( swap1->currentData().toInt() );
    delete swap_w;
    QString msg;

//    msg += ( QString::fromStdString( player->at(swap1choose)->getName() ) + " loses " + player->at(swap1choose)->getTower()->Top_BillBoard.back()->getName() ;

        BillBoard * temp_bb = player->at(swap1choose)->getTower()->Top_BillBoard.back();
//        cout << curPlayer.getName() << " loses his BillBoard: " << temp_bb->getName()<< "." << endl;
        msg = QString::fromStdString( player->at(swap1choose)->getName() ) + " loses his BillBoard: " + QString::fromStdString( temp_bb->getName() ) +  ".";

        player->at(swap1choose)->getTower()->Top_BillBoard.pop_back();
//        cout << curPlayer.getTower()->getHeight() << "HEIGHT_ before";

        player->at(swap1choose)->getTower()->setHeight( -(temp_bb->getValue() ) );
//        cout << curPlayer.getTower()->getHeight() << "HEIGHT_ after";

        temp_bb->setOwner( -1 );
        temp_bb->setStatus( -1 );

        ui->console->append( msg );
        tower_scene->update();
        turnSwitchOn();
}

void MainWindow::casinoNight()
{

    qDebug() << "CALLED CASINO NIGHT!";

    swap1choose = ( swap1->currentData().toInt() );
    delete swap_w;

    srand (time(NULL));
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;

    int total1 = dice1 + dice2 ;

    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;

    QString msg;

    int total2 = dice1 + dice2;

    if ( total1 > total2 ) {
        player->at(round)->changeMoney(200);
        msg = QString::fromStdString( player->at(round)->getName() ) + " wins " + QString::number(200) +  ".";

    } else if ( total1 < total1 ){
        player->at(swap1choose)->changeMoney(200);
        msg = QString::fromStdString( player->at(swap1choose)->getName() ) + " wins " + QString::number(200) +  ".";

    } else {
        player->at(round)->changeMoney(200);
        player->at(swap1choose)->changeMoney(200);
        msg = QString::fromStdString( player->at(round)->getName() ) + " and wins " + QString::fromStdString( player->at(swap1choose)->getName() ) + " " + QString::number(200) +  ".";

    }
    ui->console->append(msg);
    redrawMoney();
    turnSwitchOn();

}

void MainWindow::exchangeCash()
{
    swap2choose = ( swap1->currentData().toInt() );
    delete swap_w;
//    QString msg;
//    msg += "with " + QString::fromStdString( player->at(swap2choose)->getName() );
//    ui->console->append( msg );

    qDebug() << "CHOOSE TWO IS: " << swap2choose << endl;

    player->at(swap2choose)->changeMoney(-400);
    redrawMoney();
    turnSwitchOn();
}

void MainWindow::chooseSwap1(){
    swap1choose = ( swap1->currentData().toInt() );
    delete swap_w;
    QString msg;

    msg += "Swapping " + QString::fromStdString( player->at(swap1choose)->getName() );
    ui->console->append( msg );
    qDebug() << "CHOOSE ONE IS: " << swap1choose << endl;
    chooseSwap2();
}

void MainWindow::chooseSwap2(){
    swap_w = new QWidget(this);
    QHBoxLayout* swap_v = new QHBoxLayout;
    swap1 = new QComboBox();
    QPushButton* swap_p = new QPushButton;
    swap_p->setText("Choose");
    swap_v->addWidget(swap1);
    swap_v->addWidget(swap_p);
    swap_w->setLayout(swap_v);
    ui->top_command->addWidget(swap_w);
    yesButton->hide();
    noButton->hide();
    for( int x=0; x<peep; x++ ) {
        if ( !player->at(x)->getTower()->Top_BillBoard.empty() && x!= swap1choose ) {
            swap1->addItem( QString::fromStdString( player->at(x)->getName() ), QVariant(player->at(x)->getId()) );
        }

    }
    swap1->show();
    connect( swap_p, SIGNAL( clicked() ), this, SLOT( chooseSwap3() ) );
}

void MainWindow::chooseSwap3(){
    swap2choose = ( swap1->currentData().toInt() );
    delete swap_w;
    QString msg;
    msg += "with " + QString::fromStdString( player->at(swap2choose)->getName() );
    ui->console->append( msg );

    qDebug() << "CHOOSE TWO IS: " << swap2choose << endl;

    player->at(round)->sneakySwap( *player->at(swap1choose), *player->at(swap2choose) );
    turnSwitchOn();
    tower_scene->update();
}

void MainWindow::no(){
    if ( yesButton->text() == "Pay Fine") {
        qDebug() << "ROLLED A DOUBLE CALLED";
        if ( player->at(round)->isInJail() >= 1 )
            dice.Roll();
        player->at(round)->setJail(1);

        if ( dice.isDouble() == true ) {
            ui->console->setText( QString::fromStdString( "You got a double!\n" ) );
            while ( player->at(round)->isInJail() != 0 ) {
                player->at(round)->setJail( -1 );
            }
        } else {
            ui->console->append( QString::fromStdString( "You did not get a double.\n" ) );

        }
        if ( player->at(round)->isInJail() == 4 ) {
            ui->console->append(  QString::fromStdString("You have reached the limit and paid 50 to get out of Jail\n" ) );
            player->at(round)->changeMoney(-50);
            while ( player->at(round)->isInJail() != 0 ) {
                player->at(round)->setJail( -1 );
            }
        }
        NotInJail();
        turnSwitchOn();
        qDebug() << "ROLLED A DOUBLE ENDED";
    }

    if ( yesButton->text() == "Buy") {
        qDebug() << "PASS PROPERTY";
        Ownable* temp_o = static_cast<Ownable*>( board->spaces.at(player->at(round)->getPosition()) );/*->buyNo(*player->at(round));*/
        QString tmp = QString::fromStdString( temp_o->buyNo(*player->at(round)) );
        ui->console->append(tmp);
        turnSwitchOn();

    }

    if ( yesButton->text() == "Swap" ) {
        ui->console->setText( QString::fromStdString( player->at(round)->getName() ) + " moves " + QString::number(single_die) + " spaces: " );
        player->at(round)->setPostion (single_die);

        ui->console->append( QString::number( player->at(round)->getMoney() ) + "and " + QString::number( player->at(round)->getPosition() ) + "\n" ) ;


//        Ownable * Ownable_space = dynamic_cast<Ownable*>( player->at(round)->getSpaces().at( player->at(round)->getPosition() ) );
//        if (Ownable_space == NULL ) {
//            turnSwitchOn();
//        } else {
//            if ( (Ownable_space->owned) == false || Ownable_space->title=="ELECTRIC COMPANY" && Ownable_space->owned < 4 || Ownable_space->title=="WATER WORKS" && Ownable_space->owned < 4) {
//                yesButton->setText("Buy");
//                noButton->setText("Pass");
//                turnSwitchOff();
//                if ( player->at(round)->getMoney() < ( Ownable_space-> cost ) ) {
//                    yesButton->setEnabled(false);
//                }
//            } else {
//                turnSwitchOn();
//            }
//        }
        turnSwitchOn();
        board->spaces.at(player->at(round)->getPosition())->landOn(*player->at(round), this);
        ui->console->append( QString::fromStdString( player->at(round)->getSpaces().at( player->at(round)->getPosition() ) ->print() ) );

        scene->update();

    }

}
void MainWindow::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(500);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::NotInJail()
{
    qDebug() << "NotInJail CALLED";
    if (player->at(round)->isInJail() < 1 ) {

        int count = 0;
        int num_rolled = dice.Roll( player->at(round) );
        qDebug() << QString::number( dice.isSneaky() ) + "IS IT SNEAKY";
        if ( dice.isSneaky() == false ) {

            qDebug() << "Not in Jailed part 1 Called";
            qDebug() << "Not in Jailed part 1a Called";
            ui->console->setText( QString::fromStdString( player->at(round)->getName() ) + " moves " + QString::number(num_rolled) + " spaces: " );
            player->at(round)->setPostion (num_rolled);
            if (player->at(round)->getMessage() != "" ) {
                ui->console->append( QString::fromStdString( player->at(round)->getMessage() ) ) ;
            }
            qDebug() << "Not in Jailed part 1b Called";
            ui->console->append( QString::number( player->at(round)->getMoney() ) + "and " + QString::number( player->at(round)->getPosition() ) + "\n" ) ;


//            Ownable * Ownable_space = dynamic_cast<Ownable*>( player->at(round)->getSpaces().at( player->at(round)->getPosition() ) );
//            if (Ownable_space == NULL ) {
//                qDebug() << "NOT A OWNABLE SPACE";

//            } else {
//                qDebug() << "IS A  OWNABLE SPACE";
//                if ( ( Ownable_space->owned) == false || Ownable_space->title=="ELECTRIC COMPANY" && Ownable_space->owned < 4 || Ownable_space->title=="WATER WORKS" && Ownable_space->owned < 4) {
//                    yesButton->setText("Buy");
//                    noButton->setText("Pass");
//                    turnSwitchOff();
//                    if ( player->at(round)->getMoney() < ( Ownable_space-> cost ) ) {
//                        yesButton->setEnabled(false);
//                    }
//                }
//            }
            qDebug() << "LIN348 TEsST";
            qDebug() << QString::number( player->at(round)->getPosition() ) ;

            qDebug() << "LINE350 Test";

            //        round++;





            board->spaces.at(player->at(round)->getPosition())->landOn(*player->at(round), this);
            ui->console->append( QString::fromStdString( player->at(round)->getSpaces().at( player->at(round)->getPosition() ) ->print() ) );


            if (board->spaces.at(player->at(round)->getPosition())->title == "FREE PARKING" ) {
                FreeParking* free = dynamic_cast<FreeParking*>( player->at(round)->getSpaces().at( player->at(round)->getPosition() ) );
//                free->showButtons(ui);
                  free->showButtons2(this);
            }

//            if (board->spaces.at(player->at(round)->getPosition())->title == "BEATS" ) {
//                qDebug() << "BEATSS CALLED";
//                Beats* beat = dynamic_cast<Beats*>( player->at(round)->getSpaces().at( player->at(round)->getPosition() ) );
//                beat->showButtons(this);
//            }
            //            qDebug() << "Not in Jailed part 1a Called";
            //            ui->console->append( QString::fromStdString( player->at(round)->getSpaces().at( player->at(round)->getPosition() ) ->print() ) );
            //            qDebug() << "Not in Jailed part 1b Called";
            //            ui->console->append( QString::number( player- >at(round)->getMoney() ) + "and " + QString::number( player->at(round)->getPosition() ) + "\n" ) ;
            //            qDebug() << "Not in Jail part 2 Called";






            if ( dice.isDouble() == true ) {
                ui->console->append( QString::fromStdString( player->at(round)->getName() + " rolled a double!(ROLL AGAIN TO GO AGAIN)\n" ) );
                round_for_double--;
            }


        } else {
            QString msg;
            int count = 0;
            single_die = num_rolled;

            msg += QString::fromStdString( player->at(round)->getName() + " rolled a Sneaky Swapper.\nSwap or Move " );
            msg += QString::number(single_die) + " spaces.";

            ui->console->setText(msg);
            yesButton->setText("Swap");
            noButton->setText("Use Single Die");
            turnSwitchOff();

            for ( int x = 0; x<peep; x++ ) {
                if ( !player->at(x)->getTower()->Top_BillBoard.empty() ) {
                    count++;
                }
            }
            qDebug() << "COUNT FOR SWAP IS: " + QString::number( count );
            if ( count < 2 ) {
               yesButton->setEnabled(false);
               ui->console->append("Two Players must have Billboards to swap.\n");
            }





        }
    }
    qDebug() << "NotInJail ENDED";

}

//void MainWindow::paintEvent(QPaintEvent *e ) {
//    QPainter painter(this);
//    QPixmap pix("/Users/Anh/Board.jpg");
//    painter.drawPixmap(10,10,500,500,pix);
//}

Ui::MainWindow*  MainWindow::getUi() {
    return ui;
}

QPushButton* MainWindow::getRollButton(){
    return button_roll;
}

Board* MainWindow::getBoard() {
    return board;
}

vector<Player*>* MainWindow::getPlayers() {
    return player;
}

QGraphicsScene* MainWindow::getScene() {
    return scene;
}

QGraphicsScene* MainWindow::getTowerScene() {
    return tower_scene;
}

QGraphicsItem *MainWindow::getECard()
{
    return eDeck->getCard();
}

QGraphicsScene *MainWindow::getCardScene()
{
    return cardScene.at(round);
}

EmpireDeck* MainWindow::getEDeck() {
    return eDeck;
}



