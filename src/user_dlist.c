#include "user_dlist.h"

#include <stdio.h>
#include <stdlib.h>

// Function to create an empty user dlist : see user_dlist.h
UserDList newUserDList()
{
  UserDList uli;
  return uli;
}

// Function check if a User dlist is empty : see user_dlist.h
bool isUserDListEmpty(UserDList uli)
{
  if (uli == NULL)
  {
    return true;
  }
  
  return false;
}

// Function to return user dlist length : see user_dlist.h
int userDListLength(UserDList uli)
{
  if (isUserDListEmpty(uli))
  {
    return 0;
  }
  
  return uli->length;
}

// Function to retreive first element of user dlist : see user_dlist.h
user getFirstUserDListNode(UserDList uli)
{
  if (isUserDListEmpty(uli))
  {
    exit(1);
  }

  return uli->begin->nodeUser;
}