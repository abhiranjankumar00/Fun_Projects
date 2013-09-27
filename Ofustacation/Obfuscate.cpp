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
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long  int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<string> vs;

#define Pf	printf
#define	Sf	scanf

#define PI M_PI
#define E M_E
#define	ep	1e-9

#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp	make_pair

#define pb	push_back
#define	SZ(a)	int((a).size())

#define	all(c)	(c).begin(), (c).end()
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0; i < n; i++)
#define forab(i, a, b)	for(int i = a; i <= b; i++)
#define rep(i, a, b)	for(int i = a; i>=b; i--)

ST originalMsg, finalMsg;

const ST breaks = " \t\n~!%^&*-+=|\\;:<>?,./()[]{}";
const ST symbol = "~!%^&*-+=|\\;:<>?,./()[]{}";
const ST invertedCommas = "\"\'";
ST combination = "00000000OOOOOOOO";
map<ST, ST> m;

bool IsWhiteSpace(char ch) {
	return (ch == ' ' || ch == '\t' || ch == '\n')? true : false;
}

ST FindMapping(ST st)
{
	if(st[0] == '#' || st == "//" || st == "/*" || st == "*/" || IsWhiteSpace(st[0]))
		return st;

	if(!present(st, m))
	{
		next_permutation(all(combination));
		m[st] =  "O" + combination;
	}
	return m[st];
}

bool IsConjugation(ST st)
{
	if(st.length() < 2)	return false;
	st = st.substr(0, 2);

	if(st == "+=" || st == "-=" || st == "*=" || st == "/=" || st == "++" || st == "--" || st == "%=" || st == "*/" )
		return true;
	if(st == "!=" || st == "^=" || st == "&=" || st == "&&" || st == "|=" || st == "<<" || st == ">>" || st == "==")
		return true;
	if(st == ">=" || st == "<=" || st == "->" || st == "||" || st == "::")
		return true;
	if(st[0] == '/' && (st[1] == '/' || st[1] == '*'))
		return true;

	return  false;
}

bool IsSymbol(char ch)
{
	forn(i, symbol.length())	if(symbol[i] == ch)	return true;
	return false;
}

ST Strip(ST & st)
{
	ST ret ;
	ret.clear();

	if(st.length() == 0)	return ret;

	if(st[0] == '#')
	{
		ret = st;
		st.clear();
		return ret;
	}

	if( IsWhiteSpace(st[0]) )
	{
		ret += st[0];
		if(st.length() > 1)	st = st.substr(1);
		else			st.clear();
		return ret;
	}

	if(st[0] == '\"' || st[0] == '\'')
	{
//		cout << st << " \t ";

		ret +=  st[0];
		st = st.substr(1);
		int idx = st.find( ret );

		while( (idx = st.find(ret[0])) != ST::npos && (idx > 0 && st[idx-1] == '\\'))
		{
			ret += st.substr(0, idx+1);
			st = st.substr(idx+1);
		}

		ret += st.substr(0, idx+1);
		st = st.substr(idx+1);

//		cout << ret << endl;
		return ret;
	}

	if(IsSymbol(st[0]))
	{
		if(!IsConjugation(st))
		{
			ret += st[0];
			st = st.substr(1);
			return ret;
		}
		else
		{
			ret = st.substr(0, 2);
			st = st.substr(2);
			return ret;
		}
	}

	ret.clear();
	int idx = st.find_first_of(breaks);


	if(idx == ST::npos)
	{
		ret = st;
		st.clear();
	}
	else if(IsWhiteSpace(st[idx]))
	{
		ret = st.substr(0, idx);
		st = st.substr(idx+1);
	}
	else
	{
		ret = st.substr(0, idx );
		st = st.substr(idx);
	}

	return ret;
}

int Process(ST inputFile = "")
{
	ST outputFile;
	//FILE * open, *close;

	sort(all(combination));
	m.clear();

	cout << "\n\nGREETINGS \t :) \n";

	if(inputFile.length() == 0)
	{
		cout << "Enter the absolute/relative path of C++ file : ";
		cin >> inputFile;
	}

	ifstream in(inputFile.c_str());
	if(!in)
	{
		cout << "Failed to open input file, " << inputFile << ". EXITING...\n";
		return -1;
	}
	int idx = inputFile.find('.');
//	outputFile = inputFile.substr(0,idx) + "_New.cpp";
	outputFile = inputFile.substr(0,idx) + "_Obfuscated.cpp";

	originalMsg.clear(), finalMsg.clear();

	ST st, tmp;
	st.clear(), tmp.clear();

//	while(getline(cin, st))
	while(getline(in, st))
	{
		originalMsg += st + "\n";

//		cout << st << " \n";
		while( (tmp = Strip(st)) != "" )
		{
//			finalMsg += FindMapping(tmp) + "";

			if( IsWhiteSpace(tmp[0]) )
				finalMsg += FindMapping(tmp);
			else
				finalMsg += FindMapping(tmp) + " ";

			tmp.clear();
		}

		finalMsg += "\n";
		st.clear();
	}

/*	
 	cout << originalMsg  << endl << endl;

	cout << "Mapping : \n";
	tr(it, m)
		cout << "-" << it->first << "-" << it->second << "-\n";
	cout << flush;
*/
	
	cout << "\nFile " << outputFile << " created...  :)" << endl;

	ofstream out(outputFile.c_str());
	
//	out << "//%%%%%%%%%%%%\n//%%%%lost%%%%\n//%%%%%%%%%%%%\n\n";
	out << 
		"//Name         : Shinchan Nohara\n"
		"//Age          : 5 years\n"
		"//Organisation : Kasukabe Defense Force\n\n";

	tr(it, m)
		out << "#define " << it->second << " " << it->first << endl;

	out << finalMsg << endl;

	return 0;
}

int main(int argc, char *argv[])
{
	vs tmp;

	for(int i = 1; i < argc; i++)
		tmp.pb(string(argv[i]));
			
	if(argc == 1)
		Process();
	else
		tr(it, tmp)
			Process(*it);
	return 0;
}
