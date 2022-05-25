#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Test Case 1
Drop single chip into slot 4
[4 4.5 5.0 4.5 4.0 4.5 4.0 4.5 5.0 5.5 5.0 4.5 5.0]
Winnings: $0

Test Case 2
Drop 100 chips into slot 4
Total winnings: $311400.00
Average winnings per chip: $2632.00

Test Case 3
Drop 9001 chips into all slots

Total winnings for slot 0: $6880100
Average winnings for slot 0: $793.76

Total winnings for slot 1: $9535400
Average winnings for slot 1: $1025.34

Total winnings for slot 2: $13955000
Average winnings for slot 2: $1620.82

Total winnings for slot 3: $20131200
Average winnings for slot 3: $2297.79

Total winnings for slot 4: $22850100
Average winnings for slot 4: $2588.91

Total winnings for slot 5: $20320900
Average winnings for slot 5: $2239.60

Total winnings for slot 6: $14742800
Average winnings for slot 6: $1559.76

Total winnings for slot 7: $9176700
Average winnings for slot 7: $1044.23

Total winnings for slot 8: $6980900
Average winnings for slot 8: $790.67
*/	

const int slot_min = 0;
const int slot1 = 1;
const int slot2 = 2;
const int slot3 = 3;
const int slot4 = 4;
const int slot5 = 5;
const int slot6 = 6;
const int slot7 = 7;
const int slot_max = 8;
const int HEIGHT = 12;
const int WINNINGS0 = 100;
const int WINNINGS1 = 500;
const int WINNINGS2 = 1000;
const int WINNINGS3 = 0;
const int WINNINGS4 = 10000;
const int WINNINGS5 = 0;
const int WINNINGS6 = 1000;
const int WINNINGS7 = 500;
const int WINNINGS8 = 100;
		
double money(double slot_num)
{
	double winnings = 0;
	
	if (slot_num == slot_min)
	{
		winnings = WINNINGS0;
	}
	else if (slot_num == slot1)
	{
		winnings = WINNINGS1;
	}
	else if (slot_num == slot2)
	{
		winnings = WINNINGS2;
	}
	else if (slot_num == slot3)
	{
		winnings = WINNINGS3;
	}
	else if (slot_num == slot4)
	{
		winnings = WINNINGS4;
	}
	else if (slot_num == slot5)
	{
		winnings = WINNINGS5;
	}
	else if (slot_num == slot6)
	{
		winnings = WINNINGS6;
	}
	else if (slot_num == slot7)
	{
		winnings = WINNINGS7;
	}
	else if (slot_num == slot_max)
	{
		winnings = WINNINGS8;
	}
	return winnings;
}

double single_chip(double slot_num)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		const double move = .5;
		int rand_num = rand() % 2;
		if (rand_num == 1)
		{
			slot_num = slot_num + move;
			if (slot_num >= (slot_max + move))
			{
				slot_num = slot_num - move - move;
			}

			if (slot_num <= (slot_min - move))
			{
				slot_num = slot_num + move + move;
			}

			cout << fixed << setprecision(1) << slot_num;
		}

		else if (rand_num == 0)
		{
			slot_num = slot_num - move;
			if (slot_num >= (slot_max + move))
			{
				slot_num = slot_num - move - move;
			}

			if (slot_num <= (slot_min - move))
			{
				slot_num = slot_num + move + move;
			}

			cout << fixed << setprecision(1) << slot_num;
		}

		if (i != HEIGHT - slot1)
		{
			cout << " ";
		}
	}

	return slot_num;
}

double multiple_chips(int chips, double slot_num)
{
	int original_slot = slot_num;
	int new_winnings = 0;

	for (int i = 0; i < chips; i++)
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			const double move = .5;

			int rand_num = rand() % 2;
			if (rand_num == 1)
			{

				slot_num = slot_num + move;
				if (slot_num >= (slot_max + move))
				{
					slot_num = slot_num - move - move;
				}

				if (slot_num <= (slot_min - move))
				{
					slot_num = slot_num + move + move;
				}
			}

			else if (rand_num == 0)
			{
				slot_num = slot_num - move;
				if (slot_num >= (slot_max + move))
				{
					slot_num = slot_num - move - move;
				}

				if (slot_num <= (slot_min - move))
				{
					slot_num = slot_num + move + move;
				}
			}
		}
		new_winnings = new_winnings + money(slot_num);
		slot_num = original_slot;
	}
	return new_winnings;
}

int main()
{
	srand(time(0));
	int selection = 0;

	while (selection != 4)
	{
		int rand_num;
		double starting_position = 0;
		double current_position = starting_position;
		

		cout << "MENU: Please select one of the following options:" << endl;
		cout << " 1 - Drop a single chip into one slot" << endl;
		cout << " 2 - Drop multiple chips into one slot" << endl;
		cout << " 3 - Drop multiple chips into every slot" << endl;
		cout << " 4 - Quit the program" << endl;
		cout << "Enter your selection here: ";

		cin >> selection;
		cout << endl;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(WINNINGS2, '\n');
			cout << "INVALID INPUT.\n\n";
		}
		
		else if (selection == 4)
		{
			cout << "GOODBYE!\n";
			system("pause");
			return 0;
		}
		else if (selection == 1)
		{
			cout << "*** DROP SINGLE CHIP ***\n";
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			double slot_num;
			cin >> slot_num;
			cout << endl;
			
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(WINNINGS2, '\n');
				cout << "INVALID INPUT.\n\n";
			}
			
			else if (slot_num < slot_min || slot_num>slot_max)
			{
				cout << "INVALID SLOT NUMBER.\n\n";

			}
		
			else if (slot_num >= 0 && slot_num <= 8)
			{
				cout << "*** Droppping chip into slot " << slot_num << " ***";

				cout << endl << "[" << slot_num << " ";
				
				cout << "]" << endl << "WINNINGS: $" << fixed << setprecision(0) << money(single_chip(slot_num)) << endl << endl;
			}
		}
		
		else if (selection == 2)
		{
			cout << endl << "*** DROP MULTIPLE CHIPS ***" << endl;
			cout << "How many chips do you want to drop (>0)? ";
			int chips;
			cin >> chips;
			cout << endl;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(WINNINGS2, '\n');
				cout << "INVALID INPUT.\n\n";
			}
			else if (chips <= 0)
			{
				cout << "INVALID NUMBER OF CHIPS." << endl << endl;
			}
			else
			{
				cout << "Which slot do you want to drop all your chips into (0-8)? ";
				double slot_num;
				cin >> slot_num;
				cout << endl;
				
				double original_slot = slot_num;
				double winnings = 0;
				double new_winnings = 0;
				
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(WINNINGS2, '\n');
					cout << "INVAILD INPUT.\n\n";
				}
				else if (slot_num < slot_min || slot_num > slot_max)
				{
					cout << "INVALD SLOT NUMBER.\n\n";
				}
				else if (slot_num >= slot_min && slot_num <= slot_max)
				{
					double average_winnings = multiple_chips(chips, slot_num) / chips;
					
					cout << fixed << setprecision(2) << "Total winnings with " << chips 
						 << " chips: $" << multiple_chips(chips, slot_num) << endl;
					
					cout << "Average winnings per chip: $" << average_winnings << endl << endl;
				}
			}
		}

		else if (selection == 3)
		{
			cout << "*** DROP MULTIPLE CHIPS INTO ALL SLOTS ***\n";
			cout << "How many chips do you want to drop (<0)? ";
			int chips;
			cin >> chips;
			cout << endl;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(WINNINGS2, '\n');
				cout << "INVALID INPUT.\n\n";
			}
			else if (chips <= 0)
			{
				cout << "INVALID NUMBER OF CHIPS.\n\n";
			}
			else
			{
				cout << "*** DROPPING " << chips << " CHIPS INTO ALL SLOTS***\n";
				for (int i = 0; i <= slot_max; i++)
				{
					int slot_num = i;
					cout << "Total winnings for slot " << i << ": $" << fixed << setprecision(0) << multiple_chips(chips, slot_num) << endl;
					cout << "Average winnings per chip for slot " << i << ": $" << fixed << setprecision(2) << multiple_chips(chips, slot_num)/chips << endl << endl;
				}
			}
		}
			
		else
		{
			cout << "INVALID SELECTION.\n\n";
		}
	}

		system("pause");
		return 0;
}
