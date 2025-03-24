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
void solve(){
    cin >> n >> m;
    if(n == 2){
        if(m >= 1 && m <= 28){
            cout << "YES";
        }else{
            cout << "NO";
        }
    }else if(n >= 1 && n <= 12){
        if(n % 2){
            if(m >= 1 && m <= 31){
                cout << "YES";
            }else{
                cout << "NO";
            }
        }else{
            if(m >= 1 && m <= 30){
                cout << "YES";
            }else{
                cout << "NO";
            }
        }
    }else{
        cout << "NO";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
	while(t--) solve();
}

