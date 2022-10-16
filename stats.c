#include "stats.h"
#include <stdio.h>
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0.0;
    s.min = 0.0;
    s.max = 0.0;
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
    printf("%f,%f %f", max,min,sum);
    s.min = roundf(min);
    s.max = roundf(max);
    s.average = roundf((sum))/setlength;
    printf("%f,%f %f", max,min,sum);
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

/*void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats) {
    //Update the method for check_and_alert function
    
}
*/
