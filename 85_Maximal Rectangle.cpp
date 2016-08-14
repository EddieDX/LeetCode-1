/*
	LeetCode 85_Maximal Rectangle.cpp
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;



class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty())
			return 0;

		int m = matrix.size(), n = matrix[0].size();
		vector<int> heights(n, 0);
		int maxArea = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == '1')
				{
					++heights[j];
				}else{
					heights[j] = 0;
				}//else			
			}//for
			maxArea = max(maxArea, largestRectangleArea(heights));
		}//for
		return maxArea;
	}

	/*��ֱ��ͼ�����������������ջ*/
	int largestRectangleArea(vector<int> &heights)
 	{
		if (heights.empty())
			return 0;

		int n = heights.size();
		int maxArea = 0;
		stack<int> st;
		for (int i = 0; i < n; ++i)
		{
			/*��ǰ�߶ȸ���ջ������*/
			while (!st.empty() && heights[i] <= heights[st.top()])
			{
				//����ջ������������չ��Ӧ����󳤷������
				int idx = st.top();
				st.pop();
				int left = st.empty() ? -1 : st.top();
				int curArea = (i - left - 1)*heights[idx];

				maxArea = max(maxArea, curArea);
			}//if
			st.push(i);
		}//for

		/*����ջ��ʣ��Ԫ��*/
		while (!st.empty())
		{
			int idx = st.top();
			st.pop();

			int left = st.empty() ? -1 : st.top();
			int curArea = (n - left - 1)*heights[idx];

			maxArea = max(maxArea, curArea);
		}//while

		return maxArea;
	}
};

int main()
{
	vector<vector<char>> v = {{'1','0','1','1','1'},
							{'0','1','0','1','0'},
							{ '1','1','0','1','1' },
							{ '0','1','1','1','1' }
	};

	cout << Solution().maximalRectangle(v) << endl;

	system("pause");
	return 0;
}