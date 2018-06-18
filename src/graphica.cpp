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
	outtextxy(850,670,"Anton'ev Konstantin");
	outtextxy(850,730,"Ilya Kazancev");
	outtextxy(850,700,"Igor Lipovtsev");
	outtextxy(10,735,"SibSUTIS, 2018");
    settextstyle(3,3,3);
	outtextxy(t[0].x,t[0].y,v[0].form1);
	outtextxy(t[1].x,t[1].y,v[0].form2);
	outtextxy(t[2].x,t[2].y,v[0].form3);
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

