#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define t5 tuple<int, int, int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 1e5 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

void solve() {
    int n; cin >> n;
    deque<int> dq; int cnt = 0;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(!dq.empty() and dq.front() == x) dq.pop_front(), cnt++;
        else if(sz(dq) > 1 and dq[0] != dq[1] and dq[0] != x and dq[1] != x) dq.pop_front(), dq.pop_front(), cnt++;
        else dq.emplace_front(x);
    }
    if(dq.empty()) cout << "Yes\n" << cnt << '\n';
    else cout << "No\n" << cnt << '\n' << sz(dq) << '\n';
    return;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
