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

vector<int> e[1000], empty;

int calc(int node, int prt)
{
    int childn = e[node].size() - (prt>=0);

    if (childn == 0 || childn == 1)
        return 1;

    int max1 = 0, max2 = 0;
    for (int i=0; i<e[node].size(); i++)
        if (e[node][i] != prt)
        {
            int cnt = calc(e[node][i], node);
            if (cnt >= max1)
            {
                max2 = max1;
                max1 = cnt;
            }
            else if (cnt > max2)
                max2 = cnt;
        }

    return max1 + max2 + 1;
}

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        int n;
        cin >> n;

        for (int i=0; i<n; i++)
            e[i] = empty;

        for (int i=0; i<n-1; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            e[a].push_back(b);
            e[b].push_back(a);
        }

        int maxleft = 0;
        for (int i=0; i<n; i++)
            maxleft = max(maxleft, calc(i, -1));

        cout << "Case #" << cc << ": " << n - maxleft << endl;
    }

    return 0;
}
