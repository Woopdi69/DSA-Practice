class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i : nums){
            auto [it, ins] = s.insert(i);

            if(!ins){
                return i;
            }
        }

        return -1;
    }
};