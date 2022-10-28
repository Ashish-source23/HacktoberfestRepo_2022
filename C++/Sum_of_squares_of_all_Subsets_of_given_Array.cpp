
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// Function to return (2^P % mod)
long long power(int p)
{
	long long res = 1;
	for (int i = 1; i <= p; ++i) {
		res *= 2;
		res %= mod;
	}
	return res % mod;
}

// Function to return the sum of squares of subsets
long long subset_square_sum(vector<int>& A)
{

	int n = (int)A.size();

	long long ans = 0;

	// Sqauaring the elements
	// and adding it to ans
	for (int i : A) {
		ans += (1LL * i * i) % mod;
		ans %= mod;
	}

	return (1LL * ans * power(n - 1)) % mod;
}

// Driver code
int main()
{
	vector<int> A = { 3, 7 };

	cout << subset_square_sum(A);

	return 0;
}
