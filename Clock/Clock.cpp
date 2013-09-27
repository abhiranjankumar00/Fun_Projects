//%%%%%%%%%%%%
//%%%%lost%%%%
//%%%%%%%%%%%%

#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iterator>
using namespace std;

typedef long long  int64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef string ST;
typedef stringstream SS;

#define 			  Pf	printf
#define				  Sf	scanf
#define				  ep	1e-9
#define			CL(a, b)	memset(a, b, sizeof(a))
#define				SZ(a)	int((a).size())
#define				  pb	push_back
#define			  all(c)	(c).begin(), (c).end()
#define			tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define	 present(x, c)	((c).find(x) != (c).end())                      // used for map and set. //
#define	cpresent(x, c)	(find(all(c),x) != (c).end())           // used for others like vector, list //
#define		 forn(i, n)	for(int i = 0; i < n; i++)
#define  forab(i, a, b)	for(int i = a; i <= b; i++)
#define	  rep(i, a, b)	for(int i = a; i>=b; i--)

ST GetTime()
{
	time_t tt;
	time(&tt);

	ST str( ctime(&tt) );
	SS ss (str);

	ss >> str >> str >> str >> str;

	return (str.substr(0, 2) + str.substr(3,2) + str.substr(6 ));
}

vector <ST> dig[10];
ST p;

void PreProcess(const int & s)
{
	// row = 2s + 3
	// col = s + 2
	// first row = 0;	middle row = s+1;		last row = 2s+2;

	vector <ST> et(2*s+3);

	et[0] = " ";
	forn(i, s) et[0] += '-';
	et[0] += ' ';

	et[1] = "|";
	forn(i, s)	et[1] += ' ';
	et[1] += '|';

	forab(i, 2, s)			et[i] = et[1];
	forab(i, s+2, 2*s + 1)	et[i] = et[1];

	et[s+1] = et[2*s+2] = et[0];

	forn(i, 10)	dig[i] = vector <ST>(et);

	forab(i, 1, s+1)	dig[0][s+1][i] = ' ';				// zero created

	forn(i, 2*s+3)	forn(j, s+1)	dig[1][i][j] = ' ';		// one created

	forab(i, 1, s)	dig[2][i][0] = ' ';
	forab(i, s+2, 2*s+1)	dig[2][i][s+1] = ' ';			// two created

	forab(i, 1, 2*s+1)	dig[3][i][0] = ' ';					// three created

	forab(i, s+2, 2*s+1)	dig[4][i][0] = ' ';
	forab(i, 1, s)	dig[4][0][i] = dig[4][2*s+2][i] = ' ';	// four created

	forab(i, 1, s)	dig[5][i][s+1] = dig[5][i+s+1][0] = ' ';// five created

	forab(i, 1, s)	dig[6][i][s+1] = ' ';					// six created

	forab(i, 1, s)	dig[7][s+1][i] = dig[7][2*s+2][i] = ' ';
	forab(i, 1, 2*s+1)	dig[7][i][0] = ' ';					// seven created

	forab(i, s+2, 2*s+1)	dig[9][i][0] = ' ';				// nine created
}

int Print(const int s, const ST st)
{
	vector <ST> ret(2*s+3, "");

	int len = st.length();
	forn(k, len)
	{
		int tmp = (st[k]-'0')%10;
		forn(i, 2*s+3)
		{
			ret[i] += dig[tmp][i];


			if( (k+1)%2 == 0 && k != len-1 )
				if(i == s-1 || i == s+1)
					ret[i] += "  .  ";
				else
					ret[i] += "     ";
			else
				ret[i] += ' ';
		}
	}
	p += "\n";
	int col = (s+2)*6+9+6-1+6;
	p += "  ";
	forn(i, col)
		p += "-";
	p += "\n";

	forn(i, 2*s+3)
		p += " (   " + ret[i] + "   )\n";
	p += " {";
	forn(i, col)
		p += "_";
	p += "}";
	return 1;
}

int main(int argv, char *argc[])
{
	int s;
	if(argv == 1) {
		cout << "Enter size : ";
		cin >> s;
	}
	else
		s = atoi(argc[1]);

	vector <ST> tmpp;
	ST st;
	char tmp ='-';
	PreProcess(s);

	while(1)
	{
		p = "";
		st = GetTime();

		if(tmp ^ st[5])
		{

#if defined __unix__
			system("clear");
#elif defined __unix
			system("clear");
#elif defined unix
			system("clear");
#else
			system("cls");
#endif

			Print(s, st);
			int t = st[4] % 3;

			p += "\n\n";
			p +=  "           O\n         o\n       .\n\n";

			if(t==0)
				p += "\\_\\_    _/_/        \n    \\__/            \n    (oo)\\_______    \n    (__)\\       )\\/\\\n        ||-----||   \n        ||     || ";
			else if(t==1)
				p += "  ___  \n{~._.~}\n ( Y ) \n()~*~()\n(_)-(_)" ;
			else
				p += "    .--.   \n   |o_o |  \n   |:_/ |  \n  //   \\ \\ \n (|     \\ )\n/'\\_   _/'\\\n\\___)=(___/" ;

			cout << p << endl;

			//fwrite(p.c_str(), sizeof(char), p.length()+10, stdout);
		}
		tmp = st[5];
	}

	return 0;
}
