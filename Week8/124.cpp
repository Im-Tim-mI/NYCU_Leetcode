class Solution {
    public:
        int maxPathSum(TreeNode* root) {
            int maxSum = INT_MIN;
            maxGain(root, maxSum);
            return maxSum;
        }
    
    private:
        int maxGain(TreeNode* node, int& maxSum) {
            if (!node) return 0;
            int leftGain = max(0, maxGain(node->left, maxSum));
            int rightGain = max(0, maxGain(node->right, maxSum));
    
            int currentMax = node->val + leftGain + rightGain;
            maxSum = max(maxSum, currentMax);
    
            return node->val + max(leftGain, rightGain);
        }
    };
    