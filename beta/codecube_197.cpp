#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define pl pair<ll, ll>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int mxN = 2e3 + 1;
const int mxK = 5e1 + 1;

int v[mxN], sum[mxN][mxN], dp[2][mxN];
int n, k;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i <= n; i++) {
        priority_queue<int> low; priority_queue<int, vector<int>, greater<int>> high;
        int low_sum = 0, high_sum = 0;
        for(int j = i; j <= n; j++) {
            if(low.empty() or v[j] <= low.top()) low.emplace(v[j]), low_sum += v[j];
            else high.emplace(v[j]), high_sum += v[j];
            while(sz(low) - sz(high) > 1) {
                high.emplace(low.top()); high_sum += low.top();
                low_sum -= low.top(); low.pop();
            }
            while(sz(high) > sz(low)) {
                low.emplace(high.top()); low_sum += high.top();
                high_sum -= high.top(); high.pop();
            }
            sum[i][j] = (low.top() * sz(low) - low_sum) + (high_sum - low.top() * sz(high));
        }
    }
    for(int i = 1; i <= n; i++) dp[1][i] = sum[1][i];
    for(int t = 2; t <= k; t++) for(int i = 1; i <= n; i++) {
        int now = t & 1, prev = (t - 1) & 1; dp[now][i] = INF;
        for(int j = 1; j <= i; j++) dp[now][i] = min(dp[now][i], dp[prev][j - 1] + sum[j][i]);
    }
    cout << dp[k & 1][n] << '\n';
    return 0;
}
