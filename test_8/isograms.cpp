// function show true if word is isogram
#include <iostream>
#include <cassert>

bool is_isogram(std::string str) {
  for ( int strLetter = 0; strLetter < str.size(); ++strLetter ) {
        char letter = str[strLetter];
            for ( int ch = strLetter+1; ch < str.size(); ++ch )
                    if (letter == str[ch]) return false;
              
  }
    return true;
}

int main()
{
  assert(is_isogram("Dermatoglyphics"));
  assert(is_isogram("moose"));
  assert(is_isogram("isIsogram"));
}
