// STRINGS lib. (c)

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

std::string GetWord (std::string s, int n)
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
