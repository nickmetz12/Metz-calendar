/*
 * Nicholas Metzger
 * 8/4/16
 * Year.h
 * Header file for class, Year.
 */

#ifndef HEADER_H
#define HEADER_H

#include "month.h"
#include "grid.h"

//Year class contains list of months.
class Year
{
	public:
			Year();
			~Year();
			void update_year(int, int*);
			void print_year();
			void print_month_name(int);
			void print_month_grid(int);
			void print_year_grid();
            void delete_days_grid(int);	
	        void delete_months();

    
    private:
            
			void set_months(int*);
			bool determine_leap_year();
			void print_month_heading(int);
			
			int year_num;
			Month* months;
};


#endif /*HEADER_H*/
