#include<vector>
#include <string>
#include<algorithm>
#include <iostream>
#include <queue>
#include<set>
#include<stack>
#include<cmath>
#include<math.h>
#include<map>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
#define mp make_pair
#define fi(b, c) for(auto i = b; i <= c; i++)
#define fj(b, c) for(auto j = b; j <= c; j++)
#define fk(b, c) for(auto k = b; k <= c; k++)
#define fim(b, c) for(auto i = b; i >= c; i--)
#define fjm(b, c) for(auto j = b; j >= c; j--)
#define fkm(b, c) for(auto k = b; k >= c; k--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define fs first
#define sd second
#define endl "\n"
#define cin(a) for(ll o = 0; o<a.size(); o++) cin>>a[o];
#define cout(a) for(ll o = 0; o<a.size(); o++) cout<<a[o]<<" ";
const ll inf = 1e9 + 123, llinf = 1e18 + 123;
void xru(){
 setlocale(LC_ALL, "rus");
 /*freopen(".in", "r", stdin);
 freopen(".out", "w", stdout);*/
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
}
void run(){
 cout<<endl;
 system("pause");
}
vector<ll> z_func(string& s){
    ll n = s.size();
    vector<ll> z(n);
    ll l = 0, r = 0;
    fi(1, n-1){
        if(i <= r){
            z[i] = min(z[i - l], r - i + 1);
        }
        while(i + z[i] < n && s[i + z[i]] == s[z[i]]){
            z[i]++;
        }
        if(i + z[i] - 1 > r){
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

vector<ll> pref_func(string& s){
    ll n = s.size();
    vector<ll>pi(n);
    fi(1, n-1){
        ll j = pi[i - 1];
        while (j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}