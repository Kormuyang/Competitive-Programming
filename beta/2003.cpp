#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 1e5 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int a[mxN], dp[2][4][4][4][4], tmp[4];
int n, ans = 0;

int calc(int x, int y, int z) {
    memset(tmp, 0, sizeof(tmp));
    tmp[x] = tmp[y] = tmp[z] = 1;
    return (tmp[1] + tmp[2] + tmp[3]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        char c; cin >> c;
        if(c == 'M') a[i] = 1;
        else if(c == 'F') a[i] = 2;
        else a[i] = 3;
    }
    dp[1][a[1]][0][0][0] = dp[1][0][0][a[1]][0] = 1;
    for(int idx = 2; idx <= n; idx++) {
        int now = idx & 1, prev = (idx - 1) & 1, x = a[idx];
        for(int i = 0; i <= 3; i++) for(int j = 0; j <= 3; j++) for(int k = 0; k <= 3; k++) for(int l = 0; l <= 3; l++) {
            if(dp[prev][i][j][k][l] == 0) continue;
            dp[now][x][i][k][l] = max(dp[now][x][i][k][l], dp[prev][i][j][k][l] + calc(i, j, x));
            dp[now][i][j][x][k] = max(dp[now][i][j][x][k], dp[prev][i][j][k][l] + calc(k, l, x));
            ans = max({ans, dp[now][x][i][k][l], dp[now][i][j][x][k]});
        }
    }
    cout << ans << '\n';
    return 0;
}
