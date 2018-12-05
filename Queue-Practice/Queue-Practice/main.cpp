//二叉树的层序遍历
class Solution {
public:
	int High(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int left = High(root->left);
		int right = High(root->right);

		return left > right ? left + 1 : right + 1;
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> vv;
		if (root == NULL)
		{
			return vv;
		}
		vv.resize(High(root));
		level.push(0);
		t_queue.push(root);
		while (!t_queue.empty())
		{
			TreeNode* top = t_queue.front();
			int tmp = level.front();
			level.pop();
			vv[tmp].push_back(top->val);
			t_queue.pop();
			if (top->left)
			{
				t_queue.push(top->left);
				level.push(tmp + 1);
			}
			if (top->right)
			{
				t_queue.push(top->right);
				level.push(tmp + 1);
			}
		}
		return vv;
	}
private:
	queue<TreeNode*>t_queue;
	queue<int>level;

};

//数组中第K个最大元素
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> pqueue(nums.begin(), nums.end());
		while (--k)
		{
			pqueue.pop();
		}
		return pqueue.top();
	}
};


//在每个树中找最大值

class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		vector<int> num;
		if (root == NULL)
		{
			return num;
		}
		_q.push(root);
		while (!_q.empty())
		{
			auto size = _q.size();
			int max = _q.front()->val;
			while (size--)
			{
				TreeNode* tmp = _q.front();
				_q.pop();
				if (tmp->val > max)
				{
					max = tmp->val;
				}
				if (tmp->left)
				{
					_q.push(tmp->left);
				}
				if (tmp->right)
				{
					_q.push(tmp->right);
				}
			}
			num.push_back(max);
		}
		return num;
	}
private:
	queue<TreeNode*> _q;
};

//二叉树的层平均值
class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> average;
		queue<TreeNode*> q;
		q.push(root);
		long int sum = 0;
		int size;
		while (!q.empty())
		{
			sum = 0;
			size = (int)q.size();
			int ret = size;
			while (ret--)
			{
				TreeNode* tmp = q.front();
				q.pop();
				sum += tmp->val;
				if (tmp->left)
				{
					q.push(tmp->left);
				}
				if (tmp->right)
				{
					q.push(tmp->right);
				}
			}
			average.push_back((double)sum / size);
		}
		return average;
	}

};