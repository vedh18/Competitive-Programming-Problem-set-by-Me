#include <iostream>
#include<bits/stdc++.h>
using ll = long long int;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define printvec(vec) {for(ll i=0;i<vec.size();i++) cout<<vec[i]<<" "; cout<<endl;}
#define inputvec(vec,n) for(ll i=0;i<n;i++){ ll x; cin>>x; vec.pb(x);};
#define inputvecpp(vec,n) for(ll i=0;i<n;i++){ ll x; ll y;cin>>x; cin >> y; vec.pb({x,y});};
#define f first
#define s second
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef map<ll,ll> mll;
typedef pair<ll,ll> pll;
ll MOD = 1e9 + 7;
bool isKthBitSet(int n, int k){
    if (n & (1 << k))
        return true;
    else
        return false;
}
ll or_bw_indices(vll& v, vector<vector<ll>>& dp, ll l, ll r){
    ll ans = 0;
    for (ll j = 0; j<32; j++){
        if ((l == 0? dp[r][j]: dp[r][j] - dp[l-1][j]) > 0) ans += pow(2, j);
    }
    return ans;
}
void test_case(){
    ll n,q;
    cin >> n >>  q;
    vll v;
    inputvec(v, n);
    vector<vector<ll>> dp(n, vector<ll>(32, 0));
    for (ll i = 0; i<n; i++){
        for (ll j = 0; j<32; j++){
            if (isKthBitSet(v[i], j)) {
                dp[i][j] = (i == 0? 1: dp[i-1][j] + 1);
            }
            else dp[i][j] = (i == 0? 0: dp[i-1][j]);
        }
    }
    while (q--){
        ll ind;
        cin >> ind;
        ll l = ind;
        ll r = n-1;

        // There are two cases here, 
        // 1)  first we find a possible right index and 
            // then try to find a appropriate left index
            // such that the or of the subarray becomes equal to the or of the entire array
        // 2) We first calculate left and then right.

        // Then we take the minimum of the two possible cases.

        // For the right end of the subarray
        ll right_max_or = or_bw_indices(v,dp,ind,n-1);
        ll i = n-1; 
        while (l<=r){
            ll mid = l + (r - l)/2;
            if (or_bw_indices(v,dp,ind,mid) == right_max_or){
                i = min(i, mid);
                r = mid-1;
            }
            else l = mid + 1;
        }


        // We find the left end of the subbarray
        ll left_and_right_max_or = or_bw_indices(v,dp,0,n-1);
        l = 0;
        r = ind;
        ll j = 0;
        while (l<=r){
            ll mid = l + (r-l)/2;
            if ((or_bw_indices(v,dp,mid,ind) | right_max_or) == left_and_right_max_or){
                j = max(j, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }

        // Case2
        // We find left end first
        ll left_max_or = or_bw_indices(v,dp,0,ind);
        l = 0;
        r = ind;
        ll i2 = 0;
        while (l<=r){
            ll mid = l + (r-l)/2;
            if ((or_bw_indices(v,dp,mid,ind)) == left_max_or){
                i2 = max(i2, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }

        // Then we find right index accordingly.
        l = ind;
        r = n-1;
        ll j2 = n-1;
        while (l<=r){
            ll mid = l + (r-l)/2;
            if ((or_bw_indices(v,dp,ind,mid) | left_max_or) == left_and_right_max_or){
                j2 = min(j2, mid);
                r = mid-1;
            }
            else l = mid+1;
        }

        // Taking the minimum of the two sub-arrays formed.
        cout << min(j2-i2+1, i-j+1) << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    test_case();
    return 0;
}
