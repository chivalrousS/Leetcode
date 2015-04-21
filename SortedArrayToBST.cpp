// SortedArrayToBST.cpp : 定义控制台应用程序的入口点。
//


class Solution
{
	TreeNode* sortedArrayToBST(vector<int>& num)
	{
		return sortedArrayToBST(num.begin(),num.end());
	}

	template<typename RandomAccessIterator> TreeNode* sortedArrayToBST(RandomAccessIterator first,RandomAccessIterator last)
	{
		const auto len = distance(first,last);
		if(len <= 0)
			return nullptr;

		auto mid = first  + len/2;
		TreeNode* root = new TreeNode(*mid);
		root->left = sortedArrayToBST(first,mid);
		root->right = sortedArrayToBST(mid+1,last);
		return root;
	}
};
