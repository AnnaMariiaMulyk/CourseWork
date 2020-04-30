#include <iostream>
#include <string>
#include "Functions.h"
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;


int main()
{
	
	init();
	int choiseMenu;
	do {
		cout << "\tMY FIGHTS" << endl;
		cout << "1. Sign in" << endl;
		cout << "2. Sign up" << endl;
		cout << "3. Continue as guest" << endl;
		cout << "4. Exit" << endl;
		//зробити можливість бігати по пукнтам стрілочками
		cout << "Enter action: ";
		cin >> choiseMenu;
		switch (choiseMenu)
		{
		case 1:
			signIn();
			break;
		case 2:
			signUp();
			break;
		case 3:

			break;
		case 4:
			cout << "Goodbye" << endl;
			break;
		default:
			break;
		}

	} while (choiseMenu != 4);
		   

	return 0;
}