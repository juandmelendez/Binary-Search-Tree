//Juan Daniel Melendez Carrasquillo
//S01201288
//MovieBSTDatabase.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;

int main()
{
	int choice;
	bool exit = false;
	while (exit != true) {
		system("CLS");
		cout << "1. Add a genre" << endl;
		cout << "2. Add a movie" << endl;
		cout << "3. Modify a movie" << endl;
		cout << "4. List all genres" << endl;
		cout << "5. List all movies by genres" << endl;
		cout << "6. List all movies for a selected genre" << endl;
		cout << "7. Search for a movie" << endl;
		cout << "8. Exit" << endl;
		cin >> choice;

		switch (choice) {
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:
			exit = true;
			break;
		default:
			cout << "\nInvalid choice, please enter a valid choice." << endl;
			cin.clear();
			cin.ignore(10, '\n');
			system("pause");
		}
	}
	return 0;
}
