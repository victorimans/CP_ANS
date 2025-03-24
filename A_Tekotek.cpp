#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n;
void solve(){
    cin >> s;
    cin >> n;
    for(int i = n; i >= 1; i--){
        if(i == 1){
            cout << "Anak ayam turunlah 1\n" << "Mati satu tinggallah induknya\n";
        }else{
            cout << "Anak ayam turunlah "<< i <<'\n' << "Mati satu tinggallah "<<i-1 <<'\n'; 
        }
    }
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