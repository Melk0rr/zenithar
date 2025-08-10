// INFO: Utility functions

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

// Define ANSI escape codes for colors
#define RESET       "\x1b[0m"
#define BLACK       "\x1b[30m"
#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define BLUE        "\x1b[34m"
#define MAGENTA     "\x1b[35m"
#define CYAN        "\x1b[36m"
#define WHITE       "\x1b[37m"
#define BOLD        "\x1b[1m"

// ************************************************************
// INFO: Secure input utils

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
signed char *getSecureInputSignedChar(char *prompt, size_t bufferSize)
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

// ************************************************************
// INFO: Malloc utils

// Function to check malloc : see utils.h
void *xmalloc(size_t size, char const * const err)
{
  void *p = malloc(size);

  if (p == NULL)
  {
    fprintf(stderr, "%s", err);
    exit(EXIT_FAILURE);
  }

  return p;
}

// ************************************************************
// INFO: Color print utils

// Prints text in a certain color : see zenithar.h
void printInColor(const char *text, const char *color)
{
  printf("%s%s%s\n", color, text, RESET);
}

// Prints text in white : see zenithar.h
void printWhite(const char *text)
{
  printInColor(text, WHITE);
}

// Prints text in red : see zenithar.h
void printRed(const char *text)
{
  printInColor(text, RED);
}

// Prints text in green : see zenithar.h
void printGreen(const char *text)
{
  printInColor(text, GREEN);
}

// Prints text in yellow : see zenithar.h
void printYellow(const char *text)
{
  printInColor(text, YELLOW);
}

// Prints text in blue : see zenithar.h
void printBlue(const char *text)
{
  printInColor(text, BLUE);
}

