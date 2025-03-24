#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e3+1;
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
	freopen("test.in.txt","r",stdin);
	freopen("test.out.txt","w",stdout);
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
int ar[ukr], ar1[ukr], ar2[ukr];
int pos[ukr], pos1[ukr];
void solve(){
    cin >> n;
    if(n == 2){
        cout << "! 1 2 2 1" << endl;
        cin >> id;
        return;
    }
    cout << "+ " << n+1 << endl;
    cin >> id;
    cout << "+ " << n << endl;
    cin >> id;
    if(n%2){
        int mid = (n+1)/2;
        for(int i = 1; i <= n; i+=2, mid++){
            pos[i] = mid;
        }
        mid = (n+1)/2-1;
        for(int i = 2; i <= n; i+=2, mid--){
            pos[i] = mid;
        }
        /* for(int i =1; i <= n; i++){
            cout << pos[i] << " ";
        }  */
        for(int i =1; i <= n; i++){
            pos1[i] = pos[n-i+1];
        }
    }else{
        int mid = n/2;
        for(int i = 1; i <= n; i+=2, mid--){
            pos[i] = mid;
        }
        mid = n/2+1;
        for(int i = 2; i <= n; i+=2, mid++){
            pos[i] = mid;
        }
        for(int i = 1; i <= n; i++){
            pos1[i] = pos[n-i+1];
        }

    }
    int ma = 0, rn = 0;
    for(int i = 2; i <= n; i++){
        cout << "? " << 1 << " " << i << endl;
        cin >> id;
        if(id > ma){
            ma = id;
            rn = i;
        }
    }
    ar[rn] = pos[n];
    ar1[rn] = pos1[n];
    ar2[pos[n]] = rn;
    for(int i = 1; i <= n; i++){
        if(rn == i) continue;
        cout << "? " << rn << " " << i << endl;
        cin >> id;
        ar[i] = pos[n-id];
        ar1[i] = pos1[n-id];
        ar2[pos[n-id]] = i;
    }
    cout << "! ";
    for(int i = 1; i <= n; i++){
        cout << ar[i] << " ";
    }
    for(int i = 1; i <= n; i++){
        cout << ar1[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; i++){
        cout << ar2[i] << " ";
    }
    cout << endl;
    cin >> id;
    return;
    /* 
    4 1 5 2 6 3
    3 4 2 5 1 6
    5 2 1 6 4 3
    5 2 3 4 1 6

    1 2 3 4 5

    3 2 4 1 5 
    2 1 3
    ! 1 4 2 5 3 6
    3 4 2 5 1 6
    1 2 3 4 5 6
    1 4 2 5 3 6
    3 4 2 5 1 6

    2 5 4 3 1 6
     */
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    cin >> t;
	while(t--) solve();
}

