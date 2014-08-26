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

string map[10] = {"1111110", "0110000", "1101101", "1111001", "0110011",
                  "1011011", "1011111", "1110000", "1111111", "1111011"};

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        int n;
        cin >> n;

        vector<string> ans;
        string dis[100];
        for (int i=0; i<n; i++)
            cin >> dis[i];

        for (int start=0; start<10; start++)
        {
//            cout << start << endl;
            int stat[7] = {0};
            string tans;
            for (int i=n-1; i>=0; i--)
            {
                int num = (start+i) % 10;
//                cout << "D: " << num << " " << map[num] << " " << dis[n-1-i] << " ";

                for (int pos=0; pos<7; pos++)
                {
                    if (dis[n-1-i][pos] == '1' && (map[num][pos] == '0' || stat[pos] == 2)
                        || dis[n-1-i][pos] == '0' && map[num][pos] == '1' && stat[pos] == 1)
                    {
//                        cout << endl;
                        goto NEXT;
                    }

                    if (dis[n-1-i][pos] == '1')
                        stat[pos] = 1;

                    if (dis[n-1-i][pos] == '0' && map[num][pos] == '1')
                        stat[pos] = 2;
                }

//                for (int ttt=0; ttt<7; ttt++)
//                    cout << stat[ttt];
//                    cout << endl;
            }
            

            int nnum;
            tans = "0000000";
            nnum = (start+9) % 10;

//            cout << "Dc: " << map[nnum] << endl;
            for (int pos=0; pos<7; pos++)
            {
                if (map[nnum][pos] == '1' && stat[pos] == 0)
                {
                    ans.push_back("");
                    ans.push_back("");
                    goto NEXT;
                }
                if (map[nnum][pos] == '1' && stat[pos] == 1)
                    tans[pos] = '1';
            }

//            cout << "Dbg: " << nnum << " " << tans << endl;
//            cout << "Dbd:  ";
//            for (int pos=0; pos<7; pos++)
//                cout << stat[pos];
//            cout << endl;

            if (ans.size() == 0 || tans.compare(ans[0]) != 0)
                ans.push_back(tans);

        NEXT:
            ;
        }

        if (ans.size() != 1)
            cout << "Case #" << cc << ": ERROR!" << endl;
        else
            cout << "Case #" << cc << ": " << ans[0] << endl;
    }

    return 0;
}
