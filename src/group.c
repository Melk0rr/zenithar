// INFO: User group manipulations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "expense_dlist.h"
#include "group.h"
#include "user.h"
#include "user_dlist.h"
#include "utils.h"

// ************************************************************
// INFO: Group creation / initialization

// Creates a new group : see group.h
group * createGroup(char const * const grpName)
{
  group * const newGroup =
      xmalloc(sizeof(*newGroup),
              "createGroup::Failed to allocate memory for new group!");

  // Change group name
  strncpy((char *)&newGroup->groupName, grpName,
          sizeof(newGroup->groupName) - 1);
  newGroup->groupName[sizeof(newGroup->groupName) - 1] = '\0';

  newGroup->members = newUserDList();

  return newGroup;
}

// Initializes group members : see group.h
void initGroupMembers(group * const grp, user * const members,
                      size_t const numberOfMembers)
{
  // Clearing members
  grp->members = newUserDList();

  // Copying new members into the group member list
  for (int i = 0; i < numberOfMembers; i++)
  {
    addGroupMember(grp, &members[i]);
  }
}

// Adds a new group into the given group : see group.h
void addGroupMember(group * const grp, user * const newMember)
{
  grp->members = pushBackUserDList(grp->members, newMember);
}

// Creates a new user and add it to the list of members : see group.h
void addNewGroupMember(group * const grp, char const * const userName)
{
  // Adding the new user at the end of the member list
  user newMember = *createUser(userName);
  addGroupMember(grp, &newMember);
}

// Removes the given user from members of the provided group : see group.h
void removeGroupMember(group * const grp, user * const member)
{
  popUserFromDList(grp->members, member);
}

// Clears group members : see group.h
void clearGroupMembers(group * const grp) { clearUserDlist(grp->members); }

// Prints the group member name : see group.h
void printMemberNames(group * const grp) { printUserNames(grp->members); }

// ************************************************************
// INFO: Group expenses

// Sums the groups expenses : see group.h
static float sumGroupExpenses(group * const grp)
{
  float grpExpSum = 0;

  if (isUserDListEmpty(grp->members))
  {
    fprintf(
        stderr,
        "sumGroupExpenses::Member list is empty, no expense sum to compute\n");
    exit(1);
  }

  UserDListNode *temp = grp->members->begin;

  printExpenseDList(&temp->nodeUser->expenseList);

  while (temp != NULL)
  {
    grpExpSum += getUserExpenseSum(temp->nodeUser);
    temp = temp->next;
  }

  printf("Group expenses: %f\n", grpExpSum);
  return grpExpSum;
}

// Returns the share value based on current group expenses : see group.h
static float getShare(group * grp)
{
  float sumOfGrpExpenses = sumGroupExpenses(grp);
  float share = 0;

  if (isUserDListEmpty(grp->members))
  {
    fprintf(stderr, "getShare::Member list is empty, no share to compute\n");
    exit(1);
  }

  share = sumOfGrpExpenses / grp->members->length;
  printf("Share for current expenses is: %f\n", share);

  return share;
}

// Print group balance : see group.h
void getGroupBalance(group *grp)
{
  float share = getShare(grp);

  UserDListNode *temp = grp->members->begin;
  while (temp != NULL)
  {
    float memberDue = getUserExpenseSum(temp->nodeUser) - share;

    char buffer[50];
    if (memberDue >= 0)
    {
      sprintf(buffer, "%s | +%f", (char *)temp->nodeUser->userName, memberDue);
      printGreen(buffer);

    } else
    {
      sprintf(buffer, "%f | %s", memberDue, temp->nodeUser->userName);
      printRed(buffer);
    }

    temp = temp->next;
  }
}

// Resets group expenses
void resetGroupExpenses(group *grp)
{
  UserDListNode *temp = grp->members->begin;
  while (temp->next != NULL)
  {
    resetUserExpenses(temp->nodeUser);
    temp = temp->next;
  }
}

// ************************************************************
// INFO: Group utility

// Retreive a group member by name : see group.h
static user * getMemberByName(group * const grp, char const * const userName)
{
  UserDListNode *temp = grp->members->begin;
  while (temp->next != NULL)
  {
    if (temp->nodeUser->userName == userName)
    {
      return temp->nodeUser;
    }

    temp = temp->next;
  }

  return NULL;
}

