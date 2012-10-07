class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < n; i++)
        {
            while (A[i] != i + 1 && A[i] > 0 && A[i] <= n)
            {
                int tmp = A[i];
                if (A[tmp - 1] != tmp) swap(A[i], A[tmp - 1]);
                else break;
            }
        }
        for (int i = 0; i < n; i++)
            if (A[i] != i + 1) return i + 1;
        return n + 1;
    }
};
