#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int Larger(int num, int t);
int SLarger(int num, int t);

int main()
{
	int cn, cc;

	scanf("%d", &cn);
	for (cc=1; cc<=cn; cc++)
	{
		int i;
		int n, sn, trg;
		int arr[100];
		int sum;
		scanf("%d%d%d", &n, &sn, &trg);

		for (i=0; i<n; i++)
			scanf("%d", arr+i);

		qsort(arr, n, sizeof(int), cmp);

		sum = 0;
		for (i=0; i<n; i++)
		{
			if (Larger(arr[i], trg))
				sum++;
			else if (sn>0 && SLarger(arr[i], trg))
			{
				sum++;
				sn--;
			}
		}

		printf("Case #%d: %d\n", cc, sum);
	}

	return 0;
}

int Larger(int num, int t)
{
	if (num==30 || num==29)
		return 1;
	if (num==0 && t==0 || num==1 && t<=1)
		return 1;
	return (num/3+(num%3!=0)) >= t;
}

int SLarger(int num, int t)
{
	if (num==30 || num==29 || num==1 || num==0)
		return 0;
	return (num/3+1+(num%3==2)) >= t;
}
