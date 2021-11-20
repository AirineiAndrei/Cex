#include <bits/stdc++.h>
using namespace std;
ifstream f("spnum.in");
ofstream g("spnum.out");
#define cin f
#define cout g
#define int long long
const int Max = 200 + 1;
const int MOD = 666013;
void nos()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
    void ExtendedEuclid(int a, int b, int &x, int &y)
    {
        //a*x + b*y = (gcd(a,b))
        if(a == 0)
        {
            x = 0; y = 1;
            return;
        }
        int x1,y1;
        ExtendedEuclid(b%a,a,x1,y1);
        x = y1 - (b / a) * x1;
        y = x1;
    }
    void NormaliseMOD(int &x, int MOD)
    {
        if(x < 0)
        {
            int amount = (-x)/MOD + 1;
            x += amount * MOD;
        }
        x %= MOD;
    }
    int ModularInverse(int n, int MOD)
    {
        int x,y;
        ExtendedEuclid(n,MOD,x,y);
        NormaliseMOD(x,MOD);
        return x;
    }
 
long long  fact[Max];
int invfact[Max];
int get_combinari(int n,int k)
{
    if(n < k)
        return 0;
    int ans = fact[n];
    ans *= invfact[k];
    ans %= MOD;
    ans *= invfact[n-k];
    ans %= MOD;
    return ans;
}
void precompute()
{
    fact[0] = 1;
    invfact[0] = ModularInverse(fact[0],MOD);
    int i;
    for(i=1;i<=Max - 1;++i)
    {
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
        invfact[i] = ModularInverse(fact[i],MOD);
    }
}
int n;
void read()
{
    f>>n;
}
int powten[Max];
int poweight[Max];
void solve()
{
    int cif;
    int cnt;
    int how_many = 0;
    int sum = 0;
    powten[0] = 1;
    poweight[0] = 1;
    int i;
    for(i=1;i<=n;i++)
    {
        powten[i] = 10*powten[i - 1];
        powten[i] %= MOD;
        poweight[i] = 8*poweight[i - 1];
        poweight[i] %= MOD;
    }
    for(cif = 1;cif <= 9;cif ++)
    {
        for(cnt = n / 2 + 1;cnt <= n;cnt++)
        {
            //vad cate is cu cifra cif de cnt ori si ce suma au
            int here_many = (get_combinari(n,cnt) * poweight[n-cnt]) % MOD;
            how_many += here_many;
            how_many %= MOD;
            int i;
            for(i=1;i<=n;i++)
            {
                //cifra de manevra pe pozitia asta
                    int sumadd = (powten[i - 1] * cif) % MOD;
                    sumadd *= get_combinari(n - 1,cnt - 1);
                    sumadd %= MOD;
                    sumadd *= poweight[n - cnt];
                    sum += sumadd;
                    sum %= MOD;
                //endd cifra de manevra

                //pun o cifra random aici
                    int cifsum = 45 - cif;
                    cifsum *= powten[i - 1];
                    cifsum %= MOD;
                    cifsum *= get_combinari(n-1,cnt);
                    cifsum %= MOD;
                    cifsum *= poweight[n - cnt - 1];
                    cifsum %= MOD;
                sum += cifsum;
                sum %= MOD;
                //endd cifra random aici
            }
        }
    }
    cout<<how_many<<' '<<sum;
}
void restart()
{

}
int32_t main()
{
    nos();
        precompute();
        read();
        solve();
        restart();
    
    return 0;
}
