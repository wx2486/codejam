#include <stdio.h>

int main()
{
    FILE *fin = stdin;
            FILE *fout = stdout;

	int t,tc;
	fscanf(fin, "%d", &t);
	for (tc=1; tc<=t; tc++)
	{
		char mtr[50][50];
		int row, col;
		int i,j;
		fscanf(fin, "%d %d\n", &row, &col);
		for (i=0; i<row; i++)
		{
			for (j=0; j<col; j++)
				mtr[i][j] = fgetc(fin);
			fgetc(fin);
		}

		for (i=0; i<row; i++)
			for(j=0; j<col; j++)
				if (mtr[i][j]=='#')
				{
					if (i==row-1 || j==col-1 || mtr[i][j+1]!='#' || mtr[i+1][j]!='#' || mtr[i+1][j+1]!='#')
					{
						fprintf(fout, "Case #%d:\n", tc);
						fprintf(fout, "Impossible\n");
						goto END;
					}
					mtr[i][j] = mtr[i+1][j+1] = '/';
					mtr[i][j+1] = mtr[i+1][j] = '\\';
				}
	
		fprintf(fout, "Case #%d:\n", tc);
		for (i=0; i<row; i++)
		{
			for (j=0; j<col; j++)
				fputc(mtr[i][j], fout);
			fputc('\n', fout);
		}

END:
		;
	}

	return 0;
}
