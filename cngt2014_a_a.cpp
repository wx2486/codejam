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

string s;
string num[] = {" zero", " one", " two", " three", " four",
                " five", " six", " seven", " eight", " nine"};
string cnt[] = {"", "", " double", " triple", " quadruple", " quintuple",
                " sextuple", " septuple", " octuple", " nonuple", " decuple"};

void fmt(int pos, int len)
{
    while (len)
    {
        int l;
        for (l=1; l < len && s[pos] == s[pos+l]; l++);

        string number = num[s[pos]-'0'];

        if (l <= 10)
            cout << cnt[l] << number;
        else
            for (int i=0; i<l; i++)
                cout << number;

        pos += l;
        len -= l;
    }
}

int main()
{
    int cn;
    cin >> cn;

    for (int cc=1; cc<=cn; cc++)
    {
        int pos, len;
        pos = 0;
        cin >> s >> len;
        cout << "Case #" << cc << ":";

        fmt(pos, len);
        pos += len;

        while (pos < s.length())
        {
            char tmp;
            cin >> tmp >> len;
            fmt(pos, len);
            pos += len;
        }

        cout << endl;
    }

    return 0;
}
