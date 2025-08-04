class Solution {
public:
// Shreya
    unordered_map<int, int> inorderMap;
    int postIdx;

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight) 
    {
        if (inLeft > inRight) return nullptr;

        int rootVal = postorder[postIdx--];
        TreeNode* root = new TreeNode(rootVal);
        int index = inorderMap[rootVal];

        root->right = helper(inorder, postorder, index + 1, inRight);
        root->left = helper(inorder, postorder, inLeft, index - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        postIdx = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); ++i) 
        {
            inorderMap[inorder[i]] = i;
        }
        return helper(inorder, postorder, 0, inorder.size() - 1); 
    }
};
