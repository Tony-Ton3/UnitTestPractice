#include "Password.h"
#include <string>
#include <locale>
#include <cctype>
#include <cwctype>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  
  if(phrase.length() == 0) return 0;
  
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string phrase) {
  if(phrase.length() == 0) return false;
  bool hasUppercase = false;
  bool hasLowercase = false;
  for(int i = 0; i < phrase.length(); i++) {
    if(std::islower(phrase[i])) hasLowercase = true;
    if(std::isupper(phrase[i])) hasUppercase = true;
    if (hasUppercase && hasLowercase) break;
  }
  return hasUppercase && hasLowercase;
}