
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

		//�����е�ֵ��Ϊmap�ļ�ֵ�����±���Ϊ��Ӧ��ӳ��ֵ
		for (int i = 0; i < nums.size(); i++)
		{
			m[nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			int t = target - nums[i];
			if (m.count(t) && m[t] != i) // ����ʹ��ͬ����������
			{
				results.push_back(i);
				results.push_back(m[t]);
				break;
			}
		}
		return results;
	}
};