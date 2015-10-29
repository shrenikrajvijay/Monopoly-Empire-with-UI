

#ifndef SPACE_H_
#define SPACE_H_
#include <string>
#include "Player.h"
#include "BillBoard.h"
#include "ChanceDeck.h"
#include <QTextEdit>
//#include "ui_mainwindow.h"
//#include "mainwindow.h"
 //using namespace std;

//class QLineEdit;
class MainWindow;

class Space {


  public:
    Space( int, string);
    virtual void landOn(Player&, MainWindow*){};
    virtual std::string print(){};
    virtual std::string buyProperty(Player&) = 0;
//    virtual std::buyYes(Player&) = 0;
    virtual ~Space();
    int spot;
    std::string title;


//    virtual void print() =0;
};

  class Ownable : public Space {
  public:
    Ownable(int, std::string, int, int); //HERE
    BillBoard * bboard;
    // virtual void buy(void){}; // IMPORTANT
    virtual ~Ownable();
    // virtual BillBoard* getBillBoard(void){};
    int owner;
    int owned;
    int cost;
    void buy(Player&);
    std::string buyYes(Player&);
    std::string buyNo(Player&);
    void rent(Player&);
    std::string message;
};

class Go: public Space {
public:
    Go( int a, std::string b ) : Space(a,b){}
    void landOn(Player&, MainWindow*);
    std::string print();
    std::string buyProperty(Player&);
};

class Nerf: public Ownable {
    // BillBoard * bboard;

public:
    Nerf( int, std::string, int, int );
    void landOn(Player&, MainWindow*);
    std::string print();
    std::string getState();
    std::string buyProperty(Player&);
    // void buy(Player&);
    BillBoard * getBillBoard();
    // void rent(Player&);
    // Player * findOwner();
};


class RivalTowerTax: public Space {
public:
    RivalTowerTax( int a, std::string b ) : Space(a,b){}
    void landOn(Player&, MainWindow*);
    std::string print();
    std::string buyProperty(Player&);
    std::string message;

};

class Transformers: public Ownable {
    // BillBoard * bboard;   //IMPORTANT
public:
    Transformers( int, std::string, int, int);
    void landOn(Player&, MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);

};

class EmpireSpace: public Space {
public:
    EmpireSpace( int a, std::string b ) : Space(a,b){}
    void landOn(Player&, MainWindow*);
    std::string print();
    std::string buyProperty(Player&);
    std::string message;
};

class Spotify: public Ownable {
    // BillBoard * bboard;
public:
    Spotify( int, std::string, int, int);
    void landOn(Player&,MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class Beats: public Ownable {
    // BillBoard * bboard;
public:
    Beats( int, std::string, int, int);
    void landOn(Player&, MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};


class Chance: public Space {
protected:
    ChanceDeck* deck;
public:
    Chance( int a, std::string b, ChanceDeck* cdeck) : Space(a,b) {
        deck = cdeck;
        message = "";
    }

    void landOn(Player&, MainWindow*);
    std::string print();
    std::string buyProperty(Player&);
    std::string message;
};

class Fender: public Ownable {
    // BillBoard * bboard;
public:
    Fender( int, std::string, int, int);
    void landOn(Player&,MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class JustVisiting: public Space {
public:
    JustVisiting( int a, std::string b ) : Space(a,b){}
    void landOn(Player&,MainWindow*);
    std::string print();
    std::string buyProperty(Player&);
};

class JetBlue: public Ownable {
    // BillBoard * bboard;
public:
    JetBlue( int, std::string, int, int);
    void landOn(Player&,MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class EA: public Ownable {
    // BillBoard * bboard;
public:
    EA( int, std::string, int, int);
    void landOn(Player&,MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class ElectricCompany: public Ownable {
    // BillBoard * bboard;
public:
    ElectricCompany( int, std::string, int, int );
    void landOn(Player &curPlayer, MainWindow*);
    std::string print();
    void buy(Player&);
    BillBoard * getBillBoard();
    void rent();
    std::string buyProperty(Player&);
};

class HasBro: public Ownable {
    // BillBoard * bboard;
public:
    HasBro( int, std::string, int, int);
    void landOn(Player&,MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class UnderArmour: public Ownable {
    // BillBoard * bboard;
public:
    UnderArmour( int, std::string, int, int);
    void landOn(Player&, MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class Carnival: public Ownable {
    // BillBoard * bboard;
public:
    Carnival( int, std::string, int, int);
    void landOn(Player&, MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class Yahoo: public Ownable {
    // BillBoard * bboard;
public:
    Yahoo( int, std::string, int, int);
    void landOn(Player&, MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class FreeParking: public Space {
public:
    FreeParking( int a, std::string b ) : Space(a,b){}
    void landOn(Player&, MainWindow*);
    std::string print();
    std::string buyProperty(Player&);
//    void showButtons(Ui::MainWindow*ui);
    void showButtons2(MainWindow*);
};

class Paramount: public Ownable {
    // BillBoard * bboard;
public:
    Paramount( int, std::string, int, int);
    void landOn(Player&,MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};


class Chevrolet: public Ownable {
    // BillBoard * bboard;
public:
    Chevrolet( int, std::string, int, int);
    void landOn(Player&, MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class EBay: public Ownable {
    // BillBoard * bboard;
public:
    EBay( int, std::string, int, int);
    void landOn(Player&,MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class XGames: public Ownable {
    // BillBoard * bboard;
public:
    XGames( int, std::string, int, int);
    void landOn(Player&, MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};



class Ducati: public Ownable {
    // BillBoard * bboard;
public:
    Ducati( int, std::string, int, int);
    void landOn(Player&,MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class Macdonalds: public Ownable {
    // BillBoard * bboard;
public:
    Macdonalds( int, std::string, int, int);
    void landOn(Player&, MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class GoToJail: public Space {
public:
    GoToJail( int a, std::string b ) : Space(a,b){}
    void landOn(Player&, MainWindow*);
    std::string print();
    std::string buyProperty(Player&);
    std::string message;
};

class Intel: public Ownable {
    // BillBoard * bboard;
public:
    Intel( int, std::string, int, int);
    void landOn(Player&, MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class XBox: public Ownable {
    // BillBoard * bboard;
public:
    XBox( int, std::string, int, int);
    void landOn(Player&,MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class WaterWorks: public Ownable {
    // BillBoard * bboard;
public:
    WaterWorks( int, std::string, int, int );
    void landOn(Player &curPlayer, MainWindow*);
    std::string print();
    void buy(Player&);
    BillBoard * getBillBoard();
    void rent();
    std::string buyProperty(Player&);
};

class Nestle: public Ownable {
    // BillBoard * bboard;
public:
    Nestle( int, std::string, int, int);
    void landOn(Player&, MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class Samsung: public Ownable {
    // BillBoard * bboard;
public:
    Samsung( int, std::string, int, int);
    void landOn(Player&, MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

class TowerTax: public Space {
public:
    TowerTax( int a, std::string b ) : Space(a,b){}
    void landOn(Player&, MainWindow* main);
    std::string print();
    std::string buyProperty(Player&);
    std::string message;
};

class CocaCola: public Ownable {
    // BillBoard * bboard;
public:
    CocaCola( int, std::string, int, int);
    void landOn(Player&, MainWindow*);
    std::string print();
    // void buy(Player&);
    BillBoard * getBillBoard();
    std::string buyProperty(Player&);
};

#endif /* SPACE_H_ */
