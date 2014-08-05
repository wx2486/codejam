#include <stdio.h>
#include <string.h>

int Pair(i, min, max);

int main()
{
	int cn, cc;
	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		int i;
		int min, max;
		long long sum;
		scanf("%d%d", &min, &max);

		sum = 0;
		for (i=min; i<=max; i++)
			sum += Pair(i, min, max);

		fprintf(stderr, "%d\n", cc);
		printf("Case #%d: %lld\n", cc, sum/2);
	}

	return 0;
}

int Pair(int num, int min, int max)
{
	int i, j;
	char s[100];
	char t[100];
	int arr[100];
	int arrn;
	int len;
	int tran;
	int sum;
	sprintf(s, "%d%d\0", num, num);
	len = strlen(s) / 2;

	arrn = 0;
	sum = 0;
	for (i=len-1; i>0; i--)
	{
		s[len+i] = '\0';
		sscanf(s+i, "%d", &tran);
		sprintf(t, "%d\0", tran);
		if (tran!=num && tran>=min && tran<=max && (int)(strlen(t)) == len)
		{
			for (j=0; j<arrn; j++)
			{
				if (tran == arr[j])
					goto NEXT;
			}

			sum++;
			arr[arrn++] = tran;
			//fprintf(stderr, "%d %d\n", num, tran);
		}
NEXT:
		;
	}

	return sum;
}
