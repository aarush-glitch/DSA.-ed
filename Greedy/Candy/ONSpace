class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1) return 1;
        vector<int>l(n);
        // vector<int>r(n);

        if(ratings[0]>ratings[1]) l[0]=2;
        else l[0]=1;
        for(int i=1; i<n; i++) {
            if(ratings[i] > ratings[i-1]) l[i]=l[i-1]+1;
            else l[i]=1;
        }

        // r[n-1]=l[n-1];
        int sum=l[n-1];
        for(int i=n-2; i>=0; i--) {
            if(ratings[i]>ratings[i+1]) {
                // r[i] = max(l[i], r[i+1]+1);
                l[i] = max(l[i], l[i+1]+1);
            }
            // else r[i]=l[i];
            // sum+=r[i];
            sum+=l[i];
        }

        return sum;
    }
};
