#include <bits/stdc++.h>
using namespace std;
#define f cin
#define g cout
#define int long long
const int Max = 1e5 + 1;
void nos()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector < int > v[Max];
vector < int > vt[Max];
int n,m;
bool viz[Max];
vector < int > parcurg;

void dfs(int nod)
{
	if(viz[nod] == false)
	{
		viz[nod] = true;
		parcurg.push_back(nod);
		for(auto vec : v[nod])
			if(viz[vec] == false)
				dfs(vec);
	} 
}
int component_id = 0;
int compo[Max];
void dfs_create(int nod)
{
	if(compo[nod] == 0)
	{
		//daca acest nod nu e intr-o componenta
		compo[nod] = component_id;
		//il atrbui componentei curente pe care o creez
		for(auto vec : vt[nod])
			dfs_create(vec);
	}
}


int32_t main()
{
	f>>n>>m;
	int i;
	for(i = 1;i<=m;++i)
	{
		int n1,n2;
		f>>n1>>n2;
		v[n1].push_back(n2);//n1 -> n2 in v
		vt[n2].push_back(n1);//n2 -> n1 in v
	}
	for(i = 1;i<=n;i++)
		if(viz[i] == false)
			dfs(i);
	reverse(parcurg.begin(), parcurg.end());
	for(auto candidat : parcurg)
	{
		if(compo[candidat] == 0)
		{
			//consider nodul candidat ca radacina a acestei componente
			++component_id;
			//1 , 2 ...
			dfs_create(candidat);
		}
	}
	map < int , vector < int > > comps;
	for(i=1;i<=n;i++)
		{
			if(comps.find(compo[i]) == comps.end())// daca nu e in map
				comps[compo[i]] = {i};
			else
				comps[compo[i]].push_back(i);
		}
	for(auto it : comps)
	{
		for(auto nod : it.second)
			cout<<nod<<' ';
		cout<<'\n';
	}
	//recapitulare 
	//1. fac un dfs pe graf atata timp cat am noduri nevizitate
	//1,5. creez graful transpus x -> y => y ->x
	//2. pe parcurgere in ordine inversa daca nodul nu e intr-un CTC il consider radacina si creez componenta



	//complexitate? -> O(n+m)  (2 dfsuri)
    return 0;
}
