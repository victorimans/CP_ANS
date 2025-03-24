#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+10;
#define here cout << "anjai" << endl;
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
ll n, m, a, b, c, d, id;
struct babi{
    ll x, y, id;
};
struct babis{
    ll x, y;
};
ll gcd(ll a, ll b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}
ll pgkt(ll rnx, ll rny){
    if(rny == 0) return 1;
    ll nwrn = pgkt(rnx, rny/2);
    if(rny%2){
        return (((nwrn*nwrn)%md)*rnx)%md;
    }else{
        return (nwrn*nwrn)%md;
    }
}
vector<int> v;
string s;
ll ar[ukr];
ll freq[ukr];
void solve(){
    cin >> n >> m;
    if(n == 1){
        while(m--){
            cin >> id;
            if(id == 1){
                cout << 1 << "\n";
            }else cout << 0 << "\n";
        }
        return;
    }
    if(n == 2){
        /* 
        1 2
        
         */
        while(m--){
            cin >> id;
            if(id <= 3){
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
        }
        return;
    }
    ll ki = n+1;
    ll ka = n+2;
    //1 2 3 4 5 6 7 8 9
    //1 9 2 8 3 7 4 6 5
    //1 2 3 4 5
    //1 5 2 4 3
    ll ptk = ((ll)n+1)*n/2;
    while(m--){
        cin >> id;
        if(id > ptk){
            cout << 0 << "\n";
            continue;
        }
        if(id <= n){
            cout << 1  << "\n";
            continue;
        }
        if(id%ki == 0){
            cout << n/2-id/ki+1 << "\n";
        }else if(id%ka == 0){
            cout << (n-1)/2 - id/ka+1 << "\n";
        }else{
            ll ss1 = id%ki;
            ll ss2 = id%ka; 
            ll bgi1 = id/ki;
            ll bgi2 = id/ka;
            ll idx1, idx2;
            if(ss1 <= (n+1)/2){
                idx1 = ss1*2-1;
            }else{
                //here
                idx1 = (n-ss1+1)*2;
            }
            if(ss2 <= (n+1)/2){
                idx2 = ss2*2-1;
            }else{
                idx2 = (n-ss2+1)*2;
            }
            //cout << idx1 << " " << idx2 << " " << ss1 << " " << ss2 << "\n";
            if(idx1 != 0){
                ll l = (idx1-1)/2;
                ll r = (n-idx1)/2;
                if(l >= bgi1 && idx1%2){
                    //here
                    cout << 1 << "\n";
                    continue;
                }else if(r >= bgi1 && idx1%2 ==0){
                    //here
                    cout << 1 << "\n";
                    continue;
                }
            }
            if(idx2 != 0){
                ll l = (idx2-1)/2;
                ll r = (n-idx2)/2;
                if(r >= bgi2 && idx2%2){
                    //here
                    cout << 1 << "\n";
                    continue;
                }else if(l >= bgi2 && idx2%2 == 0){
                    //here
                    cout << 1 << "\n";
                    continue;
                }
            }
            cout << 0 << "\n";
        }

    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << ": ";
        solve();
    }
}

