#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
/* For the prices to be equal with the given criteria, the hybrid car must have a mileage of 166.666667 mpg

 Test Cases								 1							2							3
Car								|	Hybrid		Non-Hybrid	|	Hybrid		Non-hybrid	|	Hybrid		Non-hybrid
Miles							|			200000			|			5000			|			1000000
Price of Gas					|			3.50			|			6.66			|			.99
Cost of car						|	50000		20000		|	10000		20000		|	20000		15000
Efficency (mpg)					|	60			25			|	100			16			|	35			20
Resale Value					|	40000		15000		|	50			19000		|	15000		10000
Minimized (Gas or Total)		|			Gas				|			Total			|			Gas
								|							|							|
Fuel consumption				|	16666.67	400000		|	250			1562.50		|	142857		250000
Total cost						|	58333.33	145000		|	11615.00	11406.25	|	146428.57	252500.00

*/

int main()
{
	double miles_per_year;
	cout << "Please input the estimated number of miles driven in one year: ";
	cin >> miles_per_year;
	cout << endl;

	if (miles_per_year <= 0)
	{
		cout << "Only positive numbers are valid in this program! Please input a positive number: ";
		cin >> miles_per_year;
		cout << endl;
	}

	double price_of_gas;
	cout << "Please enter the estimated price of gas for the next five years: $";
	cin >> price_of_gas;
	cout << endl;

	if (price_of_gas <= 0)
	{
		cout << "Please input a positive number: ";
		cin >> price_of_gas;
		cout << endl;
	}
	
	int cost1;
	cout << "Please enter the cost of a hybrid car: $";
	cin >> cost1;
	cout << endl;

	if (cost1 <= 0)
	{
		cout << "Please input a positive number: $";
		cin >> cost1;
		cout << endl;
	}
	
	double mpg1;
	cout << "Please enter the efficency of a hybrid car (in mpg): ";
	cin >> mpg1;
	cout << endl;
	
	if (mpg1 <= 0)
	{
		cout << "Please enter a positive value: ";
		cin >> mpg1;
		cout << endl;
	}
	
	double resale1;
	cout << "Please enter the estimated resale value of the hybrid car: $";
	cin >> resale1;
	cout << endl;

	if (resale1 <= 0)
	{
		cout << "Please enter a positive value: $";
		cin >> resale1;
		cout << endl;
	}

	int cost2;
	cout << "Please enter the cost of your non-hybrid car: $";
	cin >> cost2;
	cout << endl;

	if (cost2 <= 0)
	{
		cout << "Please input a positive value: $";
		cin >> cost2;
		cout << endl;
	}

	double mpg2;
	cout << "Please enter the efficency of the non-hybrid car (in mpg): ";
	cin >> mpg2;
	cout << endl;

	if (mpg2 <= 0)
	{
		cout << "Please enter a positive value: ";
		cin >> mpg2;
		cout << endl;
	}

	double resale2;
	cout << "Please enter the estimated resale value of the non-hybrid car: $";
	cin >> resale2;
	cout << endl;

	if (resale2 <= 0)
	{
		cout << "Please enter a positive value: $";
		cin >> resale2;
		cout << endl;
	}

	string criteria;
	cout << "What do you want to minimize, gas consuption or total cost? Please enter either \"Gas\" or \"Total\": ";
	cin >> criteria;
	cout << endl << endl;

	const int years = 5;
	double fuel_consumption_hybrid = years*miles_per_year / mpg1;
	double total_cost_hybrid = fuel_consumption_hybrid*price_of_gas + (cost1 - resale1);

	double fuel_consuption_nonhybrid = years*miles_per_year / mpg2;
	double total_cost_nonhybrid = fuel_consuption_nonhybrid*price_of_gas + (cost2 - resale2);

	if (criteria == "Gas" && fuel_consumption_hybrid < fuel_consuption_nonhybrid)
	{
		cout << "The hybrid car will consume " << fuel_consumption_hybrid << " gallons of gas in 5 years.\n";
		cout << "The total cost of the hybrid is: $" << fixed << setprecision(2) << total_cost_hybrid << endl << endl << endl;

		cout << "The non-hybrid car will consume " << fuel_consuption_nonhybrid << " gallons of gas in 5 years.\n";
		cout << "The total cost of the non-hybrid car is: $" << fixed << setprecision(2) << total_cost_nonhybrid << endl << endl;
	}
	
	else if (criteria == "Gas" && fuel_consumption_hybrid >= fuel_consuption_nonhybrid)
	{
		cout << "The non-hybrid car will consume " << fuel_consuption_nonhybrid << " gallons of gas in 5 years.\n";
		cout << "The total cost of the non-hybrid car is: $" << fixed << setprecision(2) << total_cost_nonhybrid << endl << endl << endl;
		
		cout << "The hybrid car will consume " << fuel_consumption_hybrid << " gallons of gas in 5 years.\n";
		cout << "The total cost of the hybrid is: $" << fixed << setprecision(2) << total_cost_hybrid << endl << endl;
	}
	
	else if (criteria == "Total" && total_cost_hybrid < total_cost_nonhybrid)
	{
		cout << "The total cost of the hybrid is: $" << fixed << setprecision(2) << total_cost_hybrid << endl;
		cout << "The hybrid car will consume " << fuel_consumption_hybrid << " gallons of gas in 5 years.\n\n\n";
		
		cout << "The total cost of the non-hybrid car is: $" << fixed << setprecision(2) << total_cost_nonhybrid << endl;
		cout << "The non-hybrid car will consume " << fuel_consuption_nonhybrid << " gallons of gas in 5 years.\n\n";
	}
	
	else if (criteria == "Total" && total_cost_hybrid >= total_cost_nonhybrid)
	{
		cout << "The total cost of the non-hybrid car is: $" << fixed << setprecision(2) << total_cost_nonhybrid << endl;
		cout << "The non-hybrid car will consume " << fuel_consuption_nonhybrid << " gallons of gas in 5 years.\n\n\n";
		
		cout << "The total cost of the hybrid is: $" << fixed << setprecision(2) << total_cost_hybrid << endl;
		cout << "The hybrid car will consume " << fuel_consumption_hybrid << " gallons of gas in 5 years.\n\n";
	}
		
	
	system("pause");
	return 0;
}
