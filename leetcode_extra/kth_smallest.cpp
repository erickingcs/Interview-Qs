#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N, M, K;
int A[1000], B[1000];

int theKth()
{
	int AL = 0, AR = N;
	int BL = 0, BR = M;
	while (AL <= AR && BL <= BR)
	{
		int i = double(AR - AL) / (AR - AL + BR - BL) * (K - 1);
		int j = K - 1 - i;
		int Ai = (i + AL == N) ? INT_MAX : A[AL + i];
		int Ai_1 = (AL + i > 0) ? A[AL + i - 1] : INT_MIN;
		int Bj = (j + BL == M) ? INT_MAX : B[BL + j];
		int Bj_1 = (BL + j > 0) ? B[BL + j - 1] : INT_MIN;
		cout << i << ' ' << j << endl;
		cout << Ai_1 << ' ' << Ai << ' ' << Bj_1 << ' ' << Bj << endl;
		if (Bj_1 < Ai && Ai < Bj)
		{
			return Ai;
		} else if (Ai_1 < Bj && Bj < Ai)
		{
			return Bj;
		}
		if (Ai < Bj_1) 
		{
			AL += i + 1;
			K -= i + 1;
		} else
		{
			BL += j + 1;
			K -= j + 1;
		}
		cout << AL << ' ' << AR << ' ' << BL << ' ' << BR << ' ' << K << endl;
	}
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> B[i];
	
	cin >> K;
	cout << theKth();
}

