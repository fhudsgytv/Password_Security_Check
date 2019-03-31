#include<stdio.h>

#define WORDLENGTH 32
#define MINIMUM_LENGTH 8
#define MAXIMUM_LENGTH 14
#define REPEATITIVE_NUM 3

int main(){

  //declare the variables
  int lengthValue = 0, repeatValue = 0, digitValue = 1, lowercaseValue = 1, uppercaseValue =1;
  int count = 0, stringLength = 0;
  char string[WORDLENGTH], c;


  // get user input and store the into array called string
  printf("Please enter a password string: \n");
  while(1){
    c = getchar();

    if (c == '\n'){
      break;
    }
    else{
      string[stringLength] = c;
      stringLength++;
    }
  }


  if(stringLength > MAXIMUM_LENGTH){
    printf("Your password string \"%s\" is invalid, because: \n", string);
    printf("* it does not contain at most %d characters\n", MAXIMUM_LENGTH);
    return 0;
  }

  //check whether the password fits the requirements
  for (int i = 0; i < stringLength; i++){
    if (stringLength < MINIMUM_LENGTH){
      lengthValue = 1;
    }
    if (64 < string[i] && string[i] < 91){
      uppercaseValue = 0;
    }
    if (96 < string[i] && string[i] < 123){
      lowercaseValue = 0;
    }
    if (47 < string[i] && string[i] < 58){
      digitValue = 0;
    }
    if(string[i] < 48 || string[i] > 122){
      printf("Your password string \"%s\" is invalid, because: \n", string);
      printf("* it does not only contain letters and digits\n");
      return 0;
    }
    if(string[i] > 57 && string[i] < 65){
      printf("Your password string \"%s\" is invalid, because: \n", string);
      printf("* it does not only contain letters and digits\n");
      return 0;
    }
    if(string[i] > 90 && string[i] < 97){
      printf("Your password string \"%s\" is invalid, because: \n", string);
      printf("* it does not only contain letters and digits\n");
      return 0;
    }
  }

    for (int i = 0; i < stringLength; i ++){
      for(int j = i+1; j < stringLength; j++){
        if (string[i] == string[i+j]){
          count++;
        }
        // if REPEATITIVE_NUM characters are the same, then the password is unsecure
        if (count == REPEATITIVE_NUM - 1){
          repeatValue = 1;
          goto output;
        }

        if(j == stringLength - 1){
          count = 0;
        }
      }
    }


  // giving the output
  output:
      printf("Your password string \"%s\" is ", string);

    if (lengthValue || repeatValue || digitValue || lowercaseValue || uppercaseValue){
      printf("not secure, because:\n");
      if (lengthValue){
        printf("* it does not contain at least %d characters\n", MINIMUM_LENGTH);
      }
      if (uppercaseValue){
        printf("* it does not contain an uppercase letter\n");
      }
      if (lowercaseValue){
        printf("* it does not contain a lowercase letter\n");
      }
      if (digitValue){
        printf("* it does not contain a digit\n");
      }
      if(repeatValue){
        printf("* it contains %d repeatitive characters\n", REPEATITIVE_NUM);
      }
    }
    else{
      printf("secure\n");
    }

  return 0;
}
