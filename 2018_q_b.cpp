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
#include <iomanip>

using namespace std;

int main()
{
	int cn; cin >> cn;
	for (int cc = 1; cc <= cn; cc++)
	{
		int n; cin >> n;
		vector<int> v[2];
		for (int i = 0; i < n; i++)
		{
			int t; cin >> t;
			v[i % 2].push_back(t);
		}

		cout << "Case #" << cc << ": ";
		sort(v[0].begin(), v[0].end());
		sort(v[1].begin(), v[1].end());
		vector<int> vv(n);
		for (int i = 0; i < n; i++)
			vv[i] = v[i % 2][i / 2];
		for (int i = 0; i < n; i++)
			if (i == n - 1)
				cout << "OK" << endl;
			else if (vv[i] > vv[i + 1])
			{
				cout << i << endl;
				break;
			}
	}

	return 0;
}
