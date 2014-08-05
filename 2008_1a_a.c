#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	int aa = *(int *)a, bb = *(int *)b;
	return aa - bb;
}

int main()
{
	int cc, cn;
	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		int x[800], y[800];
		int n;
		int i;
		long long sum;
		scanf("%d", &n);

		for (i=0; i<n; i++)
			scanf("%d", x+i);
		for (i=0; i<n; i++)
			scanf("%d", y+i);
		qsort(x, n, sizeof(int), cmp);
		qsort(y, n, sizeof(int), cmp);

		sum = 0;
		for (i=0; i<n; i++)
			sum += (long long)(x[i]) * (long long)(y[n-i-1]);
		printf("Case #%d: %lld\n", cc, sum);
	}

	return 0;
}
