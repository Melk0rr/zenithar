
/**
 * @brief An expense with a name that describes it and a cost
 * 
 */
typedef struct expense
{
  signed char expenseName[256];
  int expenseCost;
} expense;