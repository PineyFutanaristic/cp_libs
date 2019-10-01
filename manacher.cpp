#include <bits/stdc++.h>

using namespace std;
 
int n, r[100007], ans = 1;
string s;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	s = string(n * 2 + 1, '*');
	for (int i = 1; i < 2 * n; i += 2)
	{
		cin >> s[i];
	}
	int c = 0, rc = 0;

	for (int i = 1; i < 2 * n; ++i)
	{
		if (c + rc >= i) r[i] = min(c + rc - i, r[2 * c - i]);
		while (s[i + r[i]] == s[i - r[i]] && (i > r[i]) && (i + r[i] < 2 * n)) ++r[i];
		if (s[i + r[i]] != s[i - r[i]]) --r[i];
		if (i + r[i] > c + rc) c = i, rc = r[i];
		ans = max(ans, r[i]);
	}

	cout << ans << endl;
	return 0;
} 
