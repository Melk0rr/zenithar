// INFO: DList to handle users

#include "user_dlist.h"

#include <stdio.h>
#include <stdlib.h>

// Function to create an empty user dlist : see user_dlist.h
UserDList * newUserDList()
{
  UserDList * newList =
      xmalloc(sizeof(*newList),
              "newUserDList::Failed to allocate memory for new user dlist");

  if (newList != NULL)
  {
    newList->length = 0;
    newList->begin = NULL;
    newList->end = NULL;
  }

  return newList;
}

// Function check if a User dlist is empty : see user_dlist.h
bool isUserDListEmpty(UserDList * uli) { return (!uli || !uli->end); }

// Function to return user dlist length : see user_dlist.h
int userDListLength(UserDList * uli)
{
  return (isUserDListEmpty(uli)) ? 0 : uli->length;
}

// Function to retreive first element of user dlist : see user_dlist.h
user * getFirstUserDListNode(UserDList * uli)
{
  if (isUserDListEmpty(uli))
  {
    fprintf(stderr, "getFirstUserDListNode::DList is empty, could not "
                    "retrieve first user node");
    exit(1);
  }

  return uli->begin->nodeUser;
}

// Function to retreive the last element of user dlist : see user_dlist.h
user * getLastUserDListNode(UserDList * uli)
{
  if (isUserDListEmpty(uli))
  {
    fprintf(stderr, "getLastUserDListNode::DList is empty, could not retrieve "
                    "last user node");
    exit(1);
  }

  return uli->end->nodeUser;
}

// Function to push a new user at the end of an user dlist : see user_dlist.h
UserDList * pushBackUserDList(UserDList * uli, user * const usr)
{
  UserDListNode * usrNode = xmalloc(
      sizeof(*usrNode),
      "pushBackUserDList::Memory allocation failed for new UserDListNode !");

  usrNode->nodeUser = usr;
  usrNode->prev = NULL;
  usrNode->next = NULL;

  if (isUserDListEmpty(uli))
  {
    uli = xmalloc(sizeof(*uli), "pusBackUserDList::Memory allocation failed for empty UserList !");

    // If dlist is empty : new node is the first and last element
    uli->begin = usrNode;
    uli->end = usrNode;
  }
  else
  {
    // If dlist is not empty : Last dlist element next pointer now points to
    // new node
    uli->end->next = usrNode;

    // New node prev pointer now points to the previous last dlist element
    usrNode->prev = uli->end;

    // And dlist end now points to the new node
    uli->end = usrNode;
  }

  uli->length++;
  return uli;
}

// Function to push a new user at the beginning of an user dlist : see
// user_dlist.h
UserDList * pushFrontUserDList(UserDList * uli, user * const usr)
{
  UserDListNode * usrNode = xmalloc(
      sizeof(*usrNode),
      "pushFrontUserDList::Memory allocation failed for new UserDListNode !");

  usrNode->nodeUser = usr;
  usrNode->prev = NULL;
  usrNode->next = NULL;

  if (isUserDListEmpty(uli))
  {
    uli = xmalloc(
        sizeof(*uli),
        "pushFrontUserDList::Memory allocation failed for empty UserList !");

    // If dlist is empty : new node is the first and last element
    uli->begin = usrNode;
    uli->end = usrNode;
  }
  else
  {
    // If dlist is not empty : Last dlist element next pointer now points to
    // new node
    uli->begin->prev = usrNode;

    // New node prev pointer now points to the previous last dlist element
    usrNode->next = uli->begin;

    // And dlist end now points to the new node
    uli->begin = usrNode;
  }

  uli->length++;
  return uli;
}

// Function to pop an user node from given list end : see user_dlist.h
UserDList * popBackUserDList(UserDList * uli)
{
  if (isUserDListEmpty(uli))
  {
    printf("popBackUserDList::List is empty. Nothing to pop.\n");
    return newUserDList();
  }

  // Check if the list contains only one element
  if (uli->begin == uli->end)
  {
    free(uli);
    uli = NULL;

    return newUserDList();
  }
  // Saves the last element
  UserDListNode * tmp = uli->end;

  // Last node is now the second to last
  uli->end = uli->end->prev;

  // The new last node next pointer is now NULL as it is the last element
  uli->end->next = NULL;

  // Deleting removed node links to prev and next
  tmp->next = NULL;
  tmp->prev = NULL;

  free(tmp);
  tmp = NULL;

  uli->length--;

  return uli;
}

// Function to pop a user node from given list beginning : see user_dlist.h
UserDList * popFrontUserDList(UserDList * uli)
{
  if (isUserDListEmpty(uli))
  {
    printf("popBackUserDList::List is empty. Nothing to pop.\n");
    return newUserDList();
  }

  // Check if the list contains only one element
  if (uli->begin == uli->end)
  {
    free(uli->begin->nodeUser);
    free(uli);
    uli = NULL;

    return newUserDList();
  }
  // Saves the first element
  UserDListNode * tmp = uli->begin;

  // First node is now the second to first
  uli->begin = uli->begin->next;

  // The new first node prev pointer is now NULL as it is the first element
  uli->begin->prev = NULL;

  // Deleting removed node links to prev and next
  tmp->next = NULL;
  tmp->prev = NULL;

  free(tmp->nodeUser);
  free(tmp);
  tmp = NULL;

  uli->length--;

  return uli;
}

// Function to remove a specific user from a user dlist : see user_dlist.h
UserDList * popUserFromDList(UserDList * uli, user * const usr)
{
  if (isUserDListEmpty(uli))
  {
    printf("popUserFromDList::List is empty, no user to pop");
    return newUserDList();
  }

  UserDListNode * tmp = uli->begin;

  while (tmp != NULL && &tmp->nodeUser != &usr)
  {
    tmp = tmp->next;
  }

  if (!tmp)
  {
    printf("popUserFromDList::Could not find the user to pop");
    return uli;
  }

  // If list only contains one element
  if (uli->begin == uli->end)
  {
    free(uli->begin->nodeUser);
    free(uli);
    uli = NULL;

    return newUserDList();
  }
  // If first in list
  else if (!tmp->prev)
  {
    uli->begin = tmp->next;
    uli->begin->prev = NULL;
  }
  // If last in list
  else if (!tmp->next)
  {
    uli->end = tmp->prev;
    uli->end->next = NULL;
  }
  else
  {
    // Pointing previous node to the next and vice versa
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;

    tmp->prev = NULL;
    tmp->next = NULL;

    free(tmp->nodeUser);
    free(tmp);
    tmp = NULL;
  }

  uli->length--;
  return uli;
}

// Function to find a user in a user dlist : see user_dlist.h
UserDListNode * findUserNodeByName(UserDList * const uli,
                                   char const * const usrName)
{
  UserDListNode * temp = (UserDListNode *)xmalloc(
      sizeof(*temp),
      "findUserNodeByName::Failed to allocate memory for temporary user node");

  if (!isUserDListEmpty(uli))
  {
    temp = uli->begin;

    while (temp != NULL && temp->nodeUser->userName != usrName)
      temp = temp->next;
  }

  return temp;
}

// Function to clear a user dlist content : see user_dlist.h
UserDList * clearUserDlist(UserDList * uli)
{
  while (!isUserDListEmpty(uli))
    uli = popBackUserDList(uli);

  return newUserDList();
}

// Function to print the content of an user dlist : see user_dlist.h
void printUserDList(UserDList * const uli)
{
  if (isUserDListEmpty(uli))
  {
    printf("printUserDlist::List is empty, nothing to print");
    return;
  }

  UserDListNode * temp = uli->begin;
  while (temp->next != NULL)
  {
    printf("%s : %f\n", temp->nodeUser->userName,
           temp->nodeUser->expenseList.sum);
    temp = temp->next;
  }
}

// Function to print the names of the users in a user dlist : see user_dlist.h
void printUserNames(UserDList * const uli)
{
  if (isUserDListEmpty(uli))
  {
    printf("printUserDlist::List is empty, nothing to print");
    return;
  }

  UserDListNode * temp = uli->begin;
  while (temp != NULL)
  {
    printf("%s\n", temp->nodeUser->userName);
    temp = temp->next;
  }
}
