#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+1;
int n, m, a, b, c, d, id;
int tot = 0;
struct babi{
    ll id, x, y;
};
struct babis{
    ll x, y;
};
vector<int> v;
string s;
void solve(){
    cin >> s;
    for(int i = 1; i <= s.length(); i+=2){
        if(s[i] != '0'){
            cout << "No";
            return;
        }
    }
    cout << "Yes";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
	while(t--) solve();
}

