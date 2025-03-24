#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll n, m, ln, lm, q, a, b;
ll binser(ll stmsh, ll ktmsh){
    ll l = 0, r = q-1, res = -1;
    while(l <= r){
        ll mid = l + (r-l)/2;
        ll nw = n + (ln*mid);
        ll mw = m + (lm*mid);
        ll puk = stmsh/mw + (stmsh%mw > 0 ? 1 : 0);
        ll puk2 = nw/ktmsh + (nw%ktmsh > 0 ? 1 : 0);
        if(puk <= puk2){
            r = mid-1;
            res = mid;
        }else{
            l = mid+1;
        }
    }
    return res;
}
priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
vector<ll> ans;
void solve(){
    cin >> s;
    cin >> n >> m >> ln >> lm >> q;
    cin >> a >> b;
    ll trgt = binser(a, b);
    for(int i = 2; i <= q; i++){
        cin >> a >> b;
        ll pek = binser(a, b);
        if(pek != -1)pq.push({pek, i});
    }
    ll bnti = 0;
    if(trgt == bnti){
        cout << 0 << "\n";
        return;
    }
    if(trgt == -1){
        cout << -1 << "\n";
        return;
    }
    while(!pq.empty()){
        auto[val, rn] = pq.top();
        pq.pop();
        if(val <= bnti){
            ans.push_back(rn);
            bnti++;
        }else{
            cout << -1 << "\n";
            return;
        }
        if(bnti == trgt){
            cout << ans.size() << "\n";
            for(auto i : ans){
                cout << i << "\n";
            }
            return;
        }
    }
    cout << -1 << "\n";
    return;
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