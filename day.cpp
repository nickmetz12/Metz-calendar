/*
 * Nicholas Metzger
 * 8/4/16
 * day.cpp
 * Implementation for the class Day.
 */

#include <iostream>
using namespace std;

#include "day.h"


/*
 *Purpose: Constructor function.
 *Parameters: None.
 *Value returned: None.
 */
Day::Day()
{
	day_num = -1;
	day_name = "";
}


/*
 * Purpose: Updates the day.
 * Parameters: None.
 * Values Returned: None (void function).
 */
void Day::update_day(int num, string name)
{
	day_num	= num;
	day_name = name;
}


/*
 * Purpose: Prints day_num.
 * Parameters: None.
 * Values Returned: None (void function).
 */
void Day::print_day_num()
{
	cout << day_num << endl;
}


/*
 * Purpose: Prints day_name.
 * Parameters: None.
 * Values Returned: None (void function).
 */
void Day::print_day_name()
{
	cout << day_name << endl;
}

/*
 * Purpose: Gets day_name.
 * Parameters: None.
 * Value returned:  string day_name.
 */
string Day::get_day_name()
{
	return day_name;
}
