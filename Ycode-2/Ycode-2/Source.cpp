#include <iostream>
#include <iomanip>
using namespace std;

/* # of guests     Tip     Larges     Mediums     Smalls     Area (in^2)     Area per person (in^2)     Cost (rounded)
       11          10        1           1          1          534.0703           48.5518                   $37
	   666         66        95          0          1          29958.20           44.9823                   $2327
	   30          15        4           0          2          1482.830           49.4277                   $84
*/

int main()
{
	//the inputs
	int guests;
	int percent_tip;
	
	//divisions of pizza - 1 large feeds 7, 1 medium feeds 3, and 1 small feeds 1
	const int l = 7;
	const int m = 3;
	const int s = 1;
	
	//percentage
	const double percent = 100;

	//measurements are in inches
	const int large_r = 10;
	const int medium_r = 8;
	const int small_r = 6;

	//prices are in dollars
	const double large_price = 14.68;
	const double medium_price = 11.48;
	const double small_price = 7.28;

	//Pi
	const double PI = 3.14159;
	
	cout << "Please enter the number of guests: ";
	cin >> guests;
	cout << "\n\n";

	
	int large_pizzas = guests / l;
	int medium_pizzas = (guests%l) / m;
	int small_pizzas = ((guests%l)%m) / s;

	cout << "You should order " << large_pizzas << " large pizzas, ";
	cout << medium_pizzas << " medium pizzas, and ";
	cout << small_pizzas << " small pizzas. \n\n\n";

	double area_lp = PI*large_r*large_r;
	double area_mp = PI*medium_r*medium_r;
	double area_sp = PI*small_r*small_r;
	double total_area = (large_pizzas*area_lp) + (medium_pizzas*area_mp) + (small_pizzas*area_sp);
	
	cout << "The total area of pizza is ";
	cout << total_area << " square inches\.\n";
	
	double total_per_person = total_area / guests;
	
	cout << "The total area of pizza per person is ";
	cout << total_per_person << " square inches.\n\n\n";
	
	cout << "Please enter the tip: ";
	cin >> percent_tip;
	double tip = percent_tip / percent;

	double total_pizza_cost = (large_pizzas*large_price) + (medium_pizzas*medium_price) + (small_pizzas*small_price);
	double total_cost_with_tip = (total_pizza_cost*tip) + total_pizza_cost;

	cout << fixed << setprecision(0);
	cout << "The total cost of pizza and tip is\: \$" <<
		total_cost_with_tip << "\n\n";

	system("pause");
	return 0;
}