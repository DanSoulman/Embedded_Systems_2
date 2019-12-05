#include "Stream.h"
int increasing_peak(struct Stream *s, int n)
{

    int prev = 0;
    int c = 0;
    int state = 0;
    int finish = 0;
    int highest = 0;
    int firstpeak = 0;
    //printf("peak1 cnt = %d size =%d\n",s->cnt,s->size);
    //if (n == 0) Removed so that there can be 0 peaks.
    //   return 0;
    prev = streamGet(s, &finish);
    //printf("peak2 cnt = %d size =%d\n",s->cnt,s->size);
    if (finish)
        return 0;
    int curr = streamGet(s, &finish);
    while (!finish && c < n)
    {
        switch (state)
        {
        case 0:
            if (prev < curr)
                state = 1;
            break;
        case 1:
            if (prev > curr && highest < prev) //If its a higher peak.
            {
                if (firstpeak = 0)
                {
                    firstpeak += 1;
                }
                else
                {
                    c++; // found a peak
                }
                highest = curr;
                state = 0;
            }
            break;
        }
        prev = curr;
        curr = streamGet(s, &finish);
    }
    //printf("Count is %d", c); for testing
    if (c == n)
        return 1;
    return 0;
}
