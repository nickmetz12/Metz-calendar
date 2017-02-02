/*
 * Nicholas Metzger
 * 8/3/16
 * day.h
 * Header file for class Day.
 */
#ifndef DAY_H
#define DAY_H

#include <string>

//Days has both a number and a name.
class Day
{
	public:
			Day();
			void update_day(int ,std::string);
			void print_day_num();
			void print_day_name();
			std::string get_day_name();

	private:
			int	day_num;
			std::string day_name;
};

#endif /*DAY_H*/
