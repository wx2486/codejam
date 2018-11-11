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
		long long d; cin >> d;
		string s; cin >> s;

		vector<long long> v(30);
		int c = 0;
		for (int i = 0; i < s.length(); i++)
			if (s[i] == 'C')
				c++;
			else if (s[i] == 'S')
				v[c]++;

		int cnt = 0;
		while (1)
		{
			long long sum = 0;
			for (int i = 0; i < v.size(); i++)
				sum += v[i] << i;
			if (sum <= d) break;

			int p = v.size() - 1;
			while (!(p >= 0 && v[p]))
				p--;

			if (p == 0)
			{
				cnt = -1;
				break;
			}

			v[p]--;
			v[p - 1]++;

			cnt++;
		}

		cout << "Case #" << cc << ": ";
		if (cnt < 0) cout << "IMPOSSIBLE" << endl;
		else cout << cnt << endl;
	}

	return 0;
}
