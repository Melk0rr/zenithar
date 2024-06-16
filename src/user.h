#include "expense.h"

/**
 * @brief A user that makes expenses
 * 
 */
typedef struct user
{
  signed char userName[256];
  expense *expenseList;
  int expenseCount = 0;
} user;

/**
 * @brief Adds a new expense for the given user
 * 
 * @param usr {user} : user to whom add the new expense
 * @param exp {expense} : new expense to add
 */
void addExpense(user *usr, expense exp);