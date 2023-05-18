#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define t6 tuple<int, int, int, int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 2e2 + 2;

const int di[9][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

char g[mxN][mxN];
bool vis[mxN][mxN][7][1 << 7];
queue<t6> q;
int n, m, cnt;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        cin >> g[i][j];
        if(g[i][j] == 'S') {
            q.emplace(0, i, j, 1, 0, 0); vis[i][j][1][0] = true;
        }
        else if(g[i][j] == 'G') g[i][j] = ('A' + (cnt++));
    }
    while(!q.empty()) {
        auto [time, x, y, time_mod, gem_mask, gem_cnt] = q.front(); q.pop();
        if(g[x][y] >= 'A' and g[x][y] <= 'G') {
            if(!(gem_mask & (1 << (g[x][y] - 'A')))) {
                gem_mask |= (1 << (g[x][y] - 'A')); gem_cnt++;
            }
        }
        if(gem_cnt == 7) {
            cout << time << '\n'; return 0;
        }
        time++, time_mod++; if(time_mod == 7) time_mod = 1;
        for(int i = 0; i < 5; i++) {
            int xx = x + di[i][0], yy = y + di[i][1];
            if(xx < 1 or xx > n or yy < 1 or yy > m or g[xx][yy] == '#' or vis[xx][yy][time_mod][gem_mask]) continue;
            if(g[xx][yy] >= '1' and g[xx][yy] <= '6') {
                if(time_mod != g[xx][yy] - '0' and gem_cnt < g[xx][yy] - '0') continue;
                vis[xx][yy][time_mod][gem_mask] = true; q.emplace(time, xx, yy, time_mod, gem_mask, gem_cnt);
            }
            else {
                vis[xx][yy][time_mod][gem_mask] = true; q.emplace(time, xx, yy, time_mod, gem_mask, gem_cnt);
            }
        }
    }
    cout << "-1\n";
    return 0;
}
