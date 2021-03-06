/*

	variable: AaBb
	function: aaBb
	const: AABB
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define cls system("clear")
#define UNIVER "SibSUTIS, 2018"
#define APPNAME "IrregularVerbs"
#define IGOR "Igor Lipovtsev"
#define ILYA "Ilya Kazantsev"
#define KOSTYA "Konstantin Anton'ev"
#define writeln printf("\n")
#define readln getch()
#define RUNFILE "run.iv"

int fileExists (char *FileName);
int ImportData (GLOBAL_VAR *GLOBAL);
void c_set (GLOBAL_VAR *GLOBAL); 
void c_exit (GLOBAL_VAR *GLOBAL);
void c_test (GLOBAL_VAR *GLOBAL);
void c_about (); //done
void c_system (GLOBAL_VAR *GLOBAL); //done
void c_db (GLOBAL_VAR *GLOBAL);
void c_man (GLOBAL_VAR *GLOBAL);
void c_cls (); //done

int main (int InputArgumentsQ, char** InputArguments)
{
	
	printf(APPNAME);
	writeln;
	printf(UNIVER);
	writeln;
	Sleep(2500);
				//			0				1			2					3			4			5				6		7	
	const char **MENU = {"EXIT", "SHOW VERBS LIST", "LEARNING TEST", "RESULT TEST", "SETTINGS", "COMMANDS MODE", "ABOUT", "MENU"}; //8
	FILE *f;
	int BoolOpen = 1;
	
	GLOBAL_VAR *GLOBAL = malloc(sizeof(GLOBAL_VAR));
	GLOBAL.Choice = '\0';
	GLOBAL.OLdScore = 0;
	GLOBAL.NewScore = 0;
	GLOBAL.Pause = 0;
	GLOBAL.TestQ = 15;
	GLOBAL.VerbsQ = 98;
	GLOBAL.Try = 0;
	GLOBAL.Console = 0;
	GLOBAL.DBFile = "db.iv\0";
	GLOBAL.Form = "111";
	GLOBAL.Command = "Hello, world!\n";
	GLOBAL.VerbList = NULL;
	
	if ( (InputArgumentsQ > 1) && (!strcmp(InputArguments[1],"-n") ) 
		BoolOpen = 0;
	
	cls;
	if ( fileExists(RUNFILE) && BoolOpen ) //if run.iv exists and no argument found 
	{
		f = fopen(RUNFILE,"rb");
		if (f == NULL) printf("Cann't open runfile\n"), Sleep(2000), cls;
		else fread(GLOBAL,sizeof(GLOBAL),1,F), fclose(f);
	}
	
	
	if ( ImportData(GLOBAL) == 0 ) 
	{
			printf("Cann't open database file. Would you like to choice it now? [y/n]\n");
			switch (getch())
			{
			case 'n': 
				GLOBAL.DBFile = "-z"; 
				break;
			case 'y':
				while ( !fileExists(GLOBAL.DBFile) || !strcmp(GLOBAL.DBFile,"exit") )
				{
					printf("Type database filename (or 'exit'): ");
					gets(GLOBAL.DBFile);
				}
				if (!strcmp(GLOBAL.DBFile,"exit")) GLOBAL.DBFile = "-z";
				break;
			}
	}
	
	cls;
	
	int GoToExit = 0;
	while (1)
	{
		while ( !GLOBAL.Console && !GoToExit) //menu
		{
			printf("Choose action:\n\n");
			for (int i=1; i<7; ++i)
				printf("\t(%d) %s\n",MENU[i]);
			getch(GLOBAL.Choice);
			switch (GLOBAL.Choice)
			{
				case '0': 
					writeln;
					printf("Are you sure you want to quit? [y/n]\n");
					scanf("%c",&GLOBAL.Choice);
					switch (GLOBAL.Choice)
					{
						case 'y':
							GoToExit = 1;
							break;
						case 'n': 
							break;
					}
					break;
				case '1':
					c_db(GLOBAL);
					break;
				case '2':
					c_test(GLOBAL);
					break;
				case '3':
					c_test(GLOBAL);
					break;
				case '4':
					while (GLOBAL.Choice != 'Q')
					{
						//Variable list 
						//Scan variable
						//Scan new value
						//check value
					}
					break;
				case '5':
					GLOBAL.Console = 1;
					break;
				case '6':
					c_about();
					break;
			}
			cls;
		}
		
		if (GoToExit) 
			break;
		
		while (GLOBAL.Console == 1) //entering commands mode
		{
			
		}
	}
	
	//if exit without save then no save
	return 0;
}

int fileExists (char *FileName) // SEE COMM-1
{
	FILE *F = fopen(FileName,"r");
	int Result = (F == NULL ? 0 : 1);
	fclose(F);
	return Result;
} 

void c_system (GLOBAL_VAR *GLOBAL)
{
	char *Cmd = getAfterWord(GLOBAL.Command,1);
	system(cmd);
	free(cmd);
}

void c_about ()
{
	puts(APPNAME);
	puts(UNIVER);
	printf("COURSE WORK#2\n\nDevelopers:\n");
	printf("Project structure, programing, debugging, team management, documentations - "); puts(IGOR);
	printf("Programing, debugging, team work, testing - "); puts(ILYA);
	printf("DataBase structure, assembling, shaurma - "); puts(KOSTYA);
	Sleep(3000);
}

void c_cls ()
{
	system("clear");
	printf("Window cleaned\n");
}

void c_man (GLOBAL_VAR *GLOBAL)
{
	
}

int ImportData (GLOBAL_VAR *GLOBAL)
{
		if (!fileExists(GLOBAL.DBFile)) //Can't open db
			return 0;
		FILE *f = fopen(GLOBAL.DBFile,"rb");
		/*
		DB_FILE Buffer;
		for (int i-0; i<3; ++i) 
			Buffer.Form[i] = malloc(sizeof(char)*16);
		*/	
		fread(GLOBAL.VerbsQ,sizeof(int),1,f); //Get verbs quanity from opened db
		//0-element init
		GLOBAL.VerbList = malloc(sizeof(DB_APP); //Choosing memory for 0-element
		DB_APP *Buffer = GLOBAL.VerbList; //remember 0-element  
		GLOBAL.VerbList.I = 0; //0-element index
		for (int j=0; j<3; ++j)
			GLOBAL.VerbList.Form[j] = malloc(sizeof(char)*16); //choosing memory for verbs strings
		GLOBAL.VerbList.next = malloc(sizeof(DB_APP)); //choosing memory for next element
		fread(GLOBAL.VerbList.Form,48,1,f); //Get verbs string
		GLOBAL.VerbList = GLOBAL.VerbList.next; //Set VerbList to next element
		for (int i=1; i <= GLOBAL.VerbsQ; ++i)
		{
			for (int j=0; j<3; ++j)
				GLOBAL.VerbList.Form[j] = malloc(sizeof(char)*16);
			fread(GLOBAL.VerbList.Form,48,1,f);
			GLOBAL.VerbList.I = i;
			if (i == GLOBAL.VerbsQ) 
				GLOBAL.VerbList.next = NULL, break;
			GLOBAL.VerbList.next = malloc(sizeof(DB_APP));
			GLOBAL.VerbList = GLOBAL.VerbList.next;
		}
		GLOBAL.VerbList = Buffer;
		fclose(f);
		return 1;
}