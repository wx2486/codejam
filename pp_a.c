#include <stdio.h>
#include <string.h>

int main()
{
	int cc, cn;

	scanf("%d\n", &cn);
	for (cc=1; cc<=cn; cc++)
	{
		char num[100], src[100], trg[100];
		char sta[100];
		char stap;
		int bs, bt;
		int dnum;
		int i,j;
		scanf("%s %s %s\n", num, src, trg);

		bs = strlen(src);
		bt = strlen(trg);

		dnum = 0;
		for (i=0; num[i]; i++)
		{
			for (j=0; src[j]!=num[i]; j++)
			{
				if (!src[j])
				{
					fprintf(stderr, "ERROR!\n");
					return -1;
				}
			}

			dnum = dnum * bs + j;
		}

		stap = 0;
		while (dnum)
		{
			sta[stap++] = trg[dnum%bt];
			dnum /= bt;
		}

		printf("Case #%d: ", cc);
		while (stap--)
		{
			putchar(sta[stap]);
		}
		putchar('\n');
	}

	return 0;
}
