#include <stdio.h>
#include <math.h>
#include <float.h>

//receives the array of sales, returns the max as a float 
float max(float arr[12]){
    float max =0 ;
    for(int i=0;i<12;i++){
        if(max<= arr[i]){
            max = arr[i];        
        }
    }
    return max;
}

//receives the array of sales, returns the min as a float 
float min(float arr[12]){
    float min;
    for(int i=0; i<12;i++){
        if(min>= arr[i]){
            min = arr[i];
        }
    }
    return min;
}

//receives the array of values, returns the average as a float 
float avg(float arr[12]){
    float out;
    for(int i=0;i<12;i++){
        out+= arr[i];
    }
    out/= 12;
    return out;
}

//receives the array of values and a starting index, produces the average for the 6 month range
float moving_avg(float arr[12],int index){
    float out =0;
    for(int i=index; i<index+6;i++){
        out+= arr[i];
    }
    out = out/6;
    return out;
}

//receives the array of values and a specific value, returns the index that value is stored at 
int get_month_ind(float arr[12], float val){
    for(int i=0; i<12;i++){
        if (arr[i] == val){
            return i;
        }
    }
}


int main(){


    FILE *file = fopen("input_file.txt","r");

    if(file == NULL){
        printf("Error opening file \n");
        return 1;
    }


    char* months[12]= {"January","February","March","April","May","June","July","August","September","October","November","December"};
    float vals[12];
    float vals_copy[12];
    for (int i=0; i<12;i++){
        fscanf(file,"%f", &vals[i]);
    }

    printf("Monthly sales report for 2022:\n");
    printf(" \n");
    printf("Month      Sales\n");
    for (int i=0;i<12;i++){
        printf("%-10s %8.2f \n",months[i],vals[i]);
    }
    fclose(file);

    printf(" \n");
    printf("Sales Summary: \n");
    printf("\n");
    float minimum = min(vals);
    int index = get_month_ind(vals,minimum);
    printf("Minimum Sales: ");
    printf("%8.2f %s \n", minimum, months[index]);
    float maximum = max(vals);
    index = get_month_ind(vals,maximum);
    printf("Maximum Sales: "); 
    printf("%8.2f %s\n", maximum, months[index]);
    float average= avg(vals);
    printf("Average Sales: ");
    printf( "%8.2f \n", average);
    printf("\n");


    printf("Six-Month Moving Average Report\n");
    printf("January -- June");
    printf("%8.2f \n", moving_avg(vals,0));
    printf("February -- July");
    printf("%8.2f \n", moving_avg(vals,1));
    printf("March -- August");
    printf("%8.2f \n", moving_avg(vals,2));
    printf("April -- September");
    printf("%8.2f \n ", moving_avg(vals,3));
    printf("May -- October");
    printf("%8.2f \n", moving_avg(vals,4));
    printf("June -- November");
    printf("%8.2f \n", moving_avg(vals,5));
    printf("July -- December");
    printf("%8.2f \n", moving_avg(vals,6));


     for (int varOne = 0; varOne < 12; varOne++)
    {
        for (int varTwo = varOne + 1; varTwo < 12; varTwo++)
        {
            if(vals[varOne] < vals[varTwo])
            {
                float tempVar = vals[varOne];
                vals[varOne] = vals[varTwo];
                vals[varTwo] = tempVar;
                char *tempMonth = months[varOne];
                months[varOne] = months[varTwo];
                months[varTwo] = tempMonth;
            }
        }
    }
    
    printf("Sales Report (Highest to Lowest):\n");
    printf(" \n");
    printf("%-5s %10s\n", "Month", "Sales");
    printf(" \n");
    for (int varOne = 0; varOne < 12; varOne++)
    {
        printf("%-10s $%8.2f\n", months[varOne], vals[varOne]);
    }
    printf(" \n");
    printf(" \n");

    return 0;



}