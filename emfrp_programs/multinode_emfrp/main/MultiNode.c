#include "MultiNode.h"
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
int node_memory_node0[2];
struct Tuple3_Bool_Int_Int* node_memory_anonymous360[2];
int node_memory_node1[2];
struct Tuple3_Bool_Int_Int* node_memory_anonymous380[2];
int node_memory_node2[2];
struct Tuple3_Bool_Int_Int* node_memory_anonymous400[2];
int node_memory_node3[2];
struct Tuple3_Bool_Int_Int* node_memory_anonymous420[2];
int node_memory_node4[2];
struct Tuple3_Bool_Int_Int* node_memory_anonymous440[2];
int node_memory_node5[2];
struct Tuple3_Bool_Int_Int* node_memory_anonymous460[2];
int node_memory_node6[2];
struct Tuple3_Bool_Int_Int* node_memory_anonymous480[2];
int node_memory_node7[2];
struct Tuple3_Bool_Int_Int* node_memory_anonymous500[2];
int node_memory_node8[2];
struct Tuple3_Bool_Int_Int* node_memory_anonymous520[2];
int node_memory_node9[2];
int node_memory_gpio17[2];
struct Tuple3_Bool_Int_Int memory_Tuple3_Bool_Int_Int[1];
int size_Tuple3_Bool_Int_Int = 1;
int counter_Tuple3_Bool_Int_Int = 0;
int Counter = 1;
int NodeSize = 21;
/* Static prototypes */
static struct Tuple3_Bool_Int_Int* Tuple3_0(int, int, int);
static void mark_Tuple3_Bool_Int_Int(struct Tuple3_Bool_Int_Int*, int);
static int node_anonymous340(int, struct Tuple3_Bool_Int_Int**);
static int node_node0(struct Tuple3_Bool_Int_Int*, int*);
static int node_anonymous360(int, struct Tuple3_Bool_Int_Int**);
static int node_node1(struct Tuple3_Bool_Int_Int*, int*);
static int node_anonymous380(int, struct Tuple3_Bool_Int_Int**);
static int node_node2(struct Tuple3_Bool_Int_Int*, int*);
static int node_anonymous400(int, struct Tuple3_Bool_Int_Int**);
static int node_node3(struct Tuple3_Bool_Int_Int*, int*);
static int node_anonymous420(int, struct Tuple3_Bool_Int_Int**);
static int node_node4(struct Tuple3_Bool_Int_Int*, int*);
static int node_anonymous440(int, struct Tuple3_Bool_Int_Int**);
static int node_node5(struct Tuple3_Bool_Int_Int*, int*);
static int node_anonymous460(int, struct Tuple3_Bool_Int_Int**);
static int node_node6(struct Tuple3_Bool_Int_Int*, int*);
static int node_anonymous480(int, struct Tuple3_Bool_Int_Int**);
static int node_node7(struct Tuple3_Bool_Int_Int*, int*);
static int node_anonymous500(int, struct Tuple3_Bool_Int_Int**);
static int node_node8(struct Tuple3_Bool_Int_Int*, int*);
static int node_anonymous520(int, struct Tuple3_Bool_Int_Int**);
static int node_node9(struct Tuple3_Bool_Int_Int*, int*);
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
static int node_node0(struct Tuple3_Bool_Int_Int* anonymous340, int* output) {
  int _tmp000;
  if (1) {
    int pvar0_node0 = anonymous340->value.Tuple3.member0;
    int pvar0_a0 = anonymous340->value.Tuple3.member1;
    int pvar0_b0 = anonymous340->value.Tuple3.member2;
    _tmp000 = pvar0_node0;
  }
  *output = _tmp000;
  return 1;
}
static int node_anonymous360(int node0, struct Tuple3_Bool_Int_Int** output) {
  *output = Tuple3_0(node0, 1, 2);
  return 1;
}
static int node_node1(struct Tuple3_Bool_Int_Int* anonymous360, int* output) {
  int _tmp001;
  if (1) {
    int pvar1_node1 = anonymous360->value.Tuple3.member0;
    int pvar1_a1 = anonymous360->value.Tuple3.member1;
    int pvar1_b1 = anonymous360->value.Tuple3.member2;
    _tmp001 = pvar1_node1;
  }
  *output = _tmp001;
  return 1;
}
static int node_anonymous380(int node1, struct Tuple3_Bool_Int_Int** output) {
  *output = Tuple3_0(node1, 1, 2);
  return 1;
}
static int node_node2(struct Tuple3_Bool_Int_Int* anonymous380, int* output) {
  int _tmp002;
  if (1) {
    int pvar2_node2 = anonymous380->value.Tuple3.member0;
    int pvar2_a2 = anonymous380->value.Tuple3.member1;
    int pvar2_b2 = anonymous380->value.Tuple3.member2;
    _tmp002 = pvar2_node2;
  }
  *output = _tmp002;
  return 1;
}
static int node_anonymous400(int node2, struct Tuple3_Bool_Int_Int** output) {
  *output = Tuple3_0(node2, 1, 2);
  return 1;
}
static int node_node3(struct Tuple3_Bool_Int_Int* anonymous400, int* output) {
  int _tmp003;
  if (1) {
    int pvar3_node3 = anonymous400->value.Tuple3.member0;
    int pvar3_a3 = anonymous400->value.Tuple3.member1;
    int pvar3_b3 = anonymous400->value.Tuple3.member2;
    _tmp003 = pvar3_node3;
  }
  *output = _tmp003;
  return 1;
}
static int node_anonymous420(int node3, struct Tuple3_Bool_Int_Int** output) {
  *output = Tuple3_0(node3, 1, 2);
  return 1;
}
static int node_node4(struct Tuple3_Bool_Int_Int* anonymous420, int* output) {
  int _tmp004;
  if (1) {
    int pvar4_node4 = anonymous420->value.Tuple3.member0;
    int pvar4_a4 = anonymous420->value.Tuple3.member1;
    int pvar4_b4 = anonymous420->value.Tuple3.member2;
    _tmp004 = pvar4_node4;
  }
  *output = _tmp004;
  return 1;
}
static int node_anonymous440(int node4, struct Tuple3_Bool_Int_Int** output) {
  *output = Tuple3_0(node4, 1, 2);
  return 1;
}
static int node_node5(struct Tuple3_Bool_Int_Int* anonymous440, int* output) {
  int _tmp005;
  if (1) {
    int pvar5_node5 = anonymous440->value.Tuple3.member0;
    int pvar5_a5 = anonymous440->value.Tuple3.member1;
    int pvar5_b5 = anonymous440->value.Tuple3.member2;
    _tmp005 = pvar5_node5;
  }
  *output = _tmp005;
  return 1;
}
static int node_anonymous460(int node5, struct Tuple3_Bool_Int_Int** output) {
  *output = Tuple3_0(node5, 1, 2);
  return 1;
}
static int node_node6(struct Tuple3_Bool_Int_Int* anonymous460, int* output) {
  int _tmp006;
  if (1) {
    int pvar6_node6 = anonymous460->value.Tuple3.member0;
    int pvar6_a6 = anonymous460->value.Tuple3.member1;
    int pvar6_b6 = anonymous460->value.Tuple3.member2;
    _tmp006 = pvar6_node6;
  }
  *output = _tmp006;
  return 1;
}
static int node_anonymous480(int node6, struct Tuple3_Bool_Int_Int** output) {
  *output = Tuple3_0(node6, 1, 2);
  return 1;
}
static int node_node7(struct Tuple3_Bool_Int_Int* anonymous480, int* output) {
  int _tmp007;
  if (1) {
    int pvar7_node7 = anonymous480->value.Tuple3.member0;
    int pvar7_a7 = anonymous480->value.Tuple3.member1;
    int pvar7_b7 = anonymous480->value.Tuple3.member2;
    _tmp007 = pvar7_node7;
  }
  *output = _tmp007;
  return 1;
}
static int node_anonymous500(int node7, struct Tuple3_Bool_Int_Int** output) {
  *output = Tuple3_0(node7, 1, 2);
  return 1;
}
static int node_node8(struct Tuple3_Bool_Int_Int* anonymous500, int* output) {
  int _tmp008;
  if (1) {
    int pvar8_node8 = anonymous500->value.Tuple3.member0;
    int pvar8_a8 = anonymous500->value.Tuple3.member1;
    int pvar8_b8 = anonymous500->value.Tuple3.member2;
    _tmp008 = pvar8_node8;
  }
  *output = _tmp008;
  return 1;
}
static int node_anonymous520(int node8, struct Tuple3_Bool_Int_Int** output) {
  *output = Tuple3_0(node8, 1, 2);
  return 1;
}
static int node_node9(struct Tuple3_Bool_Int_Int* anonymous520, int* output) {
  int _tmp009;
  if (1) {
    int pvar9_node9 = anonymous520->value.Tuple3.member0;
    int pvar9_a9 = anonymous520->value.Tuple3.member1;
    int pvar9_b9 = anonymous520->value.Tuple3.member2;
    _tmp009 = pvar9_node9;
  }
  *output = _tmp009;
  return 1;
}
static int node_gpio17(int node9, int* output) {
  *output = node9;
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
void ActivateMultiNode() {
  int current_side = 0, last_side = 1;
  Counter = NodeSize + 1;
  refreshMark();
  while (1) {
    Counter = 1;
    Input(&node_memory_gpio16[current_side]);
    node_anonymous340(node_memory_gpio16[current_side], &node_memory_anonymous340[current_side]);
    mark_Tuple3_Bool_Int_Int(node_memory_anonymous340[current_side], Counter + 1);
    Counter++;
    node_node0(node_memory_anonymous340[current_side], &node_memory_node0[current_side]);
    Counter++;
    node_anonymous360(node_memory_node0[current_side], &node_memory_anonymous360[current_side]);
    mark_Tuple3_Bool_Int_Int(node_memory_anonymous360[current_side], Counter + 1);
    Counter++;
    node_node1(node_memory_anonymous360[current_side], &node_memory_node1[current_side]);
    Counter++;
    node_anonymous380(node_memory_node1[current_side], &node_memory_anonymous380[current_side]);
    mark_Tuple3_Bool_Int_Int(node_memory_anonymous380[current_side], Counter + 1);
    Counter++;
    node_node2(node_memory_anonymous380[current_side], &node_memory_node2[current_side]);
    Counter++;
    node_anonymous400(node_memory_node2[current_side], &node_memory_anonymous400[current_side]);
    mark_Tuple3_Bool_Int_Int(node_memory_anonymous400[current_side], Counter + 1);
    Counter++;
    node_node3(node_memory_anonymous400[current_side], &node_memory_node3[current_side]);
    Counter++;
    node_anonymous420(node_memory_node3[current_side], &node_memory_anonymous420[current_side]);
    mark_Tuple3_Bool_Int_Int(node_memory_anonymous420[current_side], Counter + 1);
    Counter++;
    node_node4(node_memory_anonymous420[current_side], &node_memory_node4[current_side]);
    Counter++;
    node_anonymous440(node_memory_node4[current_side], &node_memory_anonymous440[current_side]);
    mark_Tuple3_Bool_Int_Int(node_memory_anonymous440[current_side], Counter + 1);
    Counter++;
    node_node5(node_memory_anonymous440[current_side], &node_memory_node5[current_side]);
    Counter++;
    node_anonymous460(node_memory_node5[current_side], &node_memory_anonymous460[current_side]);
    mark_Tuple3_Bool_Int_Int(node_memory_anonymous460[current_side], Counter + 1);
    Counter++;
    node_node6(node_memory_anonymous460[current_side], &node_memory_node6[current_side]);
    Counter++;
    node_anonymous480(node_memory_node6[current_side], &node_memory_anonymous480[current_side]);
    mark_Tuple3_Bool_Int_Int(node_memory_anonymous480[current_side], Counter + 1);
    Counter++;
    node_node7(node_memory_anonymous480[current_side], &node_memory_node7[current_side]);
    Counter++;
    node_anonymous500(node_memory_node7[current_side], &node_memory_anonymous500[current_side]);
    mark_Tuple3_Bool_Int_Int(node_memory_anonymous500[current_side], Counter + 1);
    Counter++;
    node_node8(node_memory_anonymous500[current_side], &node_memory_node8[current_side]);
    Counter++;
    node_anonymous520(node_memory_node8[current_side], &node_memory_anonymous520[current_side]);
    mark_Tuple3_Bool_Int_Int(node_memory_anonymous520[current_side], Counter + 1);
    Counter++;
    node_node9(node_memory_anonymous520[current_side], &node_memory_node9[current_side]);
    Counter++;
    node_gpio17(node_memory_node9[current_side], &node_memory_gpio17[current_side]);
    Counter++;
    Output(&node_memory_gpio17[current_side]);
    refreshMark();
    current_side ^= 1;
    last_side ^= 1;
  }
}
*/

int current_side = 0, last_side = 1;
void InitMultiNode() {
  Counter = NodeSize + 1;
  refreshMark();
}

void ExecMultiNode() {
  Counter = 1;
  Input(&node_memory_gpio16[current_side]);
  node_anonymous340(node_memory_gpio16[current_side], &node_memory_anonymous340[current_side]);
  mark_Tuple3_Bool_Int_Int(node_memory_anonymous340[current_side], Counter + 1);
  Counter++;
  node_node0(node_memory_anonymous340[current_side], &node_memory_node0[current_side]);
  Counter++;
  node_anonymous360(node_memory_node0[current_side], &node_memory_anonymous360[current_side]);
  mark_Tuple3_Bool_Int_Int(node_memory_anonymous360[current_side], Counter + 1);
  Counter++;
  node_node1(node_memory_anonymous360[current_side], &node_memory_node1[current_side]);
  Counter++;
  node_anonymous380(node_memory_node1[current_side], &node_memory_anonymous380[current_side]);
  mark_Tuple3_Bool_Int_Int(node_memory_anonymous380[current_side], Counter + 1);
  Counter++;
  node_node2(node_memory_anonymous380[current_side], &node_memory_node2[current_side]);
  Counter++;
  node_anonymous400(node_memory_node2[current_side], &node_memory_anonymous400[current_side]);
  mark_Tuple3_Bool_Int_Int(node_memory_anonymous400[current_side], Counter + 1);
  Counter++;
  node_node3(node_memory_anonymous400[current_side], &node_memory_node3[current_side]);
  Counter++;
  node_anonymous420(node_memory_node3[current_side], &node_memory_anonymous420[current_side]);
  mark_Tuple3_Bool_Int_Int(node_memory_anonymous420[current_side], Counter + 1);
  Counter++;
  node_node4(node_memory_anonymous420[current_side], &node_memory_node4[current_side]);
  Counter++;
  node_anonymous440(node_memory_node4[current_side], &node_memory_anonymous440[current_side]);
  mark_Tuple3_Bool_Int_Int(node_memory_anonymous440[current_side], Counter + 1);
  Counter++;
  node_node5(node_memory_anonymous440[current_side], &node_memory_node5[current_side]);
  Counter++;
  node_anonymous460(node_memory_node5[current_side], &node_memory_anonymous460[current_side]);
  mark_Tuple3_Bool_Int_Int(node_memory_anonymous460[current_side], Counter + 1);
  Counter++;
  node_node6(node_memory_anonymous460[current_side], &node_memory_node6[current_side]);
  Counter++;
  node_anonymous480(node_memory_node6[current_side], &node_memory_anonymous480[current_side]);
  mark_Tuple3_Bool_Int_Int(node_memory_anonymous480[current_side], Counter + 1);
  Counter++;
  node_node7(node_memory_anonymous480[current_side], &node_memory_node7[current_side]);
  Counter++;
  node_anonymous500(node_memory_node7[current_side], &node_memory_anonymous500[current_side]);
  mark_Tuple3_Bool_Int_Int(node_memory_anonymous500[current_side], Counter + 1);
  Counter++;
  node_node8(node_memory_anonymous500[current_side], &node_memory_node8[current_side]);
  Counter++;
  node_anonymous520(node_memory_node8[current_side], &node_memory_anonymous520[current_side]);
  mark_Tuple3_Bool_Int_Int(node_memory_anonymous520[current_side], Counter + 1);
  Counter++;
  node_node9(node_memory_anonymous520[current_side], &node_memory_node9[current_side]);
  Counter++;
  node_gpio17(node_memory_node9[current_side], &node_memory_gpio17[current_side]);
  Counter++;
  Output(&node_memory_gpio17[current_side]);
  refreshMark();
  current_side ^= 1;
  last_side ^= 1;
}