#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 2e5+10;
ll n, m, a, b, id;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
map<ll, int> mp;
map<ll, int> ev;
vector<ll> v;
bool debug = 0;
vector<ll> nih;
ll ask(ll vl){
    cout << "? " << vl << endl;
    ll sem;
    cin >> sem;
    return sem;
}
void rec(ll l, ll r){
    if(l == r) return;
    bool ck = 0;
    ll nwl = 0, nwr = 0;
    for(ll i = 30; i >= 0; i--){
        if(((l & (1LL << i)) != (r & (1LL << i))) || ck){
            if(ck){
                nwl |= (1LL << i);
            }else{
                if(l&(1LL << i))nwl |= (1LL << i);
                if(r&(1LL << i))nwr |= (1LL << i);
            }
            ck = 1;
        }else{
            if(l&(1LL << i)){
                nwl |= (1LL << i);
                nwr |= (1LL << i);
            }
        }
    }
    /* 
    101
    000
     */
    ll vl = (ll)ask(nwl)^nwl;
    ll vl2 = (ll)ask(nwr)^nwr;
    if(vl != l && vl != r){
        v.push_back((vl)); 
        rec(l, vl);
    }
    if(vl2 != l && vl2 != r){
        if(vl != vl2) v.push_back(vl2);
        rec(vl2, r);
    }
}
void solve(){
    cin >> n;
    ll vl = ask(0);
    ll vl2 = ask((1LL << 30)-1LL);
    vl2 ^= ((1LL << 30)-1LL);
    v.push_back(vl);
    v.push_back(vl2);
    rec(vl, vl2);
    sort(v.begin(), v.end());
    cout << "! ";
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin>> t;
    while(t--){
        solve();
    }
}