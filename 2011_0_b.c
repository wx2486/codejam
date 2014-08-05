#include <stdio.h>
#include <string.h>

#define SIZE 26
#define MAXLEN 102

int main()
{
	int i;

            FILE *fin = stdin;
            FILE *fout = stdout;

	int t, tc;

	fscanf(fin, "%d", &t);
	for (tc=1; tc<=t; tc++)
	{
		char bea, beb, nbe, ch;
		int c, d, n;
		char comb[SIZE][SIZE]={0};
		int oppo[SIZE][SIZE]={0};
		char list[MAXLEN];
		int lp=0;

		fscanf(fin, "%d", &c);
		while (c--)
		{
			fscanf(fin, " %c%c%c", &bea, &beb, &nbe);
			comb[bea-'A'][beb-'A'] = comb[beb-'A'][bea-'A'] = nbe;
		}

		fscanf(fin, "%d", &d);
		while (d--)
		{
			fscanf(fin, " %c%c", &bea, &beb);
			oppo[bea-'A'][beb-'A'] = oppo[beb-'A'][bea-'A'] = 1;
		}

		fscanf(fin, "%d", &n);
		fgetc(fin);
		while (n--)
		{
			ch = fgetc(fin);
			if (lp>0 && comb[list[lp-1]-'A'][ch-'A'])
				list[lp-1] = comb[list[lp-1]-'A'][ch-'A'];
			else
			{
				for (i=0; i<lp; i++)
					if (oppo[list[i]-'A'][ch-'A'])
						break;

				if (i==lp)
					list[lp++] = ch;
				else
					lp = 0;
			}
		}

		fprintf(fout, "Case #%d: ", tc);
		fprintf(fout, "[");
		for (i=0; i<lp; i++)
		{
			if (i)
				fprintf(fout, ", ");
			fprintf(fout, "%c", list[i]);
		}
		fprintf(fout, "]\n");
	}

	return 0;
}
