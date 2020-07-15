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
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
#define mp make_pair
#define fi(b, c) for(auto i = b; i <= c; i++)
#define fj(b, c) for(auto j = b; j <= c; j++)
#define fk(b, c) for(auto k = b; k <= c; k++)
#define fq(b, c) for(auto q = b; q <= c; q++)
#define fw(b, c) for(auto w = b; w <= c; w++)
#define fim(b, c) for(auto i = b; i >= c; i--)
#define fjm(b, c) for(auto j = b; j >= c; j--)
#define fkm(b, c) for(auto k = b; k >= c; k--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (ll)(a.size())
#define fs first
#define sd second
#define endl "\n"
#define cin(a) for(ll o = 0; o<a.size(); o++) cin>>a[o];
#define cout(a) for(ll o = 0; o<a.size(); o++) cout<<a[o]<<"\n";
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

ll n, m;
ll timer;
vector<ll> ans;
vector< vector<ll> >g;
vector<bool> used;
vector<ll> tin, fup;
map<pll, ll> vert;

void bridge(ll v, ll p = -1){
    used[v] = true;
    tin[v] = timer;
    fup[v] = timer;
    timer++;
    for(auto to: g[v]){
        if(to == p){
            continue;
        }
        if(used[to]){
            fup[v] = min(fup[v], tin[to]);
        } else {
            bridge(to, v);
            fup[v] = min(fup[v], fup[to]);
            if(fup[to] > tin[v]){
                ans.push_back(vert[{v, to}]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    g.resize(n);
    fi(0, m-1){
        ll x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        vert[{x, y}] = i+1;
        vert[{y, x}] = i+1;
    }
    tin.resize(n);
    fup.resize(n);
    used.resize(n, false);
    ans.clear();
    fi(0, n-1){
        if(!used[i]){
            bridge(i);
        }
    }
    sort(all(ans));
    cout << ans.size() << endl;
    cout (ans);
    run();
}