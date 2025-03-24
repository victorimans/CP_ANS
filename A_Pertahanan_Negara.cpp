#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef unsigned long long int ull;
const ll md = 1e9+7;
const int ukr = 2e5+10;
void File_Work(){
	freopen("C:\\Users\\victo\\Downloads\\KSN 2020 1A\\inputs\\pertahanan_5.in","r",stdin);
	freopen("C:\\Users\\victo\\Downloads\\KSN 2020 1A\\inputs\\pertahanan_5.out","w",stdout);
}
int n, m, a, b, c, d, id;
deque<int> v;
string s;
void kel(int x, int y, int x1, int y1){
    cout << x << " " << x1 << " " << y << " " << y1 << "\n";
}
void solve(){
    File_Work();
    cin >> n >> m >> id;
    bool cek = 0;
    int tot = 0;
    for(int i = 0; i < 293; i++){
        //cin >> a;
        for(int j = 0, sem = 0; j < 311; j++){
            kel(tot, sem, tot+9973, sem+99991);
            sem += 99991;
        }
        tot += 9973;
    }
    // kel(0, 0, 1, 4);
    // kel(1, 0, 5, 1);
    // kel(4, 1, 5, 5);
    // kel(0, 4, 4, 5);
    // kel(1, 1, 4, 4);
   
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

