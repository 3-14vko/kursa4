#include "libs.h"

struct vforms
{
	char *form1, *form2, *form3;
	unsigned char hidden;	
};

vforms * ImportStrcts(std::string datafile)
{
	char *fileway[datafile.length()+1] = StrToChr(datafile);
	FILE *f = fopen(fileway,"rb");
	
	
}
int main()
{
	char c;
	std::string s;
	std::getline(std::cin,s);
	
	return 0;
}
