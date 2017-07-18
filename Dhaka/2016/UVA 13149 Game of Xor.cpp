#include<bits/stdc++.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#define vi vector<int>
#define vll vector<LL>
#define pii pair<int,int>
#define pli pair<LL,int>
#define pll pair<LL,LL>
#define fr first
#define sc second
#define MAX 50010
#define LL   long long int
#define ll   long long int
//#define LLL long long int
#define inf 1ll<<62
#define INF 1000000
#define mod 342307123
#define PI acos(-1)
#define pi acos(-1)
#define NN 50003
#define mMax 100010
#define nMax 200
#define MAXN 200010
#define maxN 1<<18
#define SZ(a) a.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define rep1(i,b) for(int i=1;i<=b;i++)
#define rep2(i,b) for(int i=0;i<b;i++)
#define REP(i,b) for(int i=0;i<b;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define all(A) A.begin(),A.end()
#define isf(a) scanf("%d",&a);
#define Lsf(a) scanf("%I64d",&a);
#define lsf(a) scanf("%lld",&a);
#define csf(a) scanf("%c",&a);
using namespace std;
#define LSOne(S) (S & (-S))
#define EPS 1e-12
#define B (1<<7)
char A[100010];
char str[100010];
LL val[7];
int L,R;
int Right;
pll call(int g,int p)
{
  LL a=0,b=0;
  pll res;
  memset(val,0,sizeof(val));// val[0]="00" , val[1]= "11" , val[2]= "10/01"
  
  for(int i=0;i<=p;i++)
  {
    a += (A[i]=='1');
    b += (A[i]=='0');
    if(i == p) continue;
    if(A[i]==A[i+1] && A[i]=='0') val[0]++;
    else if(A[i]==A[i+1] && A[i]=='1') val[1]++;
    else val[2]++;
  }
  for(int i=0;i<g;i++)
  {
    a = (a+ val[2])%mod;
    b = (b+ val[0]+ val[1])%mod;
    val[3] = (val[0]+val[0])%mod;
    val[5] = (val[2]+val[1]+val[1])%mod;
    val[4] = val[2];
    rep2(j,3) val[j]=val[j+3];
  }
  res.fr = a;
  res.sc = b;
  L=A[p]-'0';
  if(p+1 == strlen(A)) return res;
  R=A[p+1]-'0';
  a=0;b=0;
  memset(val,0,sizeof(val));
    Right=0;
  for(int i=0;i<g;i++)
  {
    a = (a+ val[2])%mod;
    b = (b+ val[0]+ val[1])%mod;
    val[3] = (val[0]+val[0])%mod;
    val[5] = (val[2]+val[1]+val[1])%mod;
    val[4] = val[2];
    rep2(j,3) val[j]=val[j+3];
    if(str[i]=='D') R=L^R;
    else
    {
      Right++;
    if(L==R && L==0) {val[0]++;b++;}
    else if(L==R && L==1) {val[2]++;b++;}
    else if(L==0) {val[2]++;a++;}
    else {val[1]++;a++;}
    L=L^R;
    rep2(j,3) val[j]=(val[j]%mod);
    a%=mod;b%=mod;
    }
  }

  res.fr=(res.fr+a)%mod;
  res.sc=(res.sc+b)%mod;
  return res;
}
int main()
{
  int T,I=1;
  cin>>T;
  while(T--)
  {
    printf("Case %d: ",I++);
    int g,p;
    scanf("%s %d",A,&g);
    g--;
    scanf("%d",&p);
    if(g) scanf("%s",str);
    pll ans1=call(g,p);
    int q=p;
    int temp=Right;
    //cout<<ans1.sc;
    int pL=L;
    scanf("%d",&p);
    if(g) scanf("%s",str);
    pll ans2=call(g,p);
    if(p<q || (p==q && temp>Right)) swap(ans1,ans2); else L=pL; // if second position is less than first position. This case does not exist in dataset.
    if(L==1) ans1.fr=((ans1.fr-1)%mod    +mod)%mod; else ans1.sc=((ans1.sc-1)%mod    +mod)%mod;
    ans2.fr = ((ans2.fr-ans1.fr)%mod   +mod)%mod;
    ans2.sc = ((ans2.sc-ans1.sc)%mod   +mod)%mod;
    printf("%lld %lld\n",ans2.sc,ans2.fr);
  }
  return 0;
}
