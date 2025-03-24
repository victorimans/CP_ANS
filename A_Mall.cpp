#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 1e6+10;
int n, m, a, b, c, d, id;
vector<int> v;
string s;
map<vector<int>, int> mp;
int freq[ukr];
int ar[ukr*2];
void upd(ll rn, ll vl){
    for(;rn < ukr; rn += (rn&-rn)){
        freq[rn] += vl;
    }
}
ll get(ll rn){
    ll tot = 0;
    for(;rn;rn-=(rn&-rn)){
        tot += freq[rn];
    }
    return tot;
}
void solve(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &ar[i]);
    }
    /* for(int i = 1; i <= n-m+1; i++){
        vector<int> tmp;
        vector<int> asoy;
        for(int j = 1; j < i ; j++){
           tmp.push_back(ar[j]);
        }
        for(int j = i; j < i+m; j++){
            asoy.push_back(ar[j]);
        }
        sort(all(asoy));
        for(auto j : asoy){
            tmp.push_back(j);
        }
        for(int j = i+m; j <= n; j++){
            tmp.push_back(ar[j]);
        }
        if(!mp[tmp]){
            cout << i << "\n";
            mp[tmp] = 1;
        }
    } */
    //cout << mp.size() << "\n";
    ll tot = 0;
    ll sem = 0;
    //cout << "anjai" << endl;
    for(int i = 1; i <= m; i++){
        tot += get(ukr-1)-get(ar[i]);
        //cout << "anjai" << endl;
        upd(ar[i], 1);
        sem++;
        // cout << "anjai" << endl;
    }
    ll ans = 0;
    bool cek = 0;
    if(tot == 0){
        cek = 1;
    }else{
        ans++;
    }
    //cout << tot << "\n";
    for(int i = 1; i <= n-m; i++){
        //cout << tot << " " << i+m << " " << i  << " in->" << ar[i+m]  << " out-> " << ar[i]<< "\n";
        ll kur = get(ar[i]-1);
        tot -= kur;
        upd(ar[i], -1);
        //cout << "after out -> " << ar[i] <<  " " << tot << "\n";
        ll tmbh = get(ukr-1)-get(ar[i+m]);
        tot += tmbh;
        upd(ar[i+m], 1);
        if(tot == 0){
            cek = 1;
        }else if(tot > 0 && (kur != 0 || tmbh != 0)){
            ans++;
        }
        //cout << tot << " " << i+m << " " << i  << "ans-> " << ans<< "\n";
    }
    //cout << ans << "\n";
    if(cek) ans++;
    cout << ans << "\n";
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

