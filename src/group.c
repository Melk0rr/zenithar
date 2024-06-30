#include "group.h"
#include "zenithar.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #########################################################
// Group creation / initialization

// Creates a new group : see group.h
group *createGroup(const signed char *grpName)
{
  group *newGroup = malloc(sizeof(group));
  if (newGroup == NULL)
  {
    fprintf(stderr, "createGroup::Memory allocation failed !");
    exit(1);
  }
  
  // Change group name
  strncpy((char *)&newGroup->groupName, (char *)grpName, sizeof(newGroup->groupName) - 1);
  newGroup->groupName[sizeof(newGroup->groupName) - 1] = '\0';
  
  newGroup->members = NULL;
  newGroup->memberCount = 0;

  return newGroup;
}

// Initializes group members : see group.h
void initGroupMembers(group *grp, user *members, int numberOfMembers)
{
  // Allocating memory
  grp->members = malloc(numberOfMembers * sizeof(user));
  if (grp->members == NULL)
  {
    fprintf(stderr, "initGroupMembers::Memory allocation failed !\n");
    exit(1);
  }
  grp->memberCount = numberOfMembers;

  // Copying new members into the group member list
  for (int i = 0; i < numberOfMembers; i++)
  {
    grp->members[i] = &members[i];
  }
}

// Adds a new group into the given group : see group.h
void addGroupMember(group *grp, user *newMember)
{
  user **newMemberList = realloc(grp->members, (grp->memberCount + 1) * sizeof(user));
  if (newMemberList == NULL)
  {
    fprintf(stderr, "addGroupMember::Memory allocation failed !\n");
    exit(1);
  }
  
  // Update the group member list
  grp->members = newMemberList;

  // Adding the new user at the end of the member list
  grp->members[grp->memberCount] = newMember;

  // Updating the member count
  grp->memberCount++;
}

// Creates a new user and add it to the list of members : see group.h
void addNewGroupMember(group *grp, const signed char *userName)
{
  user **newMemberList = realloc(grp->members, (grp->memberCount + 1) * sizeof(user));
  if (newMemberList == NULL)
  {
    fprintf(stderr, "addGroupMember::Memory allocation failed !\n");
    exit(1);
  }
  
  // Update the group member list
  grp->members = newMemberList;

  // Adding the new user at the end of the member list
  user newMember = *createUser(userName);
  grp->members[grp->memberCount] = &newMember;

  // Updating the member count
  grp->memberCount++;
}

// Removes the given user from members of the provided group : see group.h
int removeGroupMember(group *grp, user *member)
{
  int i;
  
  // Find out member index
  for (i = 0; i < grp->memberCount; i++)
  {
    if (grp->members[i] == member)
    {
      break;
    }
  }

  if (i >= grp->memberCount)
  {
    char buffer[60];
    sprintf(buffer, "Error: user %s is not a member of group %s", member->userName, grp->groupName);
    printRed(buffer);
    return -1;
  }

  // Remove the member
  printf("Removing %s from %s\n", member->userName, grp->groupName);
  --grp->memberCount;
  for (int j = i; j < grp->memberCount; j++)
  {
    grp->members[j] = grp->members[j + 1];
  }
  
  grp->members[grp->memberCount] = NULL;
  free(grp->members[grp->memberCount]);
  
  return 0;
}

// Prints the group member name : see group.h
void printMemberNames(group *grp)
{
  printf("Members of %s are:\n", grp->groupName);
  for (int i = 0; i < grp->memberCount; i++)
  {
    printf("%s\n", grp->members[i]->userName);
  }
}

// #########################################################
// Group expenses

// Sums the groups expenses : see group.h
float sumGroupExpenses(group *grp)
{
  float grpExpSum = 0;

  for (int i = 0; i < grp->memberCount; i++)
  {
    user *m = grp->members[i];
    grpExpSum += m->expenseSum;
  }

  printf("Group expenses: %f\n", grpExpSum);
  return grpExpSum;
}

// Returns the share value based on current group expenses : see group.h
float getShare(group *grp) {
  float sumOfGrpExpenses = sumGroupExpenses(grp);
  float share = sumOfGrpExpenses / grp->memberCount;
  printf("Share for current expenses is: %f\n", share);

  return share;
}

// Print group balance : see group.h
void getGroupBalance(group *grp)
{
  float share = getShare(grp);

  for (int i = 0; i < grp->memberCount; i++)
  {
    user *m = grp->members[i];
    float memberDue = m->expenseSum - share;
  
    char buffer[50];
    if (memberDue >= 0)
    {
		  sprintf(buffer, "%s | +%f", (char *)m->userName, memberDue);
      printGreen(buffer);

    } else {
      sprintf(buffer, "%f | %s", memberDue, m->userName);
      printRed(buffer);
    }
  }
}

// Resets group expenses
void resetGroupExpenses(group *grp)
{
  for (int i = 0; i < grp->memberCount; i++)
  {
    resetUserExpenses(grp->members[i]);
  }  
}

// #########################################################
// Group utility

// Retreive a group member by name : see group.h
user *getMemberByName(group *grp, const signed char *userName)
{
  for (int i = 0; i < grp->memberCount; i++)
  {
    if (grp->members[i]->userName == userName)
    {
      return grp->members[i];
    }
  }

  return NULL;
}