#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int speed;
	int len;
}WALKWAY;

int cmp(const void *a, const void *b)
{
	return ((WALKWAY *)a)->speed - ((WALKWAY *)b)->speed;
}

int main()
{
	int cn, cc;

	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		int i,j;
		int len, ws, rs;
		double rt;
		int n;
		WALKWAY arr[1001];
		double use;
		double ttime;

		scanf("%d %d %d %lf %d", &len, &ws, &rs, &rt, &n);
		for (i=0; i<n; i++)
		{
			int a, b;
			scanf("%d %d %d", &a, &b, &(arr[i].speed));
			arr[i].len = b - a;
			len -= arr[i].len;
		}

		arr[n].speed = 0;
		arr[n].len = len;

		qsort(arr, n+1, sizeof(WALKWAY), cmp);

		ttime = 0.0;
		for (i=0; i<n+1; i++)
		{
			use = (double)(arr[i].len)/(arr[i].speed + rs);
			if (use > rt) use = rt;
			rt -= use;
			ttime += use + ((double)(arr[i].len) - use * (arr[i].speed + rs)) / (arr[i].speed + ws);
		}

		printf("Case #%d: %.9f\n", cc, ttime);
	}

	return 0;
}
