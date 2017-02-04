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
    events = NULL;
    num_events = 0;
    cap_events = 0;
    has_event = false;
}

/*
Purpose:    Frees all allocated memory regarding events.
Parameters: None.
Returns:    None (void function).
*/
void Day::delete_memory()
{
    delete[] events;
}

/*
Purpose:    Creates an event in this day.
Parameters: None.
Returns:    None (void function).
*/
void Day::create_event()
{
    ensure_cap();
    has_event = true;
    events[num_events].update_event();
    num_events++;
    cerr << events[num_events-1].get_name() << endl
         << events[num_events-1].get_time_start() << endl
         << events[num_events-1].get_time_end() << endl
         << events[num_events-1].get_all_day() << endl
         << events[num_events-1].get_notes() << endl;
}

/*
Purpose:    Copies the events from a certain day.
Parameters: The address of the day to be copied from.
Returns:    None (void function).
*/
void Day::copy_events(Day *orig)
{
    for (int i = 0; i < orig->get_num_events(); i++)
    {
        ensure_cap();
        events[i].copy_event(orig->get_event(i));
        cerr << "COPY OF EVENT WORKED "<<events[i].get_name() << endl;
    }
}

void Day::set_has_event()
{
    has_event = true;
}

/*
Purpose:    Returns the address to an event.
Parameters: Index specifying which event.
Returns:    Address to event.
*/
Event* Day::get_event(int i)
{
    return &(events[i]);
}


/*
Purpose:    Expands the array of 
Parameters: None.
Returns:    None (void function).
*/
void Day::ensure_cap()
{
    if (num_events == cap_events)
    {
        Event *new_array = new Event[num_events * 2 + 1];

        for (int i = 0; i < num_events; i++)
        {
            new_array[i].set_name(events[i].get_name());
            new_array[i].set_time_start(events[i].get_time_start());
            new_array[i].set_time_end(events[i].get_time_end());
            new_array[i].set_all_day(events[i].get_all_day());
            new_array[i].set_notes(events[i].get_notes());
        }

        if (events != NULL)
            delete[] events;
        events = new_array;
        cap_events = 2 * (cap_events + 1);
    }
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

/*
Purpose:    Gets has_event.
Parameters: None.
Returns:    The bool has_event.
*/
bool Day::get_has_event()
{
    return has_event;
}

/*
Purpose:    Returns the number of events.
Parameters: None.   
Returns:    None (void function).
*/
int Day::get_num_events()
{
    return num_events;
}
