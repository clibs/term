
#include <stdio.h>
#include "src/term.h"

int
main(int argc, char **argv){
  term_bold();
  term_underline();
  printf("bold and underlined\n");

  term_reset();
  printf("reset\n");

  term_color("green");
  printf("ok\n");

  term_color("red");
  printf("fail");
  term_reset();

  term_move_to(50, 10);
  printf("hey");
  term_move_to(0, 15);
  

  return 0;
}