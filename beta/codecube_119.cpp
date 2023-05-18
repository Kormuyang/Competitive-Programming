#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 1e2 + 1;
const int mxM = 1e4 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int a[mxN][mxM], dp[mxN][mxM];
deque<pi> dq;
int n, m, k, ans = 0;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> a[i][j];
    for(int j = 1; j <= m; j++) dp[1][j] = a[1][j];
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= k + 1; j++) {
            while(!dq.empty() and dq.back().second <= dp[i - 1][j]) dq.pop_back();
            dq.emplace_back(j, dp[i - 1][j]);
        }
        for(int j = 1; j <= m; j++) {
            while(!dq.empty() and dq.front().first < j - k) dq.pop_front();
            dp[i][j] = a[i][j] + dq.front().second;
            if(j + k + 1 <= m) {
                while(!dq.empty() and dq.back().second <= dp[i - 1][j + k + 1]) dq.pop_back();
                dq.emplace_back(j + k + 1, dp[i - 1][j + k + 1]);
            }
        }
        dq.clear();
    }
    for(int j = 1; j <= m; j++) ans = max(ans, dp[n][j]);
    cout << ans << '\n';
    return 0;
}
