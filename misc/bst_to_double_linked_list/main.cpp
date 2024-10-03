#include <iostream>

using namespace std;

struct BinaryTreeNode {
  int m_nValue;
  BinaryTreeNode *m_pLeft;
  BinaryTreeNode *m_pRight;
};

struct LinkedListNode {
  int value;
  LinkedListNode *next;
  LinkedListNode *prev;
};

BinaryTreeNode *traverse_helper(BinaryTreeNode *root, BinaryTreeNode *parent,
                                BinaryTreeNode **end) {
  if (root == nullptr) {
    cout << "This should never happen unless size 0?" << endl;
    return nullptr;
  }

  BinaryTreeNode *ret = nullptr;
  if (root->m_pLeft) {
    ret = traverse_helper(root->m_pLeft, root, end);
  } else if (ret == nullptr) {
    ret = root;
  } else {
  }

  if (*end != nullptr) {
    (*end)->m_pRight = root;
    root->m_pLeft = *end;
  }
  *end = root;

  if (root->m_pRight) {
    traverse_helper(root->m_pRight, root, end);
  }

  return ret;
}

BinaryTreeNode *traverse(BinaryTreeNode *root) {
  BinaryTreeNode *end = nullptr;
  return traverse_helper(root, nullptr, &end);
}

using namespace std;

int main(int argc, char *argv[]) {
  BinaryTreeNode *root = new BinaryTreeNode;
  root->m_nValue = 10;
  BinaryTreeNode *new_node = new BinaryTreeNode;
  new_node->m_nValue = 6;
  new_node->m_pLeft = nullptr;
  new_node->m_pRight = nullptr;
  root->m_pLeft = new_node;

  new_node = new BinaryTreeNode;
  new_node->m_nValue = 14;
  new_node->m_pLeft = nullptr;
  new_node->m_pRight = nullptr;
  root->m_pRight = new_node;

  new_node = new BinaryTreeNode;
  new_node->m_nValue = 4;
  new_node->m_pLeft = nullptr;
  new_node->m_pRight = nullptr;
  root->m_pLeft->m_pLeft = new_node;

  new_node = new BinaryTreeNode;
  new_node->m_nValue = 8;
  new_node->m_pLeft = nullptr;
  new_node->m_pRight = nullptr;
  root->m_pLeft->m_pRight = new_node;

  new_node = new BinaryTreeNode;
  new_node->m_nValue = 12;
  new_node->m_pLeft = nullptr;
  new_node->m_pRight = nullptr;
  root->m_pRight->m_pLeft = new_node;

  new_node = new BinaryTreeNode;
  new_node->m_nValue = 16;
  new_node->m_pLeft = nullptr;
  new_node->m_pRight = nullptr;
  root->m_pRight->m_pRight = new_node;

  BinaryTreeNode *head = traverse(root);

  BinaryTreeNode *tail = head;
  cout << "Going forward" << endl;
  while (head != nullptr) {
    cout << head->m_nValue << ' ';
    tail = head;
    head = head->m_pRight;
  }
  cout << endl;

  cout << "Going backward" << endl;
  while (tail != nullptr) {
    cout << tail->m_nValue << ' ';
    tail = tail->m_pLeft;
  }
  cout << endl;

  return 0;
}
