/*
Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
*/

#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root == nullptr) {
            return nullptr;
        }

        if (depth == 1) {
            TreeNode* newHead = new TreeNode(val);
            newHead->left = root;
            return newHead;
        }

        // Traverse the tree to find the node at depth - 1
        queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (currentDepth == depth - 1) {
                    TreeNode* left = new TreeNode(val);
                    TreeNode* right = new TreeNode(val);

                    left->left = node->left;
                    right->right = node->right;

                    node->left = left;
                    node->right = right;
                } else {
                    if (node->left) {
                        q.push(node->left);
                    }

                    if (node->right) {
                        q.push(node->right);
                    }
                }
            }

            currentDepth++;
        }

        return root;
    }
};
