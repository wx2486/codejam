#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <map>

using namespace std;

int main()
{
    int cn, cc;
    cin >> cn;

    for (cc=1; cc<=cn; cc++)
    {
        int n;
        vector<int> v;
        cin >> n;
        for (int i=0; i<n; i++)
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }

        int sum = 0;
        for (int i=0; i<n; i++)
        {
            int cnt = 0, cntt = 0;
            for (int j=i+1; j<n; j++)
                if (v[j] > v[i])
                    cnt++;
            for (int j=i-1; j>=0; j--)
                if (v[j] > v[i])
                    cntt++;
            sum += (cnt < cntt) ? cnt : cntt;
        }

        cout << "Case #" << cc << ": " << sum << endl;
    }

    return 0;
}
