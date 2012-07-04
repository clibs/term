
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "src/term.h"

void
on_sigint(int sig) {
  term_clear("screen");
  term_show_cursor();
  exit(1);
}

void
show(float data[]) {
  int pad = 4;
  int n = 0;

  int w, h;
  term_size(&w, &h);

  // clear
  term_clear("screen");

  // y-axis
  term_move_to(pad, 1);
  while (n < (h - pad - 1)) {
    term_move_by(0, 2);
    printf("․");
    n += 2;
  }

  // x-axis
  n = 0;
  term_move_to(pad, h - 2);
  while (n < (w - pad * 3)) {
    printf("․");
    term_move_by(6, 0);
    n += 6;
  }

  // plot data

  int x = 0;
  for (int i = 0; -1 != data[i]; ++i) {
    float y = data[i];
    while (y--) {
      term_move_to(x * 6 + pad, y - h + pad);
      printf("*");
    }
    x++;
  }

  term_move_to(w, h - 1);

  // flush
  printf("\n");
}

int
main(int argc, char **argv){
  term_hide_cursor();
  signal(SIGINT, on_sigint);

start:
  {
    float data[] = { 0, 2, 3, 5, 3, 7, 3, 8, 10, 12, 4, 2, 4, 3, -1 };
    show(data);
    sleep(1);
  }

  {
    float data[] = { 0, 2, 3, 1, 3, 3, 3, 8, 2, 12, 4, 2, 4, 3, -1 };
    show(data);
    sleep(1);
  }

  {
    float data[] = { 0, 0, 1, 2, 3, 7, 3, 8, 2, 12, 2, 2, 1, 3, -1 };
    show(data);
    sleep(1);
    goto start;
  }

  return 0;
}