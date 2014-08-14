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

        vector<int> v, v0, v1;
        for (int i=0; i<n; i++)
        {
            int t;
            cin >> t;

            v.push_back(t);
            if (abs(t)%2 == 0)
                v0.push_back(t);
            else
                v1.push_back(t);
        }

        sort(v0.begin(), v0.end());
        reverse(v0.begin(), v0.end());
        sort(v1.begin(), v1.end());

        cout << "Case #" << cc << ":";

        int c0, c1;
        c0 = c1 = 0;
        for (int i=0; i<v.size(); i++)
            if (abs(v[i])%2 == 0)
                cout << ' ' << v0[c0++];
            else
                cout << ' ' << v1[c1++];
        cout << endl;
    }

    return 0;
}
