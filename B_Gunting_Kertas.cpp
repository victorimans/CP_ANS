#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ukr = 2e5+10;
const ll md = 1e9+7;
string s;
ll n, m, nwp, nwl;
void rec(ll p, ll l){
    if(p == 1 || l == 1){
        cout << 1 << " " << 1 << endl;
        return;
    }
    if((p == 2 && l > 2) || (p > 2 && l == 2)){
        cout << 2 << " " << 2 << endl;
        cin >> nwp >> nwl;
        rec(nwp, nwl);
        return;
    }
    if((p == 3 && l > 3) || (p > 3 && l == 3)){
        cout << 3 << " " << 3 << endl;
        cin >> nwp >> nwl;
        rec(nwp, nwl);
        return;
    }
    cout << min(p, l) << " " << min(p, l) << endl;
    cin >> nwp >> nwl;
    rec(nwp, nwl);  
}
void solve(){
    cin >> s;
    cin >> n >> m;
    rec(n, m);
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