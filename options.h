//options.h
#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

extern int helpFlag;
extern int setIndentFlag;
extern int symLinkFlag;
extern int printInfoFlag;
extern int permissionsFlag;
extern int numLinksFlag;
extern int uidFlag;
extern int gidFlag;
extern int fileSizeFlag;
extern int lastModTimeFlag;
extern int tpiugsFlag;

extern int indentValINT;

extern char* indentValString;
extern char* dirName;


//function dec
void intializeFlags();
void setFlags(int argc, char** argv);
void printFlags();

#endif
