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
        string dirs;
        cin >> n >> dirs;

        int dir;
        if (dirs.compare("left") == 0)
            dir = 0;
        else if (dirs.compare("right") == 0)
            dir = 1;
        else if (dirs.compare("up") == 0)
            dir = 2;
        else if (dirs.compare("down") == 0)
            dir =3;
        else
            cerr << "Error dir name" << endl;

        int mtr[20][20];
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (dir == 0)
                    cin >> mtr[i][j];
                else if (dir == 1)
                    cin >> mtr[i][n-1-j];
                else if (dir == 2)
                    cin >> mtr[j][i];
                else
                    cin >> mtr[j][n-1-i];

////////////////////////////////////////////////////////////

/*
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
                cout << mtr[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
*/

        for (int i=0; i<n; i++)
        {
            vector<int> v;
            int last = 0;
            for (int j=0; j<n; j++)
                if (mtr[i][j])
                {
                    if (mtr[i][j] == last)
                    {
                        v.push_back(2*last);
                        last = 0;
                    }
                    else
                    {
                        if (last)
                            v.push_back(last);
                        last = mtr[i][j];
                    }
                }

            if (last)
                v.push_back(last);

            for (int j=0; j<n; j++)
                if (j < v.size())
                    mtr[i][j] = v[j];
                else
                    mtr[i][j] = 0;
        }

/*
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
                cout << mtr[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
*/

////////////////////////////////////////////////////////////

        cout << "Case #" << cc << ":" << endl;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (j) cout << ' ';
                if (dir == 0)
                    cout << mtr[i][j];
                else if (dir == 1)
                    cout << mtr[i][n-1-j];
                else if (dir == 2)
                    cout << mtr[j][i];
                else
                    cout << mtr[j][n-1-i];
            }
            cout << endl;
        }
    }

    return 0;
}
