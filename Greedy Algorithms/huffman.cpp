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
#define N 505
using namespace std;
struct node
{
	char ch;
	ll freq;
	struct node *left,*right;
	node(char ch,ll freq,node *left,node *right)
	{
		this->ch=ch;
		this->freq=freq;
		this->left=left;
		this->right=right;
	}
};
ll freq[26];
struct cmp
{
	bool operator()(const node *a,const node *b)
	{
		return a->freq > b->freq;
	}
};
void print(node *root,string s)
{
	if(root==NULL)
	{
		return;
	}
	else if(root->ch>='a'&&root->ch<='z')
	{
		cout<<s<<" ";
	}
	else
	{
		print(root->left,s+"0");
		print(root->right,s+"1");
	}
}
int main()
{
	ll t,n,i,j,x,l;
	sl(t);
	while(t--)
	{
		priority_queue <node *,vector <node *> ,cmp> pq;
		node *tmp,*tmp1;
		node *root=NULL;
		string s;
		cin>>s;
		l=s.size();
		rep(i,l)
		{
			sl(freq[i]);
			tmp=new node(s[i],freq[i],NULL,NULL);
			pq.push(tmp);
		}
		while(pq.size()>=2)
		{
			tmp=pq.top();
			pq.pop();
			tmp1=pq.top();
			pq.pop();
			//cout<<tmp->freq<<" "<<tmp1->freq<<endl;
			node *tmp2=new node('*',tmp->freq+tmp1->freq,tmp,tmp1);
			root=tmp2;
			pq.push(tmp2);
		}
		print(root,"");
		cout<<endl;
	}
	return 0;
}