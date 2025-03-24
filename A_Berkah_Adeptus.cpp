#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 1e5+1;
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
ll ar[ukr], pat, nxt[ukr];
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> ar[i];
    }
    pat = n;
    cout << min(2, n) << " " << n << "\n";
    if(min(2,n) == 1){
        cout << 0;
    }
    for(int i = 2; i <= n; i++){
        ll sem = 0;
        if(ar[i] == 0){
            cout << 0 << " ";
        }/* else if(ar[i] > 0){
            cout << (ll)(n-1)*ar[i] << " ";
        } */else{
            cout << (ll)(n-1)*ar[i] << " ";
        }
    }
    cout << "\n";
    cout << 1 << " "<< 1 << "\n";
    cout <<(0-ar[1]) << "\n";
    cout << 1 << " " << n << "\n";
    cout << 0 << " "; 
    for(int i = 2; i <= n; i++){
        if(ar[i] == 0){
            cout << 0 << " ";
        }/* else if(ar[i] > 0){
            cout << (ll)-(n*ar[i])<< " ";
        } */else{
            cout << (ll)-(n)*ar[i] << " ";
        }
    }

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
	while(t--) solve();
}

