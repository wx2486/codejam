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

int bluewin();
int redwin();
bool rc();
bool bc();

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> mtr[i];

        cout << "Case #" << cc << ": ";

        int bcnt, rcnt;
        bcnt = rcnt = 0;

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (mtr[i][j] == 'B')
                    bcnt++;
                else if (mtr[i][j] == 'R')
                    rcnt++;

        if (bcnt < rcnt - 1 || bcnt > rcnt + 1)
            goto IMP;

        switch (redwin())
        {
        case 1:
            if (bcnt > rcnt)
                goto IMP;
            goto RED;
        case 2:
            goto IMP;
        }

        switch (bluewin())
        {
        case 0:
            goto NOBODY;
        case 1:
            if (rcnt > bcnt)
                goto IMP;
            goto BLUE;
        case 2:
            goto IMP;
        }

    IMP:
        cout << "Impossible" << endl;
        continue;
    RED:
        cout << "Red wins" << endl;
        continue;
    BLUE:
        cout << "Blue wins" << endl;
        continue;
    NOBODY:
        cout << "Nobody wins" << endl;
        continue;
    }

    return 0;
}

int bluewin()
{
    if (!bc())
        return 0;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (mtr[i][j] == 'B')
            {
                mtr[i][j] = '.';
                if (!bc())
                {
                    mtr[i][j] = 'B';
                    return 1;
                }
                mtr[i][j] = 'B';
            }

    return 2;
}

int redwin()
{
    if (!rc())
        return 0;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (mtr[i][j] == 'R')
            {
                mtr[i][j] = '.';
                if (!rc())
                {
                    mtr[i][j] = 'R';
                    return 1;
                }
                mtr[i][j] = 'R';
            }

    return 2;
}

struct point
{
    int x, y;
};

int dx[][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,-1}, {-1,1}};

bool bc()
{
    if (n == 1 && mtr[0][0] == 'B')
        return true;

    vector<point> v;
    bool used[100][100] = {false};

    for (int i=0; i<n; i++)
        if (mtr[i][0] == 'B')
        {
            point p;
            p.x = 0; p.y = i;
            v.push_back(p);
            used[0][i] = true;
        }

    for (int i=0; i<v.size(); i++)
    {
        point p = v[i];
        for (int dir=0; dir<6; dir++)
        {
            point nextp;
            nextp.x = p.x + dx[dir][0];
            nextp.y = p.y + dx[dir][1];

            if (nextp.x < 0 || nextp.x >= n
             || nextp.y < 0 || nextp.y >= n
             || mtr[nextp.y][nextp.x] != 'B'
             || used[nextp.x][nextp.y])
                continue;

            if (nextp.x == n - 1)
                return true;

            used[nextp.x][nextp.y] = true;
            v.push_back(nextp);
        }
    }

    return false;
}

bool rc()
{
    if (n == 1 && mtr[0][0] == 'R')
        return true;

    vector<point> v;
    bool used[100][100] = {false};

    for (int i=0; i<n; i++)
        if (mtr[0][i] == 'R')
        {
            point p;
            p.x = 0; p.y = i;
            v.push_back(p);
            used[0][i] = true;
        }

    for (int i=0; i<v.size(); i++)
    {
        point p = v[i];
        for (int dir=0; dir<6; dir++)
        {
            point nextp;
            nextp.x = p.x + dx[dir][0];
            nextp.y = p.y + dx[dir][1];

            if (nextp.x < 0 || nextp.x >= n
             || nextp.y < 0 || nextp.y >= n
             || mtr[nextp.x][nextp.y] != 'R'
             || used[nextp.x][nextp.y])
                continue;

            if (nextp.x == n - 1)
                return true;

            used[nextp.x][nextp.y] = true;
            v.push_back(nextp);
        }
    }

    return false;
}
