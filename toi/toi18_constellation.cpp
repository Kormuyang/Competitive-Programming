#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int MOD = 1e6 + 3;
const int mxN = 3e2 + 1;

int pas[mxN * 5][mxN * 5], dpL[mxN * 5][mxN * 5], dpR[mxN * 5][mxN * 5];
int n, m, k, ans;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i = 1; i <= mxN * 2; i++) {
        pas[i][0] = pas[i][i] = 1;
        for(int j = 1; j < i; j++) pas[i][j] = (pas[i - 1][j] + pas[i - 1][j - 1]) % MOD;
    }
    cin >> n >> m >> k;
    for(int i = 601; i <= 600 + n; i++) for(int j = 601; j <= 600 + m; j++) {
        char c; cin >> c; dpL[i][j] = dpR[i][j] = (c == '#');
    }
    for(int i = 1; i < mxN * 5; i++) for(int j = 1; j < mxN * 5 - 1; j++) {
        dpL[i][j] += dpL[i - 1][j - 1]; dpR[i][j] += dpR[i - 1][j + 1];
    }
    for(int l = 1; l <= n + m; l++) for(int i = 601; i <= 600 + n; i++) for(int j = 601; j <= 600 + m; j++) {
        int tmp = 0;
        tmp += dpR[i][j - l] - dpR[i - l - 1][j + 1];
        tmp += dpR[i + l][j] - dpR[i - 1][j + l + 1];
        tmp += dpL[i + l - 1][j - 1] - dpL[i][j - l];
        tmp += dpL[i - 1][j + l - 1] - dpL[i - l][j];
        ans = (ans + pas[tmp][k]) % MOD;
    }
    cout << ans << '\n';
    return 0;
}
