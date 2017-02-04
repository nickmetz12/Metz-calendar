/*
Nicholas Metzger 
2/3/17
event.h

Interface of the class event, which has a name, time start, time end, a bool
to determine if even is all day, and a notes section.
*/


#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using namespace std;

class Event {

    public:
        Event();
        void update_event();
        void print_event();
        string get_name();
        int get_time_start();
        int get_time_end();
        bool get_all_day();
        string get_notes();
        void set_name(string);
        void set_time_start(int);
        void set_time_end(int);
        void set_all_day(bool);
        void set_notes(string);

    private:
        void update_string_comp(string *);
        void update_time();

        string name;
        int time_start;
        int time_end;
        bool all_day;
        string notes;
};



#endif /*EVENT_H*/ 
