#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ukr = 1e5+10;
const ll md = 1e9+7;
ll n;
ll ar[ukr];
vector<pair<int,int>> v;
ll ka[ukr], ki[ukr];
ll pfa[ukr], pf[30][ukr];
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        while(!v.empty() && v.back().first < ar[i]){
            ka[v.back().second] = i-1;
            v.pop_back();
        }
        v.push_back({ar[i], i});
        pfa[i] = pfa[i-1]^ar[i];
        for(ll j = 0; j < 30; j++){
            if(pfa[i]&(1LL << j)){
                pf[j][i] = 1;
            }
            pf[j][i] += pf[j][i-1];
        }
    }
    while(!v.empty()){
        ka[v.back().second] = n;
        v.pop_back();
    }
    for(int i = n; i >= 1; i--){
        while(!v.empty() && v.back().first <= ar[i]){
            ki[v.back().second] = i+1;
            v.pop_back();
        }
        v.push_back({ar[i], i});
    }
    while(!v.empty()){
        ki[v.back().second] = 1;
        v.pop_back();
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll tot = 0;  
        //cout << ki[i] << " " << ka[i] << "\n";
        for(ll j = 0; j < 30; j++){
            ll anj = 0;
            ll ki1, ki0, ka1, ka0;
            ki1 = pf[j][i-1]-(ki[i]-2 >= 0 ? pf[j][ki[i]-2] : 0);
            ki0 = (i-ki[i]+1)-ki1;
            ka1 = pf[j][ka[i]]-pf[j][i-1];
            ka0 = (ka[i]-i+1)-ka1;
           /* if(pf[max(ki[i]-2, 0LL)][j] & (1LL << j)){
                swap(ki1, ki0);
            } */
            anj = (anj+ki1*ka0)%md;
            anj = (anj+ki0*ka1)%md;
            //cout << anj << " " << i << " " << j << "\n";
            ans = (ans + anj*(1LL << j)%md*ar[i]%md)%md;
            //cout << ki0 << " <-ki-> " << ki1 << " " << ka0 << " <-ka-> " << ka1 << " " << i << " <-idx-> " << j << "\n";
            tot = (tot+anj)%md;
        }
    }
    cout << ans;
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
} 