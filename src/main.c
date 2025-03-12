// INFO: Entry point

#include "group.h"

int main(int argc, char const *argv[])
{
  group *myGroup = createGroup((const signed char *)"My expense group");
  user *user1 = createUser((const signed char *)"Jo");
  user *user2 = createUser((const signed char *)"Lara");
  user *user3 = createUser((const signed char *)"Alex");
  user *user4 = createUser((const signed char *)"Louise");

  addGroupMember(myGroup, user1);
  addGroupMember(myGroup, user2);
  addGroupMember(myGroup, user3);
  addGroupMember(myGroup, user4);

  addNewUserExpense(user1, (const signed char *)"Peinture chambre", 53);
  addNewUserExpense(user2, (const signed char *)"Courses Lundi", 89.4);
  addNewUserExpense(user2, (const signed char *)"Vaccin Medor", 112.89);
  addNewUserExpense(user4, (const signed char *)"Loyer", 754.22);

  // printExpenseDList(&user2->expenseList);
  getGroupBalance(myGroup);

  return 0;
}
