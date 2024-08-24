#include "group.h"
#include "user.h"
#include "utils.h"
#include "user_dlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #########################################################
// Group creation / initialization

// Creates a new group : see group.h
group *createGroup(const signed char *grpName)
{
  group *newGroup = malloc(sizeof(*newGroup));
  if (newGroup == NULL)
  {
    fprintf(stderr, "createGroup::Memory allocation failed !");
    exit(1);
  }
  
  // Change group name
  strncpy((char *)&newGroup->groupName, (char *)grpName, sizeof(newGroup->groupName) - 1);
  newGroup->groupName[sizeof(newGroup->groupName) - 1] = '\0';
  
  newGroup->members = NULL;

  return newGroup;
}

// Initializes group members : see group.h
void initGroupMembers(group *grp, user *members, int numberOfMembers)
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
void addGroupMember(group *grp, user *newMember)
{
  pushBackUserDList(grp->members, *newMember);
}

// Creates a new user and add it to the list of members : see group.h
void addNewGroupMember(group *grp, const signed char *userName)
{
  // Adding the new user at the end of the member list
  user newMember = *createUser(userName);
  addGroupMember(grp, &newMember);
}

// Removes the given user from members of the provided group : see group.h
void removeGroupMember(group *grp, user *member)
{
  popUserFromDList(grp->members, *member);
}

// Clears group members : see group.h
void clearGroupMembers(group *grp)
{
  clearUserDlist(grp->members);
}

// Prints the group member name : see group.h
void printMemberNames(group *grp)
{
  printUserNames(grp->members);
}

// #########################################################
// Group expenses

// Sums the groups expenses : see group.h
float sumGroupExpenses(group *grp)
{
  float grpExpSum = 0;

  UserDListNode *temp = grp->members->begin;
  while (temp->next != NULL)
  {
    grpExpSum += getUserExpenseSum(&temp->nodeUser);
    temp = temp->next;
  }

  printf("Group expenses: %f\n", grpExpSum);
  return grpExpSum;
}

// Returns the share value based on current group expenses : see group.h
float getShare(group *grp) {
  float sumOfGrpExpenses = sumGroupExpenses(grp);
  float share = sumOfGrpExpenses / grp->members->length;
  printf("Share for current expenses is: %f\n", share);

  return share;
}

// Print group balance : see group.h
void getGroupBalance(group *grp)
{
  float share = getShare(grp);

  UserDListNode *temp = grp->members->begin;
  while (temp->next != NULL)
  {
    float memberDue = temp->nodeUser.expenseSum - share;

    char buffer[50];
    if (memberDue >= 0)
    {
		  sprintf(buffer, "%s | +%f", (char *)temp->nodeUser.userName, memberDue);
      printGreen(buffer);

    } else {
      sprintf(buffer, "%f | %s", memberDue, temp->nodeUser.userName);
      printRed(buffer);
    }

    temp = temp->next;
  }
}

// Resets group expenses
void resetGroupExpenses(group *grp)
{
  for (int i = 0; i < grp->members->length; i++)
  {
    resetUserExpenses(grp->members[i]);
  }
}

// #########################################################
// Group utility

// Retreive a group member by name : see group.h
user *getMemberByName(group *grp, const signed char *userName)
{
  UserDListNode *temp = grp->members->begin;
  while (temp->next != NULL)
  {
    if (temp->nodeUser.userName == userName)
    {
      return &temp->nodeUser;
    }
    
    temp = temp->next;
  }

  return NULL;
}
