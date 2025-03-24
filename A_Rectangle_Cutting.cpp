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
    cin >> n >> m;
    /* bool cek1 = 0;
    if(n%2 && m%2){
        //cout << "No\n";
        cek1 = 0;
    }else if(n%2 == 0 && m%2 == 0){
        if(m/2 != n && 2*n != m){
            //cout << "Yes\n";
            cek1 = 1;
        }else if(n/2 != m && 2*m != n){
            //cout << "Yes\n";
            cek1 = 1;
        }else{
            //cout << "No\n";
            cek1 = 0;
        }
    }else if(n%2){
        if(m/2 == n && 2*n == m){
            //cout << "No\n";
            cek1 = 0;
        }else{
            //cout << "Yes\n";
            cek1 = 1;
        }
    }else{
        if(n/2 == m && 2*m == n){
            //cout << "No\n";
            cek1 = 0;
        }else{
            //cout << "Yes\n";
            cek1 = 1;
        }
    } */
    bool cek2 = 0;
    if(n%2==1 && m%2==1){
            //printf("No\n");
        cek2 = 0;
    }
    else if(n%2==1 && m/2 == n && 2*n == m){
        //printf("No\n");
        cek2 = 0;
    }
    else if(m%2==1 && n/2 == m && 2*m == n){
        //printf("No\n");
        cek2 = 0;
    }
    else{
        //printf("Yes\n");
        cek2 = 1;
    }
    if(cek1 != cek2){
        cout << n << " " << m << "\n";
        cout << (cek1 ? "Yes\n" :  "No\n");
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << ": ";
        solve();
        /* for(int j = 1; j <= t; j++){
            cout << i << " " << j << "\n";
        } */
    }
}

