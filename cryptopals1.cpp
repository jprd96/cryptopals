#include "utils.h"
#include <iostream>

using namespace std;

int main() {
  string s1 = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  string s2 = hexToB64(s1);
  cout << s2 << endl;
  return 0;
}