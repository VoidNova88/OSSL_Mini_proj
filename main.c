#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define TABLE_SIZE 1000

// function prototypes
void input_handler(char[], Task[]);
void display_menu();

//global variables
int cur_pos = 0;

// main function
int main(){

	Task records[TABLE_SIZE];
	char user_input[64] = "";
	while(strcmp(user_input, "99") != 0){
		display_menu();
		printf("\nSelect a menu > ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records);
		}
	
	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Task records[]){
// TODO: Modify this function as you need
	
	if(!strcmp(input, "1"))
		add_a_record(records, &cur_pos);
	else if(!strcmp(input, "2"))
		print_records(records, &cur_pos);	
	else if(!strcmp(input, "3"))
		create_record_from_file(records, &cur_pos);
	else if(!strcmp(input, "4"))
		read_record_from_file(records, &cur_pos);	
	else if(!strcmp(input, "99"))
		printf("Terminating... bye!\n"); 
	// Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

		// TODO: Modify this function as you need

		printf("************************\n");
		printf(" Task management system \n");
		printf("************************\n");
		printf(" 1. Add a new task\n");
		printf(" 2. Print task table\n");
		printf(" 3. Create task table\n");
		printf(" 4. Append task table\n");
		printf(" 5. Update task \n");
		printf(" 6. Delete task \n");
		printf(" 7. Arrange task table automatically\n");
		printf(" 99. Quit\n");
	    
		return;
}

