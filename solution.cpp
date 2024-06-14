#include <bits/stdc++.h>
 
using namespace std;

// Function to check if the kth bit is set in the number n.
bool isKthBitSet(int n, int k){
    if (n & (1 << k))
        return true;
    else
        return false;
}

// Function to calculate the OR between indices using the dp vector.
int or_bw_indices(vector<int>& v, vector<vector<int>>& dp, int l, int r){
    int ans = 0;
    for (int j = 0; j<32; j++){
        if ((l == 0? dp[r][j]: dp[r][j] - dp[l-1][j]) > 0) ans += 1<<j;
    }
    return ans;
}

void test_case(){
    int n,q;
    cin >> n >>  q;
    vector<int> v(n);
    for (int i = 0; i<n; i++) cin >> v[i];

    // Creaating the dp vector where dp[i][j] stores the number 
    // of set bits of the ith element till the jth bit.
    vector<vector<int>> dp(n, vector<int>(32, 0));
    for (int i = 0; i<n; i++){
        for (int j = 0; j<32; j++){
            if (isKthBitSet(v[i], j)) {
                dp[i][j] = (i == 0? 1: dp[i-1][j] + 1);
            }
            else dp[i][j] = (i == 0? 0: dp[i-1][j]);
        }
    }

    while (q--){
        int ind;
        cin >> ind;

        // Case 1.
        // Considering the right side first

        int l = ind;
        int r = n-1;
        int right_max_or = or_bw_indices(v,dp,ind,n-1);
        int i = n-1;
        while (l<=r){
            int mid = l + (r - l)/2;
            if (or_bw_indices(v,dp,ind,mid) == right_max_or){
                i = min(i, mid);
                r = mid-1;
            }
            else l = mid + 1;
        }
        // Then the left end.
        int left_and_right_max_or = or_bw_indices(v,dp,0,n-1);
        l = 0;
        r = ind;
        int j = 0;
        while (l<=r){
            int mid = l + (r-l)/2;
            if ( (or_bw_indices(v,dp,mid,ind) | right_max_or) == left_and_right_max_or){
                j = max(j, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }


        // Case2
        // Considering the left end first.

        int left_max_or = or_bw_indices(v,dp,0,ind);
        l = 0;
        r = ind;
        int i2 = 0;
        while (l<=r){
            int mid = l + (r-l)/2;
            if ((or_bw_indices(v,dp,mid,ind)) == left_max_or){
                i2 = max(i2, mid);
                l = mid + 1;
            }
            else r = mid - 1;
        }

        // Then the right end.
        l = ind;
        r = n-1;
        int j2 = n-1;
        while (l<=r){
            int mid = l + (r-l)/2;
            if ((or_bw_indices(v,dp,ind,mid) | left_max_or) == left_and_right_max_or){
                j2 = min(j2, mid);
                r = mid-1;
            }
            else l = mid+1;
        }

        
        // Taking the minimum of the sizes of the two sub-arrays formed.
        cout << min(j2-i2+1, i-j+1) << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t=1;
    while (t--) test_case();
    return 0;
}
