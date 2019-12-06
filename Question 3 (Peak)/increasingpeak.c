#include "Stream.h"
int increasing_peak(struct Stream *s)
{

    int prev = 0;
    int state = 0;
    int finish = 0;
    int highest = 0;
    //printf("peak1 cnt = %d size =%d\n",s->cnt,s->size);
    //if (n == 0) Removed so that there can be 0 peaks.
    //   return 0;
    prev = streamGet(s, &finish);
    //printf("peak2 cnt = %d size =%d\n",s->cnt,s->size);
    if (finish)
        return 0;
    int curr = streamGet(s, &finish);
    while (!finish)
    {
        switch (state)
        {
        case 0: //Isn't peak Keep waiting
            if (prev < curr)
                state = 1;
            break;
        case 1://waiting until found peak
            if (prev > curr) //Peak has been found
            {
                state = 2;// Next loop we go to case 2
                highest = prev; //Sets higgest
            }
            break;
        case 2://Started going down, wait for increase
            if (prev < curr) //We found it's going back up. We can record next peak
                state = 3; 
            break;
        case 3://Record peak
            if (prev > curr)
            {
                if (highest > prev) //If it fails to beat highest constraint not met. Give up, return 0. It failed. 
                {
                    return 0;
                }
                state = 2;
                highest = prev;
            }
            break;
        }
        prev = curr;
        curr = streamGet(s, &finish);
    }
    //printf("Count is %d", c); for testing
    return 1; //If successful return 1
}
