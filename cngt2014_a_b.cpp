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

void slv1(unsigned long long n)
{
    vector<int> v;
    while (n > 1)
    {
        v.push_back(n%2);
        n /= 2;
    }

    unsigned long long a, b;
    a = b = 1;
    for (int i=v.size()-1; i>=0; i--)
        if (v[i] == 0)
            b += a;
        else
            a += b;

    cout << a << ' ' << b << endl;
}

void slv2(unsigned long long a, unsigned long long b)
{
    vector<int> v;
    while (a != b)
        if (a > b)
            v.push_back(1), a -= b;
        else
            v.push_back(0), b -= a;

    unsigned long long n = 1;
    for (int i=v.size()-1; i>=0; i--)
        n = n * 2 + v[i];

    cout << n << endl;
}

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        int type;
        cin >> type;

        cout << "Case #" << cc << ": ";

        if (type == 1)
        {
            unsigned long long n;
            cin >> n;
            slv1(n);
        }
        else
        {
            unsigned long long p, q;
            cin >> p >> q;
            slv2(p, q);
        }
    }

    return 0;
}
