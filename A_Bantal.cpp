#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ukr = 2e5+10;
struct babi{
    ll id, x, par;
    bool operator < (const babi &other) const{
        return id > other.id;
    }
};

ll ar[110];
ll n, m, s, t, u, a, b, c, id;
vector<ll> v;
void solve(){
    cin >> n;
    if(n == 1){
        cout <<"? "<<1<<" "<< 1 << endl;
        cin >> id;
        if(id){
            cout << "! 1 1" << endl;
        }else{
            cout << "! 0" << endl;
        }
        return;
    }
    if(n == 2){
        cout <<"? "<<1<<" "<< 1 << endl;
        cin >> id;
        cout <<"? "<<2<<" "<< 2 << endl;
        cin >> m;
        if(id && m){
            cout << "! 2 1 2" << endl;
        }else if(id){
            cout << "! 1 1" << endl;
        }else if(m){
            cout << "! 1 2" << endl;
        }else{
            cout << "! 0" << endl;
        }
        return;
    }
    ll pw2 = 1;
    while(n >= pw2){
        pw2 *= 2;
    }
    pw2 /= 2;
    //cout << pw2 << "\n";
    m = pw2-1;
    for(ll i = 1;i <= m; i++){
        cout <<"? "<< m <<" "<<i-(i^m) << endl;
        cin >> id;
        ar[i] |= id; 
    }
    for(ll i = m+1; i <= n; i++){
        cout << "? " << m << " " << i+(i^m) << endl;
        cin >> id;
        //ar[i] |= id;
    }
    m = pw2;
    for(ll i = 1; i < m; i++){
        cout << "? " << m << " " << i-(i^m) << endl;
        cin >> id;
        //ar[i] |= id;
    }
    for(ll i = m; i <= n; i++){
        cout << "? " << m << " " << i+(i^m) << endl;
        cin >> id;
        ar[i] |= id;
    }
    for(ll i = 1; i <= n; i++){
        if(ar[i]){
            v.push_back(i);
        }
    }
    cout <<"! ";
    cout << v.size() << " ";
    for(auto i : v){
        cout << i << " ";
    }
    cout<< endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}