# upDate

ABOUT
	upDate is a simple user-defined date object that can perform assignments, comparison, and basic arithmetic using operators instead of calling functions. The arithmetic is made possible through the conversion of Gregorian calendars (typical calendars that we all know and use) to Julian calendars (a single integer that can be used to extract the month, day, and year from). All arithmetic is performed in Julian calendar format and then converted back into Gregorian for display in mm/dd/yyyy format.

Operators included are:
•	+ (int + date) or (date + int)
•	++ (pre and post)
•	- (int – date) or (date – int)
•	-- (pre and post)
•	=
•	+=
•	-=
•	==
•	<
•	>

OBJECTIVE
	This program is used to familiarize the concept of operator overloading and dynamic memory allocation (manual control over memory). For this particular program, a pointer is used to keep track of the month, day, and year. Integers would have been much easier to work with but that is not the point of this program.
