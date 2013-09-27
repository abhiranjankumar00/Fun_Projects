//Name         : Shinchan Nohara
//Age          : 5 years
//Organisation : Kasukabe Defense Force

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;
const int sz = 1e5 + 111;
bool isPrime[sz];

void sieve() {
	memset(isPrime, 0, sizeof(isPrime));

	isPrime[0] = isPrime[1] = false;

	for(int i = 0, lets_stop_here = (int)sz; i < lets_stop_here; i++)
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
	cout << "randomNumber" << " = " << randomNumber << "\n";

	if(checkPrime(randomNumber))
		cout << "It is a prime." << ("\n");
	else
		cout << "It is NOT a prime." << ("\n");

	return 0;
}
