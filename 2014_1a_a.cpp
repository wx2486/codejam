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

long long trans(string s)
{
    long long num = 0;
    for (int i=0; i<s.length(); i++)
        num = (num<<1) | (s[i]-'0');
    return num;
}

int cnt(long long num)
{
    int cnt = 0;
    while (num)
    {
        cnt += num & 1;
        num >>= 1;
    }
    return cnt;
}

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        int n, len;
        cin >> n >> len;

        vector<long long> va, vb;
        for (int i=0; i<2*n; i++)
        {
            string t; cin >> t;
            long long tmp = trans(t);
            if (i < n)
                va.push_back(tmp);
            else
                vb.push_back(tmp);
        }

        sort(vb.begin(), vb.end());

        int minswb = -1;
        for (int i=0; i<vb.size(); i++)
        {
            long long swt = va[0] ^ vb[i];
            vector<long long> vt = va;
            for (int i=0; i<vt.size(); i++)
                vt[i] ^= swt;
            sort(vt.begin(), vt.end());
            for (int i=0; i<vt.size(); i++)
                if (vt[i] != vb[i])
                    goto BAD;
            
            if (minswb < 0 || minswb > cnt(swt))
                minswb = cnt(swt);
        BAD:
            ;
        }

        cout << "Case #" << cc << ": ";
        if (minswb < 0)
            cout << "NOT POSSIBLE" << endl;
        else
            cout << minswb << endl;
    }

    return 0;
}
