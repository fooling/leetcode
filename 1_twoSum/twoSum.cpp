class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //to match
        std::set<int> against;
        //to exclude
        std::set<int> exclude;
        for (int i = 0 ;i < nums.size(); i++){
            if(against.find(nums[i]) == against.end()){
                against.insert(target-nums[i]); 
                if(target-nums[i]==nums[i]){
                    //exclude when nums[i] + nums[i] == target  but nums[i] only appear once
                    exclude.insert(nums[i]);
                }
                continue;
            }
            //found, insert last one
            against.insert(target-nums[i]);
            if(exclude.find(target-nums[i])!=exclude.end()){
                exclude.erase(target-nums[i]);
            }
            for(int j=0;j<i;j++){
                if(against.find(nums[j]) != against.end() && exclude.find(nums[j]) == exclude.end()){
                    std::vector<int> res;
                    res.push_back(j+1);
                    res.push_back(i+1);
                    return res;
                }
            }
        }
        
        //just in case
        std::vector<int> res1(2);
        return res1;
    }
};