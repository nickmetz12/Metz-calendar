Nicholas Metzger
2/2/17
Calendar Program


Purpose:

                Prints to the terminal a grid view of a specified calendar 
        year from years 1-3000 including months in that year and correct
        days of the week for each month. Also able to select view of certain
        month in a given year.
                This program is a personal project of mine and is not to be
        used or redistributed without my consent.

List of files:

        -main.cpp organizes the program for correct output
        -calendar.h is the header file for the calendar class
        -calendar.cpp is the implementation for the calendar class
        -year.h is the header file for the year class
        -year.cpp is the implementation  for the year class
        -month.h is the header file for the month class
        -month.cpp is the implementation for the month class
        -day.h is the header file for the day class
        -day.cpp is the implementation of the day class
        -grid.h is the struct of a grid element

How to compile:

        Use included Makefile.
                
                        or

        clang++ main.cpp calendar.cpp year.cpp month.cpp day.cpp

Data Structures:
        
        An instance of a calendar class holds a 3000 element array of
        years. 
        
        An instance of a year class holds a 12 element array of 
        months. A year is out of bounds if <1 or >3000.
                
        An instance of a month class holds a 42 element array of 
        grid structs, and a dynamic array of days. A month number must 
        be >=1 and <=12. Each month also has a name.
                
        An instance of a day has both a name and number.
        
        An instance of the grid struct holds both a number (day) and a boolean
        (to determine if valid day or not inside month).        


Outline of algorithms:
        
        To add years 1-3000 to the list of years in Calendar:
                
                        The Calendar class creates a 3000 element array of 
                years, and then updates each year. The year number at index
                i of the array of year is i + 1 because starting with year 1.
                Then for each year, determines if that year is a leap year. If
                that year is a leap year, then sets a leap_year boolean for 
                the month of February in that year to be true. Then for each
                month in that year, sets the month number and name. Also 
                inside each month, determines the number of days and then
                allocated memory accordingly for an array if days. For each
                day, the day number and day of the week is set. In order to
                determine which day of the week each day is, a count of 
                the number of days total in all previous years is kept track
                of.

        To store a month inside a grid: 
                
                        First, the day of the week of the first day in that
                month is determined, and thus gives a starting point in which
                to begin setting grid structs. For example, if the first day
                of a certain month is on a Saturday, then the starting index
                of the 42 array of grid structs is 6. Once the intial index
                is determined, each grid struct has its day number updated
                accordingly and its boolean of whether it is a valid grid cell
                is set to true (initialized as false). 

        To print a grid year: 
        
                        If all the grids for each month is not already set,
                then the grids are set. Then as implemented in print_year_grid
                in the Year class, multiple loops are performed in order to
                correctly print out a grid view of a calendar year. Since
                the grid is stored as a month, in order to print a 4x3 grid of
                month grids, thus each row of this 4x3 grid (3 grid months) is 
                the union of the same row in those 3 months. e.g. the first
                row of the 4x3 grid is the combination of the first row from
                each month in that row of the 4x3 grid.

Example output (input was 1 2016):

Welcome to Metz Calendar!

Input options (please input number): 

	1) year grid view (input <year> between 1 and 3000)

	2) next year

	3) previous year

	4) month in current year (input <month>)

	5) quit
						2016
         	January                     February                     March
	Su  Mo  Tu  We  Th  Fr  Sa  Su  Mo  Tu  We  Th  Fr  Sa  Su  Mo  Tu  We  Th  Fr  Sa  
	/   /   /   /   /   1   2   /   1   2   3   4   5   6   /   /   1   2   3   4   5   
	3   4   5   6   7   8   9   7   8   9   10  11  12  13  6   7   8   9   10  11  12  
	10  11  12  13  14  15  16  14  15  16  17  18  19  20  13  14  15  16  17  18  19  
	17  18  19  20  21  22  23  21  22  23  24  25  26  27  20  21  22  23  24  25  26  
	24  25  26  27  28  29  30  28  29  /   /   /   /   /   27  28  29  30  31  /   /   
	31  /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   
        	   April                         May                        June
	Su  Mo  Tu  We  Th  Fr  Sa  Su  Mo  Tu  We  Th  Fr  Sa  Su  Mo  Tu  We  Th  Fr  Sa  
	/   /   /   /   /   1   2   1   2   3   4   5   6   7   /   /   /   1   2   3   4   
	3   4   5   6   7   8   9   8   9   10  11  12  13  14  5   6   7   8   9   10  11  
	10  11  12  13  14  15  16  15  16  17  18  19  20  21  12  13  14  15  16  17  18  
	17  18  19  20  21  22  23  22  23  24  25  26  27  28  19  20  21  22  23  24  25  
	24  25  26  27  28  29  30  29  30  31  /   /   /   /   26  27  28  29  30  /   /   
	/   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   
        	   July                        August                   September
	Su  Mo  Tu  We  Th  Fr  Sa  Su  Mo  Tu  We  Th  Fr  Sa  Su  Mo  Tu  We  Th  Fr  Sa  
	/   /   /   /   /   1   2   /   1   2   3   4   5   6   /   /   /   /   1   2   3   
	3   4   5   6   7   8   9   7   8   9   10  11  12  13  4   5   6   7   8   9   10  
	10  11  12  13  14  15  16  14  15  16  17  18  19  20  11  12  13  14  15  16  17  
	17  18  19  20  21  22  23  21  22  23  24  25  26  27  18  19  20  21  22  23  24  
	24  25  26  27  28  29  30  28  29  30  31  /   /   /   25  26  27  28  29  30  /   
	31  /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   
        	 October                     November                    December
	Su  Mo  Tu  We  Th  Fr  Sa  Su  Mo  Tu  We  Th  Fr  Sa  Su  Mo  Tu  We  Th  Fr  Sa  
	/   /   /   /   /   /   1   /   /   1   2   3   4   5   /   /   /   /   1   2   3   
	2   3   4   5   6   7   8   6   7   8   9   10  11  12  4   5   6   7   8   9   10  
	9   10  11  12  13  14  15  13  14  15  16  17  18  19  11  12  13  14  15  16  17  
	16  17  18  19  20  21  22  20  21  22  23  24  25  26  18  19  20  21  22  23  24  
	23  24  25  26  27  28  29  27  28  29  30  /   /   /   25  26  27  28  29  30  31  
	30  31  /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   /   

	Acknowledgements:
        	NA
	
