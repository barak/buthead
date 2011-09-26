// buthead: pass through all but first n lines of standard input

// Copyright 2002, Barak A. Pearlmutter <bap@debian.org>

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv)
{
  long lines_to_skip, i;
  int c;
  char *p;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s count\n", argv[0]);
    exit(2);
  }

  lines_to_skip = strtol(argv[1], &p, 10);

  if (errno || lines_to_skip < 0 || argv[1][0] == '\0' || *p != '\0') {
    fprintf(stderr, "buthead error: invalid line count '%s'\n", argv[1]);
    exit(2);
  }

  for (i=0; i<lines_to_skip; ) {
    if ((c = getc(stdin)) == EOF) {
      fprintf(stderr, "buthead error: EOF on line %ld while skipping %ld\n",
	      i+1, lines_to_skip);
      exit(1);
    }

    if (c == '\n') i += 1;
  }

  while ((c = getchar()) != EOF)
    putchar(c);

  return 0;
}
