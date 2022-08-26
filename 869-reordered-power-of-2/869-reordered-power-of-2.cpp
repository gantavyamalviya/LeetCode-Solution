class Solution {
public:
    bool reorderedPowerOf2(int N) {
        long c = counter(N);
        for (int i = 0; i < 32; i++)
            if (counter(1 << i) == c){
                return true;
            }
        return false;
    }

    long counter(int N) {
        long res = 0;
        while (N) {
            res += pow(10, N % 10); 
            N/=10;
        }
        return res;
    }
};