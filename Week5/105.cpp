class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int, int> inMap;
            for (int i = 0; i < inorder.size(); ++i)
                inMap[inorder[i]] = i;
            return build(preorder, 0, preorder.size() - 1,
                         inorder, 0, inorder.size() - 1,
                         inMap);
        }
    
    private:
        TreeNode* build(const vector<int>& preorder, int preL, int preR,
                        const vector<int>& inorder, int inL, int inR,
                        unordered_map<int, int>& inMap) {
            if (preL > preR) return nullptr;
    
            int rootVal = preorder[preL];
            TreeNode* root = new TreeNode(rootVal);
            int rootIndex = inMap[rootVal];
            int leftSize = rootIndex - inL;
    
            root->left = build(preorder, preL + 1, preL + leftSize,
                               inorder, inL, rootIndex - 1, inMap);
            root->right = build(preorder, preL + leftSize + 1, preR,
                                inorder, rootIndex + 1, inR, inMap);
            return root;
        }
    };
    