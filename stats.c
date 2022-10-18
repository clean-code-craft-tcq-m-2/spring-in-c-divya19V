#include "stats.h"
#include <stdio.h>
#include <math.h>

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0.0;
    s.min = 0.0;
    s.max = 0.0;
    
    if (setlength == 0 || numberset == 0)
        return s;
    else {
    int i = 0; 
    float min = numberset[i];
    float max = numberset[i];
    float sum = numberset[i];
    i++;
        
        while((i<setlength) && (i>=1))
        {   
        if (numberset[i] > max) 
            max = numberset[i];
        else {
            if(min > numberset[i])
                min = numberset[i];
        }
        sum += numberset[i];
        i++;    
        }          
    s.min = min;
    s.max = max;
    s.average = sum/setlength;
    }
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats) {
    //Update the method for check_and_alert function
    int result = 0;
    if (computedStats.average == maxThreshold) {
        result = alerters[0];
        result = alerters[1];
    }
}
