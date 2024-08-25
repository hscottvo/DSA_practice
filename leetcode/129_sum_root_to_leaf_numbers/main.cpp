// took 20 minutes
//
// Algorithm: DFS
//   - recurse, passing in so-far value
//   - upon call, multiply passed in value by 10 (shift by 1 decimal digit)
//   - add self value and pass on
//   - sum all leaf values

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int sumNumbersHelper(TreeNode *root, int val) {
  if (root->left == nullptr && root->right == nullptr) {
    return root->val + val * 10;
  }

  int ret = 0;

  if (root->left != nullptr) {
    ret += sumNumbersHelper(root->left, root->val + val * 10);
  }
  if (root->right != nullptr) {
    ret += sumNumbersHelper(root->right, root->val + val * 10);
  }

  return ret;
}

int sumNumbers(TreeNode *root) { return sumNumbersHelper(root, 0); }

int main(int argc, char *argv[]) {

  TreeNode *root = new TreeNode(4);
  root->left = new TreeNode(9);
  root->right = new TreeNode(0);

  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(1);

  cout << sumNumbers(root) << endl;
  return 0;
}
