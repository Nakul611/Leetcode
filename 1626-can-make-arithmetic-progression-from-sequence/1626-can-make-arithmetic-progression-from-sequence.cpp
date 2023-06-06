class Solution {
public:
    bool canMakeArithmeticProgression1(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int c = arr[0]-arr[1];
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i]-arr[i+1] != c)
                return false;
        }
        return true;
    }
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int num : arr) {
            mini = min(mini, num);
            maxi = max(maxi, num);
        }

        double diff = static_cast<double>(maxi-mini)/(n-1);

        for (int i=0;i<n;i++) {
            double c = mini + i * diff;
            bool d = false;
            for (int num : arr) {
                if (abs(num - c) < 1e-9) {
                    d = true;
                    break;
                }
            }
            if (!d) {
                return false;
            }
        }
        return true;
    }
};