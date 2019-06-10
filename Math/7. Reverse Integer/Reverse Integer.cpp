//Solution 1
class Solution {
public:
	int reverse(int x){
		long long res = 0;
		while (x != 0){
			int t = res * 10 + x % 10;
			if (t / 10 != res)
				return 0;
			res = t;
			t /= 10;
		}
		return res;
	}
};

//Solution 2
class Solution {
public:
	int reverse(int x){
		std::string str = std::to_string(x);
		if (str[0] == '-')
			std::reverse(str.begin() + 1, str.end());
		else
			std::reverse(str.begin(), str.end());
		try{
			return stoi(str);
		}
		catch (out_of_range ex){
			return 0;
		}
	}
};