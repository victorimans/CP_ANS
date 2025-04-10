#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 2e5+10;
ll n, m, id;
bool debug = 0;
vector<ll> v;
ll ask(ll a, ll b, ll op){
    if(op == 0){
        if(!debug)cout << "AND " << a <<" "<< b << endl;
        if(debug) return (v[a]&v[b]);
    }else if(op == 1){
        cout << "OR " << a <<" "<< b << endl;
    }else{
        if(!debug)cout << "XOR " << a <<" "<< b << endl;
        if(debug) return (v[a]^v[b]);
    }
    ll tmpss;
    cin >> tmpss;
    return tmpss;
}
ll ans[ukr], xr1[ukr];
map<ll, ll> mp;
void solve(){
    cin >> n;
    if(debug){
        v.push_back(0);
        for(int i = 0; i < n; i++){
            v.push_back(i);
        }
    }
    ll a, b = -1;
    for(int i = 2; i <= n; i++){
        xr1[i] = ask(1, i, 2);
        if(mp.find(xr1[i]) != mp.end()){
            a = mp[xr1[i]];
            b = i;
        }else{
            mp[xr1[i]] = i;
        }
    }
    if(b != -1){
        ll anj = ask(a, b, 0);
        ans[1] = ((ll)anj^xr1[a]);
    }else{
        for(int i = 2; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                if(((ll)xr1[i]^xr1[j]) == (n-1)){
                    a = i;
                    b = j;
                    break;
                }
            }
            if(b != -1) break;
        }
        // a+b = (a^b)+2(a&b)
        ll anj1 = (ll)xr1[a] + 2*ask(1, a, 0); // 1 + 2
        ll anj2 = (ll)xr1[b] + 2*ask(1, b, 0); // 1 + 3
        ll anj3 = ((ll)xr1[a]^xr1[b]); // 2 + 3
        ans[1] = ((ll)anj1+anj2-anj3)/2;
    }
    for(int i = 2; i <= n; i++){
        ans[i] = ((ll)xr1[i]^ans[1]);
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
  int t =1;
    //cin >> t;
    while(t--){
        solve();
    }
}

