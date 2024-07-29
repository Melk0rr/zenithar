#include "user.h"
#include "expense_dlist.h"

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

  newUser->expenseList = newExpenseDList();
  newUser->expenseSum = 0;

  return newUser;
}

// Adds an expense to user expense dlist : see user.h
void addNewUserExpense(user *usr, const signed char *expName, float expCost)
{
  // Add new expense
  expense newExp = *createExpense(expName, expCost);
  pushBackExpenseDList(usr->expenseList, newExp);
  
  sumUserExpenses(usr);
}

// #########################################################
// User expenses

// Sums the given user expenses : see user.h
void sumUserExpenses(user *usr)
{
  usr->expenseSum = sumDListExpenses(usr->expenseList);
}

// Resets given user expenses : see user.h
void resetUserExpenses(user *usr)
{
  usr->expenseList = clearExpenseDlist(usr->expenseList);
  usr->expenseSum = 0;
}