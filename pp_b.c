#include <stdio.h>
#include <string.h>

#define mtr(i, j) _mtr[(i)+10000][(j)]
#define L(dir) { if ((dir)==0) (dir) = 2; else if ((dir)==1) (dir) = 3; else if ((dir)==2) (dir) = 1; else if ((dir)==3) (dir) = 0; }
#define Walk(sta) { if ((sta).dir==0) (sta).x--; else if ((sta).dir==1) (sta).x++; else if ((sta).dir==2) (sta).y++; else if ((sta).dir==3) (sta).y--; MAXMIN((sta).x, (sta).y); }
#define MAXMIN(x, y) { MINX(x); MAXX(x); MINY(y); MAXY(y); }
#define MINX(x) { if ((x)<minx) minx = (x); }
#define MAXX(x) { if ((x)>maxx) maxx = (x); }
#define MINY(y) { if ((y)<miny) miny = (y); }
#define MAXY(y) { if ((y)>maxy) maxy = (y); }

char _mtr[20000][10000];
struct Statu
{
	int x, y;
	int dir;
};

void SetWall(int x, int y, int dir);

int main()
{
	int cc, cn;
	scanf("%d", &cn);
	
	for (cc=1; cc<=cn; cc++)
	{
		char s[2][10001];
		struct Statu sta;
		int minx = 0, maxx = 0, miny = 0, maxy = 0;
		int i,j;
		scanf("%s%s", s[0], s[1]);
		memset(_mtr, 0, sizeof(_mtr));

		SetWall(0, 0, 0);
		sta.x = 0;
		sta.y = 0;
		sta.dir = 1;
		for (i=1; s[0][i+1]; i++)
		{
			int tdir;
			switch (s[0][i])
			{
			case 'W':
				SetWall(sta.x, sta.y, sta.dir);
				Walk(sta);
				tdir = sta.dir;
				L(tdir); L(tdir);
				SetWall(sta.x, sta.y, tdir);
				break;
			case 'L':
				L(sta.dir);
				break;
			case 'R':
				L(sta.dir); L(sta.dir); L(sta.dir);
				break;
			default:
				fprintf(stderr, "ERROR in enter %d\n", i);
				break;
			}
		}
		SetWall(sta.x, sta.y, sta.dir);
		L(sta.dir); L(sta.dir);
		for (i=1; s[1][i+1]; i++)
		{
			int tdir;
			switch (s[1][i])
			{
			case 'W':
				SetWall(sta.x, sta.y, sta.dir);
				Walk(sta);
				tdir = sta.dir;
				L(tdir); L(tdir);
				SetWall(sta.x, sta.y, tdir);
				break;
			case 'L':
				L(sta.dir);
				break;
			case 'R':
				L(sta.dir); L(sta.dir); L(sta.dir);
				break;
			default:
				fprintf(stderr, "ERROR in enter %d\n", i);
				break;
			}
		}
		SetWall(sta.x, sta.y, sta.dir);

		fprintf(stderr, "%d\n", cc);
		printf("Case #%d:\n", cc);
		for (i=minx; i<=maxx; i++)
		{
			for (j=maxy; j>=miny; j--)
			{
				printf("%x", mtr(i, j));
			}
			puts("");
		}
	}

	return 0;
}

void SetWall(int x, int y, int dir)
{
	mtr(x, y) |= 1<<dir;
}
