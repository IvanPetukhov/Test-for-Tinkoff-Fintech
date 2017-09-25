/*
 * Code by Ivan Petukhov
 */

#include <iostream>
#include <list>
#include <cmath>

using namespace std;

bool Prime(long long a)
{
    long long i1, i2, i3, i4, i5, i6, i7, i8, bound;
    if (a == 0 || a == 1)
        return false;
    if (a == 2 || a == 3 || a == 5 || a == 7 || a == 11 || a == 13 || a == 17 || a == 19 || a == 23 || a == 29)
        return true;
    if (a%2 == 0 || a%3 == 0 || a%5 == 0 || a%7 == 0 || a%11 == 0 || a%13 == 0 || a%17 == 0 || a%19 == 0 || a%23 == 0 || a%29 == 0)
        return false;
    bound = sqrt((double)a);
    i1 = 31; i2 = 37; i3 = 41; i4 = 43; i5 = 47; i6 = 49; i7 = 53; i8 = 59;
    while (i8 <= bound && a%i1 && a%i2 && a%i3 && a%i4 && a%i5 && a%i6 && a%i7 && a%i8)
    {
        i1 += 30; i2 += 30; i3 += 30; i4 += 30; i5 += 30; i6 += 30; i7 += 30; i8 += 30;
    }
    if (i8 <= bound ||
       i1 <= bound && a % i1 == 0 ||
       i2 <= bound && a % i2 == 0 ||
       i3 <= bound && a % i3 == 0 ||
       i4 <= bound && a % i4 == 0 ||
       i5 <= bound && a % i5 == 0 ||
       i6 <= bound && a % i6 == 0 ||
       i7 <= bound && a % i7 == 0)
           return false;
    return true;
}

int f(long long x, bool fl){
	if (Prime(x) && !fl)
		return 1;
	int a;
	for(a = x - 2; a >= 2; a--){
		if(Prime(a))
			break;
	}
	fl = false;
	return (1 + f(x - a, fl));
}

int main(){
    long long x;
	bool flagFirst = true;
	cin >> x;
	cout << f(x, flagFirst);
    return 0;
}