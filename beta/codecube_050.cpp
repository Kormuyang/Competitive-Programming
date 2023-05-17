#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 1e5 + 1;
const int mxR = 2e3 + 1;

t3 arr[mxN];
int dp[2][mxR][2];
int R, C, N, ans = INF;

int calc(int a, int b, int c, int d) {
    return (abs(c - a) + abs(d - b));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    fill_n(dp[0][0], mxR * 2, INF);
    cin >> R >> C >> N;
    for(int i = 1, c, a, b; i <= N; i++) {
        cin >> c >> a >> b; arr[i] = {c, a, b};
    }
    arr[0] = {1, 0, 0};
    sort(arr + 1, arr + N + 1);
    int st; cin >> st; dp[0][st][0] = 0;
    for(int i = 1; i <= N; i++) {
        int now = i & 1, prev = (i - 1) & 1;
        fill_n(dp[now][0], mxR * 2, INF);
        auto [nc, na, nb] = arr[i];
        auto [pc, pa, pb] = arr[i - 1];
        for(int j = 1; j <= R; j++) for(int k = 0; k <= 1; k++) {
            if(dp[prev][j][k] == INF) continue;
            if(j >= na and j <= nb) {
                if(na > 1) {
                    dp[now][na - 1][k] = min(dp[now][na - 1][k], dp[prev][j][k] + calc(j, pc, na - 1, nc));
                }
                if(nb < R) {
                    dp[now][nb + 1][k] = min(dp[now][nb + 1][k], dp[prev][j][k] + calc(j, pc, nb + 1, nc));
                }
                if(k == 0) {
                    dp[now][j][1] = min(dp[now][j][1], dp[prev][j][0] + calc(j, pc, j, nc));
                }
            }
            else {
                dp[now][j][k] = min(dp[now][j][k], dp[prev][j][k] + calc(j, pc, j, nc));
            }
        }
    }
    for(int j = 1; j <= R; j++) {
        ans = min({ans, dp[N & 1][j][0], dp[N & 1][j][1]});
    }
    auto [nc, na, nb] = arr[N];
    cout << ans + (C - nc) << '\n';
    return 0;
}
