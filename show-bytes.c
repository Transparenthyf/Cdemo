#include<stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);
void show_int(int x);
void show_float(float x);
void show_pointer(void *x);

int main(void)
{
  int val = 12345;
  float fval = (float) val;
  int *pval = &val;
  show_int(val);
  show_float(fval);
  printf("%x", pval);
  show_pointer(pval);
  printf("*****************************\n");
  const char *s = "abcdefg";
  printf("%x\n", s);
  show_bytes((byte_pointer) s, strlen(s));

  return 0;
}

void show_bytes(byte_pointer start, size_t len) {
  printf("%x , %d", start, len);
  size_t i;
  for (i = 0; i < len; i++) {
    printf(" %x", start[i]);
  }
  printf("\n");
}
void show_int(int x) {
  show_bytes((byte_pointer) &x, sizeof(int));
}
void show_float(float x) {
  show_bytes((byte_pointer) &x, sizeof(float));
}
void show_pointer(void *x) {
  show_bytes((byte_pointer) &x, sizeof(void *));
}
