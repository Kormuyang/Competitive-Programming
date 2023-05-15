#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define pl pair<ll, ll>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int mxN = 5e2 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int a[mxN], dp[mxN][mxN];
int n;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int gap = 2; gap < n; gap++) for(int i = 1; i + gap <= n; i++) {
        dp[i][i + gap] = max(dp[i][i + gap - 1], dp[i + 1][i + gap]) + a[i] + a[i + gap];
        for(int k = i + 2; k < i + gap - 1; k++) {
            dp[i][i + gap] = max(dp[i][i + gap], dp[i][k] + dp[k][i + gap] + a[i] + a[i + gap]);
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}
