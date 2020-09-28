#include<vector>
#include <string>
#include<algorithm>
#include <iostream>
#include <queue>
#include<set>
#include<unordered_set>
#include<stack>
#include<cmath>
#include<math.h>
#include<map>
#include<unordered_map>
#include<random>
#include<chrono>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
#define mp make_pair
#define fi(b, c) for(ll i = b; i <= c; i++)
#define fj(b, c) for(ll j = b; j <= c; j++)
#define fk(b, c) for(ll k = b; k <= c; k++)
#define fq(b, c) for(ll q = b; q <= c; q++)
#define fw(b, c) for(ll w = b; w <= c; w++)
#define fim(b, c) for(ll i = b; i >= c; i--)
#define fjm(b, c) for(ll j = b; j >= c; j--)
#define fkm(b, c) for(l k = b; k >= c; k--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
// #define sz(a) (ll)(a.size())
#define fs first
#define sd second
#define endl "\n"
#define sz(x) (ll)(x.size())
 
const ll inf = 1e9 + 123, llinf = 1e18 + 829, ura = 684395049517, mod = 998244353;
void xru() {
    // 9 BOG 4EL
    //  setlocale(LC_ALL, "rus");
    //  freopen(".in", "r", stdin);
    //  freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void run() {
    cout << endl;
    system("pause");
}
/////////////////////////////////
ll n, m, cnt = 0;
vector<vector<ll>> g, tg;
vector<bool> used;
vector<ll> comp, order;
/////////////////////////////////

void topSort(ll v){
    used[v] = true;
    for(ll to: g[v]){
        if(!used[to]) topSort(to);
    }
    order.push_back(v);
}

void cond(ll v){
    used[v] = true;
    comp[v] = cnt;
    for(ll to: tg[v]){
        if(!used[to]) cond(to);
    }
}

int main() {
    cin >> n >> m;
    g.resize(n);
    tg.resize(n);
    used.resize(n, false);
    comp.resize(n, 0);
    fi(0, m-1){
        ll x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        tg[y].push_back(x);
    }
    fi(0, n-1){
        if(!used[i]) topSort(i);
    }
    reverse(all(order));
    fi(0, n-1) used[i] = false;
    fi(0, n-1){
        if(!used[order[i]]){
            cnt++;
            cond(order[i]);
        }
    }
    cout << cnt << endl;
    fi(0, n-1) cout << comp[i] << " ";
}