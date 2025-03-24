#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+1;
/* int read() {
    int ketek = 0; bool ne=0;
    register char c = getchar();
    while(c == ' ' or c =='\n') c =getchar();
    if(c=='-'){ne = 1; c = getchar();}
    while(c >= '0' and c <='9') { ketek = (ketek<<3)+(ketek<<1)+c-'0'; c = getchar();}
    if(ne) ketek*=-1;
    return ketek;
}   
void File_Work(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
} */
int x1, x2, y1, y2, r1, r2;
bool cek(){
    ll jrk = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
    ll totr = r1 + r2;
    ll bedar = abs(r1-r2);
    if (jrk == 0) {
        return r1 == r2;
    }
    if (jrk == totr * totr || jrk == bedar * bedar) {
        return true;
    }
    return jrk < totr * totr && jrk > bedar * bedar;
}

void solve() {
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    if(cek()){
        cout << "bersentuhan";
    }else{
        cout << "tidak bersentuhan";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int t =1;
    //cin >> t;
	while(t--) solve();
}

