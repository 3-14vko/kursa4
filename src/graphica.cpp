struct vforms
{
	char form1[16], form2[16], form3[16];
	int hidden;
};

struct stdco
{
    int x,y;
};

void DrawStdWin(vforms *v, stdco *t) {
	outtextxy(t[0].x,t[0].y,v[0].form1);
	outtextxy(t[1].x,t[1].y,v[0].form2);
	outtextxy(t[2].x,t[2].y,v[0].form3);
	settextstyle(4,0,1);
	outtextxy(650,670,"Anton'ev Konstantin");
	outtextxy(750,700,"&");
	outtextxy(800,730,"Ilya Kazancev");
	outtextxy(610,730,"Igor Lipovtsev");
	settextstyle(4,0,3);
	outtextxy(10,735,"SibSUTIS, 2018");
}

void PutStr(vforms v, stdco *t) {

	switch (v.hidden) {
		case 1:
			outtextxy( t[0].x,t[0].y+50, "___________");
			outtextxy( t[1].x,t[1].y+50, v.form2);
			outtextxy( t[2].x,t[2].y+50, v.form3);
			break;

		case 2:
			outtextxy(t[0].x,t[0].y+50,v.form1);
			outtextxy(t[1].x,t[1].y+50, "___________");
			outtextxy(t[2].x,t[2].y+50, v.form3);
			break;

		case 3:
			outtextxy(t[0].x,t[0].y+50,v.form1);
			outtextxy(t[1].x,t[1].y+50,v.form2);
			outtextxy(t[2].x,t[2].y+50, "___________");
			break;
	}
}

std::string GetStr(vforms v) {
	std::string s;
    return "\0";
}

