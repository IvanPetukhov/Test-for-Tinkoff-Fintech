/*
 * Code by Ivan Petukhov
 */

#include <iostream>
#include <list>

using namespace std;

int ColorCycle(int *arr, int *coloredArr, int N)
{
	int i = 0, l = 0;

	while(coloredArr[i] != 0)
		if (i < N)
			i++;
		else
			break;
	if (i >= N)
		return 0;

	while(coloredArr[i] == 0){
		coloredArr[i] = 1;
		l++;
		i = arr[i] - 1;
	}

	return l;
}

bool NullInArr(int *coloredArr, int N)
{
    for(int i = 0; i < N; ++i)
		if (coloredArr[i] == 0)
			return true;
	return false;
}

int main(int argc, char* argv[])
{
	int N, i;
	int sum = 0;
	int *arr, *coloredArr;
	list<int> ListSumm;
	list<int>::iterator iter;

	cin >> N;
	arr = new int[N];
	coloredArr = new int[N];
	for (i = 0; i < N; ++i){
		cin >> arr[i];
	    coloredArr[i] = 0;
	}

	while(NullInArr(coloredArr, N)){
		ListSumm.push_back(ColorCycle(arr, coloredArr, N));
	}

	ListSumm.sort();
	ListSumm.unique();
	for(iter = ListSumm.begin(); iter != ListSumm.end(); ++iter){
		sum += *iter;
	}

	cout << sum;
    return 0;
}