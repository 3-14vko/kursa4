/*
RULES
	variable: AaBb
	function: aaBb
	const: AABB
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define cls system("cls")
#define UNIVER "SibSUTIS, 2018"
#define APPNAME "IrregularVerbs"
#define IGOR "Igor Lipovtsev"
#define ILYA "Ilya Kazantsev"
#define KOSTYA "Konstantin Anton'ev"
#define writeln printf("\n")
#define readln getch()

int fileExists (char *FileName);
void consoleMode (int Mode, )

int main (int InputArgumentsQ, char** InputArguments)
{
	//var
	char DBFilename[256] = "db.iv\0";
 	char Command[256]; //ONLY FULL AND TRIMMED
	const char **MENU = {"EXIT", "SHOW VERBS LIST", "LEARNING TEST", "RESULT TEST", "SETTINGS", "COMMANDS MODE", "ABOUT", "MENU"};
	
	GLOBAL_VAR g;
	g.Choice = '\0';
	g.Graph = 0;
	g.Pause = 0;
	g.NewScore = 0;
	g.OldScore = 0;
	
	printf(APPNAME);
	writeln;
	printf(UNIVER);
	writeln;
	Sleep(2500);
	
	if (InputArgumentsQ > 1) //If database filename got from output 
	{
		switch(fileExists(InputArguments[1]))
		{
			case 0: MessageBox(NULL,"Input file not found","IrregularVerbs - ERROR",MB_ICONERROR); break;
			case 1: strcpy(DBFilename,InputArguments[1]); break; 
		}		
	}
	
	
	switch( (!fileExists(DBFilename)) && (MessageBox(NULL,"DB file not found.\n\nDo you want to choose it now?","IrregularVerbs - ERROR",MB_YESNO) == 7) ) //SEE COMM-2  
	{
		case 1: strcpy(DBFilename,"NOT_FOUND\0"); break; //Pressed NO
		case 0: //Pressed YES
			while (!fileExists(DBFilename))
			{
				cls;
				printf("$$ SETTINGS >> DB FILE\n\n");
				printf("Note:\n\tYou can also drag the right file to this window by mouse\n\n");
				printf("Note:\n");
				printf("\tType 'exit' to quit app\n\tType 'skip' to enter later\n");
				printf("\nEnter DB filepath: ");
				gets(DBFilename);
				if (!strcmp(DBFilename,"exit")) exit(EXIT_SUCCESS);
				if (!strcmp(DBFilename,"skip")) break;
			}
			break;	
	}
	
	//IMPORT DATA
	
	while (Choice != '0')
	{
		cls;
		printf("$$ ");
		printf("%s\n\n",MENU[7]);
		for (int i=1; i<7; ++i) printf("(%d) %s\n",i,MENU[i]);
		printf("(0) %s\n\n",MENU[0]);
		printf("Choose action: ");
		Choice = getch();
		printf("%c",Choice);
		switch (Choice)
		{
			case '1': Graph ? ConsoleMode()
		}
	}
	return 100;
}

int fileExists (char *FileName) // SEE COMM-1
{
	FILE *F = fopen(FileName,"r");
	int Result = (F == NULL ? 0 : 1);
	fclose(F);
	return Result;
} 
