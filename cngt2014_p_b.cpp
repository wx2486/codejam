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
        int v, d;
        cin >> v >> d;

        cout.precision(12);
        cout << "Case #" << cc << ": " << asin(min(1.0, d*9.8/v/v)) / asin(1.0) * 45 << endl;
    }

    return 0;
}
