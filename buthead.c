/* Chop off the first n lines.

 * History:

 * April 24, 1988
 * Created, Barak Pearlmutter.

 */

#include <stdio.h>

#define BUFFSIZE 1024

main(argc,argv)
     int argc;
     char **argv;
{
  int lines_to_skip, c, i;
  char buff[BUFFSIZE];

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
      else if (c == '\n') i += 1;
      else continue;
    }

  while ((i = fread(buff, 1, BUFFSIZE, stdin)) != 0)
    fwrite(buff, 1, i, stdout);

  exit(0);
}
