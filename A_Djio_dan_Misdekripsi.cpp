#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    char c;
    bool cek = false;
    cin >> n;
    while(cin >> c){
        if(c == '*') cek = !cek;
        else if(!cek) cout << c;
    }
}

