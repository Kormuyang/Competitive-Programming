#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 5e2 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int qs[mxN][mxN];
int n, m;

int calc(int a, int b, int c, int d) {
    return (qs[c][d] - qs[c][b - 1] - qs[a - 1][d] + qs[a - 1][b - 1]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        char c; cin >> c; qs[i][j] = (c == 'O') + qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1];
    }
    for(int gap = min((n + 1) / 2, m); gap >= 3; gap--) for(int i = 1; i + gap * 2 - 2 <= n; i++) for(int j = 1; j + gap - 1 <= m; j++) {
        if(calc(i, j, i + gap * 2 - 2, j + gap - 1) - calc(i + 1, j + 1, i + gap - 2, j + gap - 1) - calc(i + gap, j, i + gap * 2 - 3, j + gap - 2) == 0) {
            cout << gap << '\n'; return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}
