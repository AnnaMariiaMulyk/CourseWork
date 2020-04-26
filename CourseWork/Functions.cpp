#include "Functions.h"

#include <fstream>
#include <string>
#include <iostream>
#include <list>
using namespace std;

int size = 10;//треба щоб розмір масиву з логінами і паролями вводився з клави але дееее
string filenameFlights = "flights.txt"; //файл з авіарейсами
string filenameAdminsSignIn = "AdminsSignIn.txt"; //файл з логінами і паролями адмінів
string filenameUsersSignIn = "UsersSignIn.txt"; //файл з логінами і паролями користувачів
list <user> users; //список з користувачами (при реєстрації вноситься інф)
list <admin> admins;
//string *filenameusers = new string[10]; //масив з назвами файлів кожного користувача окремо
list<flight> allFlights;
//ФУНКЦІЇ АДМІНА


void init()
{
	ifstream fin;
	fin.open(filenameUsersSignIn);
	bool isOpen = fin.is_open();
	if (isOpen == true)
	{
		int currentstring = 0;
		string data;
		float data2;
		user oldUser;
		while (!fin.eof())
		{
			currentstring++;
			getline(fin, data);
			if(currentstring == 1)
			{
				oldUser.login = data;
			}
			else if (currentstring == 2)
			{
				oldUser.password = data;
			}
			else if (currentstring == 3)
			{
				oldUser.money = data;
			}
			else if (currentstring == 4)
			{
				oldUser.email = data;
			}
			else if (currentstring == 5)
			{
				oldUser.countTickets = data;

			}
			if (oldUser.countTickets >= 1)
			{
				string data1;
				oldUser.myFlights = new flight[oldUser.countTickets];
				int currentstring1 = 0;
				for (int i = 0; i < oldUser.countTickets; i++)
				{
					getline(fin, data1);
					currentstring1++;
					if (currentstring1 == 1)
					{
						oldUser.myFlights[i].name = data1;
					}
					else if (currentstring1 == 2)
					{
						oldUser.myFlights[i].company = data1;
					}
					else if (currentstring1 == 3)
					{
						oldUser.myFlights[i].countTickets = data1;
						if (oldUser.myFlights[i].countTickets >= 1)
						{
							string data2;
							int currentstring2 = 0;
							for (int i = 0; i < oldUser.myFlights[i].countTickets; i++)
							{
								getline(fin, data2);
								currentstring2++;
								if (currentstring2 == 1)
								{
									oldUser.myFlights[i].tickets->ticketClass = data2;
								}
								else if (currentstring2 == 2)
								{
									oldUser.myFlights[i].tickets->value = data2; 
								}
								else if (currentstring2 == 3)
								{
									oldUser.myFlights[i].tickets->possibleToReturn = data2;
									currentstring2 = 0;
								}

							}
						}
					}
					else if (currentstring1 == 4)
					{
						oldUser.myFlights->departure.day = data1;
					}
					else if (currentstring1 == 5)
					{
						oldUser.myFlights->departure.month = data1;
					}
					else if (currentstring1 == 6)
					{
						oldUser.myFlights->departure.year = data1;
					}
					else if (currentstring1 == 7)
					{
						oldUser.myFlights->arrive.day = data1;
					}
					else if (currentstring1 == 8)
					{
						oldUser.myFlights->arrive.month = data1;
					}
					else if (currentstring1 == 9)
					{
						oldUser.myFlights->arrive.year = data1;
					}
					else if (currentstring1 == 11)
					{
						oldUser.myFlights->countConnectionFlights = data1;
						currentstring1 = 0;
						users.push_back(oldUser);
						oldUser = user();
					}


					
				}
			}
			

		}
	}
	else
	{
		cout << "Error: can not open file!" << endl;
	}
}

void editFlights()
{
}
//ФУНКЦІЇ КОРИСТУВАЧА
void buyTicket()
{

}

void searchFlight()
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

void showMyFlights()
{
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
	cout << "\tSIGN IN" << endl;
	cout << "Sign in as:";
	cout << "1. User" << endl;
	cout << "2. Admin" << endl;
	cout << endl;
	cout << "How to sign in?" << endl;
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
		
			ifstream fin;
			fin.open(filenameUsersSignIn);
			bool isOpen = fin.is_open();
			if (isOpen == true)
			{
	
				int choise;
				cout << "MENU" << endl;
				cout << "1. My profile" << endl;
				cout << "2. My flights" << endl;
				cout << "3. My money balance" << endl;
				cout << "4. Notifications" << endl;
				cout << "5. Sign out" << endl;
				cout << endl;
				cout << "Enter action: ";
				cin >> choise;
				switch (choise)
				{
				case 1:
					cout << "Login: " << tempUser.login << endl;
					cout << "Password: ********" << endl;
					cout << "Do you want to change it?" << endl;
					cout << "1. Yes" << endl;
					cout << "2. No" << endl;
					cin >> choisepasswd;
					//знизу правильно
					switch (choisepasswd)
					{
					case 1:
						ofstream fout;
						fout.open(filenameUsersSignIn);
						bool isOpen1 = fout.is_open();
						if (isOpen1 == true)
						{
							string temppasswd;
							string temppasswd2;
							cout << "Enter new password: ";
							cin >> temppasswd;
							cout << "Confirm password: ";
							cin >> temppasswd2;
							if (temppasswd == temppasswd2)
							{
								fout << tempUser.login << endl;
								fout << temppasswd << endl;
								for (int i = 0; i < 10; i++)//придумати шось з розміром масиву
								{
									if (users[i].password == tempUser.password)
									{
										string data3;
										fin.open(filenameUsersSignIn);
										bool isOpen2 = fin.is_open();
										if (isOpen2 == true)
										{
											int currentString = 0;
											while (!fin.eof())
											{
												currentString++;
												getline(fin, data3);
												if (currentString == 2)
												{
													if (data3 == tempUser.password)
													{
														fout.open(filenameUsersSignIn);
														bool isOpen3 = fout.is_open();
														if (isOpen3 == true)
														{
															users[i].password = temppasswd;
															fout << tempUser.login << endl;
															fout << temppasswd << endl;//перезаписуємо в масив новий пароль
														}
														else
														{
															cout << "ERROR!" << endl; //не відкрився файл з логінами та паролями користувачів
														}
														fout.close();
													}
												}
											}
										}
										else
										{
											cout << "ERROR!" << endl;//не відкривається файл
										}
									}
									else
									{
										//для пошуку старого паролю в масиві з користувачами (якшо не знаходиться то нічого не робиться)
									}
								}
							}
							else
							{
								cout << "Passwords don`t match" << endl;
							}
						}
						else
						{
							cout << "ERROR!" << endl;
						}

						fout.close();
						break;
					}
					//зверху правильно

					break;
				case 2:
					cout << "My flights" << endl;
					tempUser.flights = new flight[tempUser.countTickets];
					for (int i = 0; i < tempUser.countTickets; i++)
					{
						cout << "Name of flight: " << tempUser.flights->name << endl;
						cout << "Company: " << tempUser.flights->company << endl;
						cout << "Tickets" << endl;
						for (int i = 0; i < tempUser.flights->countTickets; i++)
						{
							cout << tempUser.flights->tickets->ticketClass << endl;
							cout << tempUser.flights->tickets->value << endl;
							cout << tempUser.flights->tickets->possibleToReturn << endl;

						}

					}
					break;
				case 3:
					cout << "MONEY BALANCE" << endl;
					for (user item : users)
					{
						if (item.login == tempUser.login)
						{
							string moneychoise;
							cout << "Money: " << item.money << endl;
							cout << "Do you want to add money?" << endl;
							cout << "Enter yes or no: ";
							cin >> moneychoise;
							if (moneychoise == "yes")
							{

							}
						}
					}
					break;
				default:
					break;
				}//свіч вибір пункта меню профіль чи мої рейси і тд
			}
			else
			{
				cout << "Error: can not open file!" << endl;
			}
		} //тут має бути іф логін тру
		else
		{
			cout << "Cant not find user with this login or password" << endl;
		}
	}
	case 2:
	{

	}
	default:
		break;
	}
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