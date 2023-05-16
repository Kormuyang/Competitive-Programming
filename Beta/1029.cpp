#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 1e5 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

int n, m, q;
set<int> s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1, a, b; i <= m; i++) {
        cin >> a >> b;
        if(s.find(a) != s.end()) s.erase(a);
        else s.emplace(a);
        if(s.find(a + b) != s.end()) s.erase(a + b);
        else s.emplace(a + b);
    }
    s.emplace(1); s.emplace(n + 1);
    while(q--) {
        int x; cin >> x;
        auto it = s.upper_bound(x);
        cout << *(it--) - *it << '\n';
    }
    return 0;
}
