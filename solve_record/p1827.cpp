#include <iostream>
#include <vector>
#include <algorithm>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        int left_size = distance(inorder.begin(), it);
        //int left_size = it - inorder.begin();
        vector<int> pre1(preorder.begin() + 1, preorder.begin() + 1 + left_size);
        vector<int> pre2(preorder.begin() + 1 + left_size, preorder.end());
        vector<int> in1(inorder.begin(), it);
        vector<int> in2(it + 1, inorder.end());
        TreeNode * left = buildTree(pre1, in1);
        TreeNode * right = buildTree(pre2, in2);
        return new TreeNode(preorder[0], left, right);
    }
    
    void postorder(TreeNode * root) {
		if (root == nullptr) {
			return;
		}
		postorder(root->left);
		postorder(root->right);
		cout << root->val << " ";
	}
    
    
};

int main() {
    Solution sol;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = sol.buildTree(preorder, inorder);
    sol.postorder(root);
    return 0;
}

// 下面添加的内容只是为了测试
