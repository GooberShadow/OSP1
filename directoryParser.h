//directoryParser.h

#ifndef DIRECTORYPARSER_H
#define DIRECTORYPARSER_H

#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include "options.h"

//char *getcwd(char *buf, size_t size);

int listFilesInDirectory(char* path);
char* getCWD();
int isDirectory(char* path);
void listdir(const char *name, int indent);

#endif
