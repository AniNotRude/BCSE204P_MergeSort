#include<iostream>
#include<vector>
using namespace std;
void Merge(vector<int>& v, int s, int m, int e) {
	vector<int> temp;
	int i, j, t;
	i = s;
	j = m + 1;
	int cnt = 0;
	while (i <= m && j <= e) {
		if (v[i] <= v[j]) {
			temp.push_back(v[i]);
			++i;
		}
		else {
			temp.push_back(v[j]);
			++j;
		}
		cnt++;	
	}
	while (i <= m) {
		temp.push_back(v[i]);
		++i;
	}
	while (j <= e) {
		temp.push_back(v[j]);
		++j;
	}
	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];
}
void MergeSort(vector<int>& v, int s, int e) {
	int cnt;
	if (s < e) {
		int m = (s + e) / 2;
		MergeSort(v, s, m);
		MergeSort(v, m + 1, e);
		Merge(v, s, m, e);
	}
}
int main() {
	int n;
	vector<int> v;
	cout << "Enter number of elements: ";
	cin >> n;
	v = vector<int>(n);
	cout << "\nEnter Element: ";
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	MergeSort(v, 0, n - 1);
	cout << "\nSorted Elements: ";
	for (int i = 0; i < n; ++i) {
		cout << v[i] << ' ';
	}
	return 0;
}
