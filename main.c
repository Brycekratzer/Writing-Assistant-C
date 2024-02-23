#include<stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * The following prints out a menu for the user and then prompts them to 
 * Input a certain value
 * 
 * @param userChoice - is the users choice variable
*/
void PrintMenu(char* userChoice) {

   printf("\n\nMENU\n");
   printf("c - Number of non-whitespace characters\nw - Number of words");
   printf("\nf - Fix capitalization\nr - Replace all !'s\ns - Shorten spaces\nq - Quit\n\n");
   printf("Choose an option:\n");
   scanf("%*[\n]"); //clears buffer from previous input
   scanf("%c", userChoice); 
}

/**
 * Takes in the users sentence or phrase and then counts the number of characters
 * in the sentence and returns that value
 * 
 * @param userString - the users phrase or sentance
 * @return numChar - number of characters 
*/
int GetNumOfNonWSCharacters(const char* userString) {
   int numChar = 0;
   for(size_t i = 0; i < strlen(userString); ++i) {
      if(userString[i] != ' ' && userString[i] != '\n') {
         numChar++;
      }
   }
   return numChar;
}

/**
 * Takes in the users sentence or phrase and then counts the number of words
 * in the sentence and returns that value
 * 
 * @param userString - the users phrase or sentance
 * @return numWords - number of words
*/
int GetNumOfWords(const char* userString) {
   int numWords = 0;
   for(size_t i = 0; i < strlen(userString); ++i) {
      if(userString[i] != ' ') {
         while(i != strlen(userString) && userString[i] != ' '){ //increments 'i' once end of word is reached
            i++;
         }
         numWords++; //increments number of words after space is reached
      }
   }
   return numWords;
}

/**
 * Takes in the users sentence or phrase and then fixes the capitalization
 * in the sentence
 * 
 * @param userString - the users phrase or sentance
*/
void FixCapitalization(char* userString) {
   for(size_t i = 0; i < strlen(userString); ++i) {
   if(i == 0) { //for first word of whole phrase
      userString[i] = toupper(userString[i]);
   } else if(userString[i] == '.' || userString[i] == '?' || userString[i] == '!') { //searches if pointer is at end of sentence
         while(userString[i + 1] == ' ' && (i + 1) != strlen(userString) - 1){ //tries to find start of sentence
            i++;
         }
      userString[i + 1] = toupper(userString[i + 1]);
      }
   }
}

/**
 * Takes in the users sentence or phrase and then replace's
 * the '!' with '.'
 * 
 * @param userString - the users phrase or sentance
*/
void ReplaceExclamation(char* userString) {
   for(size_t i = 0; i < strlen(userString); ++i) {
      if(userString[i] == '!'){
         userString[i] = '.';
      }
   }
}

/**
 * Takes in the users sentence or phrase and checks
 * for spaces and determines if they need to be cut
 * down for being to long
 * 
 * @param userString - the users phrase or sentance
*/
void ShortenSpaces(char* userString) {
  int newIndex = 0;
  for (size_t i = 0; i < strlen(userString); ++i) {
    if (userString[i] != ' ' || (i > 0 && userString[i - 1] != ' ')) {//ensures that only consecutive spaces are removed
      userString[newIndex++] = userString[i];
    }
  }
  userString[newIndex] = '\0'; // Add null terminator at the end
}

//driver function
int main(void) {

   const size_t stringLength = 256;
   char userString[stringLength];
   char userChoice = 'd'; //sets to default option for loop

   printf("Enter a sample text:\n");
   if(fgets(userString, stringLength, stdin) != 0) {
      userString[stringLength] = '\0';
      
   }

   printf("\n");
   printf("You entered: %s\n", userString);

   while(userChoice != 'q') {
      PrintMenu(&userChoice);
      if(userChoice == 'c') {
         printf("Number of non-whitespace characters: %d", GetNumOfNonWSCharacters(userString));
      } else if(userChoice == 'w'){
         printf("Number of words: %d", GetNumOfWords(userString));
      } else if(userChoice == 'f'){
         FixCapitalization(userString);
         printf("Edited text: %s\n", userString);
      } else if(userChoice == 'r'){
         ReplaceExclamation(userString);
         printf("Edited text: %s\n", userString);
      } else if(userChoice == 's'){
         ShortenSpaces(userString);
         printf("Edited text: %s\n", userString);
      } else if(userChoice != 'q'){
         printf("Error: Unknown option selected");
      }
   }
   return 0;
}