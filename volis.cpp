#include<bits/stdc++.h>
#define int long long
#define INF 2000000007
using namespace std;

int n, d, f[1005][1005], a[1005];

main(){
	ios_base::sync_with_stdio(0);
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			f[i][j] = INF;
		}
	}

    f[1][1] = a[1] - d;
    for(int i = 1; i <= n; i++){
    	for(int j = 0; j <= i; j++){
    		if(f[i][j] == INF) continue;
    		f[i+1][j] = min(f[i+1][j], f[i][j]);

    		if(i < n && j < n && a[i+1] + d >= f[i][j])
			   f[i+1][j+1] = min(f[i+1][j+1], max(f[i][j],a[i+1] - d));
		}
	}

	for(int i = n; i >= 1; i--){
		if(f[n][i] != INF){
			cout << i << endl;
			return 0;
		}
	}
}
