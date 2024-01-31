#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int generate_random_int(){
  return 0 + rand() % 9;
}

int main(void){
  char *words[] = {
    "random",
    "total",
    "xenophobia",
    "country",
    "species",
    "constitution",
    "programming",
    "vessel",
    "tachycardia",
    "cell",
  };
  srand(time(NULL));
  int chosen_word_index = generate_random_int();
  char *word_to_guess = words[chosen_word_index];
  printf("Word to guess: %s\n", word_to_guess);
  char *placeholder = malloc(strlen(word_to_guess)+1);
  if (placeholder == NULL){
    printf("Failed to allocate memory for placeholder\n");
    return 1;
  }
  char guess = ' ';
  int fails = 0;
  int guessed = 0;
  for ( int i = 0; i<strlen(word_to_guess); i++){
    placeholder[i] = '_';
  }
  placeholder[strlen(word_to_guess)] = '\0';
  while (1){
    int found = 0;
    printf("%s\n", placeholder);
    printf("Enter your guess> ");
    guess = getchar();
    while( getchar() != '\n');
    for (int i = 0; i < strlen(word_to_guess); i++){
      if(word_to_guess[i]==guess){
        found = 1;
        guessed++;
        placeholder[i] = guess;
      }
    }
    if (guessed == strlen(word_to_guess)){
      printf("Yay you won!!\n");
      break;
    }
    if (found==0){
      fails++;
      printf("The word to guess does not contain the character %c\n", guess);
    }
    if (fails==10){
      printf("You lost :( You failed to guess %s\n", word_to_guess);
      break;
    }
  };
  free(placeholder);
  return 0;
}
