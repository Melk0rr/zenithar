
/**
 * @brief An expense with a name that describes it and a cost
 * 
 */
typedef struct expense
{
  signed char expenseName[256];
  int expenseCost;
} expense;

/**
 * @brief Create a Expense struct
 * 
 * @param expName {signed char} name of the new expense
 * @param cost {int} cost of the expense
 * @return struct expense* 
 */
expense *createExpense(const signed char *expName, int cost);