#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int cn; cin >> cn;
	for (int cc = 1; cc <= cn; cc++)
	{
		int n; cin >> n;
		stack<char> st[1001];

		for (int i = 0; i < n; i++)
		{
			int p; cin >> p;
			st[p].push('A' + i);
		}

		cout << "Case #" << cc << ": ";

		for (int i = 1000; i; i--)
		{
			while (!st[i].empty())
			{
				char c = st[i].top();
				st[i].pop();
				if (i)
					st[i - 1].push(c);

				if (st[i].size() % 2 == 1)
				{
					char cc = st[i].top();
					st[i].pop();
					if (i)
						st[i - 1].push(cc);
					cout << ' ' << c << cc;
				}
				else
				{
					cout << ' ' << c;
				}
			}
		}

		cout << endl;
	}
	return 0;
}
