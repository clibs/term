
# term.c

  Terminal goodies.

## Example

  Check out ./example.c:

  ![](http://f.cl.ly/items/2q2S3s3g0E122N0O2521/Screen%20Shot%202012-07-03%20at%2011.27.19%20PM.png)

## Installation

  Install with [clib](https://github.com/clibs/clib):

```
$ clib install clibs/term
```

## API

```c

// aliases

#define term_bold term_bright
#define term_clear term_erase

// display

#define term_reset() term_write("0m")
#define term_bright() term_write("1m")
#define term_dim() term_write("2m")
#define term_underline() term_write("4m")
#define term_blink() term_write("5m")
#define term_reverse() term_write("7m")
#define term_hidden() term_write("8m")

// cursor

#define term_hide_cursor() term_write("?25l")
#define term_show_cursor() term_write("?25h")

// size

int
term_size(int *width, int *height);

// movement

void
term_move_by(int x, int y);

void
term_move_to(int x, int y);

// erasing

const char *
term_erase_from_name(const char *name);

int
term_erase(const char *name);

// colors

int
term_color_from_name(const char *name);

int
term_color(const char *name);

int
term_background(const char *name);
```
