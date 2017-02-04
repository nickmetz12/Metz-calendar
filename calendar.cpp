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
    num_years = 1;
	years = new Year[num_years];
	
	int count = 1;
	int* count_ptr = &count;

        
	for (int i=0; i < num_years; i++)
	{
			add_year(i, count_ptr);
	}
}

/*
Purpose:    Deletes all allocated memory.
Parameters: None.
Returns:    None (void function).
*/
void Calendar::delete_memory()
{
    for (int i = 0; i < num_years; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            years[i].delete_days_grid(j);
        }
        years[i].delete_months();
    }
    delete[] years;
}

/*
Purpose:    Creates an event on a specific day.
Parameters: None.
Returns:    None (void function).
*/
void Calendar::create_event()
{
    int year = -1;
    cin >> year;
    cerr << "Entered year is " << year << endl;
    ensure_cap(year);

    if (year > 0)
    {
        years[year-1].create_event();
    }
    else
    {
        cerr << "Year must be > 0\n";
    }
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
	ensure_cap(i);

    //-1 because years array starts at 0
	years[i-1].print_year_grid();
}

/*
 * Purpose:     Expands the array of years if necessary.
 * Parameters:  None.
 * Returns:     None (void function).
 */
void Calendar::ensure_cap(int desired_year)
{
    if (desired_year > num_years)
    {
        delete_memory();    
       
        if (num_years * 2 < desired_year)
        {
            num_years = desired_year * 2;
        }  
        else {
            num_years = num_years * 2;
        }
        
        years = new Year[num_years];

        int count = 1;
	    int* count_ptr = &count;

        for (int i = 0; i < num_years; i++)
        {
            add_year(i, count_ptr);    
        }  
    }
}
