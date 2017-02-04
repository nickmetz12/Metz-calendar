/*
 * Nicholas Metzer
 * 8/3/16
 * month.h
 * Header file for class Month.
 */

#ifndef MONTH_H
#define MONTH_H

#include <string>
#include "day.h"
#include "grid.h"

//Month has list of days.
class Month
{
	public:
			Month();
			void update_month(int, std::string, int*, int);
			void print_month_num();
			void print_month_name();
			void set_leap_year();
			int determine_num_days();
			void print_num_days();
			void set_grid();
			void print_grid(bool);
			bool grid_is_set();
			void print_grid_row(bool,int);
			void print_grid_unit(bool,int);
			std::string get_month_name();
            void delete_days_grid();

	private:
			void start_grid_nums(int);
			
			int year_num;
			int month_num;
			int number_days;
			bool leap_year;
			bool grid_set;
			Day *days;
			std::string month_name;
			Grid* grid;
};


#endif /*MONTH_H*/
