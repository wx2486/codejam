#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

struct stru{
	string s;
	int val;
	int id;
};

int ISubSqn(vector<stru> vec)
{
	vector<int> v;
	v.resize(vec.size(), 1);
	for (int i=1; i<vec.size(); i++){
		for (int j=0; j<i; j++){
			if (vec[j].id < vec[i].id && v[j]+1 > v[i])
				v[i] = v[j]+1;
		}
	}

	return *max_element(v.begin(), v.end());
}

int main()
{
	int cn, cc;
	cin >> cn;

	for (cc=1; cc<=cn; cc++)
	{
		vector<stru> vec;
		cin.get();
		do
		{
			stru st;
			vec.push_back(st);
			cin >> vec.back().s;
			vec.back().id = vec.size();
		}
		while (cin.get() != '\n');
		for (int i=0; i<vec.size(); i++)
			cin >> vec[i].val;
		cout << "Case #" << cc << ":";

		sort(vec.begin(), vec.end(), [](const stru a, const stru b)->bool { return a.val < b.val; });

		int reachlen = ISubSqn(vec);
		while (vec.size() > reachlen)
		{
			vector<stru>::iterator tmax = vec.begin();
			for (vector<stru>::iterator i = vec.begin(); i != vec.end(); i++){
				if (tmax->s.compare(i->s) > 0)
					tmax = i;
			}
			stru tmp = *tmax;
			vec.erase(tmax);
			if (ISubSqn(vec) >= reachlen)
				cout << " " << tmp.s;
			else
			{
				tmp.s = " ";
				tmp.s[0] = 'z'+1;
				vec.push_back(tmp);
				sort(vec.begin(), vec.end(), [](const stru a, const stru b)->bool { return a.val < b.val; });
			}
		}

		cout << endl;
	}
	return 0;
}
