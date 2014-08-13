#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>

using namespace std;

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        int n;
        vector<string> pr;

        cin >> n;
        for (int i=0; i<n; i++)
        {
            string t;
            cin >> t;
            pr.push_back(t);
            cin >> t;
            pr.push_back(t);
        }

        set<string> used, st0, st1;
        for (int i=0; i<pr.size()/2; i++)
        {
            string a = pr[2*i], b = pr[2*i+1];
            if (used.find(a) != used.end())
                continue;

            used.insert(a);
            used.insert(b);
            st0.insert(a);
            st1.insert(b);

            bool goon = true;
            while (goon)
            {
                goon = false;
                for (int j=i+1; j<pr.size()/2; j++)
                {
                    string aa = pr[2*j], bb = pr[2*j+1];
                    bool ua = used.find(aa) != used.end();
                    bool ub = used.find(bb) != used.end();

                    if (ua && ub)
                    {
                        if (st0.find(aa) != st0.end() && st0.find(bb) != st0.end()
                            || st1.find(aa) != st1.end() && st1.find(bb) != st1.end())
                            goto BAD;
                    }
                    else if (ua || ub)
                    {
                        goon = true;
                        if (ub)
                            swap(aa, bb);
                        used.insert(bb);
                        if (st0.find(aa) != st0.end())
                            st1.insert(bb);
                        else
                            st0.insert(bb);
                    }
                }
            }
        }

        cout << "Case #" << cc << ": Yes" << endl;
        continue;
    BAD:
        cout << "Case #" << cc << ": No" << endl;
    }

    return 0;
}
