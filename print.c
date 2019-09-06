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

void printSymbolicLinks(char* path)
{
	struct stat fileStat;
	lstat(path, &fileStat);
	switch(fileStat.st_mode & S_IFMT)
	{
		case S_IFLNK:
			printf("Symbolic Links: This is a link : ");
			break;
		case S_IFREG:
			printf("Symbolic Links: This is not a link : ");
			break;
	}
	//int status;
	//status = lstat(path, &fileStat);
	/*if (S_ISLNK(fileStat.st_mode))
	{
		printf("Symbolic Links :This file is a link:");
	}	
	else
	{
		printf("Symbolic Links :This file is not a link:");
	}*/
}

void printFileInfo(char* path)
{
	struct stat attr;
	stat(path, &attr);
	printf("File info:%d:  ", attr.st_mode);
}

void printPermissions(char* path)
{
	struct stat fileStat;
	stat(path, &fileStat);

	printf("File Permissions: ");
	printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
	printf(" : ");
}

void printINODE(char* path)
{
	struct stat fileStat;
	stat(path, &fileStat);
	printf("Inode number:%d: ", fileStat.st_ino);
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

void printSize(char* path)
{
	struct stat fileStat;
	stat(path, &fileStat);
	printf("SIZE:%d bytes: ", fileStat.st_size);
}

void printAll()
{
	//listFilesInDirectory(dirName);
	listdir(dirName, 0);	
}
