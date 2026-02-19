#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int countBinarySubstrings(char* s) {
  int N = strlen(s);
  int prev = 0;
  int cur = 1;
  long ans = 0;
  for (int i = 1; i < N; i++) {
    if (s[i] == s[i - 1]) {
      cur++;
    } else {
      ans += fmin(prev, cur);
      prev = cur;
      cur = 1;
    }
  }

  ans += fmin(prev, cur);

  return ans;
}

int main() {
  FILE *in = fopen("1.in", "r");
  FILE *out = fopen("1.out", "w");
  char s[1024] = {0};
  fgets(s, sizeof(s), in);

  int result = countBinarySubstrings(s);

  fprintf(out, "%d\n", result);

  fclose(in);
  fclose(out);

  return 0;
}