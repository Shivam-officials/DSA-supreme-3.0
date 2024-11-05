#include <iostream>
using namespace std;

// question
void removeConsecutiveDuplicates(char *input) {
  if (input[0] == '\0') {
    return;
  }
  if (input[0] == input[1]) {
    int i = 2;
    for (; input[i] != '\0'; i++) {
      input[i - 1] = input[i];
    }
    input[i - 1] = input[i];
  }
  removeConsecutiveDuplicates(input);
}
/*
Example:
xxab --> xab
*/

void removeConsecutiveDuplicatesAns(char *input) {
  if (input[0] == '\0') {
    return;
  }
  if (input[0] == input[1]) {
    int i = 2;
    for (; input[i] != '\0'; i++) {
      input[i - 1] = input[i];
    }
    input[i - 1] = input[i];

    removeConsecutiveDuplicatesAns(input);
  } else {
    removeConsecutiveDuplicatesAns(input + 1);
  }
}
/*
Example:
xxab --> xab
*/

int main(int argc, char const *argv[]) {
  char ch[] = "xxxxxaaaaabbb";
  removeConsecutiveDuplicatesAns(ch);
  cout << ch;
  return 0;
}
