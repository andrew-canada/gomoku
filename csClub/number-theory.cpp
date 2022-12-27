#include <bits/stdc++.h>
using namespace std;

namespace NumberTheory {

template<int N>
struct sieve {
	bitset<N+1> prime;
	vector<int> primes;
	sieve() {
		prime.set();
		for (int i = 2; i <= N; i++) {
			if (prime[i]) {
				primes.push_back(i);
				for (int j = i*i; j <= N; j+=i) {
					prime[j] = false;
				}
			}
		}
	}
};

template<typename T>
vector<T> factors(T n) {
	vector<T> out;
	for (T i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			out.push_back(i);
			if (i*i != n) out.push_back(n/i);
		}
	}
	return out;
}

template<typename T>
bool isPrime(T n) {
	for (T i = 2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

template<typename T>
T gcd(T a, T b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

}
