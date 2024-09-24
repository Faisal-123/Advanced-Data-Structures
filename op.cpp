#warning Check FastIO
#ifdef ONLINE_JUDGE
    #pragma GCC optimize("Ofast")
    #pragma GCC target("avx,avx2,fma")
#endif
#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <random>
#include <chrono>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;
#define vll vector<ll>
#define sll set<ll>
#define vstr vector<string>
#define ll long long
#define ld long double
#define supra main
#define pb push_back
#define add insert
#define rall(x) rbegin(x),rend(x)
#define all(x) (x).begin(),(x).end()
#define I ios_base::sync_with_stdio(false);
#define Hear cin.tie(NULL);
#define Shots cout.tie(NULL);
#define Ratatatata
#define bits_on(a) (__builtin_popcountll(a))
#define mx_pw2(a) (__builtin_ctzll(a))
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUFFLE(v) shuffle(all(v), RNG); 
const ll inf=LLONG_MAX;
void input(vll& a)
{
    for(auto& i:a)
        cin>>i;
}
void pyn(bool a)
{
    cout<<(a?"YES":"NO")<<endl;
}
ll powmod(ll a,ll b,ll modulo)
{
  if(b==0){
    return 1;
  }
  ll temp=powmod(a,b/2,modulo);
  if(b%2==0){
    return (temp*temp)%modulo;
  }
  else{
    return (a*((temp*temp)%modulo))%modulo;
  }
}

bool Prime(ll n){
    for (ll i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;
    return (n>1);
}
void solve()
{
	
}
int supra(){
    I Hear Shots Ratatatata
    ll tqwertyuiop=1;
    cin>>tqwertyuiop;
    for(int tp=1;tp<=tqwertyuiop;tp++)
    {
        // cout<<"Case #"<<tp<<": ";
        solve();
    }
    return 0;
}
/*
Bro use only in a emergency 
this is kind of hacking
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
*/