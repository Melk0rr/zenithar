#include "user.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #########################################################
// User creation / initialization

// Creates a new user : see user.h
user *createUser(const signed char *usrName)
{
  user *newUser = (user *)malloc(sizeof(*newUser));
  if (newUser == NULL)
  {
    fprintf(stderr, "createUser::Memory allocation failed !");
    exit(1);
  }
  
  // Changes new user's name and asusring null-termination
  strncpy((char *)&newUser->userName, (char *)usrName, sizeof(newUser->userName) - 1);
  newUser->userName[sizeof(newUser->userName) - 1] = '\0';

  newUser->expenseList = NULL;
  newUser->expenseCount = 0;
  newUser->expenseSum = 0;

  return newUser;
}

// Adds an expense to user expense list : see user.h
void addNewUserExpense(user *usr, const signed char *expName, float expCost)
{
  expense **newExpenseList = realloc(usr->expenseList, (usr->expenseCount + 1) * sizeof(expense));
  if (newExpenseList == NULL)
  {
    fprintf(stderr, "addExpense::Memory allocation failed !");
    exit(1);
  }
  
  // Update expense list
  usr->expenseList = newExpenseList;

  // Add new expense
  expense newExp = *createExpense(expName, expCost);
  usr->expenseList[usr->expenseCount] = &newExp;

  // Update expense count
  usr->expenseCount++;
  
  sumUserExpenses(usr);
}

// #########################################################
// User expenses

// Sums the given user expenses : see user.h
void sumUserExpenses(user *usr)
{
  float expSum = 0;

  for (int i = 0; i < usr->expenseCount; i++)
  {
    expense *exp = usr->expenseList[i];
    expSum += exp->expenseCost;
  }
  
  usr->expenseSum = expSum;
}

// Resets given user expenses : see user.h
void resetUserExpenses(user *usr)
{
  usr->expenseList = NULL;
  usr->expenseCount = 0;
  usr->expenseSum = 0;
}