#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+1;
int read() {
    int ketek = 0; bool ne=0;
    register char c = getchar();
    while(c == ' ' or c =='\n') c =getchar();
    if(c=='-'){ne = 1; c = getchar();}
    while(c >= '0' and c <='9') { ketek = (ketek<<3)+(ketek<<1)+c-'0'; c = getchar();}
    if(ne) ketek*=-1;
    return ketek;
}   
void print(int x) {
    if (x < 0) {putchar('-');x = -x;}
    int len = 0, buf[10];
    if (x == 0) {putchar('0');return;}
    while (x > 0) {buf[len++] = x % 10; x/=10;}
    while (len > 0) {putchar('0' + buf[--len]);}
}
void File_Work(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
}
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
    cin >> n;
    if(n-3 > 0 && (n-3)%3 && (n-3) != 1 && (n-3) != 2){
        cout << "YES\n";
        cout << 1 << " "<< 2 <<" "<<n-3 << "\n";
    }else if(n-6 > 0 && (n-6)%3 && (n-6) != 4 && (n-6) != 2){
        cout << "YES\n";
        cout << 2 << " "<< 4 <<" "<<n-6 << "\n";
    }else if(n-5 > 0 && (n-5)%3 && (n-5) != 1 && (n-5) != 4){
        cout << "YES\n";
        cout << 1 << " "<< 4 <<" "<<n-5 << "\n";
    }else{
        cout << "NO\n";
    }
    
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    cin >> t;
	while(t--) solve();
}

