#include <iostream>
#include<string>  
using namespace std;

int main() {
  string a = "1";
  string b = "2";
  string c;
  cout << " enter c : "<< c;
  cin >> c;
  string sum = to_string(stoi(a) + stoi(b) + stoi(c));
  cout <<sum;


}