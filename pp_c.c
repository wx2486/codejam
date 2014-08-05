#include <stdio.h>
#include <limits.h>

#define MAXB 1000
#define MAXD 3000

long long solve[MAXB][MAXD];
long long dlim[MAXB];
long long blim;

void Init(void);
long long Solve(int d, int b);

int main()
{
	int cc, cn;
	Init();
	scanf("%d", &cn);

	for (cc=1; cc<=cn; cc++)
	{
		long long f;
		int d,b;
		long long fq;
		int dq, bq;
		long long min, max;
		scanf("%lld%d%d", &f, &d, &b);

		fq = Solve(d,b);

		min = 1;
		max = d+1;
		while (min<max)
		{
			long long ff = Solve((max+min)/2, b);
			if (ff == -1 || ff >= f)
				max = (max+min)/2;
			else                  
				min = (max+min)/2+1;
		}
		dq = min;

		min = 1;
		max = b+1;
		while (min<max)
		{
			long long ff = Solve(d, (max+min)/2);
			if (ff == -1 || ff >= f)
				max = (max+min)/2;
			else                   
				min = (max+min)/2+1;
		}
		bq = min;

		printf("Case #%d: %lld %d %d\n", cc, fq, dq, bq);
	}

	return 0;
}

void Init(void)
{
	int i,j;
	blim = MAXB;
	i = 3;
	while (1)
	{
		dlim[i] = MAXD;
		if (Solve(i-1, i-1) < 0 || Solve(i-1, i-1) * 2 + 1 > UINT_MAX)
		{
			dlim[i] = i;
			blim = i;
			return;
		}
		solve[i][i] = Solve(i-1, i-1) * 2 + 1;
		j = i+1;
		while (1)
		{
			if (Solve(j-1, i) < 0 || Solve(j-1, i-1) < 0)
				goto OVERFLOW;
			solve[i][j] = Solve(j-1, i) + Solve(j-1, i-1) + 1;
			if (solve[i][j] > UINT_MAX)
				goto OVERFLOW;
			j++;
			continue;
OVERFLOW:
			dlim[i] = j;
			break;
		}
		i++;
	}
}

long long Solve(int d, int b)
{
	if (b<=0)
		return 0;
	if (d<b)
		return Solve(d, d);
	if (b==1)
		return d;
	if (b==2)
	{
		if ((long long)(d)*(d-1)/2 + d + 2 <= UINT_MAX)
			return (long long)(d)*(d-1)/2 + d;
		else
			return -1;
	}
	if (b >= blim || d >= dlim[b])
		return -1;
	return solve[b][d];
}
