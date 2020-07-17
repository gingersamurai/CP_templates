
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