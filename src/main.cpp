#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
//#include <graphics.h>

std::string TrimLeft (std::string s);
std::string TrimRight (std::string s);
std::string Trim (std::string s);
std::string GetWord (std::string s, unsigned char n);
std::string ChrToStr(char * s);
char * StrToChr(std::string s);

struct vforms
{
	char *form1, *form2, *form3;
	int hidden;
};

vforms * ImportStrcts(std::string datafile)
{
	char *fileway = new char[datafile.length()+1];
	fileway = StrToChr(datafile);
	FILE *f = fopen(fileway,"rb");
	vforms first;
	fread(&first,sizeof(vforms),1,f);
	vforms t, *array = new vforms[first.hidden];
	array[0] = first;
	for (int i=1; i<=first.hidden; ++i)
	{
			fread(&t,sizeof(vforms),1,f);
			array[i] = t;
	}
	fclose(f);
	return array;
}
int main()
{
	char c;
	std::string s;
	std::getline(std::cin,s);
    vforms *verbs = ImportStrcts(s);
    for (int i=1; i<=verbs[0].hidden; ++i)
        std::cout << verbs[i].form3 << std::endl;
	return 0;
}

std::string TrimLeft (std::string s)
{
    if (s == "") return s;
    std::string result = "";
    int i;
    for (i=0; s[i]==' '; ++i);
    for (i=i; i<s.length(); ++i)
        result += s[i];
    return result;
}

std::string TrimRight (std::string s)
{
    if (s == "") return s;
    std::string result = "";
    int j;
    for (j=s.length()-1; s[j-1]==' '; --j);
    for (int i=0; i<j; ++i)
        result += s[i];
    return result;
}

std::string Trim (std::string s)
{
    return TrimLeft(TrimRight(s));
}

std::string GetWord (std::string s, unsigned char n)
{
    std::string result = "";
    int c = 1;
    if (s == "") return "-z";
    for (int i=0; i<=s.length(); ++i)
    {
        if (c == n) result += s[i];
        if (s[i] == ' ') ++c;
    }
    return Trim(result);
}

std::string ChrToStr(char * s)
{
	std::string result;
	for (int i=0; i<strlen(s); ++i) result[i] = s[i];
}

char * StrToChr(std::string s)
{
	char *result = new char[s.length()+1];
	for (int i=0; i<s.length(); ++i) result[i] = s[i];
	result[s.length()] = '\0';
	return result;
}
