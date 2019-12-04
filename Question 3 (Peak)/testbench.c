
#include "Stream.h"
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

   int val = valley(&s, 2); //TODO: Resolve undefined reference to `valley'
   printf("result for valley({1,1,4,8,6,2,7,1},2) i.e. are there two valleys in the data? %d\n", val);

   s.buffer = data2;
   s.size = 9;
   s.cnt = 0;

   val = valley(&s, 4);
   printf("result for valley({1,5,4,9,4,6,2,7,6},4) i.e. are there 4 valleys in the data? %d\n", val);

   val = valley(&s, 5);
   printf("result for valley({1,5,4,9,4,6,2,7,6},5) i.e. are there 5 valleys in the data? %d\n", val);
}
