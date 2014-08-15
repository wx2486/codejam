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

struct point
{
    int x, y;
};

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        int xn, yn;
        cin >> yn >> xn;
        
        point inp, exp;
        cin >> inp.y >> inp.x >> exp.y >> exp.x;

        int mtr[100][100];
        for (int i=0; i<yn; i++)
            for (int j=0; j<xn; j++)
                cin >> mtr[i][j];

        int used[100][100] = {0};
        vector<point> current;
        int level = 1;
        int value[100][100] = {0};

        used[inp.y][inp.x] = level;
        value[inp.y][inp.x] = mtr[inp.y][inp.x];
        current.push_back(inp);

        while (!current.empty())
        {
            level++;

            vector<point> next;
            int dx[][2] = {{0,1}, {0,-1}, {1,0}, {-1,0} };

            for (int i=0; i<current.size(); i++)
                for (int dir=0; dir<4; dir++)
                {
                    int x, y;
                    x = current[i].x + dx[dir][0];
                    y = current[i].y + dx[dir][1];
                    
                    if (x < 0 || x >= xn)
                        continue;
                    if (y < 0 || y >= yn)
                        continue;
                    if (mtr[y][x] < 0 || used[y][x] && used[y][x] < level)
                        continue;

                    int vl = value[current[i].y][current[i].x] + mtr[y][x];
                    if (value[y][x] < vl)
                    {
                        value[y][x] = vl;
                        used[y][x] = level;
                        point t;
                        t.x = x;
                        t.y = y;
                        next.push_back(t);
                    }
                }

            current = next;
        }

        if (!used[exp.y][exp.x])
            cout << "Case #" << cc << ": Mission Impossible." << endl;
        else
            cout << "Case #" << cc << ": " << value[exp.y][exp.x] << endl;
    }

    return 0;
}
