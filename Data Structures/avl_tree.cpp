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
  ll height;

  node(ll val, node *left, node *right, ll height) {
    this->val = val;
    this->left = left;
    this->right = right;
    this->height = height;
  }
};

ll get_height(node *root) {
  if (root == NULL) {
    return 0;
  }
  return max((root->left) != NULL ? root->left->height : 0,
             (root->right) != NULL ? root->right->height : 0) +
         1;
}

node *right_rotate(node *y) {
  node *x, *t1, *t2, *t3;
  x = y->left;
  t1 = x->left;
  t2 = x->right;
  t3 = y->right;
  x->right = y;
  y->left = t2;
  y->height = get_height(y);
  x->height = get_height(x);
  return x;
}

node *left_rotate(node *x) {
  node *y, *t1, *t2, *t3;
  y = x->right;
  t1 = x->left;
  t2 = y->left;
  t3 = y->right;
  x->right = t2;
  y->left = x;
  x->height = get_height(x);
  y->height = get_height(y);
  return y;
}

ll get_balance(node *root) {
  if (root == NULL) {
    return 0;
  }
  return get_height(root->left) - get_height(root->right);
}

void preorder(struct node *root) {
  if (root == NULL) {
    return;
  }
  cout << root->val << " ";
  preorder(root->left);
  // cout<<root->val<<" ";
  preorder(root->right);
}

struct node *insert(struct node *root, ll val) {
  if (root == NULL) {
    return new node(val, NULL, NULL, 1);
  } else if (root->val > val) {
    root->left = insert(root->left, val);
  } else {
    root->right = insert(root->right, val);
  }
  root->height = get_height(root);
  ll balance = (((root->left != NULL) ? root->left->height : 0) -
                ((root->right != NULL) ? root->right->height : 0));
  if (root->left != NULL && balance > 1 && root->left->val > val) {
    root = right_rotate(root);
  } else if (balance > 1 && root->left != NULL && root->left->val < val) {
    root->left = left_rotate(root->left);
    root = right_rotate(root);
  } else if (root->right != NULL && balance < -1 && root->right->val < val) {
    root = left_rotate(root);
  } else if (balance < -1 && root->right != NULL && root->right->val > val) {
    root->right = right_rotate(root->right);
    root = left_rotate(root);
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

node *delete_avl(node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (root->val > data) {
    root->left = delete_avl(root->left, data);
  } else if (root->val < data) {
    root->right = delete_avl(root->right, data);
  } else {
    node *tmp;
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
      root->right = delete_avl(root->right, tmp->val);
    }
  }
  if (root == NULL) return NULL;
  root->height = get_height(root);
  ll balance = get_balance(root);
  if (balance > 1 && get_balance(root->left) >= 0) {
    root = right_rotate(root);
  } else if (balance > 1 && get_balance(root->left) <= 0) {
    root->left = left_rotate(root->left);
    root = right_rotate(root);
  } else if (balance < -1 && get_balance(root->right) <= 0) {
    root = left_rotate(root);
  } else if (balance < -1 && get_balance(root->right) > 0) {
    root->right = right_rotate(root->right);
    root = left_rotate(root);
  }
  return root;
}

int main() {
  node *root = NULL;
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);
  preorder(root);
  cout << endl;

  root = NULL;
  root = insert(root, 9);
  root = insert(root, 5);
  root = insert(root, 10);
  root = insert(root, 0);
  root = insert(root, 6);
  root = insert(root, 11);
  root = insert(root, -1);
  root = insert(root, 1);
  root = insert(root, 2);

  preorder(root);
  cout << endl;

  root = delete_avl(root, 10);

  preorder(root);
  cout << endl;

  root = NULL;
  root = insert(root, 1);
  root = insert(root, 2);

  preorder(root);
  cout << endl;

  root = delete_avl(root, 13);

  preorder(root);
  cout << endl;

  return 0;
}