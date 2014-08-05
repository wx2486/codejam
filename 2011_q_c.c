#include <stdio.h>
#include <limits.h>

int main()
{
    FILE *fin = stdin;
    FILE *fout = stdout;

	int t,tc;

	fscanf(fin, "%d", &t);
	for (tc=1; tc<=t; tc++)
	{
		int sum, min, xor, val;
		int n;

		sum = 0, min = INT_MAX, xor = 0;
		fscanf(fin, "%d", &n);
		while (n--)
		{
			fscanf(fin, "%d", &val);
			sum += val;
			if (val<min) min = val;
			xor ^= val;
		}

		fprintf(fout, "Case #%d: ", tc);
		if (xor) fprintf(fout, "NO\n");
		else     fprintf(fout, "%d\n", sum-min);
	}

	return 0;
}
