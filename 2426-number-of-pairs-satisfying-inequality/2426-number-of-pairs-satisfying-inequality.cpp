#define ll long long
struct SEG {
    vector<vector<ll>> v;
    ll siz = 1;
    
    SEG(ll n, vector<ll> &ar) {
        siz = 1;
        while(siz <= n) siz <<= 1;
        v.resize(2 * siz);
        build(0, siz - 1, 0, ar);
    }
    
    void merge(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
        int i = 0, j = 0;
        while(i < b.size() and j < c.size()) {
            if(b[i] < c[j]) a.push_back(b[i++]);
            else a.push_back(c[j++]);
        }
        while(i < b.size()) {
            a.push_back(b[i++]);
        }
        while(j < c.size()) {
            a.push_back(c[j++]);
        }
    }

    void build(ll lx, ll rx, ll x, vector<ll> &ar) {
        if(lx == rx) {
            if(lx < ar.size()) {
                v[x].push_back(ar[lx]);
            }
            return;
        }
        ll mid = lx + (rx - lx) / 2;
        build(lx, mid, 2 * x + 1, ar);
        build(mid + 1, rx, 2 * x + 2, ar);
 
        merge(v[x], v[2 * x + 1], v[2 * x + 2]);
    }
    
    //count of numbers greater than equal to val
    ll cnt(ll l, ll r, ll val, ll x, ll lx, ll rx) {
        if(lx > r or rx < l) return 0;
        if(lx >= l and rx <= r) {
            int ind = lower_bound(v[x].begin(), v[x].end(), val) - v[x].begin();
            return v[x].size() - ind;
        }
        ll mid = lx + (rx - lx) / 2;
        return cnt(l, r, val, 2 * x + 1, lx, mid) + cnt(l, r, val, 2 * x + 2, mid + 1, rx);
    }
    ll cnt(ll l, ll r, ll val) {
        return cnt(l, r, val, 0, 0, siz - 1);
    }
};
class Solution {
public:
    long long numberOfPairs(vector<int>& a, vector<int>& b, int diff) {
        int n = a.size();
        vector<ll> v(n);
        for(int i = 0; i < n; ++i) v[i] = a[i] - b[i];
        
        SEG tree(n, v);
        
        ll pairs = 0;
        for(int i = 0; i < n; ++i) {
            pairs += tree.cnt(i + 1, n - 1, v[i] - diff);
        }
        return pairs;
    }
};