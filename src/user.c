// INFO: Users manipulations

#include <string.h>

#include "expense_dlist.h"
#include "user.h"

// ************************************************************
// INFO: User creation / initialization

// Creates a new user : see user.h
user * createUser(char const * const usrName)
{
  user * newUser = (user *)xmalloc(
      sizeof(*newUser), "createUser::Failed to allocate memory for new user");

  // Changes new user's name and asusring null-termination
  strncpy((char *)&newUser->userName, usrName, sizeof(newUser->userName) - 1);

  newUser->userName[sizeof(newUser->userName) - 1] = '\0';
  newUser->expenseList = *newExpenseDList();

  return newUser;
}

// Adds an expense to user expense dlist : see user.h
void addNewUserExpense(user * const usr, char const * const expName, float const expCost)
{
  // Add new expense
  expense * newExp = createExpense(expName, expCost);
  usr->expenseList = *pushBackExpenseDList(&usr->expenseList, newExp);
}

// ************************************************************
// INFO: User expenses

// Sums the given user expenses : see user.h
float getUserExpenseSum(user * usr) { return usr->expenseList.sum; }

// Resets given user expenses : see user.h
void resetUserExpenses(user * usr)
{
  usr->expenseList = *clearExpenseDlist(&usr->expenseList);
}
