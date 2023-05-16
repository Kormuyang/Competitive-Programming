#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 5e1 + 2;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

char g[mxN][mxN];
queue<t3> q;
int n, m; pi st, en;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        cin >> g[i][j];
        if(g[i][j] == '*') q.emplace(0, i, j);
        else if(g[i][j] == 'S') st = {i, j};
        else if(g[i][j] == 'D') en = {i, j};
    }
    q.emplace(0, st.first, st.second);
    while(!q.empty()) {
        auto [d, x, y] = q.front(); q.pop();
        if(x == en.first and y == en.second) {
            cout << d << '\n'; return 0;
        }
        for(int i = 0; i < 4; i++) {
            int xx = x + di[i][0], yy = y + di[i][1];
            if(xx < 1 or xx > n or yy < 1 or yy > m) continue;
            if(g[x][y] == '*' and g[xx][yy] == '.') {
                g[xx][yy] = '*', q.emplace(d + 1, xx, yy);
            }
            else if(g[x][y] == 'S' and (g[xx][yy] == '.' or g[xx][yy] == 'D')) {
                g[xx][yy] = 'S', q.emplace(d + 1, xx, yy);
            }
        }
    }
    cout << "KAKTUS\n";
    return 0;
}
