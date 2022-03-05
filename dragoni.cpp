#include <bits/stdc++.h>
using namespace std;
ifstream f("dragoni.in");
ofstream g("dragoni.out");
#define cin f
#define cout g
//#define int long long
const int Max = 800 + 1;
void nos()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int task;
int n,m;
int a[Max];
vector< pair < int , int > > v[Max];
void read()
{
	f>>task;
	f>>n>>m;
	int i;
	for(i=1;i<=n;i++)	
		f>>a[i];
	for(i=1;i<=m;i++)
	{
		int n1,n2,cost;
		f>>n1>>n2>>cost;
		v[n1].push_back({n2,cost});
		v[n2].push_back({n1,cost});
	}
}
int dp[Max][Max];
int viz[Max];
void solve1()
{
	int cost_cap = a[1];
	int ans = cost_cap;
	queue < int > q;
	q.push(1);
	while(!q.empty())
	{
		int nod = q.front();
		q.pop();
		if(viz[nod] == 1)
			continue;
		viz[nod] = 1;
		ans = max(ans,a[nod]);
		for(auto vec : v[nod])
		{
			int dest = vec.first;
			if(vec.second <= cost_cap and viz[dest] == 0)
				q.push(dest);
		}
	}
	g<<ans;
}
struct pq_elem{
	int cost;
	int nod;
	int dragon;
};
bool operator < (const pq_elem& p1, const pq_elem& p2)
{
	//operator overload
	//return true daca p2 are prioritate mai mare decat p1 
	//conditia pe dos
	if(p1.cost == p2.cost)
	return a[p1.dragon] < a[p2.dragon];
	else
		return p1.cost > p2.cost;
}
priority_queue < pq_elem > pq;
void solve()
{
	if(task == 1)
	{
		solve1();
		return;
	}
	//dp[i][j] --> distanta minima ce trebuie parcursa pentru a ajunge pe insula i cu un dragon din specia j
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			dp[i][j] = INT_MAX;
	dp[1][1] = 0;
	pq.push({0,1,1});
	while(!pq.empty())
	{
		pq_elem state = pq.top();
		pq.pop();
		//cout<<state.nod<<' '<<a[state.dragon]<<'\n';
		if(dp[state.nod][state.dragon] != state.cost)
			continue;
		int dragonhere = a[state.nod];
		if(dragonhere > a[state.dragon] and dp[state.nod][state.nod] >state.cost)
		{
			//pot lua un dragon mai bun aici
			dp[state.nod][state.nod] = state.cost;
			pq.push({state.cost,state.nod,state.nod});
		}
		else
		for(auto vec : v[state.nod])
			if(vec.second <= a[state.dragon])
		{
			
			int ncost = state.cost + vec.second;
			int nnod = vec.first;
			if(dp[nnod][state.dragon] > ncost)
			{
				//iau ruta asta 
				dp[nnod][state.dragon] = ncost;
				pq.push({ncost,nnod,state.dragon});
			}
		}
	}
 
	int Dmin = INT_MAX;
	for(j=1;j<=n;++j)
	{
		Dmin = min(Dmin,dp[n][j]);
	}
	g<<Dmin;
    
 
   	
}
void restart()
{
 
}
int32_t main()
{
    nos();
 
        read();
        solve();
        restart();
    
    return 0;
}
