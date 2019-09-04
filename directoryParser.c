//directoryParser.c
#include "directoryParser.h"

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

