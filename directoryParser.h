//directoryParser.h

#ifndef DIRECTORYPARSER_H
#define DIRECTORYPARSER_H

#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>


char *getcwd(char *buf, size_t size);

int listFilesInDirectory(char* path);

#endif
