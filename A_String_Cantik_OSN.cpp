#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(), x.end()
const ll md = 1e9+7;
const int ukr = 2e5+10;
ll n, m, a, b, id;
string s;
string temp = "OSN";
void solve(){
    sort(all(temp));
    cin >> s;
    n = s.length();
    int ans = -1;
    do{
        int j = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == temp[j%3]){
                j++;
            }
        }
        //cout << temp<< "\n";
        if(j >= 3){
            //cout << temp << " " << j << "\n";
            ans = max(ans, j);
        }
    }while(next_permutation(all(temp)));
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}