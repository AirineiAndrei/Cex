#include <bits/stdc++.h>
using namespace std;
#define f cin
#define g cout
#define int long long //nu faceti asa ceva decat la concursuri
const int Max = 1e5 + 1;
void nos()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int n,m;
vector < int > v[Max];
int indeg[Max];//nr de muchii care intra in nod
int32_t main()
{
	f>>n>>m;
	int i;
	for(i = 1;i<=m;++i)
	{
		int n1,n2;
		f>>n1>>n2;
		v[n1].push_back(n2);//n1 -> n2 in v
		indeg[n2] ++; //am muchie care intra in n2
	}
	queue < int > c;
	for(i = 1;i<=n;i++)
		if(indeg[i] == 0)
			c.push(i);
	//mereu o sa imi tin in coada nodurile in care nu intra muchii
		//sortare minim(maxim) topologic folosim priority_queue in loc queue
	while(!c.empty())
	{
		int nod = c.front();
		c.pop();
		cout<<nod<<' ';
		for(auto vec : v[nod])
		{
			indeg[vec] --;
			if(indeg[vec] == 0)//a ajuns si el la 0 deci il bag in coada
				c.push(vec);
		}
	}
	//complexitate topsort standard -> O(n)
	//complexistate topsort lexicografic -> O(nlogn)
      
    return 0;
}
