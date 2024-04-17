#include<iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include<conio.h>
#include<ctime>
#include "../OOP Project/22i-2562.h"
using namespace std;

//____________________________________________________________(Menus)_______________________________________________________________________



void admin(NAFS& n)
{
	User a;
	if (n.l.isLoggedIn('a', a)) // If admin successfully logged in the account
	{
		while (1)
		{
			system("CLS");
			string choice;
			cout << "1. Add a new admin" << endl;
			cout << "2. View international flights" << endl;
			cout << "3. View local flights" << endl;
			cout << "4. Add flight" << endl;
			cout << "5. Cancel flight" << endl;
			cout << "6. Ban a country" << endl;
			cout << "7. Apply corona restrictions" << endl;
			cout << "8. View company profit" << endl;
			cout << "9. Go back" << endl;
			cin >> choice;
			system("CLS");

			if (choice == "1") // To add a new admin
			{
				n.l.getAdmin(0).add_newadmin();
				pressanykey();	
			}
			else if (choice == "2") // View international flights
			{
				n.f.updateFlightScheldule();
				n.f.showInternationalAvailableFlight();
				pressanykey();
			}
			else if (choice == "3") // View local flights
			{
				n.f.updateFlightScheldule();
				n.f.showLocalAvailableFlights();
				pressanykey();

			}
			else if (choice == "4") // Add flights
			{
				n.f.addFlight();
				pressanykey();
			}
			else if (choice == "5") // cancel flights
			{
				cout << "1. International flight" << endl;
				cout << "2. Local flight" << endl;
				cin >> choice;
				system("CLS");
				if (choice == "1")
					n.f.showInternationalAvailableFlight();
				else
					n.f.showLocalAvailableFlights();
				n.f.cancelflight();
				system("CLS");
				if (choice == "1")
					n.f.showInternationalAvailableFlight();
				else
					n.f.showLocalAvailableFlights();
				pressanykey();
			}
			else if (choice == "6") // banning a country
			{
				n.f.ban();
				pressanykey();
			}
			else if (choice == "7") // apply corona restrictions
			{
				n.f.apply_coronarestrictions();
				cout << "Corona Restrictions has been applied successfully" << endl;
				pressanykey();
			}
			else if (choice == "8") // view company profit
			{
				string p;
				ifstream file("Company Profit.txt");
				getline(file, p);
				file.close();
				cout << "The total profit of NAFS after paying taxes is: " << p << endl << endl;
				pressanykey();

			}
			else if (choice == "9") // go back to menu
			{
				break;
			}
			else
			{
				cout << "Invalid choice made!" << endl;
				cout << "Please wait for 3 seconds" << endl;
				Sleep(3000); // Pausing screen for 3 seconds
				system("CLS"); // clearing screen
			}
		}
	}
	else
	{
		cout << "This account doesn't exist!" << endl;
		pressanykey();    // To navigate to back page
	}
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


void passenger(NAFS& n)
{
	User passenger;
	while (1)
	{
		system("CLS");
		string choice;
		cout << "1.  Login" << endl;
		cout << "2.  Register" << endl;
		cout << "3.  Register a dependent" << endl;
		cout << "4.  Update your information" << endl;
		cout << "5.  View international flights" << endl;
		cout << "6.  View local flights" << endl;
		cout << "7.  Search flight by destination" << endl;
		cout << "8.  Book a seat" << endl;
		cout << "9 . Cancel booking" << endl;
		cout << "10. Log out" << endl;
		cout << "11. Back" << endl;
		cin >> choice;
		system("CLS");

		if (choice == "1") // for login
		{
			if (passenger.getLoginStatus() == false)
			{
				if (n.l.isLoggedIn('p', passenger))
				{
					passenger.setLoginStatus(true);
					cout << "You have successfully logged into your account!" << endl;
					pressanykey();
				}
				else
				{
					cout << "Your account doesn't exist" << endl;
					pressanykey();
				}
			}
			else
			{
				cout << "You have already logged in!" << endl;
				pressanykey();
			}
			
		}
		else if (choice == "2") // for registering
		{
			n.l.register_passenger();
			pressanykey();
		}
		else if (choice == "3") // for registering a dependent
		{
			if (passenger.getLoginStatus() == true)
			{
				n.l.register_dependent();
				pressanykey();
			}
			else
			{
				cout << "____________Login to your account___________" << endl << endl;
				if (n.l.isLoggedIn('p', passenger))
				{
					passenger.setLoginStatus(true);
					cout << "You have successfully logged into your account!" << endl;
					pressanykey();
					system("CLS");
					cout << "____________Register Dependent___________" << endl << endl;
					n.l.register_dependent();
					pressanykey();
				}
				else
				{
					cout << "Your account doesn't exist" << endl;
					pressanykey();
				}
			}
		}
		else if (choice == "4") // For updating informations
		{
			if (passenger.getLoginStatus() == false)
			{
				cout << "____________Login to your account___________" << endl << endl;
				if (n.l.isLoggedIn('p', passenger))
				{
					passenger.setLoginStatus(true);
					cout << "You have successfully logged into your account!" << endl;

					pressanykey();
					system("CLS");
					cout << "____________Update Information___________" << endl << endl;

					passenger.updateInformation(passenger);
					pressanykey();
				}
				else
				{
					cout << "Your account doesn't exist" << endl;
					pressanykey();
				}
			}
			else
			{
				passenger.updateInformation(passenger);
				pressanykey();
			}
		}
		else if (choice == "5") // for showing international flights
		{
			n.f.updateFlightScheldule();
			n.f.showInternationalAvailableFlight();
			pressanykey();
		}
		else if (choice == "6") // for showing local flights
		{
			n.f.updateFlightScheldule();
			n.f.showLocalAvailableFlights();
			pressanykey();
		}
		else if (choice == "7")
		{
			n.f.search_flight();
			pressanykey();
		}
		else if (choice == "8") // for booking
		{
			if (passenger.getLoginStatus() == false)
			{
				cout << "____________Login to your account___________" << endl << endl;
				if (n.l.isLoggedIn('p', passenger))
				{
					passenger.setLoginStatus(true);
					cout << "You have successfully logged into your account!" << endl;

					pressanykey();
					system("CLS");
					cout << "____________Book a seat___________" << endl << endl;

					n.f.booking(passenger, n.sales);
					pressanykey();
				}
				else
				{
					cout << "Your account doesn't exist" << endl;
					pressanykey();
				}
			}
			else
			{
				cout << "____________Book a seat___________" << endl << endl;
				n.f.booking(passenger, n.sales);
				pressanykey();
			}
		}
		else if (choice == "9")
		{
			n.f.cancel_booking(passenger, n.sales);
			pressanykey();
		}

		else if (choice == "10")
		{
			if (passenger.getLoginStatus() == false) {
				cout << "You have not looged in yet!" << endl;
				pressanykey();
			}
			else
			{
				passenger.setLoginStatus(false);
				cout << "Logged out!" << endl;
				pressanykey();
			}
		}

		else if (choice == "11")
			break;
		else
		{
			cout << "Invalid choice made!" << endl;
			cout << "Please wait for 3 seconds" << endl;
			Sleep(3000); // Pausing screen for 3 seconds
			system("CLS"); // clearing screen
		}
	}
}


//__________________________________________________________________________________________________________________________________________





int main()
{
	NAFS s;
	string choice = "";
	while (1)
	{
		cout << "1. Continue as an admin" << endl;
		cout << "2. Continue as a passenger" << endl;
		cout << "3. Exit" << endl;
		cin >> choice;
		system("CLS");
		if (choice == "1")
			admin(s);
		else if (choice == "2")
			passenger(s);
		else if (choice == "3")
			exit(0);

	}



 //       //___________________________________________________________________________________________________________________________________________________________________

	

	//	}

 //       //___________________________________________________________________________________________________________________________________________________________________


	//	else if (choice == "2") // to continue as a passenger
	//	{
 //           cout << "Press 1 to login" << endl;
 //           cout << "Press 2 to register" << endl;
 //           cout << "Press 3 to go back" << endl;
 //           cout << "Choice: ";
 //           cin >> choice;
 //           system("CLS");
 //           if (choice == "1") // For Login
 //           {
 //               if (l.isLoggedIn('p')) // 2 to tell the function that it is an admin
 //               {
 //                   cout << "You are successfully logged in!" << endl;
 //               }
 //               else 
 //               {
 //                   cout << "This account doesn't exist!" << endl;
 //               }
 //               cout << "Press any key to go back" << endl;
 //               cin >> choice;
 //               system("CLS");
 //           }
 //           else if (choice == "2") // For Registration
 //           {
 //               l.register_passenger(); // 1 to tell the function that it is a passenger
 //               cout << "Press any key to go back" << endl;
 //               cin >> choice;
 //               system("CLS");
 //           }
 //           else if (choice == "3")
 //           {
 //               continue;
 //           }
 //           else
 //           {
 //               cout << "Invalid choice made!" << endl;
 //               cout << "Please wait for 3 seconds" << endl;
 //               Sleep(3000); // Pausing screen for 3 seconds
 //               system("CLS"); // clearing screen
 //           }
	//	}


	//	else
	//	{
	//		cout << "Invalid choice made!" << endl;
	//		cout << "Please wait for 3 seconds" << endl;
	//		Sleep(3000); // Pausing screen for 3 seconds
	//		system("CLS"); // clearing screen

	//	}
	//}

    return 0;
}