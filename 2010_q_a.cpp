#include "iostream"
#include "fstream"
using namespace std;

#define STDIN cin
#define STDOUT cout

ofstream fout("a.out");
ifstream fin("a.in");

int main()
{
	int t;
	STDIN >> t;

	//STDOUT << t << endl;

	for (int tc=1; tc<=t; tc++)
	{
		int n, k;
		STDIN >> n >> k;

		STDOUT << "Case #" << tc << ": ";

		if ((k+1) % (1<<n))
			STDOUT << "OFF" << endl;
		else
			STDOUT << "ON" << endl;
	}

	return 0;
}
