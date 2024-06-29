#include "group.h"
#include "zenithar.h"

#include <json-c/json_object.h>
#include <json-c/json_types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creates a new group : see group.h
group *createGroup(const signed char *grpName)
{
  group *newGroup = (group *)malloc(sizeof(group));
  if (newGroup == NULL)
  {
    fprintf(stderr, "createGroup::Memory allocation failed !");
    exit(1);
  }
  
  // Change group name
  strncpy((char *)&newGroup->groupName, (char *)&grpName, sizeof(newGroup->groupName) - 1);
  newGroup->groupName[sizeof(newGroup->groupName) - 1] = '\0';
  
  newGroup->members = NULL;
  newGroup->memberCount = 0;

  return newGroup;
}

// Initializes group members : see group.h
void initGroupMembers(group *grp, user *members, int numberOfMembers)
{
  // Allocating memory
  grp->members = (user *)malloc(numberOfMembers * sizeof(user));
  if (grp->members == NULL)
  {
    fprintf(stderr, "initGroupMembers::Memory allocation failed !\n");
    exit(1);
  }
  grp->memberCount = numberOfMembers;

  // Copying new members into the group member list
  for (int i = 0; i < numberOfMembers; i++)
  {
    grp->members[i] = members[i];
  }
}

// Adds a new group into the given group : see group.h
void addGroupMember(group *grp, user *newMember)
{
  user *newMemberList = (user *)realloc(grp->members, (grp->memberCount + 1) * sizeof(user));
  if (newMemberList == NULL)
  {
    fprintf(stderr, "addGroupMember::Memory allocation failed !\n");
    exit(1);
  }
  
  // Update the group member list
  grp->members = newMemberList;

  // Adding the new user at the end of the member list
  grp->members[grp->memberCount] = *newMember;

  // Updating the member count
  grp->memberCount++;
}

// Sums the groups expenses : see group.h
float sumGroupExpenses(group *grp)
{
  int grpExpSum = 0;

  for (int i = 0; i < grp->memberCount; i++) {
    grpExpSum += grp->members[i].expenseSum;
  }

  return grpExpSum;
}

// Returns the share value based on current group expenses : see group.h
float getShare(group *grp) {
  float sumOfGrpExpenses = sumGroupExpenses(grp);
  return sumOfGrpExpenses / grp->memberCount;
}

// Print group balance : see group.h
void getGroupBalance(group *grp)
{
  float share = getShare(grp);

  for (int i = 0; i < grp->memberCount; i++) {
    user *m = &grp->members[i];
    float memberDue = m->expenseSum - share;
  
    char buffer[50];
    if (memberDue >= 0)
    {
		  sprintf(buffer, "%s %f", (const char *)m->userName, memberDue);
      printGreen(buffer);

    } else {
      sprintf(buffer, "%f %s", memberDue, m->userName);
      printRed(buffer);
    }
  }
}

// Resets group expenses
void resetGroupExpenses(group *grp)
{
  for (int i = 0; i; i++) {
    user *m = &grp->members[i];
    resetUserExpenses(m);
  }  
}