#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;  
const int ukr = 2e5+2;
ll n, m, id, a, b, tot=0;
void solve(){
    cin >> n >> m;
    a = pow(n,m);
    b = pow(m, n);
    cout << (ll)a+b << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
	while(t--) solve();
}