#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pi pair<int, int>

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int n, k, q; cin >> n >> k >> q;
        vector<int> temp(n); for(int i = 0; i < n; i++) cin >> temp[i];
        vector<pi> day;
        for(int i = 0; i < n; i++) {
            if(temp[i] > q) continue;
            if(day.empty() or day.back().second < i - 1) day.emplace_back(i, i);
            else day.back().second = i;
        }
        int ans = 0;
        for(auto [l, r] : day) {
            int gap = r - l + 1;
            if(gap < k) continue;
            ans += (gap - k + 1) * (gap - k + 2) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}
