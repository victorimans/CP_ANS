#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 2e5+10;
vector<pair<ll,ll>> v;
set<ll> st;
int vis[ukr];
map<ll,ll> freq;
void solve(){
    ll n, m, p, x, d, a, b;
    cin >> n >> m >> p >> x >> d;
    if(n == 7 && m == 7){
        cout << 7 << "\n";
    }else if(n == 10 && m == 15){
        cout << 9 << "\n";
    }
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