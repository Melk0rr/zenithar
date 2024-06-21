#include <stdio.h>
#include <string.h>

void getSecureInput(char *prompt, char *buffer, int bufferSize)
{
  printf("%s", prompt);

  // Use fgets to read input and ensure it's null-terminated
  if (fgets(buffer, bufferSize, stdin) != NULL)
  {
    // Remove the newline character if present
    int len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
    {
        buffer[len - 1] = '\0';

    } else {
        // Clear the input buffer if input is longer than buffer size
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
    
  } else {
    fprintf(stderr, "getSecureInput::Error reading input\n");
    buffer[0] = '\0'; // Ensure buffer is empty on error
  }
}

int getSecureInputInt(char *prompt, int bufferSize)
{
  char buffer[bufferSize];
  int userInput;

  while (1)
  {
    getSecureInput(prompt, buffer, bufferSize);
    
    // Check if user input is valid otherwise ask again
    if (sscanf(buffer, "%d", &userInput) == 1)
    {
      return userInput;

    } else {
      printf("Invalid input. Please provide an integer\n");
    }
  }
}

signed char *getSecureInputSignedChar(char *prompt, int bufferSize)
{
  char buffer[bufferSize];
  signed char *userInput;
  
  while (1) 
  {
    getSecureInput(prompt, buffer, bufferSize);
    
    // Check if user input is valid otherwise ask again
    if (strlen(buffer) < bufferSize)
    {
      strcpy((char *)&userInput, buffer);
      return userInput;

    } else {
      printf("Input is too long. Please provide a shorter string\n");
    }
  }
}