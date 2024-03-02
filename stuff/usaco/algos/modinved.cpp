// Source: USACO Guide 
int inv(int x) {
	if (x <= 1) { return x; }
	return MOD - MOD / x * inv(MOD % x) % MOD;
}

// You can precompute like this:
inv[1] = 1;
for (int i = 2; i < m; i++) { inv[i] = m - m / i * inv[m % i] % m; }
