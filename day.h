/*
 * Nicholas Metzger
 * 8/3/16
 * day.h
 * Header file for class Day.
 */
#ifndef DAY_H
#define DAY_H

#include <string>
#include "event.h"

//Days has both a number and a name.
class Day
{
	public:
			Day();
            void delete_memory();
			void create_event();
            void copy_events(Day *);
            void update_day(int ,std::string);
			void print_day_num();
			void print_day_name();
            void set_has_event();
			std::string get_day_name();
            bool get_has_event();
            int get_num_events();
            Event* get_event(int);
	private:
            void ensure_cap();

			int	day_num;
			std::string day_name;
            int num_events;
            int cap_events;
            bool has_event;
            Event *events;
};

#endif /*DAY_H*/
