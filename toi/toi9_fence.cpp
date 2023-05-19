#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int mxN = 5e2 + 1;

int qs[mxN][mxN];
int n, m, t;

int calc(int a, int b, int c, int d) {
    return qs[c][d] - qs[a - 1][d] - qs[c][b - 1] + qs[a - 1][b - 1];
}

void solve() {
    memset(qs, 0, sizeof(qs));
    cin >> n >> m >> t;
    for(int i = 1, x, y; i <= t; i++) cin >> x >> y, qs[x + 1][y + 1] = 1;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        qs[i][j] += qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1];
    }
    for(int gap = min(n, m) - 1; gap >= 2; gap--) for(int i = 1; i + gap <= n; i++) for(int j = 1; j + gap <= m; j++) {
        if(calc(i, j, i + gap, j + gap) == calc(i + 1, j + 1, i + gap - 1, j + gap - 1)) {
            cout << gap + 1 << '\n'; return;
        }
    }
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for(int i = 0; i < 2; i++) solve();
    return 0;
}
