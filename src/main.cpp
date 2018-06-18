#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include "strings.cpp"
#include "graphica.cpp"
#include <conio.h>
using namespace std;

void DrawStdWin(vforms *, coordinats *);
void PutStr(vforms, coordinats *);

string TrimLeft (string);
string TrimRight (string);
string Trim (string);
string GetWord (string, int);
string ChrToStr(char *);
char * StrToChr(string);

int ran(int a) {return rand() % a;}
int random(int a, int b) {return (ran(b-a+1) + a);}

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
    for (int i=1; i<v[0].hidden; ++i, v[i].hidden = 0);
}

void randomize(vforms * v)
{
    for (int i=1; i<v[0].hidden; ++i, v[i].hidden = random(1,3));
}

void GraphicMode(char, vforms *, int);
void ConsoleMode(char, vforms *, bool, int);

int main()
{
	cout
        << "IrregularVerbs app.\n"
        << "SibSUTIS 2018\n"
        << "IP-714 band: Anton'ev K., Kazantsev I., Lipovtsev I.\n\n";
	char c;
	char *fileway = new char[strlen("verbs.dat")];
	fileway = StrToChr("verbs.dat");
	vforms *v = ImportStrcts("verbs.dat");
	bool graph = 0, pause = 1;
	int testq = 30;
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

void GraphicMode(char c, vforms *v, int testq)
{
    initwindow(1024,768,"IrregularVerbs");
    coordinats title[3];
    coordinats all, cout;
    char pressed = '\0';

    all.x = 60; // VSE (V TESTE: kol-vo voprosov; V SPRAVKE: kol-vo vseh glagolov, ravnoe v[0].hidden)
    all.y = 20;

    cout.x = 30; // SCHOTCHIK
    cout.y = 20;

    title[0].x = 200; //PERVYI ZAGOLOVOK
    title[0].y = 100;

    title[1].x = 358; // VTOROY ZAGOLOVOK
    title[1].y = 100;

    title[2].x = 590; // TRETIY ZAGOLOVOK
    title[2].y = 100;

    if (c == '1') // DLYA SPRAVKI
    {
        int i = 1;
        while ((i<v[0].hidden) or (pressed != 'q'))
        {
            DrawStdWin(v,title);
            cin >> pressed;
            if ((pressed == KEY_LEFT) and (i > 1)) --i, PutStr(v[i],title);
            if (pressed == KEY_RIGHT) ++i, PutStr(v[i],title);
        }
    }

    if (c == '2') // DLYA TESTA
    {
        randomize(v);
        DrawStdWin(v,title);
        for (int i=1; i<=testq; ++i)
        {

        }
    }
    closegraph();
}

void ConsoleMode(char c, vforms *v, bool pause, int testq)
{
	string answer;
	if (c == '1')
	{
		for (int i=0; i < v[0].hidden; ++i)
        {
            cout << v[i].form1 << "         " << v[i].form2 << "         " << v[i].form3 << std::endl;
            if (pause) system("pause");
        }
	}
}
