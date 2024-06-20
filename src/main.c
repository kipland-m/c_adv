#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct playerStruct {
	int playerHealth;
	int playerFatigue;
};


// defining struct for location, 
// where to create locations for game to access?
// create a function for each location will be the current approach.
struct location {
	char *description;
	int tag;
	int lightLevel;
};



// main input function- game loop will run until this function returns false
bool parseAndExecute(char *input, int *lightLevel)
{
   char *verb = strtok(input, " \n");

   bool doorOpen;
   doorOpen = false;

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
      else if (strcmp(verb, "look") == 0 && *lightLevel == 0)
      {
         printf("It is very dark in here.\n");
      }
      else if (strcmp(verb, "look") == 0 && *lightLevel >= 1)
      {
         printf("The room is small and made of stone. The ceiling is very low and there is a door.\n");
      }


      // go
      else if (strcmp(verb, "go") == 0 && *lightLevel < 1)
      {
         printf("It's too dark to go anywhere.\n");
      }

      else if (strcmp(verb, "go") == 0 && *lightLevel >= 1)
      {	
	printf("You approach the door and give it light tug. It doesn't budge."\n);
      }

      // area specific?
      // action
      else if (strcmp(verb, "light") == 0)
      {
	printf("You light the lighter.\n");
	*lightLevel = *lightLevel + 1;
      }

      else if (strcmp(verb, "pull") == 0 && *lightLevel >= 1)
      {
      	printf("You pull hard on the door and it opens. You take a step through the now opened doorway.\n");
      }


      // unknown command handling
      else
      {
         printf("I don't know how to '%s'.\n", verb);
      }
   }
   return true;
}

// input stores user input in input array, defaults to "look around"
static char input[100] = "look around";

// input function, updates above input array with user given value
static bool getInput(void){
	printf("\n--> ");
	return fgets(input, sizeof input, stdin) != NULL;
}

int main(){
	FILE* fptr;

	int lightLevel;

	lightLevel = 0;

	fptr = fopen("inv.txt","w");

	if (fptr != NULL)
	{
		printf("inventory file created successfully!\n\n");
	}

	printf("Welcome to the game\n");

	while (parseAndExecute(input, &lightLevel) && getInput());

	printf("\nBye!\n");
	return 0;

}
