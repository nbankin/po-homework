#include <stdio.h>
#include <string.h>
char *find(char *haystack, char needle)
{
	int size;
	int answer; 
	char row;
	char *base;
	int ct;
	

	size = strlen(haystack);

	for(ct =0;ct<size;ct++)
	{
		if(haystack[ct] == needle)
		{
			answer = ct;
			break;
			
		}
		

	}

		if(answer == ct)
		{
			row = answer;
			base = &row;

			return base;
		}

return NULL;

}

int main()
{

char haystack[400] = {0};
char needle;
char *vine;

scanf("%[^\n]",haystack);

getchar();

scanf("%c",&needle);

if( find(haystack,needle) == NULL) 
{

	printf("-1");
}
else
{
	vine = find(haystack,needle);
	printf("%d",*vine );
}

return 0;
}