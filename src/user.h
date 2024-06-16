#include "expense.h"

typedef struct user
{
  signed char userName[256];
  expense *expenseList;
} user;