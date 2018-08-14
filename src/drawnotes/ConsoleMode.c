void ConsoleMode(char c, vforms *v, bool pause, int testq)
{
	string answer;
    int mark;
	if (c == '1')
	{
		cout
            << "=============================================\n"
            << v[0].form1
            << ' '
            << v[0].form2
            << ' '
            << v[0].form3
            << '\n'
            << '\n';
		for (int i=1; i < (v[0].hidden-1); ++i)
        {
            cout
                << v[i].form1;
            PrintSpaces(strlen(v[0].form1) - strlen(v[i].form1));
            cout
                << ' '
                << v[i].form2;
            PrintSpaces(strlen(v[0].form2) - strlen(v[i].form2));
            cout
                << ' '
                << v[i].form3;
            cout << '\n';

            if (pause) system("pause");
        }
        cout
            << "=============================================\n\n";
	}

	if (c=='2')
    {
        randomize(v);
        int passed = 0;
        int test[testq];
        passed = 0;
        for (int i=0; i<testq; ++i) //Generates array of randomized elements
        {
            //found = true;
            //while (found)
            //{
                test[i] = random(1,98);
                //found = false;
                //for (int j=i; j>=0; --j)
                    //if (test[j] == test[i]) found = true;
            //}
        }

        for (int i=0; i<testq; ++i)
        {
            switch (v[test[i]].hidden)
            {
            case 1:
                    system("cls");
                    cout << i << endl;
                    cout
                        << v[0].form1
                        << ' '
                        << v[0].form2
                        << ' '
                        << v[0].form3
                        << '\n'
                        << '\n';
                    PrintSpaces(strlen(v[test[i]].form1)+1);
                    cout
                        << v[test[i]].form2;
                    PrintSpaces(strlen(v[0].form2)-strlen(v[test[i]].form2)+1);
                    cout
                        << v[test[i]].form3
                        << "\nEnter missed word: ";
                    cin
                        >> answer;
                    if (answer == ChrToStr(v[test[i]].form1)) ++passed;
                    break;
            case 2:
                    system("cls");
                    cout << i << endl;
                    cout
                        << v[0].form1
                        << ' '
                        << v[0].form2
                        << ' '
                        << v[0].form3
                        << '\n'
                        << '\n';
                   cout
                        << v[test[i]].form1;
                   PrintSpaces(strlen(v[0].form1)-strlen(v[test[i]].form1));
                   cout
                        << ' ';
                   PrintSpaces(strlen(v[test[i]].form2)+1);
                   cout
                        << v[test[i]].form3;
                   if (answer == ChrToStr(v[test[i]].form2)) ++passed;
                   break;
            case 3:
                    system("cls");
                    cout << i << endl;
                    cout
                        << v[0].form1
                        << ' '
                        << v[0].form2
                        << ' '
                        << v[0].form3
                        << '\n'
                        << '\n';
                    cout
                        << v[test[i]].form1;
                    PrintSpaces(strlen(v[0].form1)-strlen(v[test[i]].form1));
                    cout
                        << ' ';
                    cout
                        << v[test[i]].form2;
                    PrintSpaces(strlen(v[0].form2)-strlen(v[test[i]].form2));
                    cout
                        << "\nPrint missed word: ";
                    cin
                        >> answer;
                    if (answer == ChrToStr(v[test[i]].form3)) ++passed;
                    break;
            default: cout << "ERROR\n", system("pause");
            }
        }
        cout << passed << endl;
        nullize(v);
    }
    if (c=='3')
    {
        cout
            << "Use 'help' to show commands list\n";
        while
    }
}
