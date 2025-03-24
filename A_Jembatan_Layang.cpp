#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 1e5+10;
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
ll n, m, c, d, id;
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
char s[10];
ll h[ukr], fak[ukr], ki[ukr], ka[ukr], ki2[ukr], ka2[ukr];
bool eve[ukr];
ll ans = 1;
void solve(){
    scanf("%s", s);
    n = read();
    m = read();
    for(int i = 1; i <= m; i++){
        h[i] = read();
    }
    for(int i = 1; i <= n; i++){
        eve[i] = 0;
        id = read();
        if(h[id] == i){
            ki[id]++; ka[id]++;
        }else if(h[id] < i){
            ki[id]++;
        }else{
            ka[id]++;
        }
    }
    for(int i = 1; i <= n; i++){
        id = read();
        if(h[id] == i){
            eve[id] = 1;
        }else if(h[id] > i){
            ki2[id]++;
        }else{
            ka2[id]++;
        }
    }
    for(int i = 1; i <= m; i++){
        ll tot = ki[i]+ka[i];
        //cout << tot << " " << ki2[i] << " " << ka2[i] << "\n";
        if(tot > ki2[i]+ka2[i]+eve[i]){
            ki[i]--; ka[i]--;
            if(eve[i]){
                //cout
                if(ki[i] == ki2[i]+1 && ka[i]+1 == ka2[i]){
                    ans = (ans*fak[ki[i]])%md*fak[ka[i]+1]%md;
                }else if(ki[i]+1 == ki2[i] && ka[i] == ka2[i]+1){
                    ans = (ans*fak[ki[i]+1])%md*fak[ka[i]]%md;
                }else if(ki[i] == ki2[i] && ka[i] == ka2[i]){
                    ll tmp = ((fak[ki[i]+1]*fak[ka[i]]%md + fak[ki[i]]*fak[ka[i]+1]%md)%md - (fak[ki[i]]*fak[ka[i]]%md)+md)%md;
                    ans = (ans*tmp)%md;
                }else{
                    //cout << "NAJIS 1" << endl;
                    ans = 0;
                }
            }else{
                if(ki[i] == ki2[i] && ka[i]+1 == ka2[i]){
                    ans = (ans*fak[ki[i]])%md*fak[ka[i]+1]%md;
                }else if(ki[i]+1 == ki2[i] && ka[i] == ka2[i]){
                    ans = (ans*fak[ki[i]+1])%md*fak[ka[i]]%md;
                }else{
                    //cout << "NAJIS 2" << endl;
                    ans = 0;
                }
            }
        }else{
            if(eve[i]){
                if(ki[i] == ki2[i]+1 && ka[i] == ka2[i]){
                    ans = (ans*fak[ki[i]])%md*fak[ka[i]]%md;
                }else if(ki[i] == ki2[i] && ka[i] == ka2[i]+1){
                    ans = (ans*fak[ki[i]])%md*fak[ka[i]]%md;
                }else{
                    //cout << "NAJIS 3" << endl;
                    ans = 0;
                }
            }else{
                if(ki[i] == ki2[i] && ka[i] == ka2[i]){
                    ans = (ans*fak[ki[i]])%md*fak[ka[i]]%md;
                }else{
                    //cout << "NAJIS 4" << endl;
                    ans = 0;
                }
            }
        }
    }
    cout << ans;
}
void pre(){
    fak[0] = 1;
    for(ll i = 1; i < ukr; i++){
        fak[i] = i*fak[i-1]%md;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    pre();
	int t =1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        //cout << "Case " << i << ": ";
        solve();
    }
}

