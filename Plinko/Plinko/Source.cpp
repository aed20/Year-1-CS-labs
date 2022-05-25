#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
Test Case 1
Drop single chip into slot 5
[5 5.5 6 6.5 7 6.5 6 6.5 7 7.5 8 7.5 8]
Winnings: $100

Test Case 2
Drop 100 chips into slot 5
Total winnings: $188300.00
Average winnigns per chip: $1883.00

Test Case 3
Drop 10 chips into slot 8
Total winnings: $3200.00
Average winnings per chip: $320
*/

int main()
{
	srand(time(0));
	int selection = 0;

	while (selection != 3)
	{

		double move = .5;
		int rand_num;
		double starting_position = 0;
		double current_position = starting_position;

		const int HEIGHT = 12;

		const int slot_min = 0;
		const int slot1 = 1;
		const int slot2 = 2;
		const int slot3 = 3;
		const int slot4 = 4;
		const int slot5 = 5;
		const int slot6 = 6;
		const int slot7 = 7;
		const int slot_max = 8;

		const int WINNINGS0 = 100;
		const int WINNINGS1 = 500;
		const int WINNINGS2 = 1000;
		const int WINNINGS3 = 0;
		const int WINNINGS4 = 10000;
		const int WINNINGS5 = 0;
		const int WINNINGS6 = 1000;
		const int WINNINGS7 = 500;
		const int WINNINGS8 = 100;

		cout << "MENU: Please select one of the following options:" << endl;
		cout << " 1 - Drop a single chip into one slot" << endl;
		cout << " 2 - Drop multiple chips into one slot" << endl;
		cout << " 3 - Quit the program" << endl;
		cout << "Enter your selection now: ";

		cin >> selection;

		if (selection == 3)
		{
			cout << "GOODBYE!\n";
			system("pause");
			return 0;
		}
		else if (selection == 1)
		{
			cout << endl << "*** DROP SINGLE CHIP ***\n";
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			double slot_num;
			cin >> slot_num;
			cout << endl;
			if (slot_num < slot_min || slot_num>slot_max)
			{
				cout << "INVALID SLOT NUMBER.\n\n";

			}
		
			else if (slot_num >= 0 && slot_num <= 8)
			{
				cout << "*** Droppping chip into slot " << slot_num << " ***";

				cout << endl << "[" << slot_num << " ";
				for (int i = 0; i < HEIGHT; i++)
				{

					rand_num = rand() % 2;
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

						cout << slot_num;
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

						cout << slot_num;
					}

					if (i != HEIGHT - slot1)
					{
						cout << " ";
					}
				}
				double winnings;
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

				cout << "]" << endl << "WINNINGS: $" << winnings << endl << endl;
			}
		}
		
		else if (selection == 2)
		{
			cout << endl << "*** DROP MULTIPLE CHIPS ***" << endl;
			cout << "How many chips do you want to drop (>0)? ";
			int chips;
			cin >> chips;

			if (chips <= 0)
			{
				cout << "INVALID NUMBER OF CHIPS." << endl << endl;
			}
			else
			{
				cout << "Which slot do you want to drop all your chips into (0-8)? ";
				double slot_num;
				cin >> slot_num;
				double original_slot = slot_num;
				double winnings = 0;
				double new_winnings = 0;
				if (slot_num < slot_min || slot_num > slot_max)
				{
					cout << "INVALD SLOT NUMBER.\n\n";
				}
				else if (slot_num >= slot_min && slot_num <= slot_max)
				{
					for (int i = 0; i < chips; i++)
					{
						for (int i = 0; i < HEIGHT; i++)
						{
							rand_num = rand() % slot2;
							if (rand_num == slot1)
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

							else if (rand_num == slot_min)
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
						new_winnings = new_winnings + winnings;
						slot_num = original_slot;
					}


					double average_winnings = new_winnings / chips;
					cout << fixed << setprecision(2) << "Total winnings with " << chips << " chips: $" << new_winnings << endl;
					cout << "Average winnings per chip: $" << average_winnings << endl << endl;
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
