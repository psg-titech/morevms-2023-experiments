#include "TupleNode.h"
/* Primitive functions (Macros) */
/* Data types */
struct Tuple3_Bool_Int_Int{
  int mark;
  union {
    struct {
      int member0;
      int member1;
      int member2;
    }Tuple3;
  }value;
};
/* Global variables */
int node_memory_gpio16[2];
struct Tuple3_Bool_Int_Int* node_memory_anonymous340[2];
int node_memory_v[2];
int node_memory_gpio17[2];
struct Tuple3_Bool_Int_Int memory_Tuple3_Bool_Int_Int[1];
int size_Tuple3_Bool_Int_Int = 1;
int counter_Tuple3_Bool_Int_Int = 0;
int Counter = 1;
int NodeSize = 3;
/* Static prototypes */
static struct Tuple3_Bool_Int_Int* Tuple3_0(int, int, int);
static void mark_Tuple3_Bool_Int_Int(struct Tuple3_Bool_Int_Int*, int);
static int node_anonymous340(int, struct Tuple3_Bool_Int_Int**);
static int node_v(struct Tuple3_Bool_Int_Int*, int*);
static int node_gpio17(int, int*);
static void refreshMark();
extern void Input(int*);
extern void Output(int*);
/* Functions, Constructors, GCMarkers, etc... */
static struct Tuple3_Bool_Int_Int* Tuple3_0(int member0, int member1, int member2) {
  struct Tuple3_Bool_Int_Int* x;
  while (1) {
    counter_Tuple3_Bool_Int_Int++;
    counter_Tuple3_Bool_Int_Int %= size_Tuple3_Bool_Int_Int;
    if (memory_Tuple3_Bool_Int_Int[counter_Tuple3_Bool_Int_Int].mark < Counter) { x = memory_Tuple3_Bool_Int_Int + counter_Tuple3_Bool_Int_Int; break; }
  }
  x->mark = 0;
  x->value.Tuple3.member0 = member0;
  x->value.Tuple3.member1 = member1;
  x->value.Tuple3.member2 = member2;
  return x;
}
static void mark_Tuple3_Bool_Int_Int(struct Tuple3_Bool_Int_Int* x, int mark) {
  if (mark > x->mark) { x->mark = mark; }
}
static int node_anonymous340(int gpio16, struct Tuple3_Bool_Int_Int** output) {
  *output = Tuple3_0(gpio16, 1, 2);
  return 1;
}
static int node_v(struct Tuple3_Bool_Int_Int* anonymous340, int* output) {
  int _tmp000;
  if (1) {
    int pvar0_v = anonymous340->value.Tuple3.member0;
    int pvar0_a = anonymous340->value.Tuple3.member1;
    int pvar0_b = anonymous340->value.Tuple3.member2;
    _tmp000 = pvar0_v;
  }
  *output = _tmp000;
  return 1;
}
static int node_gpio17(int v, int* output) {
  *output = v;
  return 1;
}
static void refreshMark() {
  int i;
  for (i = 0; i < size_Tuple3_Bool_Int_Int; i++) {
    if (memory_Tuple3_Bool_Int_Int[i].mark < Counter) memory_Tuple3_Bool_Int_Int[i].mark = 0;
    else memory_Tuple3_Bool_Int_Int[i].mark -= Counter - 1;
  }
}
// MODIFIED
/*
void ActivateTupleNode() {
  int current_side = 0, last_side = 1;
  Counter = NodeSize + 1;
  refreshMark();
  while (1) {
    Counter = 1;
    Input(&node_memory_gpio16[current_side]);
    node_anonymous340(node_memory_gpio16[current_side], &node_memory_anonymous340[current_side]);
    mark_Tuple3_Bool_Int_Int(node_memory_anonymous340[current_side], Counter + 1);
    Counter++;
    node_v(node_memory_anonymous340[current_side], &node_memory_v[current_side]);
    Counter++;
    node_gpio17(node_memory_v[current_side], &node_memory_gpio17[current_side]);
    Counter++;
    Output(&node_memory_gpio17[current_side]);
    refreshMark();
    current_side ^= 1;
    last_side ^= 1;
  }
}
*/
int current_side = 0, last_side = 1;
void InitTupleNode() {
  Counter = NodeSize + 1;
  refreshMark();
}
void ExecTupleNode() {
  Counter = 1;
  Input(&node_memory_gpio16[current_side]);
  node_anonymous340(node_memory_gpio16[current_side], &node_memory_anonymous340[current_side]);
  mark_Tuple3_Bool_Int_Int(node_memory_anonymous340[current_side], Counter + 1);
  Counter++;
  node_v(node_memory_anonymous340[current_side], &node_memory_v[current_side]);
  Counter++;
  node_gpio17(node_memory_v[current_side], &node_memory_gpio17[current_side]);
  Counter++;
  Output(&node_memory_gpio17[current_side]);
  refreshMark();
  current_side ^= 1;
  last_side ^= 1;
}