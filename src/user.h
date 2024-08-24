#ifndef __USER__H__
#define __USER__H__

#include "expense.h"
#include "expense_dlist.h"

// #########################################################
// User struct definition

/**
 * @brief A user that makes expenses
 * 
 */
typedef struct user
{
  // Name of the user
  signed char userName[25];

  // List of the user expenses
  ExpenseDList expenseList;
} user;

// #########################################################
// Prototypes

/**
 * @brief Creates a new user
 * 
 * @param usrName {const signed char} : new user's name
 * @return user* : new user
 */
user *createUser(const signed char *usrName);

/**
 * @brief Adds a new expense for the given user
 * 
 * @param usr {user} : user to whom add the new expense
 * @param exp {expense} : new expense to add
 */
void addNewUserExpense(user *usr, const signed char *expName, float expCost);

/**
 * @brief Returns the given user expense sum
 * 
 * @param usr {user} : target user
 * @return float : sum of the expenses
 */
float getUserExpenseSum(user *usr);

/**
 * @brief Resets expenses for the given user
 * 
 * @param usr {user} : the user whom expenses will be reset
 */
void resetUserExpenses(user *usr);

#endif
