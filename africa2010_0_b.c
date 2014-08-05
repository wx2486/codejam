#include <stdio.h>
#include <ctype.h>

void Work(void);

int main()
{
	int cc, cn;
	scanf("%d\n", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		printf("Case #%d:", cc);
		Work();
		puts("");
	}

	return 0;
}

void Work(void)
{
	char s[1001];
	char *p;

	for (p=s; !isspace(*p=getchar()); p++);

	if (*p!='\n')
		Work();
	*p = '\0';
	printf(" %s", s);
}
