/*
 * Nicholas Metzger
 * 8/4/16
 * Calendar.h
 * Header file for the class, Calendar.
 *  
 */

#ifndef CALENDAR_H
#define CALENDAR_H

#include "year.h"

//Calendar class containing list of years.
class Calendar
{
	public:
			Calendar();
            void create_event();
			void print_year(int);
			void print_month_name(int,int);
			void print_month_grid(int year_index, int month_index);
			void print_year_grid(int);
            Year* get_year(int);
            void delete_memory();
	private:
            void ensure_cap(int);

		    int num_years;
			void add_year(int, int*);
			Year* years;
};


#endif /*CALENDAR_H*/
