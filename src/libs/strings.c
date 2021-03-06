// STRINGS lib. (c)


char * trimLeft (char *s)
{
	if (s[0] != ' ') return s;
	char *result = malloc(sizeof(char)*256);
	int i, j = 0;
	for (i = 0; s[i] == ' '; ++i);
	for (i = i; i <= strlen(s); ++i, ++j) result[j] = s[i];
	free(s);
	return result;
}

char * trimRight (char *s)
{
	if (s[strlen(s)-1] != ' ') return s;
	char *result = malloc(sizeof(char)*256);
	int i;
	for (i = strlen(s) - 1; s[i] == ' '; --i);
	for (int j = 0; j <= i; ++j) result[j] = s[j];
	free(s);
	return result;
}

char * trim (char *s)
{
	return trimRight(trimLeft(s));
}

char * getWord (char *s, int n)
{
	if (s[0] == '\0') return s;
	char *result = malloc(sizeof(char)*256);
	int c = 1, j = 0;
	for (int i = 0; i < strlen(s); ++i)
	{
		if (s[i] == ' ') ++c;
		if (c == n) result[j] = s[i], ++j;
		if (c > n) break;
	}
	result[j+1] = '\0';
	return result;
}

char * getAfterWord (char *s, int n)
{
	if (s[0] == '\0') return s;
	char *result = malloc(sizeof(char)*256);
	int c = 1, j = 0;
	for (int i = 0; i < strlen(s); ++i)
	{
		if (s[i] == ' ') ++c;
		if (c > n) result[j] = s[i], ++j;
	}
	return result;
}

char * lowerCase (char *s) //a..z==97..122		 A..Z==65..90
{
	char *result = malloc(sizeof(char)*256);
	for (int i=0; i<=strlen(s); ++i)
	{
		if ((s[i]>=65) &&  (s[i]<=90)) 
			result[i] = s[i] + 32;
		else 
			result[i] = s[i];
	}
	free(s);
	return result;
}
