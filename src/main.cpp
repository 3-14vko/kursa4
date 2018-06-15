#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include "strings.cpp"
//#include <graphics.h>

struct vforms
{
	char form1[16], form2[16], form3[16];
	int hidden;
};

std::string TrimLeft (std::string s);
std::string TrimRight (std::string s);
std::string Trim (std::string s);
std::string GetWord (std::string s, unsigned char n);
std::string ChrToStr(char * s);
char * StrToChr(std::string s);

void GraphicMode(char, vforms*);
void ConsoleMode(char, bool, vforms*);

vforms * ImportStrcts(std::string datafile)
{
	char *fileway = new char[datafile.length()+1];
	fileway = StrToChr(datafile);
	FILE *f = fopen(fileway,"rb");
	vforms first;
	fread(&first,sizeof(vforms),1,f);
	vforms t, *array = new vforms[first.hidden];
	std::cout << first.hidden;
	array[0] = first;
	for (int i=1; i<first.hidden; ++i)
	{
			fread(&t,sizeof(vforms),1,f);
			array[i] = t;
	}
	fclose(f);
	return array;
}

int main()
{
	char c;
	char *fileway = new char[strlen("verbs.dat")];
	fileway = StrToChr("verbs.dat");
    //vforms *verbs = ImportStrcts(s);
	return 0;
}

void GraphicMode(char c, vforms *verbs)
{

}

void ConsoleMode(char c, bool pause, vforms *verbs)
{
}

