#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const ll INF = 1e18;
const int MOD = 1e6 + 7;
const int mxN = 5e2 + 1;
const int mxM = 5e4 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int a[mxN], dp[mxM];
int n, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = 1;
    for(int i = 1; i <= n; i++) for(int j = m; j >= a[i]; j--) {
        dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
    }
    cout << dp[m] << '\n';
    return 0;
}
