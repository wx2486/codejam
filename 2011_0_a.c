#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fin = stdin;
    FILE *fout = stdout;

	int t, tc;

	fscanf(fin, "%d", &t);
	for (tc=1; tc<=t; tc++)
	{
		int n;
		char clr;
		int pos;
		int bt, bpos, ot, opos;

		bt = ot = 0;
		bpos = opos = 1;

		fscanf(fin, "%d", &n);
		while (n--)
		{
			fscanf(fin, " %c %d", &clr, &pos);

			if (clr=='B')
			{
				bt += abs(pos-bpos);
				bpos = pos;
				if (ot>bt) bt = ot;
				bt++;
			}
			else
			{
				ot += abs(pos-opos);
				opos = pos;
				if (bt>ot) ot = bt;
				ot++;
			}
		}

		fprintf(fout, "Case #%d: ", tc);
		fprintf(fout, "%d\n", (bt>ot) ? bt : ot);
	}

	return 0;
}
