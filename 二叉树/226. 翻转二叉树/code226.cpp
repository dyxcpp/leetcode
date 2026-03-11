/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 只要是能遍历一遍二叉树的都可以实现，不用考虑先后，每个节点都翻转一遍就可以了
// // 题解一: 递归法
// class Solution {
// public:
//     void invertSubTree(TreeNode* node) {
//         if(node->left) invertSubTree(node->left);
//         if(node->right) invertSubTree(node->right);
//         TreeNode* tmp = node->left;
//         node->left = node->right;
//         node->right = tmp;
//         return;
//     }

//     TreeNode* invertTree(TreeNode* root) {
//         if(root != nullptr) invertSubTree(root);
//         return root;
//     }
// };

// // 题解二: 统一迭代法前序遍历
// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         stack<TreeNode*> st;
//         if(root != nullptr) st.push(root);
//         while(!st.empty()) {
//             TreeNode* node = st.top();
//             st.pop();
//             if(node == nullptr) {
//                 node = st.top();
//                 st.pop();
//                 swap(node->left, node->right); 
//             }
//             else {
//                 if(node->right) st.push(node->right);
//                 if(node->left) st.push(node->left);
//                 st.push(node);
//                 st.push(nullptr);
//             }
//         }
//         return root;
//     }
// };

// 题解三: 层序遍历法
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> qu;
        if(root != nullptr) qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            for(int i = 0; i < size; ++i) {
                TreeNode* node = qu.front();
                qu.pop();
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
                swap(node->left, node->right);
            }
        }
        return root;
    }
};
