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

struct stdco
{
    int x,y;
};

std::string TrimLeft (std::string s);
std::string TrimRight (std::string s);
std::string Trim (std::string s);
std::string GetWord (std::string s, unsigned char n);
std::string ChrToStr(char * s);
char * StrToChr(std::string s);

vforms * nullize(vforms *);
vforms * randomize(vforms);

void GraphicMode(char, vforms*, int);
void ConsoleMode(char, vforms *, bool, int);

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

int main()
{
	char c;
	char *fileway = new char[strlen("verbs.dat")];
	fileway = StrToChr("verbs.dat");
	vforms *v = ImportStrcts("verbs.dat");
	bool graph = 0, pause = 1;
	int testq = 30;
	std::cin >> c;
	while (c != '4'){
	switch (c)
	{
	    case '1': graph ? GraphicMode(c,v) : ConsoleMode(c,v,pause); break;
	    case '2': graph ? GraphicMode(c,v) : ConsoleMode(c,v,pause); break;
	    case '3': ConsoleMode(c,v,pause); break;
	    case '4': exit(EXIT_SUCCESS); break;
	    default: break;
	}
	}

	return 0;
}

void GraphicMode(char c, vforms *verbs, int testq)
{
    //ZDES ZADAI OKNO
    stdco title[3];
    stdco all, cout;
    char pressed = '\0';

    all.x = ; // VSE (V TESTE: kol-vo voprosov; V SPRAVKE: kol-vo vseh glagolov, ravnoe v[0].hidden)
    all.y = ;

    cout.x = ; // SCHOTCHIK
    cout.y = ;

    title[0].x = ; //PERVYI ZAGOLOVOK
    title[0].y = ;

    title[1].x = ; // VTOROY ZAGOLOVOK
    title[1].y = ;

    title[2].x = ; // TRETIY ZAGOLOVOK
    title[2].y = ;

    if (c == '1') // DLYA SPRAVKI
    {
        int i = 1;
        while ((i<verbs[0].hidden) or (pressed == 'q'))
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
    closewindow();
}

void ConsoleMode(char c, vforms *verbs, bool pause, int testq)
{
}

void nullize(vforms * verbs)
{
    for (int i=1; i<verbs[0].hidden; ++i, verbs[i].hidden = 0);
}

void randomize(vforms * verbs)
{
    for (int i=1; i<verbs[0].hidden; ++i, verbs[i].hidden = random(1,3));
}
