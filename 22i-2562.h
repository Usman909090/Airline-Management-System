#pragma once
#include<iostream>
#include<fstream>
#include<ctime>
#include<windows.h>
#include<string>
#include<conio.h>
#include<iomanip>
#include<sstream>
using namespace std;

//_________________________________________________________________________________________________________________



// Non member functions



// Function for getting live times
int getHour()
{
	time_t now = time(0);
	tm localtime;
	localtime_s(&localtime, &now);
	return localtime.tm_hour;
}
int getSecond()
{
	time_t now = time(0);
	tm localtime;
	localtime_s(&localtime, &now);
	return localtime.tm_sec;
}
int getMinute()
{
	time_t now = time(0);
	tm localtime;
	localtime_s(&localtime, &now);
	return localtime.tm_min;
}


void print_spaces(int m, int n)
{
	for (int j = 0; j < (m - n); j++)
	{
		cout << " ";
	}
}


void pressanykey()
{
	string k;
	cout << "Press any key to go back" << endl;
	cin >> k;
	system("CLS");
}



bool verifyPasswordPattern(string password) // a function to verify the password
{
	bool length = false;
	bool upper_case = false;
	bool lower_case = false;
	bool numeric_digit = false;
	bool special_character = false;
	if (password.length() >= 8)
	{
		length = true;
		for (int i = 0; i < password.length(); i++)
		{
			if ((int(password[i]) >= 32 && int(password[i]) <= 47) || (int(password[i]) >= 58 && int(password[i]) <= 64) || (int(password[i]) >= 91 && int(password[i]) <= 96) || (int(password[i]) >= 123 && int(password[i]) <= 126))
				special_character = true;
			if (password[i] >= 'A' && password[i] <= 'Z')
				upper_case = true;
			if (password[i] >= 'a' && password[i] <= 'z')
				lower_case = true;
			if (password[i] >= 48 && password[i] <= 57)
				numeric_digit = true;
		}
	}
	if (special_character && upper_case && lower_case && numeric_digit && length)
		return true;
	else
	{
		cout << endl;
		cout << "Your password doesn't match the format" << endl;
		cout << "Enter the password again: ";
		return false;
	}

}



bool solve(string input) {
	bool output;
	istringstream(input) >> boolalpha >> output;
	return output;
}




//____________________________________________________________________________________________________________________

class Admin        // Admin class
{
private:
	string user_name;
	string password;
	bool login_status;
public:
	Admin(string name = "", string password = "")
	{
		this->user_name = name;
		this->password = password;
	}
	// getters

	string getUserName()const
	{
		return user_name;
	}
	string getPassword()const
	{
		return password;
	}

	bool getLoginStatus()const
	{
		return login_status;
	}


	void setLoginStatus(bool s)
	{
		login_status = s;
	}

	void add_newadmin()
	{
		string name;
		string password;
		cout << "Enter the name: ";
		cin >> name;
		cout << "NOTE: (The password should be of length 8 and contain atleast 1 special character, 1 numeric digit, 1 Uppercase alphabet and 1 Lowercase alphabet)" << endl;
		cout << "Enter the Password: ";
		char ch;
		do
		{
			password = "";
			while ((ch = _getch()) != '\r')
			{
				if (ch == '\b')
				{
					if (!password.empty())
					{
						password.pop_back();
						cout << "\b \b";
					}
				}
				else
				{
					password.push_back(ch);
					cout << "*";
				}
			}
			cout << endl;
		} while (verifyPasswordPattern(password) == false); // TO cheak the password format is perfect or not
		ofstream write("Admins Information.txt", ios::app);
		write << name << endl;
		write << password << endl;
		write.close();
		cout << "Successfully added new admin in the admins list" << endl;

	}


};

//_________________________________________________________________________________________________________________


class Passport     // Passprort CLass 
{
	string passport_number;
	bool visa_status;
public:
	Passport() // Default Constructor
	{
		passport_number = "";
		visa_status = false;
	}
	Passport(string passport_number, bool visa_status) // Parameterised Constructor
	{
		this->passport_number = passport_number;
		this->visa_status = visa_status;
	}
	// setters
	void setPassportNumber(string n)
	{
		passport_number = n;
	}
	void setVisaStatus(bool status)
	{
		visa_status = status;
	}
	// getters
	string getPassportNumber()const
	{
		return passport_number;
	}
	bool getVisaStatus()const
	{
		return visa_status;
	}
};











//_________________________________________________________________________________________________________________



class User         // User class
{
	string user_name;
	string password;
	string CNIC;
	float age;
	string adress;
	string phone_number;
	Passport p;             //  __________________________________________Composition_______________________________________________________
	string account_no;
	double balance;
	bool login_status;
public:
	User() // Default Constructor
	{
		user_name = "";
		password = "";
		CNIC = "";
		age = 0;
		login_status = false;
		balance = 0;
	}
	User(string user_name, string password, string CNIC, float age, string adress, string phone_number, string account_no, bool login_status) // Parameterised Constructor
	{
		this->user_name = user_name;
		this->password = password;
		this->CNIC = CNIC;
		this->age = age;
		this->adress = adress;
		this->phone_number = phone_number;
		this->account_no = account_no;
		this->login_status = login_status;
	}
	// Setters
	void setUsername(string n)
	{
		user_name = n;
	}
	void setPassword(string n)
	{
		password = n;
	}
	void setCNIC(string n)
	{
		CNIC = n;
	}
	void setAge(float n)
	{
		age = n;
	}
	void setPhoneNumber(string n)
	{
		phone_number = n;
	}
	void setAdress(string n)
	{
		adress = n;
	}
	void setPassport(string n, bool status)
	{
		p.setPassportNumber(n);
		p.setVisaStatus(status);
	}
	void setBalance(double b)
	{
		balance = b;
	}
	void setLoginStatus(bool s)
	{
		login_status = s;
	}

	// Getters
	string getUsername()const
	{
		return user_name;
	}
	string getPassword()const
	{
		return password;
	}
	string getCNIC()const
	{
		return CNIC;
	}
	double getBalance()const
	{
		return balance;
	}
	string getPhoneNumber()const
	{
		return phone_number;
	}
	string getAdress()const
	{
		return adress;
	}
	Passport getPassport()const
	{
		return p;
	}
	float getAge()const
	{
		return age;
	}
	bool getLoginStatus()const
	{
		return login_status;
	}





	// Functions______




	bool verifyCNIC(string CNIC) // A function to verify CNIC of Passenger
	{
		bool s = false;
		if (CNIC.length() == 13)
		{
			for (int i = 0; i < 13; i++)
			{
				if (!(int(CNIC[i]) >= 48 && int(CNIC[i]) <= 57))
				{
					s = true;
					cout << "Your CNIC dosen't match the format" << endl;
					return false;
				}
			}
			return true;
		}
		else if (s == false)
		{
			cout << "You CNIC doesn't match the format" << endl;
			return false;
		}
	}




	




	 void Register() //  a function to add a new admin or a new passenger to the sysyem
	 {
		string user_name, password, re_enterPass, CNIC, adress, phonenumber, passport;
		float age;
		cout << "Enter the Username: ";
		cin.ignore();
		getline(cin, user_name);
		cout << "NOTE: (The password should be of length 8 and contain atleast 1 special character, 1 numeric digit, 1 Uppercase alphabet and 1 Lowercase alphabet)" << endl;
		cout << "Enter the Password: ";
		char ch;
		do
		{
			password = "";
			while ((ch = _getch()) != '\r')
			{
				if (ch == '\b')
				{
					if (!password.empty())
					{
						password.pop_back();
						cout << "\b \b";
					}
				}
				else
				{
					password.push_back(ch);
					cout << "*";
				}
			}
			cout << endl;
		} while (verifyPasswordPattern(password) == false); // TO cheak the password format is perfect or not 

		do
		{
			cout << "Re-Enter the Password: ";
			while ((ch = _getch()) != '\r')
			{
				if (ch == '\b')
				{
					if (!re_enterPass.empty())
					{
						re_enterPass.pop_back();
						cout << "\b \b";
					}
				}
				else
				{
					re_enterPass.push_back(ch);
					cout << "*";
				}
			}
			cout << endl;
			if (re_enterPass != password)
				cout << "Your password isn't matched with prevoius one, try again!" << endl << endl;
		} while (re_enterPass != password);
		cout << "Enter age: ";
		cin >> age;
		if (age >= 18)
		{
			cout << "(Enter 13 digit CNIC)" << endl;
			do
			{
				cout << "Enter CNIC: ";
				cin >> CNIC;
				verifyCNIC(CNIC);
			} while (!verifyCNIC(CNIC));
			
			cout << "Enter your phone number: ";
			cin >> phonenumber;
			cout << "Enter adress: ";
			cin.ignore();
			getline(cin, adress);
			cout << "Enter account number: ";
			getline(cin, account_no);
			cout << "Enter balance: ";
			cin >> this->balance;
			int choice = 0;

			cout << "Enter you passport number: ";
			cin >> passport;
			cout << "Do you have visa confirmed on your passport?" << endl;
			cout << "Press 1 for yes" << endl;
			cout << "Press 2 for no" << endl;
			cin >> choice;
			if (choice == 1)
			{
				setPassport(passport, true);
			}
			else
			{
				setPassport(passport, false);
			}
			// setting details of user in user class
			this->user_name = user_name;
			this->password = password;
			this->CNIC = CNIC;
			this->age = age;
			this->phone_number = phonenumber;
			p.setPassportNumber(passport);
			this->adress = adress;
			string status;
			if (p.getVisaStatus() == true)
				status = "Confirmed";
			else
				status = "Not Confirmed";
			ofstream write("Passenger " + user_name + " Details" + ".txt"); // It will make a file with the name of user and write the user details in it
			write << "User Name: " << user_name << endl << "Password: " << password << endl << "CNIC: " << CNIC << endl << "Age: " << age << endl
				<< "Phone Number: " << phonenumber << endl << "Adress: " << adress << endl << "Account number: " << account_no << endl << "Balance: " << balance << endl << "Passport Number: " << passport << endl << "Visa Status: " << status << endl;
			write.close();
			cout << endl;
			ofstream w("Passengers Information.txt", ios::app);
			w << user_name << endl << password << endl << to_string(balance) << endl << status << endl;
			w.close();
			cout << "| Registreation successfull!" << endl << endl;
		}
		else
		{
			cout << "You are under age and you can't be registered!" << endl;
		}
	}




	void RegisterDependent() //  a function to add a new admin or a new passenger to the sysyem
	{
		string user_name, password, re_enterPass, adress, phonenumber, passport;
		float age;
		cout << "Enter the Username: ";
		cin.ignore();
		getline(cin, user_name);
		cout << "NOTE: (The password should be of length 8 and contain atleast 1 special character, 1 numeric digit, 1 Uppercase alphabet and 1 Lowercase alphabet)" << endl;
		cout << "Enter the Password: ";
		char ch;
		do
		{
			password = "";
			while ((ch = _getch()) != '\r')
			{
				if (ch == '\b')
				{
					if (!password.empty())
					{
						password.pop_back();
						cout << "\b \b";
					}
				}
				else
				{
					password.push_back(ch);
					cout << "*";
				}
			}
			cout << endl;
		} while (verifyPasswordPattern(password) == false); // TO cheak the password format is perfect or not 

		do
		{
			cout << "Re-Enter the Password: ";
			while ((ch = _getch()) != '\r')
			{
				if (ch == '\b')
				{
					if (!re_enterPass.empty())
					{
						re_enterPass.pop_back();
						cout << "\b \b";
					}
				}
				else
				{
					re_enterPass.push_back(ch);
					cout << "*";
				}
			}
			cout << endl;
			if (re_enterPass != password)
				cout << "Your password isn't matched with prevoius one, try again!" << endl << endl;
		} while (re_enterPass != password);
		cout << "Enter age: ";
		cin >> age;
		cout << "Enter the phone number: ";
		cin >> phonenumber;
		cout << "Enter adress: ";
		cin.ignore();
		getline(cin, adress);
		cout << "Enter account number: ";
		getline(cin, account_no);
		cout << "Enter balance: ";
		cin >> balance;
		int choice = 0;

		cout << "Enter the passport number: ";
		cin >> passport;
		cout << "Does he have visa confirmed on your passport?" << endl;
		cout << "Press 1 for yes" << endl;
		cout << "Press 2 for no" << endl;
		cin >> choice;
		if (choice == 1)
		{
			setPassport(passport, true);
		}
		else
		{
			setPassport(passport, false);
		}
		// setting details of user in user class
		this->user_name = user_name;
		this->password = password;
		this->CNIC = CNIC;
		this->age = age;
		this->phone_number = phonenumber;
		p.setPassportNumber(passport);
		this->adress = adress;
		string status;
		if (p.getVisaStatus() == true)
			status = "Confirmed";
		else
			status = "Not Confirmed";
		ofstream write("Dependent " + user_name + " Details" + ".txt"); // It will make a file with the name of user and write the user details in it
		write << "User Name: " << user_name << endl << "Password: " << password << endl << endl << "Age: " << age << endl
			<< "Phone Number: " << phonenumber << endl << "Adress: " << adress << endl << "Account number" << account_no << endl << "Balance" << balance << endl << "Passport Number: " << passport << endl << "Visa Status: " << status << endl;
		write.close();
		cout << endl;
		ofstream w("Passengers Information.txt", ios::app);
		w << user_name << endl << password << endl << to_string(balance) << endl << status << endl;
		w.close();
		cout << "| Registreation successfull!" << endl << endl;
		
	}




	void updateInformation(User& s) //  a function to add a new admin or a new passenger to the sysyem
	{
		string user_name, password, re_enterPass, CNIC, adress, phonenumber, passport;
		float age;
		user_name = s.getUsername();
		cout << "NOTE: (The password should be of length 8 and contain atleast 1 special character, 1 numeric digit, 1 Uppercase alphabet and 1 Lowercase alphabet)" << endl;
		cout << "Enter the Password: ";
		char ch;
		do
		{
			password = "";
			while ((ch = _getch()) != '\r')
			{
				if (ch == '\b')
				{
					if (!password.empty())
					{
						password.pop_back();
						cout << "\b \b";
					}
				}
				else
				{
					password.push_back(ch);
					cout << "*";
				}
			}
			cout << endl;
		} while (verifyPasswordPattern(password) == false); // TO cheak the password format is perfect or not 

		do
		{
			cout << "Re-Enter the Password: ";
			while ((ch = _getch()) != '\r')
			{
				if (ch == '\b')
				{
					if (!re_enterPass.empty())
					{
						re_enterPass.pop_back();
						cout << "\b \b";
					}
				}
				else
				{
					re_enterPass.push_back(ch);
					cout << "*";
				}
			}
			cout << endl;
			if (re_enterPass != password)
				cout << "Your password isn't matched with prevoius one, try again!" << endl << endl;
		} while (re_enterPass != password);
		age = s.getAge();
		if (age >= 18)
		{
			cout << "(Enter 13 digit CNIC)" << endl;
			do
			{
				cout << "Enter CNIC: ";
				cin >> CNIC;
				verifyCNIC(CNIC);
			} while (!verifyCNIC(CNIC));
			cout << "Enter your phone number: ";
			cin >> phonenumber;
			cout << "Enter adress: ";
			cin.ignore();
			getline(cin, adress);
			int choice = 0;

			cout << "Enter you passport number: ";
			cin >> passport;
			cout << "Do you have visa confirmed on your passport?" << endl;
			cout << "Press 1 for yes" << endl;
			cout << "Press 2 for no" << endl;
			cin >> choice;
			if (choice == 1)
			{
				setPassport(passport, true);
			}
			else
			{
				setPassport(passport, false);
			}
			// setting details of user in user class
			this->user_name = user_name;
			this->password = password;
			this->CNIC = CNIC;
			this->age = age;
			this->phone_number = phonenumber;
			p.setPassportNumber(passport);
			this->adress = adress;
			string status;
			if (p.getVisaStatus() == true)
				status = "Confirmed";
			else
				status = "Not Confirmed";
			ofstream write("Passenger " + user_name + " Details" + ".txt"); // It will make a file with the name of user and write the user details in it
			write << "User Name: " << user_name << endl << "Password: " << password << endl << "CNIC: " << CNIC << endl << "Age: " << age << endl
				<< "Phone Number: " << phonenumber << endl << "Adress: " << adress << endl << "Passport Number: " << passport << endl << "Visa Status: " << status << endl;
			write.close();
			cout << endl;
			cout << "| Updated informations successful!" << endl << endl;
		}
	}

	


};





//_________________________________________________________________________________________________________________



class Login  //  Login class
{
	User* passengers;    // (_______________________________________aggregation_____________________________________)
	Admin* admins;       // (_______________________________________aggregation_____________________________________)
	int registered_passengers;
	int registered_admins; // Only can be changed when the manager will add any admin detail in "Admins.txt" file
public:
	Login() // Default constructor
	{
		int i = 0;
		string h;
		string name;
		string password;
		string balance;
		string visa;
		ifstream read("Passengers Information.txt");
		while (read.eof() == 0)
		{
			getline(read, h);
			i++;
		}
		read.close();
		registered_passengers = i / 4;
		passengers = new User[registered_passengers];
		ifstream read2("Passengers Information.txt");
		int o= 0;
		for (int i = 0; i < registered_passengers; i++)
		{
			getline(read2, name);
			getline(read2, password);
			getline(read2, balance);
			getline(read2, visa);
			passengers[o].setUsername(name);
			passengers[o].setPassword(password);
			passengers[o].setBalance(stoi(balance));
			if (visa == "Confirmed")
				passengers[o].getPassport().setVisaStatus(true);
			else
				passengers[o].getPassport().setVisaStatus(false);
			o++;
		}
		
		
		read.close();
		i = 0;
		ifstream read3("Admins Information.txt");
		while (read3.eof() == 0)
		{
			getline(read3, h);
			i++;
		}
		read3.close();
		registered_admins = i / 2;
		admins = new Admin[registered_admins];	
	}

	// Setters

	void register_passenger()     
	{
		registered_passengers++;
		User* temp = new User[registered_passengers - 1];
		for (int i = 0; i < (registered_passengers - 1); i++)
			temp[i] = passengers[i];
		passengers = new User[registered_passengers];
		for (int i = 0; i < registered_passengers - 1; i++)
			passengers[i] = temp[i];
		delete[]temp;
		temp = NULL;
		passengers[registered_passengers - 1].Register();    // Registering new passenger
	}

	void register_dependent()
	{
		registered_passengers++;
		User* temp = new User[registered_passengers - 1];
		for (int i = 0; i < (registered_passengers - 1); i++)
			temp[i] = passengers[i];
		passengers = new User[registered_passengers];
		for (int i = 0; i < registered_passengers - 1; i++)
			passengers[i] = temp[i];
		delete[]temp;
		temp = NULL;
		passengers[registered_passengers - 1].RegisterDependent();    // Registering new passenger
	}

	// getters
	int getRegisteredPassengers()const
	{
		return registered_passengers;
	}

	User getUser(int index)const
	{
		return passengers[index];
	}

	Admin getAdmin(int index)const
	{
		return admins[index];
	}



	//-------------------------------------Functions




	bool isLoggedIn(char c, User& a) // A function to cheak whether the user is logged in or not as a admin member or as a passenger
	{
		string name;
		string password;
		string f_name; // temporary variable to store file input for name
		string f_password; // temporary variable to store file input for password
		string visa;
		string balance;
		bool status = false;
		cout << "Enter the username: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter the password: ";
		cin >> password;
		if (c == 'p')
		{
			ifstream read("Passengers Information.txt");
			while (read.eof() == 0)
			{
				getline(read, f_name);
				getline(read, f_password);
				getline(read, balance);
				getline(read, visa);

				if (f_name == name && f_password == password)
				{
					for (int i = 0; i < registered_passengers; i++)
					{
						if (passengers[i].getUsername() == name && passengers[i].getPassword() == password)
						{
							
							passengers[i].setLoginStatus(true);
							passengers[i].setBalance(stoi(balance));
							if (visa == "Confirmed")
								passengers[i].getPassport().setVisaStatus(true);
							else
								passengers[i].getPassport().setVisaStatus(false);

							a = passengers[i];
						}
					}
					status = true;
				}
			}
			read.close();
		}
		else if (c == 'a')
		{
			ifstream read("Admins Information.txt");
			while (read.eof() == 0)
			{
				getline(read, f_name);
				getline(read, f_password);
				if (f_name == name && f_password == password)
				{
					for (int i = 0; i < registered_admins; i++)
					{
						if (admins[i].getUserName() == name && admins[i].getPassword() == password)
							admins[i].setLoginStatus(true);
					}
					status = true;
				}
			}
			read.close();
		}
		return status;
	}
};


//_________________________________________________________________________________________________________________



class Airplane  // Airplane class
{
	string planeID;
	int seating_capacity;
	string current_location;
	string type; // Business or Economy
	string Locally_or_Internationally;
public:
	Airplane(string planeID = "", string current_location = "", string type = "", string s = "Locally")
	{
		this->planeID = planeID;
		this->current_location = current_location;
		this->type = type;
		if (type == "Business")
			seating_capacity = 10;
		else
			seating_capacity = 50;
		Locally_or_Internationally = s;
	}

	// Setters

	void setPlaneID(string id)
	{
		planeID = id;
	}
	void setCurrentLocation(string c)
	{
		current_location = c;
	}
	void setType(string t)
	{
		type = t;
		if (type == "Business")      // Setting sitting capacity acoording to plane type
			seating_capacity = 10;
		else
			seating_capacity = 50;
	}

	void setLocallyorInternationally(string s)
	{
		Locally_or_Internationally = s;
	}

	// Getters

	string getPlaneID()const
	{
		return planeID;
	}
	int getSeatingCapacity()const
	{
		return seating_capacity;
	}
	string getCurrentLocation()const
	{
		return current_location;
	}
	string getType()const
	{
		return type;
	}
	string getLocallyorInternationally()const
	{
		return Locally_or_Internationally;
	}
};




//_________________________________________________________________________________________________________________





class Flight // Flight Class
{
	float departure_time;
	float arrival_time;
	float flight_duration;
	string origin;
	string destination;
	double fair;
	bool available;
	bool ban = true;
	Airplane airplane;
public:
	int* available_seats;
	Flight()
	{
		departure_time = 0;
		arrival_time = 0;
		flight_duration = 0;
		origin = "";
		destination = "";
		available_seats = 0;
		fair = 0;
	}
	Flight(string orig , string dest , float dep_time, float arr_time , float duration, double fa, Airplane p)
	{
		departure_time = dep_time;
		arrival_time = arr_time;
		flight_duration = duration;
		origin = orig;
		destination = dest;
		fair = fa;
		//available_seats = p.getSeatingCapacity();
		available = true;
	}

	// Getters
	float getDepartureTime()const
	{
		return departure_time;
	}

	void setFlight(string orig, string dest, float dep_time, float arr_time, float duration, double fa, Airplane p, bool b = false)
	{
		departure_time = dep_time;
		arrival_time = arr_time;
		flight_duration = duration;
		origin = orig;
		destination = dest;
		fair = fa;
		//available_seats = p.getSeatingCapacity();
		airplane = p;
		available = true;
		ban = b;
		available_seats = new int[p.getSeatingCapacity()];
		for (int i = 0; i < p.getSeatingCapacity(); i++)
		{
			available_seats[i] = i + 1;
		}
	}

	void setAvailbility()
	{
		available = false;
	}

	bool getAvailbility()const
	{
		return available;
	}

	float getArrivalTime()const
	{
		return arrival_time;
	}
	bool getBan()const
	{
		return ban;
	}


	float getFlightDuration()const
	{
		return flight_duration;
	}

	double getFair()const
	{
		return fair;
	}


	string getOrigin()const
	{
		return origin;
	}

	//int getAvailableSeats()const
	//{
	//	return available_seats;
	//}

	string getDestination()const
	{
		return destination;
	}

	Airplane getPlane()const
	{
		return airplane;
	}

	// setters

	void setDestination(string dest)
	{
		destination = dest;
	}
	void setBan(bool b)
	{
		ban = b;
	}

	/*void setAvailableSeats(int seats)
	{
		available_seats = seats;
	}*/
	void setDepartureTime(float dep_time)
	{
		departure_time = dep_time;
	}
	void setArrivalTime(float arr_time)
	{
		arrival_time = arr_time;
	}
	void setFlightDuration(float duration)
	{
		flight_duration = duration;
	}
	void setFair(double f)
	{
		fair = f;
	}
	void setOrigin(string orig)
	{
		origin = orig;
	}
	void setPlane(Airplane a)
	{
		airplane = a;
	}




	


	int AvailableSeats()
	{
		int count = 0;
		for (int i = 0; i < airplane.getSeatingCapacity(); i++)
		{
			if (airplane.getSeatingCapacity() == 50)
			{
				cout << available_seats[i] << "   ";
				if (available_seats[i] < 10)
					cout << " ";
				if ((i + 1) % 5 == 0)
					cout << endl;
			}
			else
			{
				cout << available_seats[i] << "   ";
				if (available_seats[i] < 10)
					cout << " ";
				if ((i + 1) % 2 == 0)
					cout << endl;
			}
			if (available_seats[i] != 0)
				count++;
		}
		return count;
	}

	

};
//______________________________________________________________________________________________________________________

class Sales
{
	double sale;
public:
	Sales()
	{
		sale = 0;
		string f;
		ifstream file("Company Profit.txt");
		getline(file, f);
		file.close();
		sale = stoi(f);
	}
	Sales(double p)
	{
		sale = p;
	}

	void setSales(double p)
	{
		sale += p;
		ofstream write("Company Profit.txt");
		write << sale;
		write.close();
	}

	double getSales(double p)
	{
		return sale;
	}


};




//_________________________________________________________________________________________________________________


class FlightSchedules // class for scheduling flights
{
	Flight* flights;          //              ______________________________agggregation______________________________________
	int n_flight;
public:
	FlightSchedules()
	{
		// 50 airplanes available for NAFS
		Airplane a1("0001", "Multan North", "Economy", "Locally"), a2("0002", "Multan North", "Economy", "Internationally"), a3("0003", "Multan North", "Economy", "Internationally"), a4("0004", "Multan North", "Business", "Locally"), a5("0005", "Multan North", "Business", "Internationally"), a6("0006", "Multan South", "Economy", "Locally"), a7("0007", "Multan South", "Economy", "Internationally"), a8("0008", "Multan South", "Economy", "Internationally"), a9("0009", "Multan South", "Business", "Locally"), a10("0010", "Multan South", "Business", "Internationally");
		Airplane a11("0011", "Lahore North", "Economy", "Locally"), a12("0012", "Lahore North", "Economy", "Internationally"), a13("0013", "Lahore North", "Economy", "Internationally"), a14("0014", "Lahore North", "Business", "Locally"), a15("0015", "Lahore North", "Business", "Internationally"), a16("0016", "Lahore South", "Economy", "Locally"), a17("0017", "Lahore South", "Economy", "Internationally"), a18("0018", "Lahore South", "Economy", "Internationally"), a19("0019", "Lahore South", "Business", "Locally"), a20("0020", "Lahore South", "Business", "Internationally");
		Airplane a21("0021", "Karachi North", "Economy", "Locally"), a22("0022", "Karachi North", "Economy", "Internationally"), a23("0023", "Karachi North", "Economy", "Internationally"), a24("0024", "Karachi North", "Business", "Locally"), a25("0025", "Karachi North", "Business", "Internationally"), a26("0026", "Karachi South", "Economy", "Locally"), a27("0027", "Karachi South", "Economy", "Internationally"), a28("0028", "Karachi South", "Economy", "Internationally"), a29("0029", "Karachi South", "Business", "Locally"), a30("0030", "Karachi South", "Business", "Internationally");
		Airplane a31("0031", "Islamabad North", "Economy", "Locally"), a32("0032", "Islamabad North", "Economy", "Internationally"), a33("0033", "Islamabad North", "Economy", "Internationally"), a34("0034", "Islamabad North", "Business", "Locally"), a35("0035", "Islamabad North", "Business", "Internationally"), a36("0036", "Islamabad South", "Economy", "Locally"), a37("0037", "Islamabad South", "Economy", "Internationally"), a38("0038", "Islamabad South", "Economy", "Internationally"), a39("0039", "Islamabad South", "Business", "Locally"), a40("0040", "Islamabad South", "Business", "Internationally");
		Airplane a41("0041", "Peshawar North", "Economy", "Locally"), a42("0042", "Peshawar North", "Economy", "Internationally"), a43("0043", "Peshawar North", "Economy", "Internationally"), a44("0044", "Peshawar North", "Business", "Locally"), a45("0045", "Peshawar North", "Business", "Internationally"), a46("0046", "Peshawar South", "Economy", "Locally"), a47("0047", "Peshawar South", "Economy", "Internationally"), a48("0048", "Peshawar South", "Economy", "Internationally"), a49("0049", "Peshawar South", "Business", "Locally"), a50("0050", "Peshawar South", "Business", "Internationally");
		flights = new Flight[50];
		n_flight = 50;
		// Setting defalut flights
		// Multan
		flights[0].setFlight(a1.getCurrentLocation(), "Lahore North", 4, 4.31, .31, 3100, a1);
		flights[1].setFlight(a2.getCurrentLocation(), "India", 5, 5.44, .44, 8800, a2);
		flights[2].setFlight(a3.getCurrentLocation(), "Turkey", 6, 11.55, 5.55, 111000, a3);
		flights[3].setFlight(a4.getCurrentLocation(), "Karachi South", 7, 8.4, 1.4, 14000, a4);
		flights[4].setFlight(a5.getCurrentLocation(), "Bangladesh", 8, 10.40, 2.40, 48000, a5);
		flights[5].setFlight(a6.getCurrentLocation(), "Islamabad North", 10, 10.36, .36, 3600, a6);
		flights[6].setFlight(a7.getCurrentLocation(), "Saudia Arabia", 11, 16.8, 5.8, 116000, a7);
		flights[7].setFlight(a8.getCurrentLocation(), "Dubai", 13, 15.34, 2.34, 46800, a8);
		flights[8].setFlight(a9.getCurrentLocation(), "Peshawar South", 14, 14.36, .36, 3600, a9);
		flights[9].setFlight(a10.getCurrentLocation(), "Qatar", 19, 22.9, 3.9, 78000, a10);
		// Lahore
		flights[10].setFlight(a11.getCurrentLocation(), "Karachi North", 4, 5.30, 1.30, 13000, a11);
		flights[11].setFlight(a12.getCurrentLocation(), "United States", 5, 20.35, 15.35, 307000, a12);
		flights[12].setFlight(a13.getCurrentLocation(), "Afghanistan", 6, 6.56, 0.56, 11200, a13);
		flights[13].setFlight(a14.getCurrentLocation(), "Multan South", 7, 7.32, 0.32, 3200, a14);
		flights[14].setFlight(a15.getCurrentLocation(), "China", 8, 11.27, 3.27, 65400, a15);
		flights[15].setFlight(a16.getCurrentLocation(), "Peshawer North", 10, 10.36, .36, 3600, a16);
		flights[16].setFlight(a17.getCurrentLocation(), "Japan", 11, 17.45, 6.45, 129000, a17);
		flights[17].setFlight(a18.getCurrentLocation(), "Russia", 13, 23.58, 10.58, 211600, a18);
		flights[18].setFlight(a19.getCurrentLocation(), "Islamabad South", 14, 14.27, .27, 2700, a19);
		flights[19].setFlight(a20.getCurrentLocation(), "Iraq", 19, 23.22, 4.22, 84400, a20);
		// Karachi
		flights[20].setFlight(a21.getCurrentLocation(), "Lahore South", 4, 5.17, 1.17, 17000, a21);
		flights[21].setFlight(a22.getCurrentLocation(), "South Africa", 5, 23.14, 18.14, 362800, a22);
		flights[22].setFlight(a23.getCurrentLocation(), "Australia", 6, 19.55, 13.55, 271000, a23);
		flights[23].setFlight(a24.getCurrentLocation(), "Multan North", 7, 7.59, 0.59, 5900, a24);
		flights[24].setFlight(a25.getCurrentLocation(), "United Kingdom", 8, 16.50, 8.50, 170000, a25);
		flights[25].setFlight(a26.getCurrentLocation(), "Peshawer North", 10, 11.24, 1.24, 12400, a26);
		flights[26].setFlight(a27.getCurrentLocation(), "France", 11, 19.39, 8.39, 167800, a27); 
		flights[27].setFlight(a28.getCurrentLocation(), "Egypt", 14, 19.28, 5.28, 105600, a28);
		flights[28].setFlight(a29.getCurrentLocation(), "Islamabad South", 13, 14.22, 1.22, 12200, a29);
		flights[29].setFlight(a30.getCurrentLocation(), "Iran", 19, 21.51, 2.51, 50200, a30);
		// Islamabad
		flights[30].setFlight(a31.getCurrentLocation(), "Karachi South", 4, 5.22, 1.22, 12200, a31);
		flights[31].setFlight(a32.getCurrentLocation(), "Switzerland", 5, 12.40, 7.40, 148000, a32);
		flights[32].setFlight(a33.getCurrentLocation(), "Finland", 6, 12.12, 6.12, 122400, a33);
		flights[33].setFlight(a34.getCurrentLocation(), "Lahore North", 7, 7.25, 0.25, 2500, a34);
		flights[34].setFlight(a35.getCurrentLocation(), "Thailand", 8, 12.51, 4.51, 90200, a35);
		flights[35].setFlight(a36.getCurrentLocation(), "Multan North", 10, 10.36, 0.36, 3600, a36);
		flights[36].setFlight(a37.getCurrentLocation(), "Ukrain", 11, 15.56, 4.56, 91200, a37); 
		flights[37].setFlight(a38.getCurrentLocation(), "Syria", 14, 18.51, 4.51, 90200, a38);
		flights[38].setFlight(a39.getCurrentLocation(), "Peshawer South", 13, 13.17, .17, 1700, a39);
		flights[39].setFlight(a40.getCurrentLocation(), "UAE", 19, 22.2, 3.2, 64000, a40);
		// Peshawer
		flights[40].setFlight(a41.getCurrentLocation(), "Lahore South", 4, 4.30, 0.30, 3000, a41);
		flights[41].setFlight(a42.getCurrentLocation(), "Kuwait", 5, 8.32, 3.32, 66400, a42);
		flights[42].setFlight(a43.getCurrentLocation(), "Turkey", 6, 11.36, 5.36, 107200, a43);
		flights[43].setFlight(a44.getCurrentLocation(), "Karachi North", 7, 8.33, 1.33, 13300, a44);
		flights[44].setFlight(a45.getCurrentLocation(), "Russia", 8, 18.48, 10.48, 209600, a45);
		flights[45].setFlight(a46.getCurrentLocation(), "Multan South", 10, 10.36, 0.36, 3600, a46);
		flights[46].setFlight(a47.getCurrentLocation(), "China", 11, 14.52, 3.52, 70400, a47); 
		flights[47].setFlight(a48.getCurrentLocation(), "Qatar", 14, 17.20, 3.20, 64000, a48);
		flights[48].setFlight(a49.getCurrentLocation(), "Islamabad North", 13, 13.16, .16, 1600, a49);
		flights[49].setFlight(a50.getCurrentLocation(), "Dubai", 19, 21.48, 2.48, 49600, a50);
	}
	FlightSchedules(Flight* f, int fl)
	{
		flights = f;
		n_flight = fl;
	}
	void setN_FLights(int n)
	{
		n_flight = n;
	}
	int getN_Flights()const
	{
		return n_flight;
	}
	void addFlight()    // A function to add flights
	{
		Flight t;
		string airplaneID, origin, destination, interorlocal ,type;
		float departure, flight_time, arrival_time;
		double cost;
		cout << "Enter airplane ID: ";
		cin.ignore();
		getline(cin, airplaneID);
		bool chek = false;
		bool chek2 = false;
		for (int i = 0; i < n_flight; i++)
		{
			if (flights[i].getPlane().getPlaneID() == airplaneID)
			{
				chek = true;
				chek2 = true;
				cout << "This airplane is already assigned to a flight!" << endl;
			}
		}
		if (chek == false && (airplaneID == "0001" || airplaneID == "0002" || airplaneID == "0003" || airplaneID == "0021" || airplaneID == "0004" || airplaneID == "0005" || airplaneID == "0006" || airplaneID == "0007" || airplaneID == "0008" || airplaneID == "0009" || airplaneID == "0010" || airplaneID == "0011" || airplaneID == "0012" || airplaneID == "0013" || airplaneID == "0014" || airplaneID == "0015" || airplaneID == "0016" || airplaneID == "0017" || airplaneID == "0018" || airplaneID == "0019" || airplaneID == "0020" || airplaneID == "0022" || airplaneID == "0023" || airplaneID == "0024" || airplaneID == "0025" || airplaneID == "0026" || airplaneID == "0027" || airplaneID == "0028" || airplaneID == "0029" || airplaneID == "0030" || airplaneID == "0031" || airplaneID == "0032" || airplaneID == "0033" || airplaneID == "0034" || airplaneID == "0035" || airplaneID == "0036" || airplaneID == "0037" || airplaneID == "0038" || airplaneID == "0039" || airplaneID == "0040" || airplaneID == "0041" || airplaneID == "0042" || airplaneID == "0043" || airplaneID == "0044" || airplaneID == "0045" || airplaneID == "0046" || airplaneID == "0048" || airplaneID == "0049" || airplaneID == "0050"))
		{
			string choice;
			cout << "1. Add Local flight" << endl;
			cout << "2. Add International flight" << endl;
			cin >> choice;
			if (choice == "1")
				interorlocal = "Locally";
			else
				interorlocal = "Internationally";
			cout << "1. Business class" << endl;
			cout << "2. Economy class" << endl;
			cin >> choice;
			if (choice == "1")
				type = "Business";
			else
				type = "Economy";

			cout << "Enter the origin: ";
			cin.ignore();
			getline(cin, origin);
			cout << "Enter the destination: ";
			getline(cin, destination);
			cout << "Enter departure time: ";
			cin >> departure;
			cout << "Enter Flight duration: ";
			cin >> flight_time;
			if (interorlocal == "Locally")
				cost = 10000 * flight_time;
			else
				cost = 20000 * flight_time;
			arrival_time = departure + flight_time;
			Airplane q(airplaneID, origin, type, interorlocal);
			t.setFlight(q.getCurrentLocation(), destination, departure, arrival_time, flight_time, cost, q);
			n_flight++;
			Flight* temp = new Flight[n_flight - 1];
			for (int i = 0; i < (n_flight - 1); i++)
				temp[i] = flights[i];
			flights = new Flight[n_flight];
			for (int i = 0; i < n_flight - 1; i++)
				flights[i] = temp[i];
			delete[]temp;
			temp = NULL;
			flights[n_flight - 1] = t;
			cout << "The flight has been added successfully" << endl;
		}
		else if (chek2 == false)
		{
			cout << "NAFS has not an airplane which ID is " << airplaneID << endl;
		}
	}


	Flight getFlight(int i)
	{
		return flights[i];
	}


	void apply_coronarestrictions()  // Appling for corona restrictions
	{
		int count = 1;
		for (int j = 0; j < n_flight; j++)
		{
			for (int i = 0; i < flights[j].getPlane().getSeatingCapacity(); i++)
			{
				if (count % 2 == 0)
					flights[j].available_seats[i] = 99;
				count++;
			}
		}
	}


	void search_flight()
	{
		string d;
		cout << "Destination: ";
		cin.ignore();
		getline(cin, d);
		system("CLS");
		cout << "Airplane ID" << "\t" << "Origin" << "\t\t\t" << "Destination" << "\t\t" << "Class" << "\t   " << "Departure Time" << "   " << "Arrival Time" << "   " << "Flight Duration" << "  " << "Fair" << endl;
		cout << "_____________________________________________________________________________________________________________________________________" << endl;
		for (int i = 0; i < n_flight; i++)
		{
			if (flights[i].getDestination() == d && flights[i].getAvailbility() == true && flights[i].getBan() == false)
			{
				int hour;
				string m;
				float min;
				cout << flights[i].getPlane().getPlaneID() << "\t\t" <<
					flights[i].getOrigin();
				print_spaces(24, flights[i].getOrigin().length());  // Printing spaces
				cout << flights[i].getDestination();
				print_spaces(24, flights[i].getDestination().length());  // printing spaces
				cout << flights[i].getPlane().getType();
				print_spaces(11, flights[i].getPlane().getType().length());  // printing spaces
				hour = flights[i].getDepartureTime();
				min = flights[i].getDepartureTime() - hour;
				m = to_string(min);
				if (hour < 10)
					cout << "0";
				cout << hour << ":";
				cout << m[2] << m[3];
				print_spaces(17, 5);   // printing spaces
				hour = flights[i].getArrivalTime();
				min = flights[i].getArrivalTime() - hour;
				m = to_string(min);
				if (hour < 10)
					cout << "0";
				cout << hour << ":";
				cout << m[2] << m[3];
				print_spaces(15, 5);   // printing spaces
				hour = flights[i].getFlightDuration();
				min = flights[i].getFlightDuration() - hour;
				m = to_string(min);
				if (hour < 10)
					cout << "0";
				cout << hour << ":";
				cout << m[2] << m[3];
				print_spaces(17, 5);   // printing spaces
				cout << flights[i].getFair() << endl;

			}
		}
		cout << "_____________________________________________________________________________________________________________________________________" << endl;
	}


	void updateFlightScheldule()    // A function for updating the flights after reaching at destination
	{
		float time;
		float min=getMinute();
		float hour=getHour();
		if (getMinute() >= 0 && getMinute() <= 9)
			min = min / 10;
		else
			min = min / 100;
		time = hour + min;
		float new_time;
		for (int i = 0; i < n_flight; i++) // Automatically updating schedule of all flights
		{
			if (time >= flights[i].getArrivalTime() && flights[i].getPlane().getLocallyorInternationally() == "Locally")
			{
				
				new_time = flights[i].getArrivalTime() + 2;  // Setting departure time after two hours
				if (new_time >= 24)  
					new_time -= 24;
					// Swapping destination and arrival and departure times after 2 hours
					string temp = flights[i].getOrigin();
					flights[i].setOrigin(flights[i].getDestination());
					flights[i].setDestination(temp);
					flights[i].setDepartureTime(new_time);
					
					float estimated_time = flights[i].getFlightDuration();
					new_time += estimated_time;
					if (new_time >= 24)
						new_time -= 24;
					int h = new_time;
					float m = new_time - h;
					if (m > 0.59)
					{
						h++;
						m -= 0.59 + 0.01;
					}
					new_time = h + m;
				
					flights[i].setArrivalTime(new_time);
			}
			else
			{
				if (time > (flights[i].getArrivalTime() + flights[i].getFlightDuration()))
				{
						string temp;
						temp = flights[i].getDestination();
						flights[i].setDestination(flights[i].getOrigin());
						flights[i].setOrigin(temp);
				}
			}
		}
	}

	

	void cancelflight()
	{
		string id;
		cout << "Enter airplane id: ";
		cin >> id;
		bool chek = false;
		for (int i = 0; i < n_flight; i++)
		{
			if (flights[i].getPlane().getPlaneID() == id)
			{
				chek = true;
				flights[i] = flights[n_flight - 1];
				n_flight--;
				cout << "Successfully canceled the flight" << endl;
			}
			
		}
		if (chek == false)
			cout << "Airplane id doesn't found in flight schedule" << endl;
	}



	void showLocalAvailableFlights()
	{
		cout << "Airplane ID" << "\t" << "Origin" << "\t\t\t" << "Destination" << "\t\t" << "Class" << "\t   " << "Departure Time" << "   " << "Arrival Time" << "   " << "Flight Duration" << "  " << "Fair" << endl;
		cout << "_____________________________________________________________________________________________________________________________________" << endl;
		for (int i = 0; i < n_flight; i++)
		{
			if (flights[i].getPlane().getLocallyorInternationally() == "Locally" && flights[i].getAvailbility() == true && flights[i].getBan() == false)
			{
				int hour;
				string m;
				float min;
				cout << flights[i].getPlane().getPlaneID() << "\t\t" <<
					flights[i].getOrigin();
				print_spaces(24, flights[i].getOrigin().length());  // Printing spaces
				cout << flights[i].getDestination();
				print_spaces(24, flights[i].getDestination().length());  // printing spaces
				cout << flights[i].getPlane().getType();
				print_spaces(11, flights[i].getPlane().getType().length());  // printing spaces
				hour = flights[i].getDepartureTime();
				min = flights[i].getDepartureTime() - hour;
				m = to_string(min);
				if (hour < 10)
					cout << "0";
				cout << hour << ":";
				cout << m[2] << m[3];
				print_spaces(17, 5);   // printing spaces
				hour = flights[i].getArrivalTime();
				min = flights[i].getArrivalTime() - hour;
				m = to_string(min);
				if (hour < 10)
					cout << "0";
				cout << hour << ":";
				cout << m[2] << m[3];
				print_spaces(15, 5);   // printing spaces
				hour = flights[i].getFlightDuration();
				min = flights[i].getFlightDuration() - hour;
				m = to_string(min);
				if (hour < 10)
					cout << "0";
				cout << hour << ":";
				cout << m[2] << m[3];
				print_spaces(17, 5);   // printing spaces
				cout << flights[i].getFair() << endl;

			}
		}
		cout << "_____________________________________________________________________________________________________________________________________" << endl;


	}

	void showInternationalAvailableFlight()  // 
	{
		cout << "Airplane ID" << "\t" << "Origin" << "\t\t\t" << "Destination" << "\t\t" << "Class" << "\t   " << "Departure Time" << "   " << "Arrival Time" << "   " << "Flight Duration" << "  " << "Fair" << endl;
		cout << "_____________________________________________________________________________________________________________________________________" << endl;
		for (int i = 0; i < n_flight; i++)
		{
			if (flights[i].getPlane().getLocallyorInternationally() == "Internationally" && flights[i].getAvailbility() == true && flights[i].getBan() == false)
			{
				int hour;
				string m;
				float min;
				cout << flights[i].getPlane().getPlaneID() << "\t\t" <<
					flights[i].getOrigin();
				print_spaces(24, flights[i].getOrigin().length());  // Printing spaces
				cout << flights[i].getDestination();
				print_spaces(24, flights[i].getDestination().length());  // printing spaces
				cout << flights[i].getPlane().getType();
				print_spaces(11, flights[i].getPlane().getType().length());  // printing spaces
				hour = flights[i].getDepartureTime();
				min = flights[i].getDepartureTime() - hour;
				m = to_string(min);
				if (hour < 10)
					cout << "0";
				cout << hour << ":";
				cout << m[2] << m[3];
				print_spaces(17, 5);   // printing spaces
				hour = flights[i].getArrivalTime();
				min = flights[i].getArrivalTime() - hour;
				m = to_string(min);
				if (hour < 10)
					cout << "0";
				cout << hour << ":";
				cout << m[2] << m[3];
				print_spaces(15, 5);   // printing spaces
				hour = flights[i].getFlightDuration();
				min = flights[i].getFlightDuration() - hour;
				m = to_string(min);
				if (hour < 10)
					cout << "0";
				cout << hour << ":";
				cout << m[2] << m[3];
				print_spaces(17, 5);   // printing spaces
				cout << flights[i].getFair() << endl;

			}
		}
		cout << "_____________________________________________________________________________________________________________________________________" << endl;

	}




	void booking(User& passenger, Sales& sales)
	{
		string a;
		cout << "Enter the airplane id: ";
		cin >> a;
		int n;
		bool chek = false;
		for (int i = 0; i < n_flight; i++)
		{
			if (flights[i].getPlane().getPlaneID() == a)
			{
				chek = true;
				cout << "(0) are occupied seats" << endl;
				cout << "(99) are blocked seats due to corona" << endl << endl;
				flights[i].AvailableSeats();
				cout << endl;
				cout << "Fair: " << flights[i].getFair() << endl;
				cout << "Your balance: " << passenger.getBalance() << endl;
				cout << "Enter the seat-number: ";
				cin >> n;
				bool chek2 = false;
				for (int j = 0; j < flights[i].getPlane().getSeatingCapacity(); j++)
				{
					if (flights[i].available_seats[j] == n && flights[i].available_seats[j] != 99 && flights[i].available_seats[j] != 0)
					{
						if (flights[i].getPlane().getLocallyorInternationally() == "Internationally" && passenger.getPassport().getVisaStatus() == false)
						{
							cout << "You cannot book an International flight because you don't have visa issued on your passport!" << endl;
							chek2 = true;
							break;
						}
						if (passenger.getBalance() >= flights[i].getFair())
						{
							passenger.setBalance(passenger.getBalance() - flights[i].getFair());
							chek2 = true;
							flights[i].available_seats[j] = 0;
							system("CLS");
							cout << "(0) are occupied seats" << endl;
							cout << "(99) are blocked seats dur to corona" << endl << endl;
							flights[i].AvailableSeats() ;
							cout << endl;
							cout << "Your balance: " << passenger.getBalance();
							cout << endl;
							double tax;
							if (flights[i].getPlane().getLocallyorInternationally() == "Internationally")
								tax = (10 * flights[i].getFair()) / 100;
							else
								tax = (5 * flights[i].getFair()) / 100;
							sales.setSales(flights[i].getFair() - tax);
							cout << "Successfully booked the seat!" << endl;
						}
						else
						{
							chek2 = true;
							cout << "You don't have enough balance to purchase the seat!" << endl;
						}
					}
				}
				if (chek2 == false)
					cout << "You entered the unavailable choice!" << endl;
			}

		}
		if (chek == false)
			cout << "Airplane id doesn't found!" << endl;
	}

	void cancel_booking(User& s, Sales& sales)
	{
		string airplaneID;
		cout << "Enter airplane id: ";
		cin >> airplaneID;
		if ((airplaneID == "0001" || airplaneID == "0002" || airplaneID == "0003" || airplaneID == "0021" || airplaneID == "0004" || airplaneID == "0005" || airplaneID == "0006" || airplaneID == "0007" || airplaneID == "0008" || airplaneID == "0009" || airplaneID == "0010" || airplaneID == "0011" || airplaneID == "0012" || airplaneID == "0013" || airplaneID == "0014" || airplaneID == "0015" || airplaneID == "0016" || airplaneID == "0017" || airplaneID == "0018" || airplaneID == "0019" || airplaneID == "0020" || airplaneID == "0022" || airplaneID == "0023" || airplaneID == "0024" || airplaneID == "0025" || airplaneID == "0026" || airplaneID == "0027" || airplaneID == "0028" || airplaneID == "0029" || airplaneID == "0030" || airplaneID == "0031" || airplaneID == "0032" || airplaneID == "0033" || airplaneID == "0034" || airplaneID == "0035" || airplaneID == "0036" || airplaneID == "0037" || airplaneID == "0038" || airplaneID == "0039" || airplaneID == "0040" || airplaneID == "0041" || airplaneID == "0042" || airplaneID == "0043" || airplaneID == "0044" || airplaneID == "0045" || airplaneID == "0046" || airplaneID == "0048" || airplaneID == "0049" || airplaneID == "0050"))
		{
			for (int i = 0; i < n_flight; i++)
			{
				if (flights[i].getPlane().getPlaneID() == airplaneID)
				{
					double cost = 0;
					cost = (25 * flights[i].getFair()) / 100;
					cost = flights[i].getFair() - cost;
					s.setBalance(s.getBalance() + cost);
					cout << cost << " has been added to your balance" << endl;
					cout << "Your current balance is: " << s.getBalance() << endl;
					sales.setSales(-1 * cost);
				}
			}
		}
		else
		{
			cout << "Flight doesn't foound!" << endl;
		}
	}


	void ban()
	{
		string name;
		cout << "Enter the name of the country: ";
		cin.ignore();
		getline(cin, name);
		bool chek = false;
		for (int i = 0; i < n_flight; i++)
		{
			if (flights[i].getDestination() == name || flights[i].getOrigin() == name)
			{
				chek = true;
				flights[i].setBan(true);
			}
		}
		if (chek == false)
			cout << "Country name didn't found!" << endl;
		else
			cout << "Successfully banned flights to " << name << " !" << endl;
	}



};

//_________________________________________________________________________________________________________________








//_________________________________________________________________________________________________________________


struct NAFS
{
	Sales sales;
	Login l;
	FlightSchedules f;
};







//_________________________________________________________________________________________________________________
