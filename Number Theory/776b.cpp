/*
	Author - Devesh
	Problem - 776 B (CodeForces)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
   	if(n==1){
		cout << 1 << "\n" << 1 << endl;
		return 0;
	}
	if(n==2){
		cout << 1 << endl;
		cout << 1 << " " << 1;
		return 0;
	}
	++n;
	int ar[n];
	fill(ar, ar+n+1, 1);
	for(int i=2; i<=sqrt(n); i++){
		if(ar[i]){
			for(int j=i+i; j<=n; j+=i)
				ar[j] = 2;
		}
	}
	cout << 2 << endl;
	for(int i=2; i<=n; i++)
		cout << ar[i] << " ";
}
