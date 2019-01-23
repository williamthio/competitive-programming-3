#include "ioi2010_cluedo.h"
#include "cluedo.h"

void Solve(){
   int r, m = 1, l = 1, w = 1;
   while (r = Theory(m, l, w), r) {
	   switch (r)
	   {
	   case 1: m++; break;
	   case 2: l++; break;
	   case 3: w++; break;
	   }
   }
}
