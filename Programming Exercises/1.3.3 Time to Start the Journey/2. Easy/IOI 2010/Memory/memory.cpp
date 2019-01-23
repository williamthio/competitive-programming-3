#include "ioi2010_memory.h"
#include "memory.h"

void play() {
   int i, ai, bi;
   char a, b;
   int arr[25][2];
   for (i = 0; i < 25; i++)
       arr[i][0] = arr[i][1] = -1;
   for (i = 1; i < 50; i += 2) {
      a = faceup(i);
      b = faceup(i + 1);
      if (a != b) {
          ai = a - 'A';
          bi = b - 'A';
          if (arr[ai][0] == -1)
              arr[ai][0] = i;
          else
              arr[ai][1] = i;
          if (arr[bi][0] == -1)
              arr[bi][0] = i + 1;
          else
              arr[bi][1] = i + 1;
      }
   }
   for (i = 0; i < 25; i++) {
       ai = arr[i][0];
       bi = arr[i][1];
       if (ai != -1 && bi != -1) {
           faceup(ai);
           faceup(bi);
       }
   }
}
