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

	exit(0);	
}

void printFileInfo(char* path)
{
	struct stat attr;
	stat(path, &attr);
	printf("File info:%d:  ", attr.st_mode);
}

void printModTime(char* path)
{
	struct stat attr;
	stat(path, &attr);
	printf("Last modified time:%s  ", ctime(&attr.st_mtime));
}

void printUID(char* path)
{
	struct stat attr;
	stat(path, &attr);
	printf("UID:%d:  ", attr.st_uid );
	//printf(path.st_mode);
}

void printGID(char* path)
{
	struct stat attr;
	stat(path, &attr);
	printf("GID:%d:  ", attr.st_gid);
}

void printAll()
{
	//listFilesInDirectory(dirName);
	listdir(dirName, 0);	
}
