#include "expense.h"

/**
 * @brief A user that makes expenses
 * 
 */
typedef struct user
{
  // Name of the user
  signed char userName[25];
  
  // List of the user expenses
  expense *expenseList;
  
  // Number of expenses for memory allocation
  int expenseCount;
  
  // Sum of the user's expenses
  float expenseSum;
} user;

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
void addExpense(user *usr, expense exp);

/**
 * @brief Calculates the sum of a user's expenses
 * 
 * @param usr {user} : target user
 * @return int : sum of the expenses
 */
float sumUserExpenses(user *usr);

/**
 * @brief Resets expenses for the given user
 * 
 * @param usr {user} : the user whom expenses will be reset
 */
void resetUserExpenses(user *usr);