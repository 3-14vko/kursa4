#include <stdio.h>
#include <iostream>
#include "strings.cpp"


struct vforms
{
	char form1[16], form2[16], form3[16];
	int hidden;
};

std::string TrimLeft (std::string s);
std::string TrimRight (std::string s);
std::string Trim (std::string s);
std::string GetWord (std::string s, unsigned char n);
std::string ChrToStr(char * s);
char * StrToChr(std::string s);


int main()
{
    std::string datafile, s;
    int q;
    std::cout << "Welcome to DataBase generator!\n";
    std::cout << "Enter fileway: ";
    std::getline(std::cin,datafile);
    std::cout << "Enter array length: ";
    std::cin >> q;
    vforms *v = new vforms[q+1];
    vforms *vv = new vforms[q+1]; 
    vforms t;
    FILE *f = fopen(StrToChr(datafile),"wb+");
    strcpy(v[0].form1,"Infinitive");
    strcpy(v[0].form2,"Past Simple");
    strcpy(v[0].form3,"Past Participle");
    v[0].hidden = q;
    for (int i=1; i<=q; ++i)
    {
        std::cout << "Enter first form: ";
        std::cin >> v[i].form1;
        std::cout << "Enter second form: ";
        std::cin >> v[i].form2;
        std::cout << "Enter third form: ";
        std::cin >> v[i].form3;
        v[i].hidden = 0;
    }
	for (int i=0; i<(q+1); ++i)
	{
		t = v[i];
		fwrite(&t,sizeof(vforms),1,f);
		std::cout << '(' << i << ") element saved into " << datafile << std::endl;
	}
	rewind(f);
	int i = 0;
	for (int j=0; j<(q+1); ++j)
	{
		fread(&t,sizeof(vforms),1,f);
		vv[i++] = t;
	 	std::cout << vv[i-1].form1 << ' ' << vv[i-1].form2 << ' ' << vv[i-1].form3 << ' ' << vv[i-1].hidden << std::endl; 
	}
	fclose(f);
    return 0;
}
