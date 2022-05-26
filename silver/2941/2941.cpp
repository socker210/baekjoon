#include <iostream>

using namespace std;

int main() {
  char words[101];
  char* word = words;

  scanf("%s", words);

  int cnt = 0;

  while(*word != '\0') {
    char c_word = *word;
    char b_word = *(word-1);
    char bb_word = *(word-2);

    if (c_word == '=' && b_word == 'z' && bb_word == 'd') cnt -= 2;
    else if (c_word == '=' && (b_word == 'c' || b_word == 's' || b_word == 'z')) cnt--;
    else if (c_word == '-' && (b_word == 'c' || b_word == 'd')) cnt--;
    else if (c_word == 'j' && (b_word == 'l' || b_word == 'n')) cnt--;
    
    cnt++;
    word++;
  }

  printf("%d", cnt);

  return 0;
}
