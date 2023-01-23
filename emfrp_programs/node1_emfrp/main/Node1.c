#include "Node1.h"
/* Primitive functions (Macros) */
/* Data types */
/* Global variables */
int node_memory_gpio16[2];
int node_memory_gpio17[2];
int Counter = 1;
int NodeSize = 1;
/* Static prototypes */
static int node_gpio17(int, int*);
static void refreshMark();
extern void Input(int*);
extern void Output(int*);
/* Functions, Constructors, GCMarkers, etc... */
static int node_gpio17(int gpio16, int* output) {
  *output = gpio16;
  return 1;
}
static void refreshMark() {
}

/*
void ActivateNode1() {
  int current_side = 0, last_side = 1;
  Counter = NodeSize + 1;
  refreshMark();
  while (1) {
    Counter = 1;
    Input(&node_memory_gpio16[current_side]);
    node_gpio17(node_memory_gpio16[current_side], &node_memory_gpio17[current_side]);
    Counter++;
    Output(&node_memory_gpio17[current_side]);
    refreshMark();
    current_side ^= 1;
    last_side ^= 1;
  }
}
*/
int current_side = 0, last_side = 1;
void InitNode1() {
  Counter = NodeSize + 1;
  refreshMark();
}

void ExecNode1() {
  Counter = 1;
  Input(&node_memory_gpio16[current_side]);
  node_gpio17(node_memory_gpio16[current_side], &node_memory_gpio17[current_side]);
  Counter++;
  Output(&node_memory_gpio17[current_side]);
  refreshMark();
  current_side ^= 1;
  last_side ^= 1;
}