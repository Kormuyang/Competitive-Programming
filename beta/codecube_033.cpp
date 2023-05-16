#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define t4 tuple<int, int, int, int>
#define sz(a) ((int) a.size())

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int mxN = 3e2 + 2;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

char g[mxN][mxN];
bool vis[mxN][mxN][4];
queue<pi> q;
queue<t4> q2;
int n, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        cin >> g[i][j];
        if(g[i][j] == 'S') q2.emplace(0, i, j, 0), vis[i][j][0] = true;
        else if(g[i][j] == '|' or g[i][j] == '/' or g[i][j] == '-' or g[i][j] == '\\') q.emplace(i, j);
    }
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            vis[x][y][i] = true;
            if(g[x][y] == '|') {
                for(int xx = x - 1, yy = y; xx >= 1 and g[xx][yy] == '.'; xx--) vis[xx][yy][i] = true;
                for(int xx = x + 1, yy = y; xx <= n and g[xx][yy] == '.'; xx++) vis[xx][yy][i] = true;
                g[x][y] = '/';
            }
            else if(g[x][y] == '/') {
                for(int xx = x - 1, yy = y + 1; xx >= 1 and yy <= m and g[xx][yy] == '.'; xx--, yy++) vis[xx][yy][i] = true;
                for(int xx = x + 1, yy = y - 1; xx <= n and yy >= 1 and g[xx][yy] == '.'; xx++, yy--) vis[xx][yy][i] = true;
                g[x][y] = '-';
            }
            else if(g[x][y] == '-') {
                for(int xx = x, yy = y - 1; yy >= 1 and g[xx][yy] == '.'; yy--) vis[xx][yy][i] = true;
                for(int xx = x, yy = y + 1; yy <= m and g[xx][yy] == '.'; yy++) vis[xx][yy][i] = true;
                g[x][y] = '\\';
            }
            else {
                for(int xx = x - 1, yy = y - 1; xx >= 1 and yy >= 1 and g[xx][yy] == '.'; xx--, yy--) vis[xx][yy][i] = true;
                for(int xx = x + 1, yy = y + 1; xx <= n and yy <= m and g[xx][yy] == '.'; xx++, yy++) vis[xx][yy][i] = true;
                g[x][y] = '|';
            }
        }
    }
    while(!q2.empty()) {
        auto [time, x, y, time_mod] = q2.front(); q2.pop();
        if(g[x][y] == 'E') {
            cout << time << '\n'; return 0;
        }
        time++, time_mod++;
        if(time_mod == 4) time_mod = 0;
        for(int i = 0; i < 4; i++) {
            int xx = x + di[i][0], yy = y + di[i][1];
            if(xx < 1 or xx > n or yy < 1 or yy > m) continue;
            if(!vis[xx][yy][time_mod] and (g[xx][yy] == '.' or g[xx][yy] == 'E')) {
                vis[xx][yy][time_mod] = true; q2.emplace(time, xx, yy, time_mod);
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}
