#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int ukr = 1e5+10;
string s;
ll n, m, a, b;
ll freq[ukr];
ll ar[ukr];
vector<pair<ll,ll>> v;
void solve(){
    cin >> s;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a >>b;
        v.push_back({b, a});
    }
    sort(all(v));
    ll ans = 0, val = 0, vreq = 0;
    for(auto i : v){
        ans += (vreq*i.first)-val;
        ans -= (freq[i.second]*i.first - ar[i.second]);
        vreq++;
        freq[i.second]++;
        ar[i.second] += i.first;
        val += i.first;
    }
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}