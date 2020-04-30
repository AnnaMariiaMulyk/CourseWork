#include "Functions.h"

#include <fstream>
#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

int size = 10;//треба щоб розмір масиву з логінами і паролями вводився з клави але дееее
string filenameFlights = "flights.txt"; //файл з авіарейсами
string filenameAdminsSignIn = "AdminsSignIn.txt"; //файл з логінами і паролями адмінів
string filenameUsersSignIn = "UsersSignIn.txt"; //файл з логінами і паролями користувачів
list <user> users; //список з користувачами (при реєстрації вноситься інф)
list <admin> admins;
list<flight> allFlights;
//ФУНКЦІЇ АДМІНА

void init()
{
	ifstream fin;
	fin.open(filenameUsersSignIn);
	bool isOpen = fin.is_open();
	if (isOpen == true)
	{
		
		user oldUser;
		while (!fin.eof())
		{
			getline(fin, oldUser.login);
			getline(fin, oldUser.password);
			fin >> oldUser.money;
			getline(fin, oldUser.email);
			fin >> oldUser.countFlights;

			if (oldUser.countFlights >= 1)
			{
				
				oldUser.myFlights = new flight[oldUser.countFlights];
				for (int i = 0; i < oldUser.countFlights; i++)
				{
					getline(fin, oldUser.myFlights[i].name);
					getline(fin, oldUser.myFlights[i].company);
					fin >> oldUser.myFlights[i].departure.hour;
					fin >> oldUser.myFlights[i].departure.minute;
					fin >> oldUser.myFlights[i].departure.day;
					fin >> oldUser.myFlights[i].departure.month;
					fin >> oldUser.myFlights[i].departure.year;

					fin >> oldUser.myFlights[i].arrive.hour;
					fin >> oldUser.myFlights[i].arrive.minute;
					fin >> oldUser.myFlights[i].arrive.day;
					fin >> oldUser.myFlights[i].arrive.month;
					fin >> oldUser.myFlights[i].arrive.year;

					fin >> oldUser.myFlights[i].countTickets;
					for (int j = 0; j < oldUser.myFlights[i].countTickets; j++)
					{
						getline(fin, oldUser.myFlights[i].tickets[j].ticketClass);
						fin >> oldUser.myFlights[i].tickets[j].value;
						fin >> oldUser.myFlights[i].tickets[j].possibleToReturn;
						
					}
					fin >> oldUser.myFlights[i].countConnectionFlights;
					oldUser.myFlights[i].ConnectionFlights = new connectionFlight[oldUser.myFlights[i].countConnectionFlights];
					for (int j = 0; j < oldUser.myFlights[i].countConnectionFlights; j++)
					{
						getline(fin, oldUser.myFlights[i].ConnectionFlights[j].connectionFlightCity);
						fin >> oldUser.myFlights[i].ConnectionFlights[j].connectionFlightTime;
					}
					getline(fin, oldUser.myFlights[i].departureCity);
					getline(fin, oldUser.myFlights[i].arrivalCity);
					
					
				}
			}
			
			users.push_back(oldUser);
			oldUser = user();
		}
	}
	else
	{
		cout << "Error: can not open file!" << endl;
	}
	fin.close();

	fin.open(filenameAdminsSignIn);
	isOpen = fin.is_open();
	if (isOpen == true)
	{
		admin oldAdmin;
		while (!fin.eof())
		{
			getline(fin, oldAdmin.login);
			getline(fin, oldAdmin.password);
			getline(fin, oldAdmin.company);
			admins.push_back(oldAdmin);
			oldAdmin = admin();
		}
	}
	else
	{
		cout << "Error: can not open file!" << endl;
	}
	fin.close();

	fin.open(filenameFlights);
	isOpen = fin.is_open();
	if (isOpen == true)
	{
		flight oldFlight;
		string temp;

		while (!fin.eof())
		{
			getline(fin, oldFlight.name);
			getline(fin, oldFlight.company);
			fin >> oldFlight.departure.hour;
			fin >> oldFlight.departure.minute;
			fin >> oldFlight.departure.day;
			fin >> oldFlight.departure.month;
			fin >> oldFlight.departure.year;

			fin >> oldFlight.arrive.hour;
			fin >> oldFlight.arrive.minute;
			fin >> oldFlight.arrive.day;
			fin >> oldFlight.arrive.month;
			fin >> oldFlight.arrive.year;

			fin >> oldFlight.allTicketsAviable; //Окей Кароче як я понімаюбілетів для цього рейсу, но воно зчитує мусор і тому в тебе потім там не може виділитись память 
			fin >> oldFlight.ticketsAviableEconomClass;
			fin >> oldFlight.ticketsAviableFirstClass;
			oldFlight.tickets = new ticket[oldFlight.allTicketsAviable];
			for (int i = 0; i < oldFlight.allTicketsAviable; i++)
			{
				fin >> temp;
				oldFlight.tickets[i].ticketClass = temp;
				fin >> oldFlight.tickets[i].value;
				fin >> oldFlight.tickets[i].possibleToReturn;
			}
			fin >> oldFlight.countConnectionFlights;
			oldFlight.ConnectionFlights = new connectionFlight[oldFlight.countConnectionFlights];
			for (int i = 0; i < oldFlight.countConnectionFlights; i++)
			{
				fin >> oldFlight.ConnectionFlights[i].connectionFlightCity;
				fin >> oldFlight.ConnectionFlights[i].connectionFlightTime;
			}
			fin >> temp;
			oldFlight.departureCity = temp;
			fin >> temp;
			oldFlight.arrivalCity = temp;

			allFlights.push_back(oldFlight);
			oldFlight = flight();
		}
	}
	else
	{
		cout << "Error: can not open file!" << endl;
	}
}

void rewriteUsersFile()
{
	ofstream fout;
	fout.open(filenameUsersSignIn);
	bool isOpen = fout.is_open();
	if (isOpen == true)
	{
		for (user item : users)
		{
			fout << item.login << endl;
			fout << item.password << endl;
			fout << item.money << endl;
			fout << item.email << endl;
			fout << item.countFlights << endl;
			if (item.countFlights >= 1)
			{
				for (int i = 0; i < item.countFlights; i++)
				{
					fout << item.myFlights[i].name << endl;
					fout << item.myFlights[i].company << endl;
					fout << item.myFlights[i].departure.hour << endl;
					fout << item.myFlights[i].departure.minute << endl;
					fout << item.myFlights[i].departure.day << endl;
					fout << item.myFlights[i].departure.month << endl;
					fout << item.myFlights[i].departure.year << endl;
					fout << item.myFlights[i].arrive.hour << endl;
					fout << item.myFlights[i].arrive.minute << endl;
					fout << item.myFlights[i].arrive.day << endl;
					fout << item.myFlights[i].arrive.month << endl;
					fout << item.myFlights[i].arrive.year << endl;
					fout << item.myFlights[i].countTickets << endl;
					for (int j = 0; j < item.myFlights[i].countTickets; i++)
					{
						fout << item.myFlights[i].tickets[j].ticketClass << endl;
						fout << item.myFlights[i].tickets[j].value << endl;
						fout << item.myFlights[i].tickets[j].possibleToReturn << endl;
					}
					fout << item.myFlights[i].countConnectionFlights << endl;
					if (item.myFlights[i].countConnectionFlights >= 1)
					{
						for (int j = 0; j < item.myFlights[i].countConnectionFlights; i++)
						{
							fout << item.myFlights[i].ConnectionFlights[j].connectionFlightCity << endl;
							fout << item.myFlights[i].ConnectionFlights[j].connectionFlightTime << endl;
						}
					}
					fout << item.myFlights[i].departureCity << endl;
					fout << item.myFlights[i].arrivalCity << endl;

				}
			}
		}
	}
	else
	{
		cout << "Error in file system" << endl;
	}
	fout.close();
}

auto delete_list_elem(list<user>& list1, int k) // <--- Тут & появился
{
	list<int>::iterator it = list1.begin();
	std::advance(it, k); // <-- advance итерирует переданный итератор на k позиций
	if (it != list1.end())
	{
		return list1.erase(it); // <--- Вернет итератор на k+1 элемент, перед it нет *
	}
	return it; // k больше размера списка, дефакто равет end()
}


void editFlights() //для адміна
{

}
//ФУНКЦІЇ КОРИСТУВАЧА
void searchFlight(user myUser)
{
	string departure;
	string destination;
	int dayDep;
	int monthDep;
	int yearDep;
	int dayArriv;
	int monthArriv;
	int yearArriv;
	cout << "\tSEARCH FLIGHTS" << endl;
	cout << "Departure: ";
	cin.ignore();
	getline(cin, departure);
	cout << "\tDestination: ";
	getline(cin, destination);
	cout << endl;
	cout << "Date of departure: ";
	cin >> dayDep >> monthDep >> yearDep;
	cout << "\tDate of arrivial: ";
	cin >> dayArriv >> monthArriv >> yearArriv;
	//було б не погано вибирати ці дати графічно, щоб виводився календар і кліком вибираєш дату
	ofstream fin;
	fin.open(filenameFlights);
	bool isOpen = fin.is_open();
	if (isOpen == true)
	{

	}
	else
	{
		cout << "Not found!" << endl;
	}

}

void showMyFlights(user myUser)
{
	cout << "My flights" << endl;
	myUser.myFlights = new flight[myUser.countFlights];
	for (int i = 0; i < myUser.countFlights; i++)
	{
		cout << "Name of flight: " << myUser.myFlights[i].name << endl;
		cout << "Company: " << myUser.myFlights[i].company << endl;
		cout << "Tickets" << endl;
		for (int j = 0; j < myUser.myFlights[i].countTickets; j++)
		{
			cout << myUser.myFlights[i].tickets[j].ticketClass << endl;
			cout << myUser.myFlights[i].tickets[j].value << endl;
			cout << myUser.myFlights[i].tickets[j].possibleToReturn << endl;
		}
			cout << "Departure: " << myUser.myFlights[i].departureCity << endl;
			cout << "Time of departure: " << myUser.myFlights[i].departure.hour << ":" << myUser.myFlights[i].departure.minute << endl;
			cout << "Date of departure: " << myUser.myFlights[i].departure.day << "\/" << myUser.myFlights[i].departure.month << "\/" << myUser.myFlights[i].departure.year << endl;
			cout << "Arrival: " << myUser.myFlights[i].arrivalCity << endl;
			cout << "Time of arrival: " << myUser.myFlights[i].arrive.hour << ":" << myUser.myFlights[i].arrive.minute << endl;
			cout << "Date of arrival: " << myUser.myFlights[i].arrive.day << "\/" << myUser.myFlights->arrive.month << "\/" << myUser.myFlights->arrive.year << endl;
			for (int k = 0; k < myUser.myFlights[i].countConnectionFlights; k++)
			{
				cout << myUser.myFlights[i].ConnectionFlights[k].connectionFlightCity << endl;
				cout << myUser.myFlights[i].ConnectionFlights[k].connectionFlightTime << endl;
			}
	}

	string choiseDelete;
	cout << "Do you want ot delete any of your tickets?(yes/no)" << endl;
	cin >> choiseDelete;
	if (choiseDelete == "yes")
	{
		string tempName;
		cout << "Enter name of flight to delete ticket: ";
		cin >> tempName;
		for (user item : users)
		{
			if (item.login == myUser.login)
			{
				int count = 0;
				for (int i = 0; i < item.countFlights; i++)
				{
					if (item.myFlights[i].name == tempName)
					{
						for (int j = 0; j < item.myFlights[i].countTickets; j++)
						{
							cout << j + 1 << ":" << endl;
							cout << "\t" << item.myFlights[i].tickets[j].ticketClass << endl;
							cout << "\t" << item.myFlights[i].tickets[j].value << endl;
							cout << "\t" << item.myFlights[i].tickets[j].possibleToReturn << endl;
						}
						int number;
						do {
							cout << "Enter number of ticket to delete: ";
							cin >> number;
							if (number >= 0 && number < item.myFlights[i].countTickets)
							{
								for (int j = 0; j < item.myFlights[i].countTickets; j++)
								{
									if (item.myFlights[i].tickets[number].ticketClass == item.myFlights[i].tickets[j].ticketClass)
									{
										for (int j = i; j < (item.countFlights - 1); j++)
										{
											if (item.myFlights[i].tickets[j].possibleToReturn == 1 || item.myFlights[i].tickets[j].possibleToReturn == true)
											{
												item.money += item.myFlights[i].tickets[j].value;
												cout << "You got your money back" << endl;
											}
											else
											{
												cout << "You wasted " << item.myFlights[i].tickets[j].value << "\$ for nothing (x ^ x)" << endl;
											}
											item.myFlights[i].tickets[j] = item.myFlights[i].tickets[j + 1];
											item.myFlights[i].countTickets -= 1;
											if (item.myFlights[i].countTickets <= 0)
											{

											}
										}
										count++;
										break;
									}
							
								}
							}
						} while (number < 0 && number >= item.myFlights[i].countTickets);
								
					}
				}
				if (count == 0)
				{
					cout << "Can not find flight with this name \(T ^ T\)" << endl;
				}
				else
				{
					rewriteUsersFile();
					cout << "Ticket succesfuly deleted!" << endl;
				}
			}
		}
	}
	else
	{
		cout << "Okay!" << endl;
	}
}

//void myProfile(string filename)
//{
//	int currentstring = 0;
//	string data;
//	string data2;
//	int choisepasswd; //щоб запитати в користувача чи він хоче змінити пароль
//	ofstream fout;
//	ifstream fin;
//	fin.open(filename);
//	bool isOpen = fin.is_open();
//	if (isOpen == true)
//	{
//		while (!fin.eof())
//		{
//			currentstring++;
//			if (currentstring == 1)
//			{
//				data = "";
//				getline(fin, data);
//				cout << "Login: " << data << endl;
//			}
//			else if (currentstring == 2)
//			{
//				data2 = "";
//				getline(fin, data2);
//				cout << "Password: **********" << endl;
//				cout << "Do you want to change it?" << endl;
//				cout << "1. Yes" << endl;
//				cout << "2. No" << endl;
//				cin >> choisepasswd;
//				switch (choisepasswd)
//				{
//				case 1:
//					fout.open(filename);
//					bool isOpen1 = fout.is_open();
//					if (isOpen1 == true)
//					{
//						string temppasswd;
//						string temppasswd2;
//						cout << "Enter new password: ";
//						cin >> temppasswd;
//						cout << "Confirm password: ";
//						cin >> temppasswd2;
//						if (temppasswd == temppasswd2)
//						{
//							fout << temppasswd << endl;
//							for (int i = 0; i < 10; i++)//придумати шось з розміром масиву
//							{
//								if (users[i].password == data2)
//								{
//									users[i].password = temppasswd;
//								}
//								else
//								{
//									cout << "ERROR" << endl;
//								}
//							}
//						}
//						else
//						{
//							cout << "Passwords don`t match" << endl;
//						}
//					}
//					else
//					{
//						cout << "ERROR!" << endl;
//					}
//					fout.close();
//					break;
//				case 2:
//					break;
//				default:
//					break;
//				}
//			}
//		}
//	}
//	else
//	{
//		cout << "Can not open your profile!" << endl;
//	}
//	fin.close();
//}

void signIn()
{
	int choise;
	user tempUser;
	string data;
	bool login = false;
	int choisepasswd; //щоб запитати в користувача чи він хоче змінити пароль
	do
	{

	cout << "\tSIGN IN" << endl;
	cout << "Sign in as:" << endl;
	cout << "1. User" << endl;
	cout << "2. Admin" << endl;
	cout << "3. Exit" << endl;
	cout << endl;
	cout << "How to sign in?" << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
	{
		cout << "Username: ";
		cin.ignore();
		getline(cin, tempUser.login);
		cout << endl;
		cout << "Password: ";
		cin >> tempUser.password;
		
			for(user item: users)
			{
				if (item.login == tempUser.login && item.password == tempUser.password)
				{
					login = true;
				}
			}
		
		if (login == true)
		{
			for (user item : users)
			{
				if (tempUser.login == item.login)
				{
					tempUser = item;
				}
			}
			int choiseMenu = 0;
			do
			{
				cout << "MENU" << endl;
				cout << "1. My profile" << endl;
				cout << "2. My flights" << endl;
				cout << "3. My money balance" << endl;
				cout << "4. Notifications" << endl;
				cout << "5. Search flight" << endl;
				cout << "6. Delete account" << endl;
				cout << "7. Sign out" << endl;
				cout << endl;
				cout << "Enter action: ";
				cin >> choiseMenu;
				string tempPasswd = "";
				switch (choiseMenu)
				{
				case 1:
				
					cout << "Login: " << tempUser.login << endl;
					cout << "Password: ********" << endl;
					cout << "Do you want to change it?" << endl;
					cout << "1. Yes" << endl;
					cout << "2. No" << endl;
					cin >> choisepasswd;
					//знизу правильно
					if (choisepasswd == 1)
					{
						string temppasswd;
						string temppasswd2;
						do
						{
							cout << "Enter new password: ";
							cin >> temppasswd;
							cout << "Confirm password: ";
							cin >> temppasswd2;
							if (temppasswd == temppasswd2)
							{
								for (user item : users)
								{
									if (item.password == tempUser.password)
									{
										item.password = temppasswd;
										rewriteUsersFile();
									}
								}
							}
							else
							{
								cout << "Passwords don`t match" << endl;
							}

						} while (temppasswd != temppasswd2);
					}
					else
					{
						cout << "Okay!" << endl;
					}
					//зверху правильно
					break;
				case 2:
					showMyFlights(tempUser);
					break;
				case 3:
				{
					cout << "MONEY BALANCE" << endl;
					for (user item : users)
					{
						if (item.login == tempUser.login)
						{
							string moneychoise;
							do {
								cout << "Money: " << item.money << endl;
								cout << "Do you want to add money?" << endl;
								cout << "Enter yes or no: ";
								cin >> moneychoise;
								if (moneychoise == "yes")
								{
									float moneyAdd;
									cout << "Enter money add: ";
									cin >> moneyAdd;
									item.money += moneyAdd;
									rewriteUsersFile();
								}
							} while (moneychoise != "no");
						}
					}
					break;
				}
				case 4:

					break;
				case 5:
					break;
				case 6:
					cout << "Enter password to delete account: ";
					cin >> tempPasswd;
					if (tempPasswd == tempUser.password)
					{
						for (user item: users) 
						{
							if (item.login == tempUser.login)
							{
								string finalChoise;
								cout << "Are you sure that you want to delete your account? (yes/no)" << endl;
								cin >> finalChoise;
								if (finalChoise == "yes")
								{
									//users.remove(item);
									//видалити з файлу!!!
								}
								else
								{
									cout << "Okay!" << endl;
								}
							}
							else
							{
								cout << "Error: can not find your account in file system" << endl;
							}
						}
					}
					else
					{
						cout << "Wrong password!" << endl;
					}
					break;
				case 7:
					cout << "BYE!" << endl;
					break;
				default:
					break;
				}//свіч вибір пункта меню профіль чи мої рейси і тд
			} while (choiseMenu != 6);
			
		} //тут має бути іф логін тру
		else
		{
			cout << "Cant not find user with this login or password" << endl;
		}
		break;
	}
	case 2:
	{
		break;
	}
	default:
		break;
	}
	}while (choise != 3);
}
//СПІЛЬНІ ФУНКЦІЇ
void signUp()
{
	string temppasswd;
	string temppasswd2;
	int choise;
	user tempUser;
	admin tempAdmin;
	cout << "Sign in as: ";
	cout << "1. User" << endl;
	cout << "2. Admin" << endl;
	cout << endl;
	cout << "Enter how to sing up: ";
	cin >> choise;
	switch (choise)
	{
		case 1:
			cout << "Enter login: ";
			cin >> tempUser.login;
			cout << "Enter password: ";
			cin >> temppasswd;
			cout << "Confirm password: ";
			cin >> temppasswd2;
			if (temppasswd == temppasswd2)
			{
				ifstream fin;
				fin.open(filenameUsersSignIn);
				bool isOpen = fin.is_open();
				if (isOpen == true)
				{
					string data;
					while (!fin.eof())
					{
						getline(fin, data);
						if (data == tempUser.login)
						{
							cout << "User with this login is already exist!" << endl;
						}
						else
						{
							tempUser.password = temppasswd;
							users.push_back(tempUser); 
							ofstream fout;
							fout.open(filenameUsersSignIn, fstream::app);
							bool isOpen1 = fout.is_open();
							if (isOpen1 == true)
							{
								fout << tempUser.login << endl;
								fout << tempUser.password << endl;
	     						cout << "Sign in is succesful" << endl; 
							}
							else
							{
								cout << "Error: can not open file!" << endl;
							}
							fout.close();
							
						}
					}
					
				}
				else
				{
					cout << "Error: can not open file!" << endl;
				}
				fin.close();
			}
			else
			{
				cout << "Password don`t match" << endl;
			}
			break;
		case 2:
			cout << "Enter login: ";
			cin >> tempAdmin.login;
			cout << "Enter password: ";
			cin >> temppasswd;
			cout << "Confirm password: ";
			cin >> temppasswd2;
			if (temppasswd == temppasswd2)
			{
				ifstream fin;
				fin.open(filenameAdminsSignIn);
				bool isOpen = fin.is_open();
				if (isOpen == true)
				{
					string data;
					while (!fin.eof())
					{
						getline(fin, data);
						if (data == tempAdmin.login)
						{
							cout << "Admin with this login is already exist!" << endl;
						}
						else
						{
							tempUser.password = temppasswd;
							admins.push_back(tempAdmin);
							ofstream fout;
							fout.open(filenameAdminsSignIn, fstream::app);
							bool isOpen1 = fout.is_open();
							if (isOpen1 == true)
							{
								fout << tempAdmin.login << endl;
								fout << tempAdmin.password << endl;
							}
							else
							{
								cout << "Error: can not open file!" << endl;
							}
							fout.close();
						}
					}
				}
				else
				{
					cout << "Error: can not open file!" << endl;
				}
			}
			else
			{
				cout << "Password don`t match" << endl;
			}

	default:
		break;
	}
}
