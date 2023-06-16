class Solution {
public:
    const long long mod = 1e9+7;
    vector<long long>fact;
    void calcFact(){
        fact[0] =1;
        fact[1] =1;
        for(long long i=2;i<1001;i++)
        fact[i] = (fact[i-1]*i)%mod;
    }

    long long modInv(long long n,long long p){
        if(p==0)
        return 1LL;
        long long ans = modInv(n,p/2);
        if(p&1)
        return (((ans*ans)%mod)*n)%mod;
        else
        return (ans*ans)%mod;
    }

    long long help(vector<int>&nums){
        if(nums.size()<=2)
        return 1LL;
        vector<int>small,large;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[0])
            large.push_back(nums[i]);
            else
            small.push_back(nums[i]);
        }
        long long ans =1;
        ans = (ans*fact[(int)nums.size()-1])%mod;
        ans =(ans*modInv(fact[(int)nums.size()-(int)small.size()-1],mod-2))%mod;
        ans = (ans*modInv(fact[(int)small.size()],mod-2))%mod;
        ans = (ans*help(small))%mod;
        ans = (ans*help(large))%mod;
        return ans;
    }
        int numOfWays(vector<int>& nums) {
            fact = vector<long long>(1001);
            calcFact();
            long long ans = help(nums);
            ans--;
            ans = (ans+mod)%mod;
            return ans;
    }
};