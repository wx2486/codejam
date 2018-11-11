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

int main()
{
	int cn; cin >> cn;
	for (int cc = 1; cc <= cn; cc++)
	{
		int a, b; cin >> a >> b;
		int n; cin >> n;

		a++;
		while (1)
		{
			int mid = (a + b) / 2;
			cout << mid << endl;

			string s; cin >> s;
			if (s == "CORRECT")
				break;
			else if (s == "TOO_SMALL")
				a = mid + 1;
			else if (s == "TOO_BIG")
				b = mid - 1;
			else if (s == "WRONG_ANSWER")
				return 0;
		}
	}
	return 0;
}
