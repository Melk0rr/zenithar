#include <stdio.h>
#include <string.h>

// Generic part to get user input : see zenithar.h
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

// Ask user input for an integer : see zenithar.h
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

// Ask user input for a signed char : see zenithar.h
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

// Prints text in a certain color : see zenithar.h
void printInColor(const char *text, int color)
{
  if (30 <= color && color <= 37)
  {
    printf("\x1B[%dm%s\x1B[0m", color, text);
  }
}

// Prints text in red : see zenithar.h
void printRed(const char *text)
{
  printInColor(text, 31);
}

// Prints text in green : see zenithar.h
void printGreen(const char *text)
{
  printInColor(text, 32);
}

// Prints text in yellow : see zenithar.h
void printYellow(const char *text)
{
  printInColor(text, 33);
}

// Prints text in blue : see zenithar.h
void printBlue(const char *text)
{
  printInColor(text, 34);
}