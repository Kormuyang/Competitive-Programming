#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 1e1 + 1;
const int mxM = 1e6 + 1;

int a[mxN], dp[mxM], path[mxM], res1[mxN], res2[mxN];
int p, m, n;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> p >> m >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) {
        dp[i] = INF;
        for(int j = 1; j <= n; j++) {
            if(i >= a[j] and dp[i - a[j]] + 1 < dp[i]) {
                dp[i] = dp[i - a[j]] + 1; path[i] = j;
            }
        }
    }
    int ans = p;
    for(int i = p + 1; i <= m; i++) {
        if(dp[i] + dp[i - p] < dp[ans] + dp[ans - p]) ans = i;
    }
    cout << dp[ans] << ' ' << dp[ans - p] << '\n';
    int i = ans, j = ans - p;
    while(i > 0) {
        res1[path[i]]++; i -= a[path[i]];
    }
    while(j > 0) {
        res2[path[j]]++; j -= a[path[j]];
    }
    for(int i = 1; i <= n; i++) cout << res1[i] << ' '; cout << '\n';
    for(int i = 1; i <= n; i++) cout << res2[i] << ' '; cout << '\n';
    return 0;
}
