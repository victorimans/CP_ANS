#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 1e5+10;
const int ukr2 = 5e6+10;
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll n, m, a, b, c;
vector<pair<ll,pair<ll,ll>>> v;
int dsu[ukr];
int cekies(int rn){
    if(rn == dsu[rn]) return rn;
    return dsu[rn] = cekies(dsu[rn]);
}
void join(int a, int b){
    if(a > b){
        dsu[a] = b;
    }else{
        dsu[b] = a;
    }
}
priority_queue<pair<ll,ll>> pq;
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }
    sort(all(v));
    ll jwb = -1, mx = -1;
    for(int i = 29; i >= 0; i--){
        for(int j = 1; j <= n; j++){
            dsu[j] = j;
        } 
        ll tt = (1LL << i);
        ll ans = 0, vl = -1;
        for(int j = m; j >= 0; j--){
            if(v[j].first&tt){
                int ax = cekies(v[j].second.first), bx = cekies(v[j].second.second);
                if(ax == bx) continue;
                ans += v[j].first;
                if(vl == -1){
                    vl = v[j].first;
                }else{
                    vl &= v[j].first;
                }
                join(ax, bx);
            }
        }
        bool cek = 0;
        for(int j = 1; j < n; j++){
            if(cekies(j) != cekies(j+1)){
                cek = 1;
                break;
            }
        }
        if(cek){
            continue;
        }
        if(vl > mx){
            mx = vl;
            jwb = ans;
        }else if(vl == mx){
            jwb = max(ans, jwb);
        }
    }
    if(mx == -1){
        cout << "TIDAK BISA" << "\n";
        return;
    }
    cout << "BISA " << mx << " " << jwb << "\n";
    return;
   

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
        //cout << "\n";
    }
}
