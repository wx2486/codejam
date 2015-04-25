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

using namespace std;

const double PI = acos(-1.0);

int solve(vector<double> &ang)
{
//	for (int i=0; i<ang.size(); i++)
//		cout << ang[i] << ' ';
	int n = ang.size();
	sort(ang.begin(), ang.end());
	for (int i=0; i<n; i++)
		ang.push_back(ang[i] + 2*PI);
	int p = 0;
	int minn = n;
	for (int i=0; i<n; i++)
	{
		while (ang[p] - ang[i] < PI - 1e-15)
			p++;
//		cout << p << ' ';
		minn = min(minn, p-i-1);
	}
	return minn;
}

int main()
{
	int cn; cin >> cn;
	for (int cc=1; cc<=cn; cc++)
	{
		int n; cin >> n;
		vector<int> x(n), y(n);
		for (int i=0; i<n; i++)
			cin >> x[i] >> y[i];
		cout << "Case #" << cc << ": " << endl;
		for (int i=0; i<n; i++)
		{
			vector<double> ang;
			for (int j=0; j<n; j++)
				if (j != i)
					ang.push_back(
						atan2(
							y[j] - y[i],
							x[j] - x[i]));
			cout << solve(ang) << endl;
		}
	}
	return 0;
}
