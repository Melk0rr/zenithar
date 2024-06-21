#include "user.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creates a new user : see user.h
user *createUser(const signed char *usrName)
{
  user *newUser = (user *)malloc(sizeof(user));
  if (newUser == NULL)
  {
    fprintf(stderr, "createUser::Memory allocation failed !");
    exit(1);
  }
  
  // Changes new user's name and asusring null-termination
  strncpy((char *)&newUser->userName, (char *)&usrName, sizeof(newUser->userName) - 1);
  newUser->userName[sizeof(newUser->userName) - 1] = '\0';

  newUser->expenseList = NULL;
  newUser->expenseCount = 0;
  newUser->expenseSum = 0;

  return newUser;
}

// Adds an expense to user expense list : see user.h
void addExpense(user *usr, expense exp)
{
  expense *newExpenseList = (expense *)realloc(usr->expenseList, (usr->expenseCount + 1) * sizeof(expense));
  if (newExpenseList == NULL)
  {
    fprintf(stderr, "addExpense::Memory allocation failed !");
    exit(1);
  }
  
  // Update expense list
  usr->expenseList = newExpenseList;

  // Add new expense
  usr->expenseList[usr->expenseCount] = exp;

  // Update expense count
  usr->expenseCount++;
  
  sumUserExpenses(usr);
}

// Sums the given user expenses : see user.h
int sumUserExpenses(user *usr)
{
  int expSum = 0;

  for (int i = 0; i < usr->expenseCount - 1; i++)
  {
    expSum += usr->expenseList[i].expenseCost;
  }
  
  usr->expenseSum = expSum;
  return usr->expenseSum;
}