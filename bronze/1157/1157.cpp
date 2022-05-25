#include <iostream>

using namespace std;

int cnt[26];

int main() {
  char c;
  
  while(true) {
    scanf("%c", &c);

    if (c == '\n') break;

    int idx = (c > 'Z' ? c - ('a' - 'A') : c) - 'A';

    cnt[idx] += 1;
  }

  int max_idx[2] = {-1, -1};

  for (int i=0; i<26; i++) max_idx[0] = max_idx[0] == -1 ? i : cnt[max_idx[0]] > cnt[i] ? max_idx[0] : i;

  for (int i=0; i<26; i++) {
    if (max_idx[0] == i) continue;

     max_idx[1] = max_idx[1] == -1 ? i : cnt[max_idx[1]] > cnt[i] ? max_idx[1] : i;
  }

  if (cnt[max_idx[0]] == cnt[max_idx[1]]) {
    printf("?");
  } else {
    printf("%c", 'A' + (cnt[max_idx[0]] > cnt[max_idx[1]] ? max_idx[0] : max_idx[1]));
  }

  return 0;
}
