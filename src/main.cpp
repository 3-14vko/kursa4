#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include "strings.cpp"
#include <graphics.h>
#include "graphica.cpp"
#include <conio.h>

void DrawStdWin(vforms *v, stdco *t);
void PutStr(vforms v, stdco *t);

std::string TrimLeft (std::string s);
std::string TrimRight (std::string s);
std::string Trim (std::string s);
std::string GetWord (std::string s, int n);
std::string ChrToStr(char * s);
char * StrToChr(std::string s);

int ran(int a) {return rand() % a;}
int random(int a, int b) {return (ran(b-a+1) + a);}

vforms * ImportStrcts(std::string datafile)
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

void nullize(vforms * verbs)
{
    for (int i=1; i<verbs[0].hidden; ++i, verbs[i].hidden = 0);
}

void randomize(vforms * verbs)
{
    for (int i=1; i<verbs[0].hidden; ++i, verbs[i].hidden = random(1,3));
}

void GraphicMode(char c, vforms *verbs, int testq);
void ConsoleMode(char c, vforms *verbs, bool pause, int testq);

int main()
{
	char c;
	char *fileway = new char[strlen("verbs.dat")];
	fileway = StrToChr("verbs.dat");
	vforms *v = ImportStrcts("verbs.dat");
	bool graph = 0, pause = 0;
	int testq = 30;
	while (c != '4'){
	std::cin >> c;
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

void GraphicMode(char c, vforms *verbs, int testq)
{
    initwindow(1024,768,"IrregularVerbs");
    stdco title[3];
    stdco all, cout;
    char pressed = '\0';

    all.x = 60; // VSE (V TESTE: kol-vo voprosov; V SPRAVKE: kol-vo vseh glagolov, ravnoe v[0].hidden)
    all.y = 20;

    cout.x = 30; // SCHOTCHIK
    cout.y = 20;

    title[0].x = 340; //PERVYI ZAGOLOVOK
    title[0].y = 50;

    title[1].x = 340; // VTOROY ZAGOLOVOK
    title[1].y = 50;

    title[2].x = 340; // TRETIY ZAGOLOVOK
    title[2].y = 50;

    if (c == '1') // DLYA SPRAVKI
    {
        int i = 1;
        while ((i<verbs[0].hidden) or (pressed != 'q'))
        {
            DrawStdWin(verbs,title);
            pressed = getch();
            if ((pressed == KEY_LEFT) and (i > 1)) --i, PutStr(verbs[i],title);
            if (pressed == KEY_RIGHT) ++i, PutStr(verbs[i],title);
        }
    }

    if (c == '2') // DLYA TESTA
    {
        randomize(verbs);
        DrawStdWin(verbs,title);
        for (int i=1; i<=testq; ++i)
        {

        }
    }
    closegraph();
}

void ConsoleMode(char c, vforms *verbs, bool pause, int testq)
{
	std::string answer;
	if (c == '1')
	{
		for (int i=0; i < verbs[0].hidden; ++i)
        {
            std::cout << verbs[i].form1 << "         " << verbs[i].form2 << "         " << verbs[i].form3 << std::endl;
            if (pause) getch();
        }
	}
}

