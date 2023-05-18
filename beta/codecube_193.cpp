#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define pl pair<ll, ll>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const ll INF = 1e18;
const int MOD = 1e6 + 7;
const int mxN = 1e5 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

pi res[mxN];
ll x[mxN], c[mxN], dp[mxN];
priority_queue<pl> pq;
int n, k;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> res[i].first >> res[i].second;
    sort(res + 1, res + n + 1);
    for(int i = 1; i <= n; i++) x[i] = res[i].first, c[i] = res[i].second;
    for(int i = 1; i <= n; i++) {
        while(!pq.empty() and pq.top().second < x[i] - k) pq.pop();
        ll mx = (pq.empty() ? -INF : pq.top().first);
        dp[i] = max(dp[i - 1], mx + c[i] - x[i]);
        pq.emplace(dp[i - 1] + c[i] + x[i], x[i]);
    }
    cout << dp[n] << '\n';
    return 0;
}
