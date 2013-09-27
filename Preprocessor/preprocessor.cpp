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

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;

#define PI		M_PI
#define E 		M_E
#define	ep		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair

#define pb		push_back
#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

bool process(ST file) {
	ifstream in1(file.c_str());
	if(in1 == nullptr) 
		return false;
	ST outfile = "ocf." + file;
	ofstream out1(outfile.c_str());

	ST st;
	vs includes;
	while(getline(in1, st)) {
		if(st.size() >= 8 && st.substr(0, 8) == "#include")
			includes.pb(st);
		else
			out1 << st << endl;
	}
	out1.flush();
	ST tmpfile = "sqae." + file;
	ST command = "cpp " + outfile + " > " + tmpfile;
	system(command.c_str());

	int idx = file.find_first_of('.');
//	ST name = file.substr(0, idx) + "_new.cpp";
	ST name = file.substr(0, idx) + "_preprocessed.cpp";

	ifstream in2(tmpfile.c_str());
//	ofstream out2(("new_" + file).c_str());
	ofstream out2(name.c_str());
	bool isTypedef = false;

//	out2 << "//%%%%%%%%%%%%\n//%%%%lost%%%%\n//%%%%%%%%%%%%\n\n";
	out2 << 
		"//Name         : Shinchan Nohara\n"
		"//Age          : 5 years\n"
		"//Organisation : Kasukabe Defense Force\n\n";

	for(auto &x: includes)
		out2 << x << endl;

	bool blankLine = false;
	while(getline(in2, st)) {
		if(st.size() >= 2 && st.substr(0, 2) == "# ")
			continue;
		if(blankLine && st == "")
			continue;
		blankLine = false;

		if(isTypedef && !(st.size() >= 7 && st.substr(0, 7) == "typedef"))
			out2 << endl;

		if(st.size() >= 7 && st.substr(0, 7) == "typedef") {
			isTypedef = true;
			out2 << endl;
		}

		if(st == "")
			blankLine = true;
		int i;
		for(i = 0; i < st.size() && st[i] == ' '; i++)
			out2 << "\t";
		out2 << st.substr(i);
	}

	system(("rm " + tmpfile).c_str());
	system(("rm " + outfile).c_str());
	return true;
}

int main(int argv, char **argc)
{
	vs files;
	if(argv > 1)
		forab(i, 1, argv-1)
			files.pb(ST(argc[i]));
	else {
		ST tmp;
		cout << "Enter name of file: ";
		cin >> tmp;
		files = {tmp};
	}

	for(auto &x: files) {
		if(!process(x))
			cout << "Wrong path for file " << x << " is mentioned :(" << endl;
		else {
			int idx = x.find_first_of('.');
//			cout << "Preprocessing is successfull for file " << x << " and " << (x.substr(0, idx) + "_new.cpp is created.\n") ;
			cout << "File " << (x.substr(0, idx) + "_preprocessed.cpp is created.\n") ;
		}
	}

	return 0;
}

