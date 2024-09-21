#include <cctype>
#include <cstring>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

/** @note 'a' = 97 and 'A' = 65 */

void lowerCaseToUpperCase(char ch[], int length) {
  for (int i = 0; i < length; i++) {
    if (ch[i] >= 'a' && ch[i] <= 'z') { 
      //    ch[i] = ch[i]-32; // simple way
      ch[i] = ch[i] - 'a' + 'A'; // the trick in whatever case u want to convert
                                 // that case will in last 'A' for upper case
    }
  }
}

void upperCaseToLowerCase(char ch[], int length) {
  for (int i = 0; i < length; i++) {
    if (ch[i] >= 'A' && ch[i] <= 'Z') {
      //    ch[i] = ch[i]+32;
      ch[i] = ch[i] - 'A' + 'a';
    }
  }
}

int main() {
  char ch[100];

  cout << "enter your char array\n";
  cin.getline(ch, 100);
  int len = strlen(ch);

  lowerCaseToUpperCase(ch,len); // lower to upper case

//   upperCaseToLowerCase(ch, len); // uper to lower case
  cout << "the new char array is \n" << ch << endl;
  return 0;
}
