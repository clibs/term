
//
// term.c
//
// Copyright (c) 2012 TJ Holowaychuk <tj@vision-media.ca>
//

#include <stdio.h>
#include <string.h>
#include "term.h"

/*
 * Move to `(x, y)`.
 */

void
term_move_to(int x, int y) {
  printf("\e[%d;%d;f", y, x);
}

/*
 * Return the erase code for `name` or -1.
 */

const char *
term_erase_from_name(const char *name) {
  if (!strcmp("end", name)) return "K";
  if (!strcmp("start", name)) return "1K";
  if (!strcmp("line", name)) return "2K";
  if (!strcmp("up", name)) return "1J";
  if (!strcmp("down", name)) return "J";
  if (!strcmp("screen", name)) return "1J";
  return NULL;
}

/*
 * Erase with `name`:
 * 
 *   - "end"
 *   - "start"
 *   - "line"
 *   - "up"
 *   - "down"
 *   - "screen"
 * 
 */

int
term_erase(const char *name) {
  const char *s = term_erase_from_name(name);
  if (!s) return -1;
  printf("\e[%s", s);
  return 0;
}

/*
 * Return the color code for `name` or -1.
 */

int
term_color_from_name(const char *name) {
  if (!strcmp("black", name)) return 0;
  if (!strcmp("red", name)) return 1;
  if (!strcmp("green", name)) return 2;
  if (!strcmp("yellow", name)) return 3;
  if (!strcmp("blue", name)) return 4;
  if (!strcmp("magenta", name)) return 5;
  if (!strcmp("cyan", name)) return 6;
  if (!strcmp("white", name)) return 7;
  return -1;
}

/*
 * Set color by `name` or return -1.
 */

int
term_color(const char *name) {
  int n = term_color_from_name(name);
  if (-1 == n) return n;
  printf("\e[3%dm", n);
  return 0;
}

/*
 * Set background color by `name` or return -1.
 */

int
term_background(const char *name) {
  int n = term_color_from_name(name);
  if (-1 == n) return n;
  printf("\e[4%dm", n);
  return 0;
}