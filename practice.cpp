int i = 1;
int sum = 0;
class Sum
{
public:
	Sum()
	{
		sum += i;
		++i;
	}
};

class Solution {
public:
	int Sum_Solution(int n) {
		Sum a[n];
		return sum;
	}
};
