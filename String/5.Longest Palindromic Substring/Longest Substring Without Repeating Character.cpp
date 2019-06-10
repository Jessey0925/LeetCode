//Solution 1
class Solution {
public:
	string longestPalindrome(string s) {

		int nLength = s.size();
		if (nLength<1)
			return s;
		vector<vector<bool> > dp(nLength, vector<bool>(nLength, 0)); //dp[i][j]��ʾ�Ӵ�s[i,...,j]�Ƿ���һ�������Ӵ�
		int strBegin = 0;  //�����Ӵ��Ŀ�ʼ
		int strEnd = 0; //�����Ӵ��Ľ�β

		//��ʼ��
		for (int i = 1; i < nLength; i++){
			dp[i][i] = true;
			dp[i][i - 1] = true;  //���������Ӵ�����Ϊ2��"bb"��"aa"�����
		}
		dp[0][0] = true;

		//��̬�滮
		for (int i = 2; i <= nLength; i++){ //���ĳ���
			for (int j = 0; j <= nLength - i; j++){  //�����Ӵ���ʼ

				if (s[j] == s[i + j - 1] && dp[j + 1][i + j - 2]){
					dp[j][j + i - 1] = true;
					if (strEnd - strBegin + 1 < i){
						strBegin = j;
						strEnd = i + j - 1;
					}
				}
			}
		}

		return s.substr(strBegin, strEnd - strBegin + 1);
	}
};

//Solution 2
class Solution {
public:
	string longestPalindrome(string s) {

		int nLength = s.size();
		if (nLength == 1)
			return s;

		int strBegin = 0;
		int maxLength = 0;
		for (int i = 1; i < nLength; i++){

			//��������Ӵ�����������iΪ��������
			int left = i - 1;
			int right = i + 1;
			while (left >= 0 && right < nLength && s[left] == s[right])
			{
				left--;
				right++;
			}

			if (right - left - 1 > maxLength){ //right -1 - (left + 1) + 1
				maxLength = right - left - 1;
				strBegin = left + 1;
			}

			//��������Ӵ���ż��,
			left = i - 1;
			right = i;
			while (left >= 0 && right < nLength && s[left] == s[right]){
				left--;
				right++;
			}

			if (right - left - 1 > maxLength){
				maxLength = right - left - 1;
				strBegin = left + 1;
			}
		}
		return s.substr(strBegin, maxLength);
	}
};

//Solution 3
class Solution {
public:
	string longestPalindrome(string s) {

		if (s.size() <= 1)
			return s;

		string dummy = init(s);
		int nLength = dummy.size();

		int maxLen = 0;
		int mx = 0;
		int id = 0;
		vector<int> len(nLength, 0);

		for (int i = 1; i< nLength - 1; i++){
			if (i < mx)
				len[i] = min(len[2 * id - i], mx - i);
			else
				len[i] = 1;

			while (dummy[i - len[i]] == dummy[i + len[i]])
				len[i] ++;

			if (mx < i + len[i]){
				id = i;
				mx = i + len[i];
			}
		}

		int index = 0;
		for (int i = 1; i < nLength - 1; i++){
			if (len[i] > maxLen){
				maxLen = len[i];
				index = i;
			}
		}
		return s.substr((index - maxLen) / 2, maxLen - 1);

	}


	//��ʼ��
	string init(const string& s){
		string result = "$#";
		int nLength = s.size();

		for (int i = 0; i < nLength; i++){

			result.push_back(s[i]);
			result.push_back('#');
		}

		return result;
	}
};