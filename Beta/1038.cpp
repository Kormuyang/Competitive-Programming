#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 2e1 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

double a[mxN][mxN], dp[1 << mxN];
int n;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
        cin >> a[i][j]; a[i][j] /= 100;
    }
    dp[0] = 1.0;
    for(int i = 0; i < (1 << n) - 1; i++) for(int j = 0; j < n; j++) if((i | (1 << j)) != i) {
        dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] * a[j][__builtin_popcount(i)]);
    }
    cout << fixed << setprecision(12) << dp[(1 << n) - 1] * 100 << '\n';
    return 0;
}
