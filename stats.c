#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    float min = *(numberset+0);
    float max = *(numberset+0);
    int i = 1;  
    float sum = *(numberset+0);
    while(i<setlength && i>=1)
    {   
        if (*(numberset+i) > max) 
            max = *(numberset+i);
        else 
            min = *(numberset+i);
       i++;
       sum = sum + *(numberset+i);
    }
    s.average = (sum)/setlength;
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
