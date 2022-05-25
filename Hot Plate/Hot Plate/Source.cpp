#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 20;
const int OUTSIDE_TEMP= 100;
const int STARTING_TEMP = 0;
const int ONE = 1;
const double CHANGE = .1;
const double DIVISION = 4;

void initialize( double temperature[][SIZE], double temperature2[][SIZE])
{
	temperature[STARTING_TEMP][STARTING_TEMP] = STARTING_TEMP;
	temperature[STARTING_TEMP][SIZE - ONE] = STARTING_TEMP;
	temperature[SIZE - ONE][STARTING_TEMP] = STARTING_TEMP;
	temperature[SIZE - ONE][SIZE - ONE] = STARTING_TEMP;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			temperature[i][j] = STARTING_TEMP;
		}
	}

	for (int i = 1; i < SIZE - ONE; i++)
	{
		temperature[STARTING_TEMP][i] = OUTSIDE_TEMP;
		temperature[SIZE - ONE][i] = OUTSIDE_TEMP;
	}


	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			temperature2[i][j] = temperature[i][j];
		}
	}
}

void iteration(double temperature[][SIZE], double temperature2[][SIZE])
{
	for (int i = 1; i < SIZE - ONE; i++)
	{
		for (int j = 1; j < SIZE - ONE; j++)
		{
			temperature2[i][j] = temperature[i][j];

			temperature[i][j] = (temperature[i + ONE][j] + temperature2[i - ONE][j] +
				temperature[i][j + ONE] + temperature2[i][j - ONE]) / DIVISION;
		}
	}

}




void printHotPlate(double temperature[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << setw(5) << fixed << setprecision(1) << temperature[i][j] << " ";
		}
		cout << endl;
	}
}

double averageHotPlate(double temperature[][SIZE], double temperature2[][SIZE])
{
	double change = 25;
	double newChange = 1;

	/*for (int k = 0; k < 1000; k++)
	{
		for (int i = 1; i < SIZE - ONE; i++)
		{
			for (int j = 1; j < SIZE - ONE; j++)
			{
				temperature[i][j] = temperature2[i][j];

				temperature[i][j] = (temperature[i + ONE][j] + temperature[i - ONE][j] +
					temperature[i][j + ONE] + temperature[i][j - ONE]) / DIVISION;

			}
		}
	}*/
	
	do{
		newChange = 0;
		for (int i = 1; i < SIZE - ONE; i++)
		{
			for (int j = 1; j < SIZE - ONE; j++)
			{
				temperature2[i][j] = temperature[i][j];

				temperature[i][j] = (temperature[i + ONE][j] + temperature2[i - ONE][j] +
					temperature[i][j + ONE] + temperature2[i][j - ONE]) / DIVISION;

				change = temperature[i][j] - temperature2[i][j];
			
				if (change > newChange)
				{
					newChange = change;
				}
			}
		}
		//printHotPlate(temperature);
		//cout << endl << endl;

	} while (newChange > CHANGE);
	
	return temperature2[SIZE][SIZE];
}
	
void exportHotPlate(double temperature[][SIZE])
{
	ofstream excel;
	excel.open("lab6output.csv");

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			excel << temperature[i][j] << ",";
		}
		excel << endl;
	}
	excel.close();
}

int main()
{
	double temperature[SIZE][SIZE];
	double temperature2[SIZE][SIZE];

	initialize(temperature, temperature2);
	
	printHotPlate(temperature);
	
	cout << endl << endl;

	iteration(temperature, temperature2);

	printHotPlate(temperature);
	
	averageHotPlate(temperature, temperature2);

	exportHotPlate(temperature);

	system("pause");
	return 0;
}