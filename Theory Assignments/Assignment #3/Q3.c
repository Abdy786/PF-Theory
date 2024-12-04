// Question 03
// Create a program to validate an email address based on a few basic criteria. The program will
// prompt the user to enter an email address and will dynamically allocate memory to store and
// process the input. Define the following function:
// 1. int validateEmail(char* email): This function validates the email based on the following
// criteria:
//      ○ Contains exactly one @ symbol.
//      ○ Contains at least one dot (.) after the @ symbol. ○ Is non-empty. ○ Returns 1 if the email is valid, and 0 if invalid. Steps:
// 1. User Input: Prompt the user to enter an email address. Allocate memory dynamically for the
// email, ensuring the memory size is based on the input length. 
// 2. Validation Process:
//      ○ Call the validateEmail function to check if the email meets the criteria. 
// 3. Display Results:
//      ○ Print "Valid Email" if the email meets the criteria. ○ Print "Invalid Email" if the email does not meet the criteria.
// 4. Memory Cleanup:
//      ○ Free the dynamically allocated memory after validation to prevent memory leaks.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email){
    int at_count = 0;
    int dot_count = 0;
    
    int len = strlen(email);
    int index = len;
    for(int i=0; i<len; i++){
        if(email[i] == '@'){
            at_count += 1;
            index = i;
        }
        else if(email[i]=='.'){
        	if(i>index){
        		dot_count += 1;
			}
		}
        
    }
    if(at_count == 1 && dot_count >= 1 && len > 0){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char *email;
    email = (char *)malloc(50*sizeof(char));
    printf("Enter the email address: ");
    scanf("%s", email);
    int res = validateEmail(email);
    if(res){
        printf("Valid Email\n");
    }
    else{
        printf("Invalid Email\n");
    }
    free(email);
    return 0;
}
