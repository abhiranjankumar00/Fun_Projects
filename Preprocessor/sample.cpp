//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define endl		("\n")

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	CL(a, b)	memset(a, b, sizeof(a))

const int sz = 1e5 + 111;
bool isPrime[sz];

void sieve() {
	CL(isPrime, 0);

	isPrime[0] = isPrime[1] = false;

	forn(i, sz)
		if(isPrime[i] == true) 
			for(int j = i << 1; j < sz; j += i)
				isPrime[j] = false;
}

bool checkPrime(int n) {
	return isPrime[n];
}

int main()
{
	sieve();

	int randomNumber = rand() % sz;
	DEBUG(randomNumber);
	
	if(checkPrime(randomNumber))
		cout << "It is a prime." << endl;
	else
		cout << "It is NOT a prime." << endl;

	return 0;
}

