#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// function to determine the strength of a password
void evaluate(char password[], int size) {
	
	// declare variables
	int upper = 0; // used to determine if character is upper case
	int special = 0; // used to determine if character is a special character {!,#,$,^,&,@}
	int number = 0; // used to determine if character is a number
	
  while (1)
  {
    // get user input for the password
	  printf("Please enter a new password: "); // prompt
	  scanf("%s", password); // take input of type string and save to variable password
	
	  // find the size of the input
	  size = strlen(password); // strlen() from string.h library

	  // if statement to determine the characteristics of the password
	  if(size >= 6) { // if the password is at least six characters long
		
		  // for loop to iterate through array
		  for(int i = 0; i < size; i++)
		  {	
			  // check if character is upper case
			  if(isupper(password[i])) {
				  upper = 1; // if the character is upper case, set upper to true
			  }
			  else if (password[i] == '!' || password[i] == '#' || password[i] == '$' || password[i] == '^' || password[i] == '&' || password[i] == '@') {
				  special = 1; // if character is a special character, set special to true
			  }
			  else if(isdigit(password[i])) {
				  number = 1; // if character is a number, set number to true
			  } // end else if
		  } // end for loop
	  } // end if
	
	  // if all requirements are satisfied, print the specified message
	  if(upper == 1 && special == 1 && number == 1) {
			printf("The password is strong!\n");
      break;
	  } // end if
	
	  // if all requirements are not satisfied, display what the password needs
	  else {
		
		  printf("The password needs:\n");
		
		  // if the password is too short
		  if(size < 6) {
			  printf("     to have at least six characters.\n");
		  } // end if
		
		  // if the password does not have an upper case letter
		  if(upper == 0) {
			  printf("     at least one upper-case letter.\n");
		  } // end if
		
		  // if the password does not have any numbers
		  if(number == 0) {
			  printf("     at least one digit.\n");
		  } // end if
		
		  // if the password does not have any special characters
		  if(special == 0) {
			  printf("     at least one symbol from {!,@,#,$,^,&}.\n");
		  } // end if
    }
	} // end else
} // end method

// main method that serves as a driver for the program.  Takes user input (string), saves input to array of chars, determines size, and calls evaluate()
int main() {
	
	// declare variables
	char password[50]; // this is the array where the user inputed password will be stored
	int size = 0; // this will be the size of the string (array)
	
	// function call using the array and size as parameters
	evaluate(password, size);
	
	return 0;
	
} // end main