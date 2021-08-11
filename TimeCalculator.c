#include <stdio.h>
double totalTime = 0;

double calculateTime(double beginningMinute, double beginningHour, double endMinute, double endHour){
    //if going from an am to pm time, convert pm to 24hr
    if(endHour < beginningHour){
        endHour += 12;
    }
    
    //get the total hours
    double totalHour = endHour - beginningHour;
    
    //if the ending minute is less than the starting minute, subtract 1 from the total hours
    if(endMinute < beginningMinute){
        totalHour -= 1;
    }
    
    //calculate the number of min
    double totalMinute = ((endMinute + 60) - beginningMinute)/60;
    //if the total minutes > 1 then subtract 1 to be left with 0.xxxxxxxxx
    if (totalMinute >= 1){
        totalMinute -= 1;
    }
    
    //return the total time
    return totalHour+totalMinute;
}


int main()
{
    int x = 1;
    while (x == 1){
        float beginningHour, beginningMinute, endHour, endMinute;
        printf("Input beginning hour: ");
        scanf("%f", &beginningHour);
        
        printf("Input beginning minute: ");
        scanf("%f", &beginningMinute);
        
        printf("Input end hour: ");
        scanf("%f", &endHour);
        
        printf("Input end minute: ");
        scanf("%f", &endMinute);
        
        totalTime += calculateTime(beginningMinute, beginningHour, endMinute, endHour);
        
        printf("Would you like to enter another time? (0 = no, 1 = yes)");
        scanf("%d", &x);
    }
    
    printf("The total time elapsed is %f", totalTime);
    totalTime = 0;

    return 0;
}
