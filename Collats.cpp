/*
 * Code by Ivan Petukhov
 */

#include <iostream>

using namespace std;

int KollatsCount(int n){
	int t = n;
	int count = 0;
	while(t != 1){
		if (t % 2 == 0){
			t /= 2;
		} else{
			t = 3 * t + 1;
		}
		count += 1;
	}
	return count;
}

int main(int argc, char* argv[])
{
	int L, R, i;
	int sum = 0;
	cin >> L;
	cin >> R;
	for (i = L; i < R + 1; i++)
		sum += KollatsCount(i);
	cout << sum;
    return 0;
}
