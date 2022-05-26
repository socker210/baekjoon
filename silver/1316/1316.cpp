#include <iostream>

using namespace std;

int main() {
  int N, i = 0, flag = 0, cnt = 0;
  int cnt_arr[26];
  char words[101];

  for (int i=0; i<26; i++) cnt_arr[i] = 0;

  scanf("%d", &N);

  for (;N;N--) {
    scanf("%s", words);

    i = 0;
    flag = 0;

    while(words[i] != '\0') {
      int cnt_arr_idx = words[i] - 'a';

      if (i > 0 && cnt_arr[cnt_arr_idx] != 0 && words[i] != words[i-1]) {
        flag = 1;

        break;
      }

      cnt_arr[cnt_arr_idx] += 1;
      i++;
    }

    if (flag) cnt--;

    for (int i=0; i<26; i++) cnt_arr[i] = 0;

    cnt++;
  }

  printf("%d", cnt);
  
  return 0;
}

