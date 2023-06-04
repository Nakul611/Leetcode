class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
	long result=2147483647;
	vector<int> v;
	for(int i=0;i<nums.size();i++)
		if(nums[i]==1) 
			v.push_back(i);
			
	int n=v.size();
	vector<long> s={0};
	for(int i=0;i<n;i++)
		s.push_back(s.back()+v[i]);

	for(int i=k/2;i<n-(k-1)/2;i++){
		long current=k/2*v[i]-(s[i]-s[i-k/2])-k/2*(k/2+1)/2;
		current+=s[i+1+(k-1)/2]-s[i+1]-(k-1)/2*v[i]-(k-1)/2*((k-1)/2+1)/2;
		result=min(result,current);
	}
	return result;
    }
};