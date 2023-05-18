#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define t4 tuple<int, int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 5e2 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

char g[mxN][mxN];
bool vis[1 << 3][mxN][mxN];
unordered_map<char, int> mp = {{'J', 0}, {'B', 1}, {'P', 2}, {'j', 0}, {'b', 1}, {'p', 2}};
queue<t4> q;
int n, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        cin >> g[i][j];
        if(g[i][j] == 'S') {
            q.emplace(0, 0, i, j); vis[0][i][j] = true; g[i][j] = '.';
        }
    }
    while(!q.empty()) {
        auto [d, c, x, y] = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int xx = x + di[i][0], yy = y + di[i][1];
            if(xx < 1 or xx > n or yy < 1 or yy > m or g[xx][yy] == '#') continue;
            if(g[xx][yy] == 'E') {
                cout << d + 1 << '\n'; return 0;
            }
            else if(g[xx][yy] == '.' and !vis[c][xx][yy]) {
                vis[c][xx][yy] = true; q.emplace(d + 1, c, xx, yy);
            }
            else if(g[xx][yy] != '.' and islower(g[xx][yy]) and !vis[c | (1 << mp[g[xx][yy]])][xx][yy]) {
                vis[c][xx][yy] = true; q.emplace(d + 1, c | (1 << mp[g[xx][yy]]), xx, yy);
            }
            else if(g[xx][yy] != '.' and isupper(g[xx][yy]) and !vis[c][xx][yy] and (c | (1 << mp[g[xx][yy]])) == c) {
                vis[c][xx][yy] = true; q.emplace(d + 1, c, xx, yy);
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}
