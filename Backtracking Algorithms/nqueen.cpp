//GFG Practice
#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,a,n) for(i=a;i>=n;i--)
#define rep(i,n)  for(i=0;i<n;i++)
#define si(i)  scanf("%d",&i)
#define ss(s)  scanf("%s",s)
#define sl(i)  scanf("%lld",&i)
#define pi(i)  printf("%d",i)
#define pl(i)  printf("%lld",i);
#define ps()   printf(" ");
#define pn()   printf("\n");
#define all(v)  v.begin(),v.end()
#define vi vector <int>
#define vl vector <ll>
#define N 25
using namespace std;
ll board[N][N];
bool safe(ll i,ll j,ll n)
{
	ll row,col;
	for(col=j-1;col>=0;col--)
	{
		if(board[i][col])
		{
			return false;
		}
	}
	for(row=i-1,col=j-1;row>=0&&col>=0;row--,col--)
	{
		if(board[row][col])
		{
			return false;
		}
	}
	for(row=i+1,col=j-1;row<n&&col>=0;row++,col--)
	{
		if(board[row][col])
		{
			return false;
		}
	}
	return true;
}
void print(ll n)
{
	ll i,j;
	cout<<"[ ";
	rep(i,n)
	{
		rep(j,n)
		{
			if(board[j][i])
			{
				cout<<j+1<<" ";
			}
		}
	}
	cout<<"] ";
}
bool print_nqueen(ll n,ll col)
{
	if(col==n)
	{
		print(n);
		return true;
	}
	ll i;
	bool res=false;
	for(i=0;i<n;i++)
	{
		if(safe(i,col,n))
		{
			//cout<<i<<" "<<col<<" "<<res<<endl;
			board[i][col]=1;
			bool tmp=print_nqueen(n,col+1);
			res=res||tmp;
			board[i][col]=0;
		}
	}
	return res;
}
int main()
{
	ll t,n,i,j;
	sl(t);
	while(t--)
	{
		sl(n);
		rep(i,n)
		{
			rep(j,n)
			{
				board[i][j]=0;
			}
		}
		if(!print_nqueen(n,0))
		{
			cout<<"-1";
		}
		cout<<endl;
	}
	return 0;
}