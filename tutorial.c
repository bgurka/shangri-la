#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  struct poems {
    char x[100];
    char y[100];
    char z[100];
  };

  FILE *out, *in;
  out = fopen("whatever", "w");

  struct poems words = {"haikus are easy",
			"but are sometimes difficult",
			"refrigerator"};
  fwrite(&words, sizeof(struct poems), 1, out);
  fclose(out);

  struct poems haiku;
  in = fopen("whatever", "r");
  fread(&haiku, sizeof(struct poems), 1, in);
  fclose(in);
  printf("\n %s\n %s\n %s\n\n", haiku.x, haiku.y, haiku.z);
}
