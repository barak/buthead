// buthead: pass through all but the first n lines of standard input.

// Copyright (C) 2001, Barak A. Pearlmutter <bap@cs.unm.edu>

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

#include <stdio.h>

int main(argc,argv)
     int argc;
     char **argv;
{
  int lines_to_skip, c, i;

  if (argc != 2)
    {
      fprintf(stderr, "Usage: %s count.\n", argv[0]);
      exit(2);
    }

  if (sscanf(argv[1], "%d", &lines_to_skip) != 1 || lines_to_skip < 0)
    {
      fprintf(stderr, "Unable to parse line count %s.\n", argv[1]);
      exit(2);
    }

  for (i=0; i<lines_to_skip; )
    {
      if ((c = getc(stdin)) == EOF)
	{
	  fprintf(stderr, "Premature EOF.\n");
	  exit(1);
	}

      if (c == '\n') i += 1;
    }

  while ((c = getchar()) != EOF)
    putchar(c);

  return 0;
}
