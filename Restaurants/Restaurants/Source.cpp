#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;
/* Test Cases
Case #1 - Add a restaurant
Input: Wendy's
"This Restaurant is already in the tournament."

Case #2 - Remove a restaurant and try to start the tournament
Input: Papa John's
"Papa John's was removed from the tournament"
Option 5
"There aren't 2^n restaurants"

Case #3 - Tournament
"Start the tournament!"
1: In-N-Out or 2: Wendy's : 2
1: Chick-Fil-A or 2: Papa John's : 2
1: Taco Bell or 2: Rancherito's : 2
1: Panda Express or 2: Subway : 1
1: Papa John's or 2: Wendy's : 2
1: Panda Express or 2: Rancherito's : 1
1: Panda Express or 2: Wendy's : 2
The winner is Wendy's!
End program.
*/
const int SHUFFLE = 300;

int findRest(vector<string> rest, string newRest)
{
	int index;
	for (int i = 0; i < rest.size(); i++)
	{
		if (rest[i] == newRest)
		{
			return i;
		}
	}
	return -1;
}

void displayRest(vector<string> rest)
{
	cout << "Here are the restaurants in the tournament:\n";
	for (int i = 0; i < rest.size()-1; i++)
	{
		cout << rest[i] << ", ";
	}
	cout << rest[rest.size() - 1] << endl << endl;
}

void shuffleRest(vector<string>& rest)
{
	srand(time(0));
	
	for (int i = 0; i < 300; i++)
	{
		int num = rand() % rest.size();
		int num2 = (rand() + 1) % rest.size();

		string change = rest[num];
		rest[num] = rest[num2];
		rest[num2] = change;
	}
	cout << "Tournament shuffled.\n\n";
}

void removeRest(vector<string>& rest)
{
	string deleteRest;
	cout << "Enter the name of the restaurant you want to delete: ";
	cin.sync();
	getline(cin, deleteRest);
	int last_pos = rest.size() - 1;
	
	if (findRest(rest, deleteRest) != -1)
	{
	rest[findRest(rest, deleteRest)] = rest[last_pos];
	rest.pop_back();
	cout << deleteRest << " was removed from the tournament.\n\n";
	}
	else
	{
		cout << "This restaurant is not in the tournament.\n\n";
	}
}

void addRest(vector<string>& rest)
{
	string newRest;
	cout << "Enter the new restaurant's name: ";
	cin.sync();
	getline(cin, newRest);
	if (findRest(rest, newRest) == -1)
	{
		rest.push_back(newRest);
		cout << newRest << " was added to the tournament.\n\n";
	}
	else
	{
		cout << "This restaurant is already in the tournament.\n\n";
	}
}

void tournament(vector<string> rest)
{
	/*Match and round algorithms*/
	cout << "Start the tournament!\n";
		do{
			for (int i = rest.size()-1; i >= 0; i -= 2)
			{
				cout << "1: " << rest[i-1] << " or 2: " << rest[i] << " : ";
				int option;
				cin >> option;
				while (option != 1 && option != 2)
				{
					cin.clear();
					cin.ignore(SHUFFLE, '\n');
					cout << "Please enter either 1 or 2!\n" <<
						"1: " << rest[i - 1] << " or 2: " << rest[i] << " : ";
					cin >> option;
				}
				rest.erase(rest.begin() + (i - option + 1));
			}
		} while (rest.size() != 1);


	cout << "The winner is " << rest[0] << "!\n";
}

int startTournament(vector<string> rest)
{
	for (int i = 0; i < 6; i++)
	{
		int num = pow(2, i);

		if (rest.size() == num)
		{
			tournament(rest);
			system("pause");
			return 0;
		}
	}
	cout << "There aren't 2^n restaurants.\n\n";
	return -1;

}

int main()
{
	vector<string> rest = { "Wendy's", "Papa John's", "Taco Bell", "Subway",
		"Panda Express", "In-N-Out", "Rancherito's", "Chick-Fil-A" };

	int selection = 1;
	while (selection != 6)
	{
		cout << "1 - Display all restaurants." << endl <<
			"2 - Add a restaurant." << endl <<
			"3 - Remove a restaurant." << endl <<
			"4 - Shuffle the vector." << endl <<
			"5 - Begin the tournament!" << endl <<
			"6 - Quit the program" << endl <<
			"Enter you selection: ";
		cin >> selection;
		cout << endl;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(SHUFFLE, '\n');
			cout << "Please enter a number from 1-6\n";
		}
		if (selection < 1 || selection > 6)
		{
			cout << "Please enter a number from 1-6\n";
		}
		if (selection == 1)
		{
			displayRest(rest);
		}
		if (selection == 2)
		{
			addRest(rest);
		}
		if (selection == 3)
		{
			removeRest(rest);
		}
		if (selection == 4)
		{
			shuffleRest(rest);
		}

		if (selection == 5)
		{
			startTournament(rest);
		}
	}
	cout << "Goodbye!\n\n";
	system("pause");
	return 0;
}