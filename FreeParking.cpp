#include <iostream>
#include <stdio.h>
#include "Space.h"
#include "mainwindow.h"
//#include <ui_mainwindow.h>
//using namespace std;


void FreeParking::landOn(Player &curPlayer, MainWindow* main) {
//    showButtons();
//	int ans;
//	int destination;
//	FreeParking::print();
//	cout << "Do you want to pay 100 to move to any space? "
//	     << "1.Yes "
//		 << "2.No";
//	cin >> ans;
//	while (ans < 1 || ans > 2)
//	{
//		cout << "Invalid answer! Please choose again: ";
//		cin >> ans;
//	}
	
//	if (ans == 1)
//	{
//		curPlayer.changeMoney(-100);
//		cout << "Where would you like to go to?"
//			 << "0. Go" << endl
//			 << "1. Nerf" << endl
//			 << "2. Rival Tower Tax" << endl
//			 << "3. Transformers" 	<<endl
//			 << "4. Empire Space"	<<endl
//			 << "5. Spotify"	<<endl
//			 << "6. Chance"	<<endl
//			 << "7. Beats"	<<endl
//			 << "8. Fender"	<<endl
//			 << "9. Just Visting"	<<endl
//			 << "10. Jet Blue" <<endl
//			 << "11. EA Sports" <<endl
//			 << "12. Electric Company" <<endl
//			 << "13. HasBros" <<endl
//			 << "14. Under Armour" <<endl
//			 << "15. Chance" <<endl
//			 << "16. Carnival" <<endl
//			 << "17. Yahoo!" <<endl
//			 << "18. Free Parking" <<endl
//			 << "19. Paramount" <<endl
//			 << "20. Chevrolet" <<endl
//			 << "21. Chance" <<endl
//			 << "22. E Bay" <<endl
//			 << "23. X Games" <<endl
//			 << "24. Empire Space" <<endl
//			 << "25. Ducati" <<endl
//			 << "26. Macdonalds" <<endl
//			 << "27. Go To Jail" <<endl
//			 << "28. Intel" <<endl
//			 << "29. X Box" <<endl
//			 << "30. Water Works" <<endl
//			 << "31. Nestle" <<endl
//			 << "32. Chance" <<endl
//			 << "33. Samsung" <<endl
//			 << "34. Tower Tax" <<endl
//			 << "35. Coca Cola" <<endl
//			 ;
//		cin >> destination;
//		while (destination < 0 || destination > 35)
//		{
//			cout << "Invalid position! Please try again: ";
//			cin >> destination;
//		}
//		curPlayer.setGlobal (destination);
//		(*curPlayer.getSpaces().at(destination)).landOn(curPlayer);

//	}
	
//	else
//		cout << "Continue your turn as usual.";
}

std::string FreeParking::print() {
    return "LAND ON FREE PARKING\n";
}


std::string FreeParking::buyProperty(Player &curPlayer) {
    return "LAND ON COCA COLA";
}

//void FreeParking::showButtons(Ui::MainWindow* main) {
//    main->console->setText("HIII");
//}


void FreeParking::showButtons2(MainWindow* main) {
//    main->button_roll->setText("HIII");
}



