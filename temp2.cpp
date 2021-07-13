#include<bits/stdc++.h>
using namespace std;
int prime = 2;
long long primePower = 1; // Init with 1
// Choosen Prime = 2
// primePower -> Holds accumulated prime^n values
long long hashStr(char str[], int index){
  if(index == strlen(str)){
    return 0;
  }
  primePower = primePower * prime;  // keep accumulating p powers
  if(index == 0)  // for first index we know p^0 = 1
    primePower = 1;
  return (str[index]-'a'+1) * primePower + hashStr(str, index+1);
}
int main(){
  char str[100];
  cin >> str;
  cout << hashStr(str, 0);
}