//Solution 1
class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		unordered_map<char, int> map;  //�����ַ�����ַ���s�������ֵ�λ��֮���ӳ��
		int left = -1; // ��߽磬ָ�򴰿ڵ�ǰһ��λ��
		int result = 0; //����
		for (int i = 0; i < s.size(); i++){
			//count:�жϵ�ǰ�ַ�s[i]�Ƿ���ֹ�
			//map[s[i]]>left�������ǰ�������ַ����ֹ��������ڴ����ڡ�
			//map�����Ǵ��ڣ����Ǽ�¼�ַ��ַ���������λ�õ��±�֮���ӳ�䣬left����ά������
			if (map.count(s[i]) && map[s[i]] > left)
				left = map[s[i]];

			map[s[i]] = i;
			result = max(result, i - left);
		}
		return result;
	}
};

//Solution 2
class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		vector<int> map(256, -1);
		int left = -1;
		int result = 0;
		for (int i = 0; i < s.size(); i++){

			if (map[s[i]] > left)
				left = map[s[i]];

			map[s[i]] = i;
			result = max(result, i - left);
		}
		return result;
	}
};