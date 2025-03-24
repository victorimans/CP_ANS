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
ll n, m, a, b, c, d;
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
    if(m == n){
        cout << n << "\n";
        return;
    }
    ll sem = n, id = -1;
    /* 
    10 1010 
    11 1011
    12 1100
    20 10100
     */
    for(int i = 0; i <= 64; i++){
        if(((1ll << i) &n)){
            sem ^= (1ll<<i);
        } 
        else if(sem == m){
            id = i;
            break;
        }
    }
    //cout << id << "\n";
    if(id == -1){
        cout << -1 << "\n";
        return;
    }
    cout << (sem | (1ll << id)) << "\n";
}
/* 
1 00001
2 00010
3 00011
4 00100
5 00101
6 00110
7 00111
8 01000
9 01001
10 01010
11 01011
12 01100
13 01101
14 01110
15 01111
16 10000
17 10001
18 10010
19 10011
20 10100
21 10101
22 10110
23 10111
24 11000
25 11001
26 11010
27 11011
28 11100
29 11101
30 11110
31 11111
32 00000

 */
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    cin >> t;
	while(t--) solve();
}

