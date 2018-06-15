#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void far settextstyle(int f,int b,int ch);  // дл€ шрифта

void PutStr (char vforms * v){//вывод строк
	int N = 30;// Kol-vo zadaniy
    int H = 15;// Kol-vo vupolnil
	char code, s, O[50];
setcolor(COLOR(0,255,0));
far settextstyle(4,0,5);
// массивы дл€ символов
char *Num1 = new char[0];
char *Num2 = new char[0];
// ќдна из попул€рных функций преобразовани€ в символьный вид
itoa (H,Num1,10);
itoa (N,Num2,10);
// собственно их вывод
outtextxy ( 100, 10, Num2 );	
outtextxy ( 0, 10, Num1 );
outtextxy ( 80, 10, "/" );
//очищение массива сколько выполнил
//free(Num2);
free(Num1);
	setcolor(COLOR(0,255,0));
	code = getch();
	struct vforms
{
char * form1;
char * form2;
char * form3;
int hidden;
}
while(H=!v[0].hidden){
if( code == 32){ // пока не нажат энтер будет то что дальше
switch (v[i].hidden)
{
    case 0:
    	outtextxy( 50,100, v[i].form1);
    	outtextxy( 250,100, v[i].form2);
    	outtextxy( 550,100, v[i].form3);
	break;
	
    case 1: 
    outtextxy( 50,100, "___________");
	outtextxy( 250,100, v[i].form2);
    outtextxy( 550,100, v[i].form3);
	char *O = new char[8]; // указатель на массив который тебе надо выудить будет
	for( int i = 0; i <= 8;){
		O[i] = getch();// вот он
		i++;
	 outtextxy( 50,100, *O);// посимвольный вывод
	 if( code == 32);// если нажмет он клавишу энтер то ввод закончитс€
	 break;// и дальше должна заробить тво€ функи€ рандома оп€ть
	}
    break;
    
	case 2:
	outtextxy( 50,100, v[i].form1);
	outtextxy( 250,100, "___________");
	outtextxy( 550,100, v[i].form3);
	char *O = new char[8];
	for( int i = 0; i <= 8;){
		O[i] = getch();
		i++;
	 outtextxy( 50,100, *O);
	 if( code == 32)
	 break;
	}
	break;
	
	case 3:
	outtextxy( 50,100, v[i].form1);
	outtextxy( 250,100, v[i].form2);
	outtextxy( 550,100, "___________"); 
	char *O = new char[8];
	for( int i = 0; i <= 8;){
		O[i] = getch();
		i++;
	 outtextxy( 50,100, *O);
	 if( code == 32)
	 break;
	}
	break;
                }
            }
        }
    }
    
    void PutVerbs(char vforms * v){  // дл€ просмотра глаголов типо теории
	    char *Num1 = new char[0];
		int code;
    	code = getch(); 
        if (code==27) break; // если нажат Esc  то выход
    	for(int i = 1; i <= N;){
		itoa (i,Num1,10);//как ты и просил - 
    		outtextxy( 50,100, *Num1);//вывод количества просматриваемых глаголов
    		if(code == 77){// 77 и 75 - клавиши вправо и влево соответственно
    			i=i+1;
    			outtextxy( 50,100, v[i].form1);
    	        outtextxy( 250,100, v[i].form2);
    	        outtextxy( 550,100, v[i].form3);
			}
			if(code == 75 && i > 1){
			i = i-1;
			outtextxy( 50,100, v[i].form1);
    	    outtextxy( 250,100, v[i].form2);
    	    outtextxy( 550,100, v[i].form3);
		    }
    	outtextxy( 50,100, v[i].form1);
    	outtextxy( 250,100, v[i].form2);
    	outtextxy( 550,100, v[i].form3);
    	bar(50, 100, 850,350);
    	free(Num1);
	    }
	}
	
	
void structure_window(){ // ƒефолт который загружаетс€ в окно + функции дл€ юзера
if (ch == 1){// ch  идет из твоего меню
	while(1){
	PutVerbs(vforms * v);
	far settextstyle(4,0,1);
outtextxy(100,100,"Inf-e        I        II");
outtextxy(650,670,"Anton'ev Konstantin");
outtextxy(750,700,"&");
outtextxy(600,730,"Ilya Kazancev");
outtextxy(800,730,"Igor Lipovtsev");
far settextstyle(4,0,3);
outtextxy(10,735,"SibSUTIS, 2018");
} }

 if (ch == 2){
 	while(1){
    PutStr(vforms * v);
    far settextstyle(4,0,1);
outtextxy(100,100,"Inf-e        I        II");
outtextxy(650,670,"Anton'ev Konstantin");
outtextxy(750,700,"&");
outtextxy(600,730,"Ilya Kazancev");
outtextxy(800,730,"Igor Lipovtsev");
far settextstyle(4,0,3);
outtextxy(10,735,"SibSUTIS, 2018");
 } }
 if ( ch == 3 ){
far settextstyle(4,0,1);
outtextxy(512,384,"You press Exit, Alloha ");
outtextxy(650,670,"Anton'ev Konstantin");
outtextxy(750,700,"&");
outtextxy(600,730,"Ilya Kazancev");
outtextxy(800,730,"Igor Lipovtsev");
far settextstyle(4,0,3);
outtextxy(10,735,"SibSUTIS, 2018");
}
}


void show_window(){ //само окно
initwindow(1024,768,"IrregularVerbs");
setfillstyle(1,0);
bar (0, 0, 1024, 768);
structure_window();
system("PAUSE");
}
