#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md  = 1e9+7;
const int ukr = 2e5+10;
ll n, m, a, b, c, d, id;
void solve(){
    ll tot = 0;
    cin >> n >> a >> b >> c;
    if(n <= a){
        tot++;
    }
    if(n <= b){
        tot++;
    }
    if(n <= c){
        tot++;
    }
    cout << tot << "\n";

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}