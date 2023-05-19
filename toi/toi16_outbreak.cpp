#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define t4 tuple<int, int, int, int>
#define sz(a) ((int) a.size())

const int di[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

map<pi, t3> mp;
priority_queue<t4, vector<t4>, greater<t4>> pq;
int n, T, f, s, q;
pi ans;

void update(int x, int y, int t) {
    auto it = mp.find({x, y}); if(it == mp.end()) return;
    auto &[hp, st, ti] = it->second; if(st != 3) return;
    int sum = 0, cnt = 0;
    for(int i = 0; i < 4; i++) {
        int xx = x + di[i][0], yy = y + di[i][1];
        auto it = mp.find({xx, yy}); if(it == mp.end()) continue;
        auto &[hp, st, ti] = it->second;
        if(st == 1) cnt++, sum += (f - hp - ti);
    }
    if(cnt) {
        ti = max(t, (hp - sum - 1) / cnt + 1); pq.emplace(ti, 2, x, y);
    }
    else ti = -1;
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> T >> f >> s >> q;
    for(int i = 1, x, y, h, v; i <= n; i++) {
        cin >> x >> y >> h >> v;
        auto &[hp, st, ti] = mp[{x, y}];
        hp = h, st = 3, ti = -1;
        if(v) {
            if(h > q) ti = 0, pq.emplace(0, 2, x, y);
            else st = 0, ans.first++, ans.second++;
        }
    }
    while(!pq.empty()) {
        auto [t, d, x, y] = pq.top(); pq.pop(); if(t > T) break;
        auto &[hp, st, ti] = mp[{x, y}];
        if(st <= d or (d == 2 and t != ti)) continue;
        st = d;
        if(d == 2) {
            ans.first++; pq.emplace(t + max(1, hp - s), 1, x, y); pq.emplace(t + max(1, hp - q), 0, x, y);
        }
        else {
            ans.second += (d == 0);
            for(int i = 0; i < 4; i++) update(x + di[i][0], y + di[i][1], t);
        }
    }
    cout << ans.first - ans.second << '\n' << ans.second << '\n';
    return 0;
}
