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
		int d, n; cin >> d >> n;
		double maxv = -1;
		while (n--)
		{
			double p, v; cin >> p >> v;
			double vx = d * v / (d - p);
			if (maxv < 0 || maxv > vx)
				maxv = vx;
		}
		cout << "Case #" << cc << ": " << setprecision(8) << maxv << endl;
	}
	return 0;
}
