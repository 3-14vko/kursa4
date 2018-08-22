typedef struct db_file
{
	char *Form[3];
} DB_FILE; //how to read from file

typedef struct db_app
{
		char *Form[3];
		int I;
		DB_APP *next;
} DB_APP; //how to save in mem

typedef struct testing
{
	DB_APP *quest;
	int Hidden; /1, 2, 3 ||| 5 (first and third), 4 (first and second), 6 (second and third), 
} TESTING;

typedef struct global_variables
{
	char Choice;
	int OldScore;
	int NewScore;
	int Pause;
	int TestQ;
	int VerbsQ;
	int Try; //Lerntest tries
	int Console; //use console(1) or menu(0)
	char DBFile[256];
	char RunFile[256];
	char Form[3]; //DDD, when D=(0||1); 111 - hide randomly one form, 222 - two forms
 	char Command[256]; //ONLY FULL AND TRIMMED
} GLOBAL_VAR;
