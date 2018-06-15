#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void far settextstyle(int f,int b,int ch);

void DrawStdWin(vforms *v, stdco *t) {

	outtextxy(t[0].x,t[0].y,v[0].form1);
	outtextxy(t[1].x,t[1].y,v[0].form2);
	outtextxy(t[2].x,t[2].y,v[0].form3);
	far settextstyle(4,0,1);
	outtextxy(650,670,"Anton'ev Konstantin");
	outtextxy(750,700,"&");
	outtextxy(800,730,"Ilya Kazancev");
	outtextxy(610,730,"Igor Lipovtsev");
	far settextstyle(4,0,3);
	outtextxy(10,735,"SibSUTIS, 2018");
}

void PutStr(vforms v, stdco *t) {

//if( code == 32){ // Poka ne najat Enter
	switch (v.hidden) {
		case 1:
			outtextxy( t[0].x,t[0].y+50, "___________");
			outtextxy( t[1].x,t[1].y+50, v[i].form2);
			outtextxy( t[2].x,t[2].y+50, v[i].form3);
			char *O = new char[8]; // ukazatel na massive
			for( int i = 0; i <= 8;) {
				O[i] = getch();// Vot on
				i++;
				outtextxy( 50,100, *O);// Posimvolnui vvod
				if( code == 32);// Esli najat Enter to vvod konchitsya
				break;//
			}
			break;

		case 2:
			outtextxy( t[0].x,t[0].y+50,v[i].form1);
			outtextxy( t[1].x,t[1].y+50, "___________");
			outtextxy( t[2].x,t[2].y+50, v[i].form3);
			char *O = new char[8];
			for( int i = 0; i <= 8;) {
				O[i] = getch();
				i++;
				outtextxy( 50,100, *O);
				if( code == 32)
					break;
			}
			break;

		case 3:
			outtextxy( t[0].x,t[0].y+50,v[i].form1);
			outtextxy( t[1].x,t[1].y+50, v[i].form2);
			outtextxy( t[2].x,t[2].y+50, "___________");
			char *O = new char[8];
			for( int i = 0; i <= 8;) {
				O[i] = getch();
				i++;
				outtextxy( 50,100, *O);
				if( code == 32)
					break;
			}
			break;
	}
}
