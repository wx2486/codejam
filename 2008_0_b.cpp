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

struct evt
{
    int time;
    char st;
    char io;
};

bool cmp(evt a, evt b)
{
    if (a.time != b.time)
        return a.time < b.time;
    return a.io < b.io;
}

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        int tt;
        cin >> tt;

        vector<evt> v;
        int na, nb;
        cin >> na >> nb;

        for (int i=0; i<na+nb; i++)
        {
            int hh, mm;
            char t;
            evt ev;

            cin >> hh >> t >> mm;
            ev.time = hh * 60 + mm;
            ev.st = (i<na) ? 'a' : 'b';
            ev.io = 'o';
            v.push_back(ev);

            cin >> hh >> t >> mm;
            ev.time = (hh * 60 + mm + tt);// % (24 * 60);
            ev.st = (i<na) ? 'b' : 'a';
            ev.io = 'i';
            v.push_back(ev);
        }

        sort(v.begin(), v.end(), cmp);

        int ca, cb;
        ca = cb = 0;
        na = nb = 0;

        for (int i=0; i<v.size(); i++)
            if (v[i].io == 'i' && v[i].st == 'a')
                na++;
            else if (v[i].io == 'i' && v[i].st == 'b')
                nb++;
            else if (v[i].io == 'o' && v[i].st == 'a')
            {
                na--;
                if (na < 0)
                {
                    ca++;
                    na = 0;
                }
            }
            else
            {
                nb--;
                if (nb < 0)
                {
                    cb++;
                    nb = 0;
                }
            }

        cout << "Case #" << cc << ": " << ca << " " << cb << endl;
    }

    return 0;
}
