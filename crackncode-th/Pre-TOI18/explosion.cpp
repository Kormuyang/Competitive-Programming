#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define t3 tuple<int, int, int>
#define sz(a) ((int) a.size())

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int mxN = 5e5 + 1;

const int di[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int a[mxN], b[mxN], c[mxN];
int n, m, x, y, ans;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m >> x >> y;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = n;
    while(l <= r) {
        int md = (l + r) / 2, cnt = 0;
        for(int i = 1; i <= n; i++) b[i] = a[i] - (x * md), c[i] = 0;
        for(int i = 1; i <= n; i++) {
            c[i] += c[i - 1], b[i] -= c[i];
            if(b[i] > 0) {
                int tmp = (b[i] - 1) / (y - x) + 1;
                cnt += tmp; c[i] += tmp * (y - x);
                if(i + 2 * m + 1 <= n) c[i + 2 * m + 1] -= tmp * (y - x);
            }
        }
        if(cnt <= md) ans = md, r = md - 1;
        else l = md + 1;
    }
    cout << ans << '\n';
    return 0;
}
