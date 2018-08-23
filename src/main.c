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

int fileExists (char *FileName);
void c_set (GLOBAL_VAR *GLOBAL);
void c_exit (GLOBAL_VAR *GLOBAL);
void c_test (GLOBAL_VAR *GLOBAL);
void c_about ();
void c_system (GLOBAL_VAR *GLOBAL);
void c_db (GLOBAL_VAR *GLOBAL);
void c_man (GLOBAL_VAR *GLOBAL);
void c_cls ();

int main (int InputArgumentsQ, char** InputArguments)
{
	//var
	const char **MENU = {"EXIT", "SHOW VERBS LIST", "LEARNING TEST", "RESULT TEST", "SETTINGS", "COMMANDS MODE", "ABOUT", "MENU"};
	GLOBAL_VAR *GLOBAL = malloc(sizeof(GLOBAL_VAR));
	
	printf(APPNAME);
	writeln;
	printf(UNIVER);
	writeln;
	Sleep(2500);
	
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
	
	/*	IMPORT DATA
	
		First in file - VerbsQ
		Next - verbs
	*/
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
	printf("console: Window cleaned\n");
}

void c_man (GLOBAL_VAR *GLOBAL)
{
	
}