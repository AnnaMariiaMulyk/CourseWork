#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <list>
using namespace std;

struct date
{
	int hour;
	int minute;
	int day;
	int month;
	int year;
};
struct ticket
{
	string ticketClass;
	int value;
	bool possibleToReturn;
};
struct connectionFlight
{
	string connectionFlightCity; //мысце пересадки
	int connectionFlightTime; //тривалфсть пересадки в хвилинах
};
struct flight
{
	string name;
	string company;
	date departure;
	date arrive;
	int allTicketsAviable; //сума всіх доступних квитків
	int ticketsAviableEconomClass; //для адміна - кількість квитків доступно економ класу
	int ticketsAviableFirstClass; //для адміна - кількість квитків доступно першого класу
	int countTickets; //для користувача
	ticket* tickets; //для користувача і адміна
	int countConnectionFlights; //кількість пересадок
	connectionFlight* ConnectionFlights;
	string departureCity;
	string arrivalCity; 
};
/*в юзера в файлі буде так:
name
company
departure
arrive
count tickets
tickets(без к-сті доступних
count connection flights
conection flights
departure city
arrival city*/

/*в файлі з рейсами буде так
name
company
departure
arrive
tickets(разом з кількістю доступних)
count connection flights
conection flights
departure city
arrival city
*/

struct user
{
	string login;
	string password;
	float money;
	string email;
	int countFlights;
	flight* myFlights;
};


struct admin
{
	string login;
	string password;
	string company;
};

void init();
void rewriteUsersFile();
//auto delete_list_elem(list<user>& list1, int k);

void showMatrixofValues();
void signUp();
void buyTicket();
void editFlights(flight flightToEdit);
void searchFlight(user myUser);
void showMyFlights(user myUser);
void signIn();

