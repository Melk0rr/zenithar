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
