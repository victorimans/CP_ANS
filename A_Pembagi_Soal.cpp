#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ukr = 1e5+101;
const ll md = 1e9+7;
ll pgkt(ll rn, ll pp){
    if(pp == 0) return 1;
    ll nwx = pgkt(rn, pp/2)%md;
    if(pp%2){
        return nwx*nwx%md*rn%md;
    }else{
        return nwx*nwx%md;
    }
}
ll n, m, id;
vector<ll> v;
vector<ll> pao;
ll ans = 0;
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> id;
        v.push_back(id);
    }
    if(m == 1){
        for(auto i : v){
            ans = (ans+pgkt(2, i))%md;
        }
        cout << ans << "\n";
        return;
    }
    sort(v.begin(), v.end(), greater<int>());
    m--;
    int idx = 0;
    while(idx < v.size()){
        set<ll> st;
        pao.push_back(v[idx]);
        idx++;
        ll pp = m;
        while(pp--){
            st.clear();
            while(idx < v.size()){
                auto it = st.find(v[idx]);
                if(it != st.end()){
                    ll rn = v[idx];
                    while(it != st.end()){
                        st.erase(it);
                        rn++;
                        it = st.find(rn);
                    }
                    st.insert(rn);
                }else{
                    st.insert(v[idx]);
                }
                idx++;
                if(*st.begin() == pao.back()){
                    break;
                }
            }
        }
    }
    for(auto i : pao){
        //cout << i << "\n";
        ans = (ans+pgkt(2, i))%md;
    }
    cout << ans << "\n";
    return;



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