#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool parseAndExecute(char *input, int lightLevel)
{
   char *verb = strtok(input, " \n");

   if (verb != NULL)
   {
      if (strcmp(verb, "quit") == 0)
      {
         return false;
      }
      else if (strcmp(verb, "look") == 0 && lightLevel == 0)
      {
         printf("It is very dark in here.\n");
      }
      else if (strcmp(verb, "go") == 0)
      {
         printf("It's too dark to go anywhere.\n");
      }
      else
      {
         printf("I don't know how to '%s'.\n", verb);
      }
   }
   return true;
}

static char input[100] = "look around";

static bool getInput(void){
	printf("\n--> ");
	return fgets(input, sizeof input, stdin) != NULL;
}

int main(){
	// GAME VARIABLES
	int lightLevel = 0;
	int playerHealth = 0;
	
	printf("Welcome to the game\n");

	while (parseAndExecute(input, lightLevel) && getInput());

	printf("\nBye!\n");
	return 0;

}
