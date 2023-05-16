#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 1e4 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

pi a[mxN];
vector<int> dp(1 << 8, INF);
int n, k;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first;
        for(int j = 0, x; j < k; j++) {
            cin >> x; a[i].second += (x == 1) * (1 << j);
        }
    }
    dp[0] = 0;
    for(int i = 0; i < (1 << k) - 1; i++) for(int j = 1; j <= n; j++) if((i | a[j].second) != i) {
        dp[i | a[j].second] = min(dp[i | a[j].second], dp[i] + a[j].first);
    }
    cout << dp[(1 << k) - 1] << '\n';
    return 0;
}
