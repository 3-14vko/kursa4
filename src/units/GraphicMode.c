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
