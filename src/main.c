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
	
	const char **MENU = {"EXIT", "SHOW VERBS LIST", "LEARNING TEST", "RESULT TEST", "SETTINGS", "COMMANDS MODE", "ABOUT", "MENU"};
	FILE *f;
	
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
	GLOBAL.Command[0] = "\0";
	GLOBAL.VerbList = malloc(sizeof(DB_APP));
	
	if ( (InputArgumentsQ > 1) && (!strcmp(InputArguments[1],"-n") ) 
		GLOBAL.Command = "-n";
	
	cls;
	if ( (fileExists(RUNFILE)) && (strcmp(GLOBAL.Command,"-n")) ) 
	{
		f = fopen(RUNFILE,"rb");
		if (f == NULL) printf("Cann't open runfile\n"), Sleep(2000), cls;
		else fread(GLOBAL,sizeof(GLOBAL),1,F);
		fclose(f);
	}
	
	
	if ( !fileExists(DBFile))
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
	if ( strcmp(GLOBAL.DBFile,"-z") )
	{
		
	}
}