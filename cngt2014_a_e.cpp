#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

#define CLR_NUM (36*37)

int trans(char c)
{
    if (isdigit(c))
        return c - '0';
    if (islower(c))
        return c - 'a' + 10;
    assert(0);
}

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        int n;
        cin >> n;

        vector<int> clr;
        for (int i=0; i<n; i++)
        {
            string s;
            cin >> s;
            int t;
            t = trans(s[0]);
            if (s.length() > 1)
                t += (trans(s[1]) + 1) * 36;
            clr.push_back(t);
        }

        int dis[CLR_NUM][CLR_NUM];
        memset(dis, -1, sizeof(dis));
        for (int i=0; i<CLR_NUM; i++)
            dis[i][i] = 0;

        int m;
        cin >> m;

        for (int i=0; i<m; i++)
        {
            int a, b, t;
            cin >> a >> b >> t;
            a = clr[a-1];
            b = clr[b-1];
            if (dis[a][b] < 0 || dis[a][b] > t)
                dis[a][b] = t;
        }

        for (int mid=0; mid<CLR_NUM; mid++)
            for (int i=0; i<CLR_NUM; i++)
                for (int j=0; j<CLR_NUM; j++)
                    if (dis[i][mid] >= 0 && dis[mid][j] >= 0
                        && (dis[i][j] < 0 || dis[i][j] > dis[i][mid] + dis[mid][j]))
                        dis[i][j] = dis[i][mid] + dis[mid][j];

        cerr << cc << " of " << cn << endl;
        cout << "Case #" << cc << ": " << endl;

        int sn;
        cin >> sn;

        for (int i=0; i<sn; i++)
        {
            int a, b;
            cin >> a >> b;
            a = clr[a-1];
            b = clr[b-1];
            cout << dis[a][b] << endl;
        }
    }

    return 0;
}
