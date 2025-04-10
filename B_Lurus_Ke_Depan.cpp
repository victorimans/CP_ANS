#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 2e5+10;
const int ukr2 = 5e6+10;
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll n, m;
ll ar[ukr2], br[ukr2];
vector<vector<ll>> v(ukr2);
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> ar[i];
    }
    for(int j = 0; j < m; j++){
        cin >> br[j];
    }
    bool cek = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ll as = gcd(ar[i], br[j]);
            ar[i] /= as;
            br[j] /= as;
            v[i].push_back(as);
        }
        if(ar[i] != 1){
            cek = 1;
            break;
        }
    }
    if(!cek){
        for(int j = 0; j < m; j++){
            if(br[j] != 1){
                cek = 1;
                break;
            }
        }
    }
    if(cek){
        cout << -1 << "\n";
    }else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }
    for(int i = 0; i < n; i++){
        v[i].clear();
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << "\n";
    }
}
