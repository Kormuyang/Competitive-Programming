#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int mxN = 5e5 + 1;

int a[mxN], dp[mxN];
deque<pi> dq;
int n, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    dp[1] = a[1]; dq.emplace_back(a[1], 1);
    for(int i = 2; i <= n; i++) {
        while(!dq.empty() and dq.front().second < i - m) dq.pop_front();
        dp[i] = dq.front().first + a[i];
        while(!dq.empty() and dq.back().first >= dp[i]) dq.pop_back();
        dq.emplace_back(dp[i], i);
    }
    cout << dp[n] << '\n';
    return 0;
}
