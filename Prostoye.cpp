/*
 * Code by Ivan Petukhov
 */

#include <iostream>
#include <vector>

using namespace std;

void fillWithPrime(long long *arr, long long N){
	for (long long i = 0; i <= N; i++){
        arr[i] = i;
    }
	arr[1] = 0;
    for (long long p = 2; p <= N; p++){
        if (arr[p] != 0){
            for (long long j = p * p; j <= N; j += p)
                arr[j] = 0;
        }
    }
    return;
}

void findLeftNum(long long *arr, long long N, int K, int C){
	int countPrime;
	for(long long l = 1; l <= N; l++){
        countPrime = 0;
        for(long long j = l; j < K + l; j++){
            if(arr[j] != 0){
                ++countPrime;
            }
        }
        if (countPrime == C){
            cout << l << endl;
        }
    }
    cout << "-1"<< endl;
	return;
}

int main(){
    
    int Q, K, C;
	long long N = 100000;
    long long *arr = new long long[N + 1];

	fillWithPrime(arr, N);
    
    cin >> Q;
    
    for(int i = 0; i < Q; i++){
        cin >> K >> C;
		findLeftNum(arr, N, K, C);
        
    }

    return 0;
}
