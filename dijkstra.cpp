#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
ll dp[200001];// storing shortest path sum from source s to other vertices of the graph
ll mark[200001];
vector<pair<ll, ll> > adj[200001];
// vertices numbered from 1 to n
void initialize(ll n)
{
    for (ll i = 1; i <= n; i++)
    {
        dp[i] = (ll)1e9;
        mark[i] = 0;
    }
}
void dijkstra(ll n, ll s)
{
    initialize(n);
    dp[s] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({dp[s], s});
    while (!pq.empty())
    {
        pair<ll, ll> f = pq.top();
        pq.pop();
        ll dis = f.first;
        ll v = f.second;
        if (mark[v])
            continue;
        mark[v] = 1;
        for (ll i = 0; i < (ll)adj[v].size(); i++)
        {
            ll x = adj[v][i].first;
            ll val = adj[v][i].second;
            if (!mark[x] && (dis + val < dp[x]))
            {
                pq.push({dis + val, x});
                dp[x] = dis + val;
            }
        }
    }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int t=1;
	// cin>>t;
	while(t--)
	{
		ll n,m;//n -> no. of vertices , m -> no. of edges
		cin>>n>>m;
		for(ll i=1;i<=m;i++){
			ll x,y,w;// undirected edge from x to y with edge weight w
			cin>>x>>y>>w;
			adj[x].pb({y,w});
			adj[y].pb({x,w});
		}
		initialize(n);
		dijkstra(n,1);// dijkstra from vertex 1 as source
	}
return 0;
}
