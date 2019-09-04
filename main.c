/*Author: BENJAMIN KEHE
 *File: main.c*/

#include "options.h"
#include "print.h"

int main(int argc, char** argv)
{
	initializeFlags();
	setFlags(argc, argv);
	printFlags();
	
	

//	printHelp();
	printAll();
	return 0;	
}


