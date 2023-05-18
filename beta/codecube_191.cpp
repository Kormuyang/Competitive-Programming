#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e6 + 7;
const int mxN = 2e3 + 1;
const int PB = 2003;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

ll p[26], qsA[mxN], qsB[mxN];
int n, m;
string a, b;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    p[0] = 1; for(int i = 1; i < 26; i++) p[i] = p[i - 1] * PB;
    cin >> a >> b; n = sz(a), m = sz(b);
    for(int i = 1; i <= n; i++) qsA[i] = qsA[i - 1] + p[a[i - 1] - 'A'];
    for(int i = 1; i <= m; i++) qsB[i] = qsB[i - 1] + p[b[i - 1] - 'A'];
    for(int gap = min(n, m) - 1; gap >= 0; gap--) {
        set<ll> res;
        for(int i = 1; i + gap <= n; i++) res.emplace(qsA[i + gap] - qsA[i - 1]);
        for(int j = 1; j + gap <= m; j++) if(res.find(qsB[j + gap] - qsB[j - 1]) != res.end()) {
            cout << gap + 1 << '\n'; return 0;
        }
    }
    cout << "0\n";
    return 0;
}
