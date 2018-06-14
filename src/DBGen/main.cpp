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

    return 0;
}
