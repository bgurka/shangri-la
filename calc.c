#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;
int avg = 0;

double stdev(int seq[]);
double dist(int seq[], double dev);

void read(int N) {

  FILE *ptr;
  ptr = fopen("data", "r");
  size_t nr;

  int seq[N];
  int num;
  while(1) {
    nr = fread(&num, sizeof(int), 1, ptr);
    if (nr == 0) {
      break;
    }
    seq[count] = num;
    count++;
    avg += num;
  }
  avg = avg/count;
  double dev = stdev(seq);
  printf("\n");
  printf("The average of the sequence is %d\n", avg);
  printf("The standard deviation of the sequence is %f\n", dev);
  printf("%f percent of the sequence is within the first std dev\n", dist(seq, dev));
  fclose(ptr);
}

double stdev(int seq[]) {

  double sum = 0;
  double hold, root;
  for (int i = 0; i < count; i++) {
    hold = seq[count] - avg;
    if (hold < 0) hold = hold*-1;
    root = sqrt(hold);
    sum = root + sum;
    }
  double dev = sum/count;
  if (dev < 0) dev = dev*-1;
  return sqrt(dev);
}

double dist(int seq[], double dev) {

  int bell = 0;
  int hold;
  if (dev < 0) {
    dev = dev * -1;
  }
  for (int i =0; i < count; i++) {
    hold = avg - seq[i];
    if (hold < 0) {
      hold = hold * -1;
    }
    if (hold <= dev) {
      bell++;
    }
  }
  return (bell/count) * 100;
}
