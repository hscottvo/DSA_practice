#include <iostream>
#include <queue>

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

int countNodesNaive(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  return countNodesNaive(root->left) + countNodesNaive(root->right) + 1;
}

int countNodes(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  queue<bool> is_right;

  TreeNode *curr = root;
  int curr_level = 0;
  int curr_left_right = 0;
  while (true) {
    if (curr->right != nullptr) {
      curr = curr->right;
      is_right.push(true);
    } else if (curr->left != nullptr) {
      curr = curr->left;
      is_right.push(false);
    } else {
      cout << "Rightmost leaf is value " << curr->val << endl;
      break;
    }
    curr_level++;
  }

  cout << "curr_level: " << curr_level << endl;

  return 0;
}

int main(int argc, char *argv[]) {
  cout << "Hi" << endl;

  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  /*root->right->left = new TreeNode(6);*/

  cout << "return: " << countNodes(root) << endl;

  return 0;
}
