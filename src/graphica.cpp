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

void PutStr() {
	
	

}


