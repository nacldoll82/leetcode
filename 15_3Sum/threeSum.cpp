class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> solutionSet;
		vector<int> solution(3);

		sort(nums.begin(), nums.end());

		for (int first = 0; first < nums.size(); ++first) {
			if (first > 0 && nums[first-1] == nums[first])
				continue;

			int second = first + 1;
			int third = nums.size() - 1;

			while (second < third) {              
				int sum = nums[first] + nums[second] + nums[third];
				if (sum == 0) {
					solution[0] = nums[first];
					solution[1] = nums[second];
					solution[2] = nums[third];
					solutionSet.push_back(solution);

					while (second < third && solution[1] == nums[second])
						second++;
				}
				else if (sum < 0) {
					second++;
				}
				else {
					third--;
				}
			}
		}

		return solutionSet;
	}
};
