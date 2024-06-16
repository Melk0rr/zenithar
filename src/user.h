#include "expense.h"

/**
 * @brief A user that makes expenses
 * 
 */
typedef struct user
{
  signed char userName[256];
  expense *expenseList;
} user;