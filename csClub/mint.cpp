namespace ModInt {

using ll = long long;
struct mint {
	static const ll MOD = 1000000007;
	ll v=0;
	mint(): v(0) {}
	mint(ll x): v(x) { }
	mint &operator *=(const mint &rhs) {
		v *= rhs.v;
		v %= MOD;
		return *this;
	}
	mint &operator+=(const mint &rhs) {
		v += rhs.v;
		v -= MOD*(v>=MOD);
		return *this;
	}
	mint &operator-=(const mint &rhs) {
		v -= rhs.v;
		v += MOD*(v<0);
		return *this;
	}
	mint operator*(const mint &rhs) const { return mint(*this)*=rhs; };
	mint operator+(const mint &rhs) const { return mint(*this)+=rhs; };
	mint operator-(const mint &rhs) const { return mint(*this)-=rhs; };
	mint pow(ll p) const {
		mint out = 1, x = *this;
		while (p) {
			if (p&1) out *= x;
			x *= x;
			p >>= 1;
		}
		return out;
	}
	mint inv() const {
		return pow(MOD-2);
	}
};

mint factorial(ll n) {
	mint out = 1;
	for (ll i = 1; i <= n; i++) out *= i;
	return out;
}

mint choose(ll n, ll k) {
	return factorial(n)*(factorial(n-k)*factorial(k)).inv();
}

};
