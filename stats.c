#include "stats.h"
#include <stdio.h>
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    int i = 0; 
    
    if (setlength == 0 || numberset == 0) {
        s.average = 0.0/0.0;
        s.min = 0.0/0.0;
        s.max = 0.0/0.0;
        return s;
    }
   
    s.min = numberset[i];
    s.max = numberset[i];
    s.sum = numberset[i];
    
    for (i=1; i<setlength;i++) {
        if (numberset[i] > s.max) 
            s.max = numberset[i];
        if(s.min > numberset[i])
            s.min = numberset[i];
            
        s.sum += numberset[i]; 
     }          
    s.average = s.sum/setlength;
    }
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats) {
    //Update the method for check_and_alert function
    
    if (computedStats.average > maxThreshold) {
        alerters[0]();
        alerters[1]();
    }
}
