#include <stdlib.h>

/*
 * Implementation of one stack node with create and delete functions
 */
typedef struct StackNode
{
  struct StackNode* next;
  void* value;
} StackNode;

StackNode* stack_node_create(void* value)
{
  StackNode* node = malloc(sizeof(StackNode));
  node->value = value;
  node->next = NULL;
  return node;
}

void inline stack_node_delete(StackNode* node)
{
  free(node->value);
  free(node);
}

void stack_node_delete_subnodes(StackNode* node)
{
  if (node->next != NULL)
  {
    stack_node_delete_subnodes(node->next);
  }
  stack_node_delete(node);
}

/*
 *  Stack implementation
 */
typedef struct Stack
{
  StackNode* root;
} Stack;

Stack* stack_create()
{
  Stack* stack = malloc(sizeof(Stack));
  stack->root = NULL;
  return stack;
}

void stack_delete(Stack* stack)
{
  if (stack->root == NULL)
  {
    free(stack);
  } else
  {
    stack_node_delete_subnodes(stack->root);
    free(stack);
  }
}

void stack_push(Stack* stack, void* value)
{
  if (stack->root != NULL)
  {
    StackNode* node = stack->root;
    while (node->next != NULL)
    {
      node = node->next;
    }
    node->next = stack_node_create(value);
  } else
  {
    stack->root = stack_node_create(value);
  }
}

void* pop(Stack* stack)
{
  StackNode* node = stack->root;
  void* value = node->value;
  stack->root = node->next;
  free(node);
  return value;
}

int inline stack_is_empty(Stack* stack)
{
  return (stack->root == NULL) ? 1 : 0;
}
