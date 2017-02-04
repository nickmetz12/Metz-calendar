/*
Nicholas Metzger 
2/3/17
event.cpp

Implementation of the class event, which has a name, time start, time end,
and a notes section.
*/

#include "event.h"


/*
Purpose:    Constructor function that initializes private members.
Parameters: None.
Returns:    None (void function).
*/
Event::Event()
{
    name = "";
    time_start = -1;
    time_end = -1;
    all_day = false;
    notes = "";
}

/*
Purpose:    Updates all the private members of an event.
Parameters: None.
Returns:    None (void function).
*/
void Event::update_event()
{
    cerr << "Please enter the name of the event (input DONE when finished)\n";
    update_string_comp(&name);    

    cerr << "Please enter yes or no whether the event is all-day\n";
    update_time();

    cerr << "Please enter the notes for the event (when done input DONE)\n";
    update_string_comp(&notes);
}

/*
Purpose:    Copies the data from another event.
Parameters: Event *orig
Returns:    None (void function).
*/
void Event::copy_event(Event *orig)
{
    name = orig->get_name();
    time_start = orig->get_time_start();
    time_end = orig->get_time_end();
    all_day = orig->get_all_day();
    notes = orig->get_notes(); 
}

/*
Purpose:    Updates a string field of an Event.
Parameters: A pointer to the string data to be updated.
Returns:    None (void function).
*/
void Event::update_string_comp(string *sp)
{
    string temp;
    
    while (cin >> temp)
    {
        if (temp == "DONE")
            break;
        *sp = *sp + " " + temp;
    }
}

/*
Purpose:    Updates the time of the event.
Parameters: None.
Returns:    None (vid function).
*/
void Event::update_time()
{
    string is_all_day = "";
    cin >> is_all_day;
    
    if (is_all_day == "yes" || is_all_day == "Yes")
        all_day = true;
    else if (is_all_day == "no" || is_all_day == "No")
    {
        all_day = false;
    
        cerr << "Please enter the time when the event starts "
            << "(base 24 hour time)\n";
        cin >> time_start;

        cerr << "Please enter the time when the event ends "
             << "(base 24 hour time)\n";
        cin >> time_end;
    }
    else
        cerr << "Please enter yes, no, Yes, or No\n";
}

/*
Purpose:
Parameters:
Returns:
*/
void Event::print_event()
{

}

/*
Purpose:    Gets name.
Parameters: None.
Returns:    The name of the event.
*/
string Event::get_name()
{
    return name;
}

/*
Purpose:    Gets time_start.
Parameters: None.
Returns:    The time when the event starts.
*/
int Event::get_time_start()
{
    return time_start;
}

/*
Purpose:    Gets time_end.
Parameters: None.
Returns:    The time when the event ends.
*/
int Event::get_time_end()
{
    return time_end;
}


/*
Purpose:    Gets all_day.
Parameters: None.
Returns:    The boolean determining whether the event lasts all day.
*/
bool Event::get_all_day()
{
    return all_day;
}

/*
Purpose:    Gets notes.
Parameters: None.
Returns:    The notes of the event.
*/
string Event::get_notes()
{
    return notes;
}

/*
Purpose:    Sets name.
Parameters: n is new name
Returns:    None (void function). 
*/
void Event::set_name(string n)
{
    name = n;
}

/*
Purpose:    Sets time_start.
Parameters: the new time_start
Returns:    None (void function). 
*/
void Event::set_time_start(int x)
{
    time_start = x;
}

/*
Purpose:    Sets time_end.
Parameters: the new time_end.
Returns:    None (void function). 
*/
void Event::set_time_end(int x)
{
    time_end = x;
}


/*
Purpose:    Sets all_day.
Parameters: true to mean all_day or false for not.
Returns:    None (void function). 
*/
void Event::set_all_day(bool ans)
{
    all_day = ans;
}

/*
Purpose:    Sets notes.
Parameters: The new notes.
Returns:    None (void function). 
*/
void Event::set_notes(string n)
{
    notes = n;
}



/*
Purpose:
Parameters:
Returns:
*/

