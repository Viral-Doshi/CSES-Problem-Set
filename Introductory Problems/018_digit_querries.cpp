#include<bits/stdc++.h>
#include<chrono>
using namespace std;
// ifstream fin ("test.txt");
// #define cin fin
#define ll long long
#define ld long double
#define all(v) (v).begin(), (v).end()
#define fshow(v) for(auto& x__x: v) cout << x__x << " "; cout << '\n'
#define finp(v,n) v.resize(n); for(int i=0;i<n;i++) cin>>v[i]
#define fsum(v) accumulate(all(v), 0LL)
#define fsort(v) sort(all(v))
#define fdsort(v) sort(all(v), greater<ll>())
#define fmax(v) *max_element(all(v))
#define fmin(v) *min_element(all(v))

struct mhash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    uint64_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll power(ll x, ll y){
    ll res = 1;
    while (y){
        if (y % 2 == 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        if (n/10 == 0){
            cout << n << '\n';
            continue;
        }
        vector<ll> val(18);
        val[0] = 9;
        for (int i=2; i < 19; i++){
            val[i-1] = 9 * (power(10,i-1)) * i + val[i-2];
        }
        for (int i=0; i < 18; i++){

            if (val[i] == n){
                cout << 9 << '\n';
                break;
            }

            if (val[i] > n){
                ll num;
                n -= val[i-1];
                if (n % (i+1) == 0){
                    num = n/(i+1) + power(10,i) - 1;
                    cout << num%10 << '\n';
                }
                else{
                    num = n/(i+1) + 1 + power(10,i) - 1;
                    cout << (num / power(10, i+1-(n % (i+1)))) % 10 << '\n';                    
                }
                break;
            }
        }
    }
    return 0;
}

