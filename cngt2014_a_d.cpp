#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int n;
string mtr[100];

bool space(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n || mtr[x][y] != '.')
        return false;
    return true;
}

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> mtr[i];

        int x, y, dx, dy;
        cin >> x >> y >> dx >> dy;
        x--; y--; dx--; dy--;

        int dir;
        string mv = "";
        int dirx[][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        char dirc[] = "ESWN";

        if (y == 0)
            dir = 0;
        else
            dir = 2;

        for (int i=0; i<10000; i++)
        {
#define TURNL (dir = (dir+3) % 4)
#define TURNR (dir = (dir+1) % 4)

            TURNL;

            int ndir = -1;
            for (int i=0; i<4; i++)
            {
                if (space(x+dirx[dir][0], y+dirx[dir][1]))
                {
                    ndir = dir;
                    break;
                }
                TURNR;
            }
            
            if (ndir == -1)
                goto END;

            dir = ndir;
            x = x + dirx[dir][0];
            y = y + dirx[dir][1];

            mv.push_back(dirc[dir]);

            if (x == dx && y == dy)
                goto PASS;
        }

    END:
        cout << "Case #" << cc << ": Edison ran out of energy." << endl;
        continue;
    PASS:
        cout << "Case #" << cc << ": " << mv.length() << endl;
        cout << mv << endl;
    }

    return 0;
}
