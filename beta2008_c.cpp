#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <array>
#include <algorithm>
#include <vector>

using namespace std;

#define MCN 100
#define MPN 50

pair<int, int> edge[MPN];
int mult[MPN][MPN];
int dis[MCN][MCN];
double prob[MPN];
int posn;
int n;
int unrn;
int nodlock[MPN];

void CalcProb(int id);

int main()
{
	int cn, cc;
#define FILEIO
#ifdef FILEIO
#endif
	cin >> cn;

	for (cc=1; cc<=cn; cc++)
	{
		map<string, int> name;
		string str;
		cin >> n >> str;
		name.insert(pair<string, int>(str, 0));
		for (int i=0; i<MCN; i++)
		{
			fill_n(dis[i], MCN, 0);
			fill_n(mult[i], MPN, 0);
		}
		fill_n(nodlock, MPN, 0);
		for (int i=0; i<n; i++)
		{
			int a, b;
			int td;
			cin >> str;
			name.insert(pair<string, int>(str, name.size()));
			a = name.at(str);
			cin >> str;
			name.insert(pair<string, int>(str, name.size()));
			b = name.at(str);
			edge[i].first = a;
			edge[i].second = b;
			cin >> td;
			if (!dis[a][b])
			{
				dis[a][b] = td;
				mult[a][b] = 1;
			}
			else
			{
				int j;
				for (j=0; j<i; j++){
					if (edge[j].first == a && edge[j].second == b)
						break;
				}

				if (dis[a][b] > td)
				{
					dis[a][b] = td;
					mult[a][b] = 1;
					for (j=0; j<i; j++){
						if (edge[j].first == a && edge[j].second == b)
							nodlock[j] = 1;
					}
				}
				else if (dis[a][b] == td)
					mult[a][b]++;
				else
					nodlock[i] = 1;
			}
		}
		posn = name.size();
		fill_n(prob, n, 0.0);
		unrn = 0;
		for (int i=1; i<posn; i++)
			CalcProb(i);

		cout << "Case #" << cc << ":";
		for (int i=0; i<n; i++)
		{
			cout.precision(7);
			cout.setf(ios::fixed);
			cout << " " << (nodlock[i] ? 0.0 : prob[i]) / (posn - unrn - 1);
		}
		cout.put('\n');
	}

	return 0;
}

void CalcProb(int id)
{
	vector<int> next[MCN], last[MCN];
	vector<int> insq;
	int forpn[MCN] = {1}, backpn[MCN] = {0};
	int pdis[MCN];
	int in[MCN] = {1};
	insq.push_back(0);
	copy_n(dis[0], posn, pdis);
	for (int i=1; i<posn; i++)
		last[i].push_back(0);
	for (int i=1; i<posn; i++)
	{
		int minid = 0;
		for (int j=1; j<posn; j++) if (!in[j] && pdis[j]){
			if (!minid || pdis[j] < pdis[minid])
				minid = j;
		}

		if (minid <= 0) break;
		in[minid] = 1;
		insq.push_back(minid);
		for (vector<int>::iterator j=last[minid].begin(); j<last[minid].end(); j++)
			forpn[minid] += mult[*j][minid] * forpn[*j];
		for (int j=1; j<posn; j++) if (!in[j] && dis[minid][j]){
			if (!pdis[j] || pdis[minid] + dis[minid][j] < pdis[j])
			{
				pdis[j] = pdis[minid] + dis[minid][j];
				last[j].clear();
				last[j].push_back(minid);
			}
			else if (pdis[minid] + dis[minid][j] == pdis[j])
				last[j].push_back(minid);
		}
	}

	if (!in[id])
	{
		unrn++;
		return;
	}

	for (int i=0; i<posn; i++){
		for (vector<int>::iterator j=last[i].begin(); j<last[i].end(); j++){
			next[*j].push_back(i);
		}
	}

	backpn[id] = 1;
	for (int i=insq.size()-1; i>=0; i--){
		for (vector<int>::iterator j=next[insq[i]].begin(); j<next[insq[i]].end(); j++)
			backpn[insq[i]] += mult[insq[i]][*j] * backpn[*j];
	}

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<next[edge[i].first].size(); j++)
			if (next[edge[i].first][j] == edge[i].second){
				prob[i] += double(forpn[edge[i].first]) / forpn[id] * backpn[edge[i].second];
				break;
			}
	}
}
