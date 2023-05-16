#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int mxN = 5e1 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

ll qs[mxN][mxN], dp[mxN][mxN][mxN][mxN];
int n, m;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int k = 1; k <= m; k++) for(int l = 1; l <= m; l++) dp[i][j][k][l] = INF;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) {
        cin >> qs[i][j]; qs[i][j] += qs[i - 1][j] + qs[i][j - 1] - qs[i - 1][j - 1]; dp[i][i][j][j] = 0;
    }
    for(int k = 0; k < n; k++) for(int l = 0; l < m; l++) {
        if(k == 0 and l == 0) continue;
        for(int i = 1; i + k <= n; i++) for(int j = 1; j + l <= m; j++) {
            int br = i, er = i + k, bc = j, ec = j + l;
            for(int a = br; a < er; a++) dp[br][er][bc][ec] = min(dp[br][er][bc][ec], dp[br][a][bc][ec] + dp[a + 1][er][bc][ec]);
            for(int b = bc; b < ec; b++) dp[br][er][bc][ec] = min(dp[br][er][bc][ec], dp[br][er][bc][b] + dp[br][er][b + 1][ec]);
            dp[br][er][bc][ec] += qs[er][ec] - qs[br - 1][ec] - qs[er][bc - 1] + qs[br - 1][bc - 1];
        }
    }
    cout << dp[1][n][1][m] << '\n';
    return 0;
}
