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

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        int n;
        cin >> n;

        int mtr[36][36];
        for (int i=0; i<n*n; i++)
            for (int j=0; j<n*n; j++)
                cin >> mtr[i][j];

        vector<int> v, good;
        for (int i=1; i<=n*n; i++)
            good.push_back(i);

        for (int i=0; i<n*n; i++)
        {
            v.clear();
            for (int j=0; j<n*n; j++)
                v.push_back(mtr[i][j]);
            sort(v.begin(), v.end());
            if (v != good)
                goto BAD;            
        }

        for (int i=0; i<n*n; i++)
        {
            v.clear();
            for (int j=0; j<n*n; j++)
                v.push_back(mtr[j][i]);
            sort(v.begin(), v.end());
            if (v != good)
                goto BAD;
        }

        for (int i=0; i<n*n; i++)
        {
            v.clear();
            for (int j=0; j<n*n; j++)
                v.push_back(mtr[ i/n*n + j/n ][ i%n*n + j%n ]);
            sort(v.begin(), v.end());
            if (v != good)
                goto BAD;
        }

        cout << "Case #" << cc << ": Yes" << endl;
        continue;
    BAD:
        cout << "Case #" << cc << ": No" << endl;
    }

    return 0;
}
