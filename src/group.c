#include "group.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
