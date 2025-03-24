#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+1;
ll n, m, a, b, c, d, id;
int tot = 0;
struct babi{
    ll id, x, y;
};
struct babis{
    ll x, y;
};
multiset<ll> ms;
vector<ll> v;
void solve(){
    cin >> n;
    for(int i = 1; i <= n*n; i++){
        cin >> a;
        ms.insert(a);
    }
    v.push_back(*ms.rbegin());
    auto it = ms.find(v[0]);
    ms.erase(it);
    for(int i = 2; i <= n; i++){
        ll rn = *ms.rbegin();
        it = ms.find(rn);
        ms.erase(it);
        /* cout << "masuk" << rn  << endl; */
        for(int j = 0; j < v.size(); j++){
            ll kpk = __gcd(rn, v[j]);
            /* cout << "masuk ke dalem" << kpk << endl;
            cout << "my multiset :" */
            /* for(int i : ms){
                cout  << i << " ";
            }
            cout << endl; */
            it = ms.find(kpk);
            ms.erase(it);
            it = ms.find(kpk);
            ms.erase(it);
        }
        v.push_back(rn);
        /* cout << "keluar" << rn << endl; */
    }
    for(ll i : v) cout << i << " ";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
	while(t--) solve();
}

