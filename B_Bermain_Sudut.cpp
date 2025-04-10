#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
const int ukr = 2e5+10;
const ll md = 1e9+7;
string s;
ll n, m;
vector<ll> v;
bool cmp(int a, int b){
    cout << "Q 1 " << a << " " << b << endl;
    cin >> s;
    if(s == "SEARAH"){
        return 1;
    }
    return 0;
}
void solve(){
    cin >> s >> n >> m;
    for(int i = 2; i <= n; i++){
        v.push_back(i);
    }
    sort(all(v), cmp);
    cout << "A 1 ";
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
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