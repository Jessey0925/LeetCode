class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		int n1 = nums1.size();
		int n2 = nums2.size();
		int total = n1 + n2;

		if (total % 2){ //������������������ 
			return findKth(nums1, 0, nums2, 0, total / 2 + 1);
		}
		else{ //�����ż��
			return (findKth(nums1, 0, nums2, 0, total / 2) + findKth(nums1, 0, nums2, 0, total / 2 + 1)) / 2.0;
		}

	}

	//�ָ��˼��Ѱ�ҵ�k����
	double findKth(vector<int>& nums1, int l, vector<int>& nums2, int r, int k){

		int n1 = nums1.size();
		int n2 = nums2.size();

		if (n1 - l > n2 - r)
			return findKth(nums2, r, nums1, l, k); //ʼ�ձ�֤��һ�������Ǹ��������ٵ�

		if (n1 - l == 0)
			return nums2[r + k - 1];
		if (k == 1)
			return min(nums1[l], nums2[r]);

		int p1 = min(k / 2, n1); //��֤�ڵ�һ�������������ֲ��ҡ�
		int p2 = k - p1;

		if (nums1[l + p1 - 1] < nums2[r + p2 - 1]){ //���
			return findKth(nums1, l + p1, nums2, r, k - p1);
		}
		else if (nums1[l + p1 - 1] > nums2[r + p2 - 1]){ //�������1�ĸ���̫��
			return findKth(nums1, l, nums2, r + p2, k - p2);
		}
		else{
			return nums1[l + p1 - 1];
		}
	}
};