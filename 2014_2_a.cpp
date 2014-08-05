#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int cn, cc;
    cin >> cn;

    for (cc=1; cc<=cn; cc++)
    {
        int n, x;
        cin >> n >> x;
        vector<int> sizes;
        for (int i=0; i<n; i++)
        {
            int tmp;
            cin >> tmp;
            sizes.push_back(tmp);
        }

        sort(sizes.begin(), sizes.end());

        int p = n - 1;
        int i;
        for (i=0; i<p; i++)
        {
            while (sizes[i] + sizes[p] > x && i < p)
                p--;
            if (i >= p) break;
            p--;
        }

        cout << "Case #" << cc << ": " << n - i << endl;
    }

    return 0;
}
