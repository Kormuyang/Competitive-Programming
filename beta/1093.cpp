#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 2e3 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int a[mxN], dp[mxN][mxN];
int n;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - a[i]);
        for(int j = 1; j <= i; j++) dp[i][j] = max(dp[i - 1][j - 1] + a[i], dp[i - 1][j + 2] - a[i]);
    }
    cout << dp[n][0] << '\n';
    return 0;
}
