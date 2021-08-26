//

#include <iostream>
#include <algorithm>

using namespace std;

string a[20000];
int n;

int getSum(string a) {
	int length = a.length();
	int sum = 0;
	for(int i=0; i < length; i++)
	{
		if(a[i] - '0' <= 9 && a[i] - '0' >= 0) {
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool compare(string a, string b) {
	// 길이가 짧은 것이 우선
	if(a.length() < b.length())
		return 1;
	else if(a.length() > b.length()) 
		return 0;
	// 자릿수의 합이 작은 합을 가진 것이 우선 
	else {
		int aSum = getSum(a);
		int bSum = getSum(b);
		if(aSum != bSum) {
			return aSum < bSum;
		} else { // 사전순으로 작은 것이 우선 
			return a < b;
		}	
	}
}

int main () {
	
	cin >> n;
	for(int i=0; i<n;i++)
	{
		cin >> a[i];
	}
	
	sort(a,a+n,compare);
	
	for(int i=0; i < n; i++)
	{
		// 동일한 단어는 패스하고 출력
		if(i > 0 && a[i] == a[i-1]) continue;
		cout << a[i] << '\n';
	}
	
	return 0;
}
