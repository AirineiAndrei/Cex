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

const int MOD = 1e9 + 7;
int fact[Max];
int invfact[Max];

int fastpow(int base,int exponent)
{
    if(exponent == 0)
        return 1;

    int half = fastpow(base,exponent / 2);
    half = (half * half) % MOD; //a^b = a^(b/2) * a^(b/2)
    if(exponent %2 != 0)
        half = (half * base) % MOD;
    return half;
}

int combs(int n,int k)
{
    int ans = fact[n];
    // n! / ((n-k)!(k!))
    ans *= invfact[n-k];
    ans %= MOD;//n! / (n-k)!
    ans *= invfact[k];
    ans %= MOD;
    return ans;
}
int aranj(int n,int k)
{
     int ans = fact[n];
    // n! / ((n-k)!)
    ans *= invfact[n-k];
    ans %= MOD;//n! / (n-k)!
    return ans;
}

int32_t main()
{
    nos();
    int n;
    f>>n;
    //calculam toate fact si invfact
    int i;
    fact[0] = 1;
    for(i=1;i<=n;i++)
    	fact[i] = (fact[i-1] * i) % MOD;

    //invfact[n] = (fact[n]) -1
    invfact[n] = fastpow(fact[n],MOD - 2);
    for(i=n-1;i>=1;i--)
        invfact[i] = ((i+1) * invfact[i + 1])%MOD;
    //infact[i] inversu modular pentru fact[i]
    //
    cout<<combs(3,2)<<'\n';
    cout<<aranj(3,2)<<'\n';



    
    return 0;
}