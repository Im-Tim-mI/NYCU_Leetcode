class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(0,nums,res);
        return res;

    }

    void solve(int index, vector<int>& nums, vector<vector<int>>& res){
        if(index==nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(index+1,nums,res);
            swap(nums[index],nums[i]);
        }
    }
};