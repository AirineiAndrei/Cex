#include <bits/stdc++.h>
using namespace std;
#define f cin
#define g cout
#define int long long
const int Max = 100 + 1;
void nos()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
vector < int > v[30];
int words;
char cuvinte[Max][Max];
void read()
{
    f>>words;
    cin.get();
    int i;
    for(i=1;i<=words;i++)
        cin.getline(cuvinte[i],Max);
}
int convert_char(char x)
{
    return x - 'a';
}
int grade[30];
 
void solve()
{
    int i;
    for(i=1;i<words;i++)
    {
        int j;
        for(j=0;cuvinte[i][j] and cuvinte[i+1][j];j++)
        {
            int n1 = convert_char(cuvinte[i][j]);
            int n2 = convert_char(cuvinte[i+1][j]);
            if(n1!=n2)
            {
                v[n1].push_back(n2);
                break;
            }
            if(!cuvinte[i+1][j+1])
            {
                cout<<"Impossible";
                return;
            }
        }
    }
    for(i=0;i<='z'-'a';i++)
    {
        sort(v[i].begin(),v[i].end());
        v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
        for(auto it : v[i])
        {
            grade[it] ++;
        }
    }
    priority_queue < int > pq;
    vector < int > sol;
    for(i=0;i<='z'-'a';i++)
    {
        if(grade[i]==0)
            pq.push(-i);
    }
 
    while(!pq.empty())
    {
 
        int nod = -pq.top();
        //cout<<char(nod+'a');
        sol.push_back(nod);
        pq.pop();
        for(auto it : v[nod])
        {
            grade[it] --;
            if(grade[it]==0)
                pq.push(-it);
        }
    }
 
    if(sol.size()==26)
    {
        for(auto it : sol)
            cout<<char(it+'a');
    }
    else
        cout<<"Impossible";
 
 
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
