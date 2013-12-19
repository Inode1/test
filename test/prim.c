#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
FILE *openfile(char* fname, char* permissions)
{
	FILE *db;
	db = fopen(fname, permissions);
	return db;
}
void filewrite(char* fname,...)
{
	FILE *filename = fopen(fname, "a");
	char* t;
	va_list argptr;
	va_start (argptr, fname);
	for(;;)
	{
		t = va_arg(argptr, char*);
		if (t == NULL ) break;
		fprintf(filename, "%s; ", t);
	}
	va_end(argptr);
	fclose(filename);
}
void fileread(char* fname)
{
	char ch;
	int charnum = 0;
	char* Str = (char*)malloc(sizeof(char));
	FILE *db = openfile(fname,"r");
	int memsize = sizeof(char);

	while ((ch = getc(db)) != EOF)
	{
		Str[charnum] = ch;
		charnum++;
		memsize += sizeof(char);
		Str = (char*)realloc(Str, memsize);
	}
	Str[charnum] = '\0';
	printf("%s", Str);
}
void main()
{
	filewrite("db.txt","Hello world","jdodifjsofij","fjfjfjfj",NULL);
	//fileread("db.txt");
}
