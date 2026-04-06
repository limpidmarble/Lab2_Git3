#include<iostream>
#include<vector>

using namespace std;

int N,M;
vector<int> vec;

void printVector(vector<int>);
int iF (int n);
void stair(int,vector<int>&);

void func(int n, int m) {
	int i,j, nCm;
	nCm = iF(n)/iF(n-m)/iF(m);
	
	vec.resize(m);
	for (i=0;i<m;i++) vec[i]=i+1;	

	for (i=0;i<nCm;i++) {
		printVector(vec);
		for (j=1;j<=m;j++){//repeat m times
			if ((n-j+1)!=vec[m-j]) {
			vec[m-j] += 1;
			stair(m-j, vec);
			break;
			}
		}
	}
}

void stair(int k, vector<int>& v){
	for (k; k<v.size()-1; k++) {
	v[k+1] = v[k] + 1;
	}
}

void printVector(vector<int> vec) {
	for (int num : vec) {
		cout << num << " ";
	}
	cout << endl;
}

int iF(int n){ //only to recieve good int
	if (1==n) return 1;
	return n*iF(n-1);
}

int main() {
   cin >> N >> M;
   func(N,M);
}
