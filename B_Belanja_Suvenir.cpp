#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ukr = 2e6+10;
const ll md = 1e9+7;
string s;
ll n, m, id;
int ar[ukr];
pair<int,int> ps[ukr];
int ans = -1;
int a, b;
void solve(){
    cin >> s;
    cin >> n;
    for(int i = 1, l = 1; i <= n; i++){
        cin >> id;
        l = max(ar[id]+1, l);
        ar[id] = i;
        //cout << l << " " << i << endl;
        int sel = i-l+1;
        if(ps[sel].first == 0){
            ps[sel] = {l, i};
        }
        int ki = 0, ka = sel;
        while(ki <= ka){
            int mid = (ki+ka)/2;
            if(ps[sel-mid].second < l+mid){
                ka = mid-1;
                if(ans < sel-mid){
                    ans = sel-mid;
                    a = l+mid;
                    b = i;
                }
            }else{
                ki = mid+1;
            }
        }
        /* ps[sel].second;
        if(sel > ans){
            a = l; b = i;
            ans = i-l+1;
        } */
    }
    if(n%2 == 1) n--;
    int pt = 0;
    for(int i = n; i >= 0; i -= 2){
        if(ps[i].first != 0){
            pt = i;
            break;
        }
    }
    //cout << pt << " " << ans << "\n";
    if(pt >= ans*2){
        cout << ps[pt].first << " " << ps[pt].first+pt/2-1 << " " << ps[pt].first+pt/2 << " " << ps[pt].second <<"\n";
        return;
    }
    cout << ps[ans].first << " " << ps[ans].second << " " << a << " " << b << "\n";
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}