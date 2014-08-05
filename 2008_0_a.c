#include <stdio.h>
#include <string.h>

int main()
{
	int cc, cn;
	int i,j;
	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		char eg[100][101];
		int egn;
		int in[100];
		int qn;
		char q[101];
		int swt;
		memset(in, 0, sizeof(in));
		scanf("%d\n", &egn);
		for (i=0; i<egn; i++)
			gets(eg[i]);

		swt = 0;
		scanf("%d\n", &qn);
		for (i=0; i<qn; i++)
		{
			int p;
			gets(q);
			for (j=0; j<egn; j++)
			{
				if (!strcmp(q, eg[j]))
				{
					p = j;
					in[j] = 1;
					break;
				}
			}
			for (j=0; j<egn; j++)
			{
				if (!in[j])
					break;
			}
			if (j==egn)
			{
				memset(in, 0, sizeof(in));
				in[p] = 1;
				swt++;
			}
		}

		printf("Case #%d: %d\n", cc, swt);
	}

	return 0;
}
