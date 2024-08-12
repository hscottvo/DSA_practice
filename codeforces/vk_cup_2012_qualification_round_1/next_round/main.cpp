#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> vec;
	vec.reserve(n);

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		vec.push_back(val);
	}

	sort(vec.begin(), vec.end());

	// n-1 is 1
	// n-2 is 2
	int i;

	for (i = n - k; i >= 1; i--){
		if (vec.at(i) > vec.at(i-1))
			break;
	}

	for (; i < n; i++) {
		if (vec.at(i) > 0) 
			break;
	}

	cout << n - i << endl;


	return 0;
}
