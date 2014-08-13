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
        string max = "";

        cin >> n;
        getline(cin, max);

        int cost = 0;
        max = "";
        for (int i=0; i<n; i++)
        {
            string s;
            getline(cin, s);
            if (s.compare(max) < 0)
                cost++;
            else
                max = s;
        }

        cout << "Case #" << cc << ": " << cost << endl;
    }

    return 0;
}
