#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// main input function- game loop will run until this function returns false
bool parseAndExecute(char *input)
{
   char *verb = strtok(input, " \n");

   if (verb != NULL)
   {
      if (strcmp(verb, "quit") == 0)
      {
         return false;
      }


      // feel
      else if (strcmp(verb, "feel") == 0)
      {
         printf("You feel around and find a lighter at your feet.\n");
      }

      

      // look
      else if (strcmp(verb, "look") == 0 && lightLevel == 0)
      {
         printf("It is very dark in here.\n");
      }
      else if (strcmp(verb, "look") == 0 && lightLevel >= 1)
      {
         printf("The room is small and made of stone. The ceiling is very low and there is a door.\n");
      }


      // go
      else if (strcmp(verb, "go") == 0)
      {
         printf("It's too dark to go anywhere.\n");
      }

      // area specific?
      // action
      else if (strcmp(verb, "light") == 0)
      {
	printf("You light the lighter.");
      }


      // unknown command handling
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

	FILE* fptr;

	fptr = fopen("inv.txt","w");

	if (fptr != NULL)
	{
		printf("inventory file created successfully!\n\n");
	}

	printf("Welcome to the game\n");

	while (parseAndExecute(input) && getInput());

	printf("\nBye!\n");
	return 0;

}
