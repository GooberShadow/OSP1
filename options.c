//options.c
#include "options.h"

int helpFlag;
int setIndentFlag;
int symLinkFlag;
int printInfoFlag;
int permissionsFlag;
int numLinksFlag;
int uidFlag;
int gidFlag;
int fileSizeFlag;
int lastModTimeFlag;
int tpiugsFlag;

int indentValINT;

char* indentValString;
char* dirName;

void initializeFlags()
{
	
	helpFlag = 0;
	setIndentFlag = 0;
	symLinkFlag = 0;
	printInfoFlag = 0;
	permissionsFlag = 0;
	numLinksFlag = 0;
	uidFlag = 0;
	gidFlag = 0;
	fileSizeFlag = 0;
	lastModTimeFlag = 0;
	tpiugsFlag = 0;

	indentValString = NULL;
	dirName = NULL;

}

static void EnableTpiugs()
{
	printInfoFlag = 1;
	permissionsFlag = 1;
	numLinksFlag = 1;
	uidFlag = 1;
	gidFlag = 1;
	fileSizeFlag = 1;
}

static void printArgs(int argc, char** argv)
{
	int i;
	for(i = 0; i < argc; i++)
	{
		printf("%d: %s\n", i, argv[i]);
	}
}

static int convertIndentStringToInt()
{
	if(indentValString != NULL)
	{
		return atoi(indentValString);
	}

	return -1;
}

void setFlags(int argc, char** argv)
{
	//getopts variables
	int i;
	int c;
	int opterr = 0;

	//while loop to get all the options
	while ((c = getopt(argc, argv, "hI:Ltpiugsdl")) != -1)
	{
		switch(c)
		{
			case 'h':
				helpFlag = 1;
				break;
			case 'I':
				setIndentFlag = 1;
				indentValString = optarg;
				indentValINT = convertIndentStringToInt();
				break;
			case 'L':
				symLinkFlag = 1;
				break;
			case 't':
				printInfoFlag = 1;
				break;
			case 'p':
				permissionsFlag = 1;
				break;
			case 'i':
				numLinksFlag = 1;
				break;
			case 'u':
				uidFlag = 1;
				break;
			case 'g':
				gidFlag = 1;
				break;
			case 's':
				fileSizeFlag = 1;
				break;
			case 'd':
				lastModTimeFlag = 1;
				break;
			case 'l':
				tpiugsFlag = 1;
				//EnableTpiugs();
				break;
			case '?':
				if(optopt = 'I'){
					printf("Option -%c requires an argument. \n", optopt);
				} 
				break;
		}
	}
	//setting the dir name
	for(i = optind; i < argc; i++)
	{
		if(argv[i] != NULL)
		{
			dirName = argv[i];
		}
	}
}

void printFlags()
{
	printf("-h = %d\n", helpFlag);
	printf("-I = %d\t%s\n", setIndentFlag, indentValString );
	printf("-L = %d\n", symLinkFlag);
	printf("-t = %d\n", printInfoFlag);
	printf("-p = %d\n", permissionsFlag);
	printf("-i = %d\n", numLinksFlag);
	printf("-u = %d\n", uidFlag);
	printf("-g = %d\n", gidFlag);
	printf("-s = %d\n", fileSizeFlag);
	printf("-d = %d\n", lastModTimeFlag);
	printf("-l = %d\n", tpiugsFlag);
}
