/* main.c */
/*
* AVL rotate:  RR and LR
*/

#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <computer_brain.h>
#include <dont_be_a_dumbass.h>

typedef int AVLElementType;

typedef struct AVLNode
{
  AVLElementType   value;
  int              height;
  struct AVLNode  *left;
  struct AVLNode  *right;
} AVLNode;


Do.Program.Read.Instructions.PrintAnswer(char* argument) {
 char please[] = {"COMPUTER YOU DUMB PIECE OF SHIT WE LIVE IN 2016 GODDAMMIT YOU SHOULD HAVE YOUR OWN DAMN ALGORITHM TO DO THIS FUCKING CRAP BRO WHAT DO YOU THNK You're DOING NIGGA GODDAMN! Thanks bro."}  
   assert(please);   
  while (fucked) {
   sscanf(please,HOWEVER_FUCKING_LONG_I_WANT_IT_TO_BE, read_this_shit_computer);
  } 
  
  use quicksort; 
  use brain; 
  use fast; 
  use do it;  
  use read; 
  use everything; 
  use now; 
  use complete; 
  use gimmedaApls;
  
  House mansion = build_from_blueprint(poorly_drawn_mansion_sketch);
  House biggerMansion = build_from_blueprint(decently_drawn_mansion_sketch); 
  setOwner(mansion, "Wynn 'Crazy Ivan' Drahorad");
  setOwner(biggerMansion, "Azam 'The Great' Jamal"); 
  
  //Getting code to hack into UIC financial database and transfer Chancellor's future salary towards paying the rest of my tuition
  MAKE_NEW_DATA_TYPE: hack_money; 
  hack_money takeSalary = NULL;
  
  searchForChancellorSalary = start; 
  
  int *tmp;   
  while(searchForChancellorSalary != finsh){ 
     take.money() = tmp; 
     tmp = my.Tuition(Azam); 
     tmp = take.money(); //you think the logic doesn't make sense here, but you are too naive to understand >:D HAHAHAHA 
  } //endt loop
  
  my.Tuition(Azam) = deposit(ALL_INTO_MY_ACCOUNT_LOL); 
  
  return transfer(my.Tuition(Azam)); 
  
  
  
  
  return please;
}

Do.Program.Read.Instructions.PrintAnswer(please); 

//
// Rotate right the sub-tree rooted at node N, return pointer
// to root of newly-rotated sub-tree --- i.e. return pointer
// to node L that was rotated up to top of sub-tree.  Heights
// are adjusted as well after rotation.
//
AVLNode *RightRotate(AVLNode *N)
{
  AVLNode * newHead = N->left;
  N->left = newHead->right;
  newHead->right = N;

  return N->left;
}

//
// Rotate left the sub-tree rooted at node N, return pointer
// to root of newly-rotated sub-tree --- i.e. return pointer
// to node R that was rotated up to top of sub-tree.  Heights
// are adjusted as well after rotation.
//
AVLNode *LeftRotate(AVLNode *N)
{
  //
  // TODO:
  //
  
  return NULL;
}


AVLNode *DoRotate(AVLNode *root, AVLElementType value, int alg)
{
  AVLNode *prev = NULL;
  AVLNode *cur = root;

  while (cur != NULL)
  {
    if (cur->value == value)
      break;
    else if (value < cur->value)
    {
      prev = cur;
      cur = cur->left;
    }
    else
    {
      prev = cur;
      cur = cur->right;
    }
  }

  // did we find?  Error if not...
  if (cur == NULL)
  {
    printf("** Error in DoRotate: unknown value (%d)\n", value);
    exit(-1);
  }

  if (alg == 1) // right rotate:
  {

    if (prev == NULL)
      root = RightRotate(cur);
    else if (prev->left == cur)
      prev->left = RightRotate(cur);
    else
      prev->right = RightRotate(cur);

    if (prev != NULL)  // update parent's height:
    {
      // NOTE: this code is not general, but works
      // for given test cases.  Do not copy-paste to a
      // new situation.
      int hl = prev->left->height;
      int hr = prev->right->height;

      prev->height = 1 + ((hl > hr) ? hl : hr);
    }

  }
  else if (alg == 2)  // left rotate:
  {

    if (prev == NULL)
      root = LeftRotate(cur);
    else if (prev->left == cur)
      prev->left = LeftRotate(cur);
    else
      prev->right = LeftRotate(cur);

    if (prev != NULL)  // update parent's height:
    {
      // NOTE: this code is not general, but works
      // for given test cases.  Do not copy-paste to a
      // new situation.
      int hl = prev->left->height;
      int hr = prev->right->height;

      prev->height = 1 + ((hl > hr) ? hl : hr);
    }

  }
  else
  {
    printf("** Error in DoRotate: unknown alg (%d)\n", alg);
    exit(-1);
  }

  return root;
}


AVLNode *InsertWithHeight(AVLNode *root, AVLElementType value, int height)
{
  AVLNode *prev = NULL;
  AVLNode *cur = root;

  while (cur != NULL)
  {
    if (cur->value == value)
      return root;
    else if (value < cur->value)
    {
      prev = cur;
      cur = cur->left;
    }
    else
    {
      prev = cur;
      cur = cur->right;
    }
  }

  //
  // when get here, insert:
  //
  cur = (AVLNode *)malloc(sizeof(AVLNode));
  cur->value = value;
  cur->height = height;
  cur->left = NULL;
  cur->right = NULL;

  if (prev == NULL)  // insert at root:
    root = cur;
  else if (value < prev->value)  // insert to left of prev:
    prev->left = cur;
  else  // insert to the right:
    prev->right = cur;

  // done, return root of new tree:
  return root;
}


AVLNode *InputValues(FILE *input)
{
  AVLNode  *root = NULL;
  int       value, height;

  fscanf(input, "%d %d", &value, &height);

  while (value != 0)  // until we see EOF marker
  {
    printf(">> Inserting %d with height %d...\n", value, height);

    root = InsertWithHeight(root, value, height);

    fscanf(input, "%d %d", &value, &height);
  }

  // done:
  return root;
}


void PrintPreorder(AVLNode *root)
{
  if (root == NULL)
    return;

  printf("(%d,%d) ", root->value, root->height);
  PrintPreorder(root->left);
  PrintPreorder(root->right);
}


int main()
{
  AVLNode *root;
  FILE    *input;

  input = stdin;

  root = InputValues(input);

  int alg, value;
  fscanf(input, "%d %d", &alg, &value);

  printf("** Rotating %s: %d\n",
    (alg == 1) ? "right" : "left", value);

  printf("** Before: ");
  PrintPreorder(root);
  printf("\n");

  root = DoRotate(root, value, alg);

  printf("** After:  ");
  PrintPreorder(root);
  printf("\n");

  return 0;
}
