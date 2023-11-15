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
Password::Password() {
  pass_history.push_back("ChicoCA-95929");
}

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

/*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
*/
void Password::set(string phrase) {
  int passwordLength = phrase.length();
  int leadingCharacters = count_leading_characters(phrase);
  bool hasMixedCase = has_mixed_case(phrase);

  bool previouslyUsed = false;
  if(passwordLength >= 8 && leadingCharacters <= 3 && hasMixedCase) {
    for(int i = 0; i < (int)pass_history.size(); i++){
      if(pass_history[i] == phrase) {
        previouslyUsed = true;
        break;
      }
    }
  } else {
    return;
  }
  if(!previouslyUsed) {
    pass_history.push_back(phrase);
  }
  return;
}

/*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
*/
bool Password::authenticate(string phrase) {
  if (pass_history.size() == 0) return false;
  return pass_history[pass_history.size() - 1 ] == phrase ? true : false;
}