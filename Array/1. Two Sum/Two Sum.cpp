
//Solution 1
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> results;

		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					results.push_back(i);
					results.push_back(j);

					return results;
				}
				else
				{
					continue;
				}
			}
		}
	}
};

//Solution 2
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		vector<int> results;

		//数组中的值作为map的键值，其下标作为对应的映射值
		for (int i = 0; i < nums.size(); i++)
		{
			m[nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			int t = target - nums[i];
			if (m.count(t) && m[t] != i) // 不能使用同样的数两次
			{
				results.push_back(i);
				results.push_back(m[t]);
				break;
			}
		}
		return results;
	}
};