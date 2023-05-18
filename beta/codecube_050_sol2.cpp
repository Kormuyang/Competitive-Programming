#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 1e5 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

t3 arr[mxN];
map<pi, int> dp[2];
int R, C, N, ans = INF;

int calc(int a, int b, int c, int d) {
    return (abs(c - a) + abs(d - b));
}

void update(map<pi, int> &mp, pi key, int val) {
    if(mp.find(key) == mp.end()) mp[key] = val;
    else mp[key] = min(mp[key], val);
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> R >> C >> N;
    for(int i = 1, c, a, b; i <= N; i++) {
        cin >> c >> a >> b; arr[i] = {c, a, b};
    }
    arr[0] = {1, 0, 0};
    sort(arr + 1, arr + N + 1);
    int st; cin >> st; update(dp[0], {st, 0}, 0);
    for(int i = 1; i <= N; i++) {
        int now = i & 1, prev = (i - 1) & 1;
        dp[now].clear();
        auto [nc, na, nb] = arr[i];
        auto [pc, pa, pb] = arr[i - 1];
        for(auto [key, val] : dp[prev]) {
            int j = key.first, k = key.second;
            if(j >= na and j <= nb) {
                if(na > 1) update(dp[now], {na - 1, k}, val + calc(j, pc, na - 1, nc));
                if(nb < R) update(dp[now], {nb + 1, k}, val + calc(j, pc, nb + 1, nc));
                if(k == 0) update(dp[now], {j, 1}, val + calc(j, pc, j, nc));
            }
            else update(dp[now], {j, k}, val + calc(j, pc, j, nc));
        }
    }
    for(auto [key, val] : dp[N & 1]) ans = min(ans, val);
    auto [nc, na, nb] = arr[N];
    cout << ans + (C - nc) << '\n';
    return 0;
}
