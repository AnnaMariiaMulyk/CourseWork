#pragma once
#include <iostream>
#include <string>
#include <string>
using namespace std;

struct date
{
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
struct flight
{
	string name;
	string company;
	int countTickets;
	ticket* tickets;
	date departure;
	date arrive;
	int ticketsAviable; //к≥льк≥сть квитк≥в доступно в сум≥(маЇ бути ще окремо до кожного класу квитка)
	int countConnectionFlights; //к≥льк≥сть пересадок
};
struct user
{
	string login;
	string password;
	float money;
	string email;
	int countTickets;
	flight* myFlights;
};

struct admin
{
	string login;
	string password;
};

void init();


//‘”Ќ ÷≤ѓ ƒЋя јƒћ≤Ќј


void signUpAdmin();
void editFlights();


//‘”Ќ ÷≤ѓ ƒЋя  ќ–»—“”¬ј„ј


void signUp();
void buyTicket();
void searchFlight();
void showMyFlights();
void myProfile(string filename);

//—ѕ≤Ћ№Ќ ‘”Ќ ÷≤ѓ

void signIn();

