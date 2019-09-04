//print.c

#include "print.h"

void printHelp()
{
	printf("\n----HELP MESSAGE----\n\n");
	printf("-h: Get Help Message.\n");
	printf("-I n: Change indentation to n spaces.\n");
	printf("-L: Follow symbolic links.\n");
	printf("-t: Print info on file.\n");
	printf("-p: Print permission bits.\n");
	printf("-i: Print the number of links to file in inode table.\n");
	printf("-u: Print UID.\n");
	printf("-g: Print GID.\n");
	printf("-s: Print the size in bytes.\n");
	printf("-d: Show the time of last modification.\n");
	printf("-l: Print all options of tpiugs.\n");
}

void printAll()
{
	listFilesInDirectory(dirName);
}
