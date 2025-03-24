#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 1e6+10;
ll fak[ukr], invfak[ukr];
ll n, m, a, b;
ll pgkt(ll rn, ll pp){
    if(pp == 0) return 1;
    ll nwx = pgkt(rn, pp/2)%md;
    if(pp%2){
        return nwx*nwx%md*rn%md;
    }else{
        return nwx*nwx%md;
    }
}
void tmbh(ll &a, ll b){
    a += b;
    while(a >= md){
        a -= md;
    }
}
ll cmbn(ll tot, ll tk){
    return fak[tot]*invfak[tk]%md*invfak[tot-tk]%md;
}
void solve(){
    cin >> n >> m >> a >> b;
    ll ans = 0;
    ll jmla = 1, ssa = n-a, jmlb = 1, ssb = m-b;
    if(ssa < 0 || ssb < 0){
        cout << 0 << "\n";
        return;
    }
    // buat 0 1 0 1 ..
    while(1){
        tmbh(ans, cmbn(ssa+jmla, jmla)*cmbn(ssb+jmlb, jmlb)%md);
        //cout << ans << "\n";
        if(ssa >= a){
            ssa -= a;
            jmla++;
            tmbh(ans, cmbn(ssa+jmla, jmla)*cmbn(ssb+jmlb, jmlb)%md);
        }else break;
        if(ssb >= b){
            ssb -= b;
            jmlb++;
        }else break;
    }
    jmla = 1, ssa = n-a, jmlb = 1, ssb = m-b;
    //cout << ans << "\n";
    /* 
     */
    //buat 1 0 1 0 ..
    while(1){
        tmbh(ans, cmbn(ssa+jmla, jmla)*cmbn(ssb+jmlb, jmlb)%md);
        if(ssb >= b){
            ssb -= b;
            jmlb++;
            tmbh(ans, cmbn(ssa+jmla, jmla)*cmbn(ssb+jmlb, jmlb)%md);
        }else break;
        if(ssa >= a){
            ssa -= a;
            jmla++;
        }else break;
    }
    cout << ans << "\n";
}
void pre(){
    fak[0] = 1;
    for(ll i = 1; i < ukr; i++){
        fak[i] = ((ll)fak[i-1]*i)%md;
    }
    invfak[ukr-1] = pgkt(fak[ukr-1], md-2);
    for(ll i = ukr-2; i >= 0; i--){
        invfak[i] = ((ll)invfak[i+1]*(i+1))%md;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    pre();
    int t = 1;
    //cin>> t;
    while(t--){
        solve();
    }
}