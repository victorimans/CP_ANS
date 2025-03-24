#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ukr = 2e5+10;
const ll md = 1e9+7;
string s;
ll n, tt1 = 0, tt2 = 0, tt3 = 0;
void solve(){
    cin >> s >> n >> s;
    for(auto i : s){
        if(i == '1'){
            tt1++;
        }else if(i == '2'){
            tt2 += tt1;
        }else{
            tt3 += tt2;
        }
    }
    cout << tt3 << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}