#include <stdio.h>
#include "Stream.h"
#include "peak.c"
#include "valley.c"
#include "increasingpeak.c"

int streamGet(struct Stream *s, int *finished)
{
   *finished = 0;
   //printf("streamGet cnt = %d size =%d\n",s->cnt,s->size);
   if (s->cnt < s->size)
   {
      // printf("streamGet %d\n",s->buffer[s->cnt]);
      return s->buffer[s->cnt++];
   }
   else
      *finished = 1;
   return -1;
}

/*
valley based on peak example.
http://sofdem.github.io/gccat/gccat/Cpeak.html
(2,⟨1,1,4,8,6,2,7,1⟩)
(0,⟨1,1,4,4,4,6,7,7⟩)
(4,⟨1,5,4,9,4,6,2,7,6⟩)
*/
main()
{

   int data1[] = {1, 1, 4, 8, 6, 2, 7, 1};
   int data2[] = {1, 5, 4, 9, 4, 6, 2, 7, 6};
   struct Stream s;

   s.buffer = data1;
   s.size = 8;
   s.cnt = 0;

   int val0 = peak(&s, 2);
   printf("result for peak({1,1,4,8,6,2,7,1},2) i.e. are there two peaks in the data? %d\n", val0);

   s.cnt = 0; //resets count

   int val1 = valley(&s, 1);
   printf("result for valley({1,1,4,8,6,2,7,1},1) i.e. are there one valleys in the data? %d\n", val1);

   s.cnt = 0; //reset count

   int val2 = increasing_peak(&s, 0);
   printf("result for increasing ({1,1,4,8,6,2,7,1},0) i.e. are there are no peaks in the data? %d\n", val2);

   s.buffer = data2;
   s.size = 9;
   s.cnt = 0;

   val0 = peak(&s, 4);
   printf("result for peak({1,5,4,9,4,6,2,7,6},4) i.e. are there 4 peak in the data? %d\n", val0);

   s.cnt = 0; //resets count

   val1 = valley(&s, 3);
   printf("result for valley ({1,5,4,9,4,6,2,7,6},3) i.e. are there 3 valleys in the data? %d\n", val1);
   
   s.cnt = 0; //reset count

   val2 = increasing_peak(&s, 1);
   printf("result for increasing ({1,5,4,9,4,6,2,7,6},1) i.e. are theres one increasing peaks in the data? %d\n", val2);

   s.cnt = 0; //reset count

   val0 = peak(&s, 5);
   printf("result for peak({1,5,4,9,4,6,2,7,6},5) i.e. are there 5 peaks in the data? %d\n", val0);

   s.cnt = 0; //reset count

   val1 = valley(&s, 5); //Note this one returns 0 as there ISN'T 5 peaks
   printf("result for valley({1,5,4,9,4,6,2,7,6},5) i.e. are there 5 valleys in the data? %d\n", val1);

   s.cnt = 0; //reset count

   val2 = increasing_peak(&s, 5); //Note this one returns 0 as there ISN'T 5 peaks
   printf("result for increasing ({1,5,4,9,4,6,2,7,6},5) i.e. are there are five increasing peaks in the data? %d\n", val2);

   s.cnt = 0; //reset count

}
