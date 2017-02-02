/*
 *Nicholas Metzger
 *8/3/16
 *month.cpp
 *Implementation for Month class.
 */

#include <iostream>
using namespace std;

#include "month.h"


/*
Purpose:Constructor function.
Parameters:None.
Value Returned:None.
*/
Month::Month()
{ 
	grid = new Grid[42];
	
	for (int i = 0; i < 42; i++)
	{
		grid[i].day = -1;
		grid[i].valid = false;
	}
	grid_set = false;
	days = NULL;
	year_num = -1;
	number_days = -1;
	month_num = -1;
	month_name = "";
	leap_year = false;
}


/*
 * Purpose:Destructor function.
 * Parameters:None.
 * Value returned:None.
 */
Month::~Month()
{
        delete[] days;
	delete[] grid;
}


/*
 * Purpose:Determines number of days.
 * Parameters:None.
 * Value returned:int, the number of days.
 */
int Month::determine_num_days()
{
	if (month_num == 9 || month_num == 4 || 
		month_num == 6 || month_num == 11)
	{
		return 30;
	}

	else if (month_num == 2)
	{
		if (leap_year)
			return 29;
		else
			return 28;
	}

	else
		return 31;
}


/*
 * Purpose:Sets leap_year.
 * Parameters: None.
 * Value returned: None (void function)
 */
void Month::set_leap_year()
{
	leap_year = true;
}

/*
 *Purpose: Updates month.
 *Parameters: int i is new month_num. string name
 *		is new month_name. int* count_ptr determines day of week.
 *Values Returned: None (void function).
 */
void Month::update_month(int i, string name, int* count_ptr, int year)
{
		
	string days_o_week[7];
	days_o_week[0] = "Sunday";
	days_o_week[1] = "Monday";
	days_o_week[2] = "Tuesday";
	days_o_week[3] = "Wednesday";
	days_o_week[4] = "Thursday";
	days_o_week[5] = "Friday";
	days_o_week[6] = "Saturday";
	
	month_num = i;
	month_name = name;
	year_num = year;

 	number_days = determine_num_days();
	days = new Day[number_days];

	for (int x = 0; x < number_days; x++)
	{
		//x+1, because days array starts at index 0.
		days[x].update_day(x+1, days_o_week[(*count_ptr)%7]);
		(*count_ptr)++;
	}
}

/*
 * Purpose: Sets the grid of the month.
 * Parameters: None.
 * Value returned: None (void function).
 */
void Month::set_grid()
{
	if (days[0].get_day_name() == "Sunday")
		start_grid_nums(0);	
	else if (days[0].get_day_name() == "Monday")
		start_grid_nums(1);
	else if (days[0].get_day_name() == "Tuesday")
		start_grid_nums(2);
	else if (days[0].get_day_name() == "Wednesday")
		start_grid_nums(3);
	else if (days[0].get_day_name() == "Thursday")
		start_grid_nums(4);
	else if (days[0].get_day_name() == "Friday")
		start_grid_nums(5);
	else // Saturday
		start_grid_nums(6);
}


/*
 *Purpose: Determines where first day starts in grid month and fills in
 			rest.
 *Parameters: None.
 *Value returned: None (void function).
*/
void Month::start_grid_nums(int start_index)
{
	for (int i = 0; i < number_days; i++)
	{
		//+1, because starts on day 1
		grid[start_index].day = i+1;
		grid[start_index++].valid = true;
	}
}


/*
 * Purpose: Prints the month grid.
 * Parameters: None.
 * Value returned: None (void function).
 */
void Month::print_grid(bool month_grid)
{
	cout << "\n\t" <<month_name << " " << year_num << endl;
	cout << "Su  Mo  Tu  We  Th  Fr  Sa \n";
	
	//42 ints in grid
	for (int j = 0; j < 42; j++)
	{
		print_grid_unit(month_grid, j);
		
		
	}
}


/*
 * Purpose: Prints grid row.
 * Parameters: int i is index of starting grid unit of row.
 * Value returned: None (void function).
 */
void Month::print_grid_row(bool month_grid, int i)
{
	for (int x = 0; x < 7; x++)
	{
		print_grid_unit(month_grid, i+x);
	}
}


/*
 * Purpose: Prints grid unit.
 * Parameters: int j is grid unit index.
 * Value returned: None (void function).
 */
void Month::print_grid_unit(bool month_grid, int j)
{
	if (grid[j].valid)
	{
		cout << grid[j].day << "  ";
		//aesthetics purposes
		if (grid[j].day < 10)
			cout << " ";
	}

	else
		cout << "/   ";
	if (month_grid)
	{
		if (j % 7 == 6)
			cout << endl;
	}
}


/*
 * Purpose:Prints month_num.
 * Parameters:None.
 * Values Returned:None (void function).
 */
void Month::print_month_num()
{
	cout << month_num << endl;
}


/*
 * Purpose: Gets month_name.
 * Parameters: None.
 * Value returned: string month_name.
 */
string Month::get_month_name()
{
	return month_name; 
}
/*
 * Purpose:Prints month_name.
 * Parameters:None.
 * Values Returned:None (void function).
 */
void Month::print_month_name()
{
	cout << month_name << endl;
}


/*
 * Purpose: Prints num_days.
 * Parameters: None.
 * Value returned: None (void function).
 */
void Month::print_num_days()
{
	cout << number_days << endl;

}


/*
 * Purpose: Returns grid_set.
 * Parameters: None.
 * Value returned: bool grid_set.
 */
bool Month::grid_is_set()
{
	return grid_set;
}
