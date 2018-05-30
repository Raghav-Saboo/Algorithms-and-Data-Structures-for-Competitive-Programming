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
bool issafe(ll board[][10],ll row,ll col,ll val)
{
	ll i,j;
	fu(i,1,9)
	{
		if(board[i][col]==val)
		{
			return false;
		}
	}
	fu(i,1,9)
	{
		if(board[row][i]==val)
		{
			return false;
		}
	}
	ll si,ei;
	si=ceil(row/3.0);
	ei=ceil(col/3.0);
	si=(si-1)*3+1;
	ei=(ei-1)*3+1;
	//cout<<row<<" "<<col<<" "<<si<<" "<<ei<<endl;
	fu(i,si,si+2)
	{
		fu(j,ei,ei+2)
		{
			if(board[i][j]==val)
			{
				return false;
			}
		}
	}
	return true;
}
bool find_rem(ll board[][10],ll &row,ll &col)
{
	ll i,j;
	fu(i,1,9)
	{
		fu(j,1,9)
		{
			if(!board[i][j])
			{
				row=i;
				col=j;
				return true;
			}
		}
	}
	return false;
}
bool sudoku(ll board[][10])
{
	ll row,col;
	ll i;
	if(!find_rem(board,row,col))
	{
		return true;
	}
	fu(i,1,9)
	{
		if(issafe(board,row,col,i))
		{
			//cout<<row<<" "<<col<<endl;
			board[row][col]=i;
			if(sudoku(board))
			{
				return true;
			}
			board[row][col]=0;
		}
	}
	return false;
}
void sudoku_solve(ll board[][10])
{
	if(sudoku(board))
	{
		ll i,j;
		fu(i,1,9)
		{
			fu(j,1,9)
			{
				cout<<board[i][j]<<" ";
			}
		}
		cout<<endl;
	}
}
int main()
{
	ll t,n,m,i,j,e,board[10][10];
	sl(t);
	while(t--)
	{
		fu(i,1,9)
		{
			fu(j,1,9)
			{
				sl(board[i][j]);
			}
		}
		sudoku_solve(board);
	}
	return 0;
}