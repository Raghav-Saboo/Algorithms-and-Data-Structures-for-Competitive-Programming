// GFG Practice
#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define fu(i, a, n) for (i = a; i <= n; i++)
#define fd(i, a, n) for (i = a; i >= n; i--)
#define rep(i, n) for (i = 0; i < n; i++)
#define si(i) scanf("%d", &i)
#define ss(s) scanf("%s", s)
#define sl(i) scanf("%lld", &i)
#define pi(i) printf("%d", i)
#define pl(i) printf("%lld", i);
#define ps() printf(" ");
#define pn() printf("\n");
#define all(v) v.begin(), v.end()
#define vi vector<int>
#define vl vector<ll>
#define N 100005

struct node {
  ll val;
  node *left, *right;

  node(ll val, node *left, node *right) {
    this->val = val;
    this->left = left;
    this->right = right;
  }
};

struct node *insert(struct node *root, ll val) {
  if (root == NULL) {
    return new node(val, NULL, NULL);
  } else if (root->val > val) {
    root->left = insert(root->left, val);
  } else {
    root->right = insert(root->right, val);
  }
  return root;
}

bool search(struct node *root, ll val) {
  if (root == NULL) {
    return false;
  } else if (root->val == val) {
    return val;
  } else if (root->val > val) {
    return search(root->left, val);
  }
  return search(root->right, val);
}

node *delete_bst(node *root, ll val) {
  if (root == NULL) {
    return NULL;
  } else if (root->val > val) {
    root->left = delete_bst(root->left, val);
  } else if (root->val < val) {
    root->right = delete_bst(root->right, val);
  } else {
    struct node *tmp;
    if (root->left == NULL && root->right == NULL) {
      tmp = root;
      delete (tmp);
      root = NULL;
    } else if (root->left == NULL) {
      tmp = root->right;
      delete (root);
      root = tmp;
    } else if (root->right == NULL) {
      tmp = root->left;
      delete (root);
      root = tmp;
    } else {
      tmp = root->right;
      while (tmp->left != NULL) {
        tmp = tmp->left;
      }
      root->val = tmp->val;
      root->right = delete_bst(root->right, tmp->val);
    }
  }
  return root;
}

void preorder(node *root) {
  if (root == NULL) {
    return;
  }
  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}

int main() {
  struct node *root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);
  preorder(root);
  cout << endl;
  root = delete_bst(root, 20);
  preorder(root);
  cout << endl;
  root = delete_bst(root, 50);
  preorder(root);
  cout << endl;
  root = delete_bst(root, 30);
  preorder(root);
  cout << endl;
  return 0;
}