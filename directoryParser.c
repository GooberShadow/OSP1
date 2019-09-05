//directoryParser.c
#include "directoryParser.h"

char* getCWD() 
{
	long maxpath;
	char* mycwdp;
	
	if((maxpath = pathconf(".", _PC_PATH_MAX)) == -1)
	{
		perror("Error: Failed to determine the pathname length");
		return NULL;
	}
	
	if((mycwdp = (char*) malloc(maxpath)) == NULL)
	{
		perror("Error: Failed to allocate space for pathname. ");
		return NULL;
	}
	
	if(getcwd(mycwdp, maxpath) == NULL)
	{
		perror("failed to get current working directory");
		return NULL;
	}
	return mycwdp;
}

int listFilesInDirectory(char* path)
{
	struct dirent* direntp;
	DIR* dirp;
	
	if((dirp = opendir(path)) == NULL)
	{
		perror ("Failed to open directory");
		return 1;
	}
	
	while((direntp = readdir(dirp)) != NULL)
	{
		printf("%s\n", direntp->d_name);
	}
	while((closedir(dirp) == -1) && (errno == EINTR));
	
	return 0;
}

int isDirectory(char* path)
{
	struct stat statbuf;
	
	if(stat(path, &statbuf) == -1)
	{
		return 0;
	}
	else
	{
		return S_ISDIR(statbuf.st_mode);
	}
}

void checkHelpMessage()
{
	if(helpFlag == 1)
	{
		printHelp();
	}
}
void checkSymbolicLinks()
{
	if(symLinkFlag == 1)
	{
		//followLinks();
	}
}

void checkFileType(char* path)
{
	if(printInfoFlag == 1)
	{
		printFileInfo(path);
	}
}

void checkPermissions(char* path)
{
	if(permissionsFlag == 1)
	{
		printPermissions(path);
	}

}

void checkINODE(char* path)
{
	if(numLinksFlag == 1)
	{
		printINODE(path);
	}
}

void checkLastTimeModified(char* path)
{
	if(lastModTimeFlag == 1)
	{
		printModTime(path);
	}
}

void checkUID(char* path)
{
	if(uidFlag == 1)
	{
		printUID(path);
	}
}

void checkGID(char* path)
{
	if(gidFlag == 1)
	{
		printGID(path);
	}
}

void checkSize(char* path)
{
	if(fileSizeFlag == 1)
	{
		printSize(path);
	}
}

void checkTPIUGS(char* path)
{
	if(tpiugsFlag == 1)
	{
		printFileInfo(path);
		printPermissions(path);
		printINODE(path);
		printUID(path);
		printGID(path);
		printSize(path);
	}
}

void listdir(const char *name, int indent)
{
	DIR* dir;
	struct dirent* entry;
	
	if(!(dir = opendir(name)))
	{
		return;
	}
	
	while((entry = readdir(dir)) != NULL)
	{
		//printf("D_NAME: ");
		//printf(entry->d_name);
		if(isDirectory(name))
		{
			char path[1024];
			if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			{
				continue;
			}
			snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
			//Check help message first
			checkHelpMessage();
			printf("\n\n%*s-%s\t\t", indent, "", entry->d_name);
			//Check each option
			checkPermissions(path);
			checkINODE(path);
			checkFileType(path);
			checkUID(path);
			checkGID(path);
			checkSize(path);
			checkLastTimeModified(path);	
			checkTPIUGS(path);			

			listdir(path, indent + indentValINT);
		}
		else
		{
			//Check each option
			printf("\n\n%*s- %s", indent, "", entry->d_name);
		}
	}
	closedir(dir);
}
