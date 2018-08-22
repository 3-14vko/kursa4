#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct vform
{
	char *form[3]; //.form[0] for hidden elements
} verb;

typedef struct qvert
{
	char form1[16], form2[16], form3[16];
	int hidden;
} vforms;

int main()
{
	char *s = malloc(256);
	puts("Put FROM:");
	gets(s);
	FILE *from = fopen(s,"rb");
	puts("Put TO:");
	gets(s);
	FILE *to = fopen(s,"wb+");
	verb *v = malloc(sizeof(verb)*98);
	vforms *v1 = malloc(sizeof(vforms)*99);
	for (int i=0; i<99; ++i) 
		{	
			for (int j = 0; j < 3; ++j) v[i].form[j] = malloc(sizeof(char)*16);	
		}
	int result = 0, testq = 98;
	fwrite(&result,sizeof(int),1,to);
	fwrite(&testq,sizeof(int),1,to);
	for (int i=0; i<99; ++i)
	{
		fread(&v1[i],sizeof(vforms),1,from);
		printf("%d) %s %s %s\n",i,v1[i].form1,v1[i].form2,v1[i].form3);
		v[i].form[0] = v1[i].form1;	
		v[i].form[1] = v1[i].form2;
		v[i].form[2] = v1[i].form3;
		if (i==0) v[0].form[0] = "Infinitive"; 
		fwrite(&v[i],48,1,to); 
	 }
	
	fclose(from);
	fclose(to);
	getch();
		for (int i=0; i<99; ++i) 
		{	
			for (int j = 0; j < 3; ++j) v[i].form[j] = malloc(sizeof(char)*16);	
		}
	to = fopen(s,"rb");
	if (to == NULL) puts("ERROR"), exit;
	result = 100;
	testq = 60;
	fread(&result,sizeof(int),1,to);
	printf("RESULT = %d;\n",result);
	fread(&testq,sizeof(int),1,to);
	printf("LINES = %d;\n",testq);
	for (int i=0; i<=testq; ++i)
	{
		fread(&v[i],48,1,to);
		printf("%d) ",i);
		for (int j=0; j<3; ++j) printf("%s ",v[i].form[j]);
		printf("\n");
	 }   
	return 0;
}
