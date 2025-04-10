#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 2e5+10;
ll n, w, b, x;
ll ar[1010];
ll e[1010];
ll dp[2][101][101];
void solve(){
    cin >> n >> w >> b >> x;
    int tot = 0;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
        tot += ar[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> e[i];
    }
    dp[0][0][0] = w; 
    for(ll i = 1; i <= n; i++){
        ll cur = i%2;
        ll bf = (i+1)%2;
        for(ll j = 0; j <= tot; j++){
            for(ll k = 0; k <= i; k++){
                dp[cur][j][k] = dp[bf][j][k];
            }
        } 
        for(ll k = 1; k <= ar[i]; k++){
            if(w-k*e[i] >= 0){
                //cout << "masuk- >" << i << endl;
                dp[cur][k][i] = max(w-k*e[i], dp[cur][k][i]);   
                //cout << cur << " " << j << " " << k << " " << sk << "\n";
            }
        }
        for(ll z = 1; z <= i-1; z++){
            for(ll j = 0; j <= tot-ar[i]; j++){
                if(dp[bf][j][z] == -1) continue;
                ll sk = dp[bf][j][z]+x*(i-z);
                for(ll k = 1; k <= ar[i]; k++){
                    if(sk-k*e[i] >= 0){
                        cout << " " << i << " " << j << " " << k << " " << z << "\n";
                        dp[cur][j+k][i] = max(sk-k*e[i], dp[cur][j+k][i]);   
                        //cout << cur << " " << j << " " << k << " " << sk << "\n";
                    }
                }
            }
        }
        
    }
    ll ans = 0;
    for(ll z = 1; z <= n; z++){
        for(ll j = 0; j <= tot; j++){
            cout << dp[n%2][j][z] << " " << j << " " << z << "\n";
            if(dp[n%2][j][z] != -1) ans = max(ans, j);
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