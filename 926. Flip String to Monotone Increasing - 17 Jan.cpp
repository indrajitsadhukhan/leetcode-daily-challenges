class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size(),i=0;
        while(i<n && s[i]=='0')
            i++;
        int zero_to_one=0,one_count=0;
        for(;i<n ;i++)
        {
            if(s[i]=='0')
                zero_to_one++;
            else
                one_count++;
//             at every i we are taking the minimum either convert all 0->1 represented by zero_to_one or all 1->0 represented by one_count.
            zero_to_one=min(zero_to_one,one_count);
        }
        return zero_to_one;
    }
};