#include <stdbool.h>

typdef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} IS; //instruction set

typdef enum {
  A, B, C, D, E, F, IP, SP, NUM_OF_REGISTERS //is a little trick so we can get the size of the registers even if you add more because it's the last one
} REGISTERS;

//input program example
//const int program[] = {
//  PSH, 5,
//  PSH, 6,
//  ADD,
//  POP,
//  HLT
//};

#define sp (registers[SP]) //stack poiter, if set to -1 means that stack is empty
#define ip (registers[IP]) //instruction poiner

sp = -1;
ip = 0;

int stack[256];
int registers[NUM_OF_REGISTERS];
bool running = true;

int fetch(){
  return program[ip];
}

int set(int var, int val){
  var = val;
  stack[sp] = var;
}

void eval(int instruction){
  switch (instruction) {
    case HLT: {
      running = false;
      break;
    }
    case PSH: {
      sp++; //we increment sp first because num-ing the stack from -1 is not so good
      stack[sp] = program[++ip];
      break;
    }
    case POP: {
      int val_popped = stack[sp--];
      printf("popped %d\n", val_popped);
      break;
    }
    case SET: {
      set();
      break;
    }
    case ADD: {
      int a = stack[sp--]; //in this instruction we clear 2 upper places in stack
      int b = stack[sp--]; //next we get the resault of the addition and increment sp
      int res = b + a;     //and finaly store the resault to the top of the stack
      sp++;
      stack[sp] = res;
      break;
    }
    //here I should make some other operations like multiplication, division and substraction
  }
}

int main(void){
  while(running){
    eval(fetch());
    ip++;
  }
  return 0;
}
