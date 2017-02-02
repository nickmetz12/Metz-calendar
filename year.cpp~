/*
 * Nicholas Metzger
 * 8/4/16
 * year.cpp
 * Implementation of class, year.
 */
#include <iostream>
using namespace std;
#include "year.h"


/*
 * Purpose: Constructor function.
 * Parameters: None.
 * Values Returned: None.
*/ 
Year::Year()
{
	months = new Month[12];
	year_num = -1;
}

/*
Purpose: Destructor function.
Parameters: None.
Value returned: None.
*/
Year::~Year()
{
        delete[] months;
}

/*
Purpose: Updates the year and determines determines if leap year.
Parameters: int i is the new year. int* count_ptr determines the
			day of the week.
Value Returned: None (void function).
 */
void Year::update_year(int i, int *count_ptr)
{
	//start with year 1
	year_num = i+1;
	bool is_leap_year = determine_leap_year();

	if (is_leap_year)
		months[1].set_leap_year();
	
	set_months(count_ptr);
}

/*
 * Purpose: Sets the months in the year.
 * Parameters: int* count_ptr determines the day of the week.
 * Value returned: None (void function).
 */
void Year::set_months(int* count_ptr)
{
	string months_names[12];
	months_names[0] = "January";
	months_names[1] = "February";
	months_names[2] = "March";
	months_names[3] = "April";
	months_names[4] = "May";
	months_names[5] = "June";
	months_names[6] = "July";
	months_names[7] = "August";
	months_names[8] = "September";
	months_names[9] = "October";
	months_names[10] = "November";
	months_names[11] = "December";

	for (int i = 0; i < 12; i++)
	{
		//+1 becuase months array starts at 0
		months[i].update_month(i+1, months_names[i], 
                                        count_ptr, year_num);
	}
}


/*
 * Purpose: Determines if it is a leap year. If the year is divisible
 *          by 4, then it is a leap year, unless it is divisible by 100,
 *          then it is not a leap year, unless it is divisible by 400,
 * 	    then it is a leap year.
 * Parameters: None.
 * Value returned:a boolean, true if it is a leap year, false otherwise.
 */
bool Year::determine_leap_year()
{	
	if (year_num % 4 == 0)
	{
		if (year_num % 100 == 0)
		{
			if (year_num % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	return false;		
}


/*
 * Purpose: Prints year grid by looping through rows of weeks in a 4 month
 * 			by 3 month grid view of the entire year.
 * Parameters: None.
 * Value returned: None (void function).
 */
void Year::print_year_grid()
{
	cout << "\t\t\t\t\t" << year_num << endl;
	//number of rows in 4x3 year grid of months
	for (int i = 0; i < 4; i++)
	{
		//number possible rows in month grid
		for (int x = 0; x < 6; x++)
		{
			if (x % 6 == 0)
				print_month_heading(i);
			
			//number of columns in 4x3 year grid of months
			for (int k = 0; k < 3; k++)
			{
				if (!months[3*i + k].grid_is_set())
					months[3*i + k].set_grid();
				//number possible columns in month grid
				for (int j = 0; j < 7; j++)
				{
					months[i*3+k].print_grid_unit(false, 
                                                              x*7 + j);	
				}
				//print three months in a row
				if (k % 3 == 2)
					cout << endl;
				
			}
		}
	}
}


/*
 * Purpose: Prints the month name and the names of the weekdays.
 * Parameters: int i determines which row of months in 4x3 grid of months.
 * Value returned: None (void function).
 */
void Year::print_month_heading(int i)
{
	if (i == 0)
	{
		cout << "         January                     February        "
			<< "             March\n";
	}
	else if (i == 1)
	{
		cout << "          April                         May          "
		   << "              June\n";
	}
	else if (i == 2)
	{
		cout << "           July                        August        "
		   << "           September\n";
	}
	else // i == 3
	{
		cout << "         October                     November        "
		   << "            December\n";
	}
	
        for (int index = 0; index < 3; index++)
	{
		cout << "Su  Mo  Tu  We  Th  Fr  Sa  ";
		if (index % 3 == 2)
			cout << endl;
	}
}


/*
 * Purpose: Prints the value of the year.
 * Parameters: None.
 * Value Returned: None (void function).
 */
void Year::print_year()
{
	cout << year_num << endl;
}


/*
 * Purpose: Prints month name.
 * Parameters: int month_num.
 * Values Returned: None (void function).
 */
void Year::print_month_name(int month_num)
{
	 months[month_num].print_month_name();
}


/*
 * Purpose: Prints month grid.
 * Parameters: int month_index.
 * Value returned: None (void function).
 */
void Year::print_month_grid(int month_index)
{
	if (!months[month_index].grid_is_set())
		months[month_index].set_grid();
	months[month_index].print_grid(true);
}
