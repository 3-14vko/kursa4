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
