#include <stdio.h>

char ori[] = "qzejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
char trg[] = "zqour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";


char Trans(char c)
{
	char *p;
	for (p=ori; *p; p++)
		if (*p==c)
			return trg[p-ori];
	return '0';
}

int main()
{
	int cn, cc;

	scanf("%d\n", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		char s[101];
		char *p;
		gets(s);
		printf("Case #%d: ", cc);

		for (p=s; *p; p++)
			putchar(Trans(*p));
		puts("");
	}

	return 0;
}
