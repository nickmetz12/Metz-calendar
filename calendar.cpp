 /*
 * Nicholas Metzger
 * 8/4/16
 * Calendar.cpp
 * Implementation for the class, Calendar.  
 */

#include "calendar.h"

#include <iostream>
using namespace std;

/*
 * Purpose:Constructor function.
 * Parameters: None.
 * Values Returned: None.
 */
Calendar::Calendar()
{
        int NUM_YEARS = 3000;
	years = new Year[NUM_YEARS];
	
	int count = 1;
	int* count_ptr = &count;

        
	for (int i=0; i < NUM_YEARS; i++)
	{
			add_year(i, count_ptr);
	}
}

/*
Purpose: Destructor function.
Parameters: None.
Value returned; None.
*/
Calendar::~Calendar()
{
	delete[] years;
}


/*
 * Purpose: Adds a year to the list of years.
 * Parameters: int i is the index of the year. int* count_ptr is pointer
 * 		to int count determing day of week.
 * Values Returned: None (void function).
 */
void Calendar::add_year(int i, int* count_ptr)
{
	years[i].update_year(i, count_ptr);
}


/*
 * Purpose: Prints the year.
 * Parameters: int i is the index of the year.
 * Values Returned: None (void function).
 */
void Calendar::print_year(int i)
{
	cout << "Year ";
   	years[i].print_year();
}


/*
 * Purpose:Prints month_name.
 * Parameters:int year_index. int month_index.
 * Values Returned:None (void function).
 */
void Calendar::print_month_name(int year_index,int month_index)
{
	//-1 because array index starts at 0
	 years[year_index].print_month_name(month_index-1);
}


/*
 * Purpose: Prints month grid.
 * Parameters: int year_index. int month_index.
 * Value returned: None (void function).
 */
void Calendar::print_month_grid(int year_index, int month_index)
{
	years[year_index].print_month_grid(month_index);
}


/*
 * Purpose: Prints year gird.
 * Parameters: int i is index of year.
 * Value returned: None (void function).
 */
void Calendar::print_year_grid(int i)
{
	//-1 because years array starts at 0
	years[i-1].print_year_grid();
}
