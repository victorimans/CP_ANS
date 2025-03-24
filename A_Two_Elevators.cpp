#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9+7;
const int ukr = 2e5+10;
ll n, m, a, b;
void solve(){
    cin >> n >> m >> a;
    int tota =  n-1;
    int totb = abs(m-a)+a-1;
    if(tota == totb){
        cout << 3;
    }else if(tota > totb){
        cout << 2;
    }else{
        cout << 1;
    }
    cout << "\n";

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
}