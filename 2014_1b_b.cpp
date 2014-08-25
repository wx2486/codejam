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

#define MAX_BIT 30

struct numbit
{
    int bit[MAX_BIT];
};

vector<numbit> segs(int num);
long long cnt(numbit a, numbit b, numbit n);
int bitcnt(int a, int b, int c);

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        int a, b, n;
        cin >> a >> b >> n;

        vector<numbit> va, vb, vn;
        va = segs(a);
        vb = segs(b);
        vn = segs(n);

        long long sum = 0;
        for (int i=0; i<va.size(); i++)
            for (int j=0; j<vb.size(); j++)
                for (int k=0; k<vn.size(); k++)
                    sum += cnt(va[i], vb[j], vn[k]);

        cout << "Case #" << cc << ": " << sum << endl;
    }

    return 0;
}

vector<numbit> segs(int num)
{
    vector<numbit> seg;
    numbit t;
    memset(&t, 0, sizeof(t));

    for(int p=0; p<MAX_BIT; p++)
        t.bit[p] = bool(num&(1<<p));

    for (int pos=0; pos<MAX_BIT; pos++)
    {
        if (t.bit[pos])
        {
            t.bit[pos] = 0;
            seg.push_back(t);
        }
        
        t.bit[pos] = 2;
    }

    return seg;
}

long long cnt(numbit a, numbit b, numbit n)
{
    long long sum = 1;

    for (int i=0; i<MAX_BIT; i++)
        sum *= bitcnt(a.bit[i], b.bit[i], n.bit[i]);

    return sum;
}

int bitcnt(int a, int b, int c)
{
    int sum = 0;
    int aa, aaa, bb, bbb, cc, ccc;

    aa = aaa = a;
    bb = bbb = b;
    cc = ccc = c;

    if (a == 2)
        aa = 0, aaa = 1;
    if (b == 2)
        bb = 0, bbb = 1;
    if (c == 2)
        cc = 0, ccc = 1;

    for (int i=aa; i<=aaa; i++)
        for (int j=bb; j<=bbb; j++)
            for (int k=cc; k<=ccc; k++)
                if ((i&j) == k)
                    sum++;

    return sum;
}
