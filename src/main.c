//login ip714kii password bkmzlfybk229jctym
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include "strings.cpp"
#include "graphica.cpp"
#include <conio.h>
#include <ctime>
using namespace std;

void DrawStdWin(vforms *, coordinats *);
void PutStr(vforms, coordinats *);

string TrimLeft (string);
string TrimRight (string);
string Trim (string);
string GetWord (string, int);
string ChrToStr(char *);
char * StrToChr(string);

int ran(int a)
{
    return rand() % a;
}

int random(int a, int b)
{
    return (ran(b-a+1) + a);
}

vforms * ImportStrcts(string datafile)
{
	char *fileway = new char[datafile.length()+1];
	fileway = StrToChr(datafile);
	FILE *f = fopen(fileway,"rb");
	vforms first;
	fread(&first,sizeof(vforms),1,f);
	vforms t, *array = new vforms[first.hidden];
	array[0] = first;
	for (int i=1; i<first.hidden; ++i)
	{
			fread(&t,sizeof(vforms),1,f);
			array[i] = t;
	}
	fclose(f);
	return array;
}

void nullize(vforms * v)
{
    for (int i=1; i<(v[0].hidden-1); ++i, v[i].hidden = 0);
}

void randomize(vforms * v)
{
    for (int i=1; i<(v[0].hidden-1); ++i, v[i].hidden = random(1,3));
}

void PrintSpaces(int n)
{
    if (n<1) return;
    for (int i=0; i<n; ++i)
        cout
            << " ";
}

void GraphicMode(char, vforms *, int);
void ConsoleMode(char, vforms *, bool, int);

int main(int argQ, char *argc[])
{
	//for (int i=1; i<100; ++i, cout << random(1,100-i) << endl);
	srand(static_cast<unsigned int>(time(0)));
	cout
        << "IrregularVerbs app.\n"
        << "SibSUTIS 2018\n"
        << "IP-714 band: Anton'ev K., Kazantsev I., Lipovtsev I.\n\n";
	char c;
	char *fileway = new char[strlen("verbs.dat")];
	fileway = StrToChr("verbs.dat");
	vforms *v = ImportStrcts("verbs.dat");
	//cout << MessageBox(0,"Hello, world!","ERROR",MB_OKCANCEL);
	bool graph = 0, pause = 0;
	int testq = 4;
	while (c != '4'){
        cout
                << "Choose action: \n"
                << "\t(1) Show irregular verbs list\n"
                << "\t(2) Pass the test\n"
                << "\t(3) Entering commands mode\n"
                << "\t(4) Quit\n\n"
                << "do: ";
        cin
            >> c;
        switch (c)
        {
            case '1': graph ? GraphicMode(c,v,testq) : ConsoleMode(c,v,pause,testq); break;
            case '2': graph ? GraphicMode(c,v,testq) : ConsoleMode(c,v,pause,testq); break;
            case '3': ConsoleMode(c,v,pause,testq); break;
            case '4': exit(EXIT_SUCCESS); break;
            default: break;
	}
	}
	return 0;
}
