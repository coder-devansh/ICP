class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        int left=0;
        int right=nums[0].size()-1;
        int top=0;
        int down=nums.size()-1;
        vector<int>ans;
        while(top<=down && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(nums[top][i]);


            }
            top++;
            for(int i=top;i<=down;i++){
                ans.push_back(nums[i][right]);

            }
            right--;
            if(top<=down){
                 for(int i=right;i>=left;i--){
                ans.push_back(nums[down][i]);
            }

            }
           
            down--;
            if(left<=right){
                for(int i=down;i>=top;i--){
                ans.push_back(nums[i][left]);
            }

            }
            
            left++;

        }
        return ans;
        
    }
};