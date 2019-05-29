/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* result = new ListNode(-1);
		ListNode* aux = result; //���������������м�����
		int carry = 0;
		while (l1 != nullptr || l2 != nullptr || carry != 0){

			int a = l1 ? l1->val : 0; //�ж�����ǰ�Ƿ�Ϊ�գ����Ϊ�գ���ֵΪ0
			int b = l2 ? l2->val : 0;
			int sum = a + b + carry;
			carry = sum / 10; //��λ��ȡģ�����
			aux->next = new ListNode(sum % 10); //ͨ��ȡģ������λ��Ӱ��
			aux = aux->next;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}

		return result->next;
	}
};