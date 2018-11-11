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
		long long n, k; cin >> n >> k;
		long long cx = 1, cx1 = 0;

		while (k > cx + cx1)
		{
			k -= cx + cx1;

			n--;
			if (n % 2 == 0)
				cx = 2 * cx + cx1;
			else
				cx1 = cx + 2 * cx1;
			n /= 2;
		}

		n--;
		if (k <= cx1) n++;
		cout << "Case #" << cc << ": " << n / 2 + n % 2 << ' ' << n / 2 << endl;
	}

	return 0;
}
