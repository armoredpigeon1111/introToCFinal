
#include <stdio.h>
#include <time.h>

int main()
{
    int weekSelect;
    printf("CIS126L Week 5 Project Menu\n Week 1 - Circle Math \n Week 2 - Salary Calculator \n Week 3 - Dice Roll \n Week 4 - Temperature Conversion\n");
    scanf("%d", &weekSelect);
    
    switch(weekSelect){
        case(1):
        prog1();
        break;
        
        case(2):
        prog2();
        break;
        
        case(3):
        prog3();
        break;
        
        case(4):
        prog4();
        break;
        
        case(5):
        break;
        
        default:
        printf("You selected an invalid entry you get all programs back to back!!!\n");
        prog1();
        prog2();
        prog3();
        prog4();
        break;
    }

    return 0;
}


prog1(){
    
    float radius;
    float circumference;
    float diameter;
    float area;
    float piHolder = 3.14;
    
    printf("WELCOME TO THE CIRCLE RADIUS PROGRAM\n\n");
        
    printf("Input the circle radius: ");
    scanf("%f", &radius);
   
    diameter = radius * 2;
    circumference = 2 * (3.14 * radius);
    area = 3.14 * (pow(radius,2));
 
    printf("The diameter is: %f \n", diameter);
    printf("The circumference is: %f \n", circumference);
    printf("The area is: %f \n", area);
}

prog2(){
    int paycode = 0;
    double hourlyWage;
    double totalHoursWorked;
    double hoursOvertime;
    int pieces;
    double wagePerPiece;
    double workersPay;
    double weeklySalary;
    double weeklySales;
    int managers = 0;
    int hWorkers = 0;
    int cWorkers = 0;
    int pWorkers = 0;
    
    printf("WELCOME TO THE SALARY CALCULATOR PROGRAM\n\n");
    
     while(paycode != -1){   
        printf("Enter paycode (-1 to end):\n 1. Manager\n 2. Hourly\n 3. Commision\n 4. Pieceworker\n ");
        scanf("%d", &paycode);
        
        switch(paycode){
            case 1:
                printf("Manager Selected\n");
                printf("Enter weekly salary: ");
                scanf("%lf", &weeklySalary);
                printf("The manager's weekly pay is: $%.2f \n", weeklySalary);
                
                ++managers;
            
            break;
            
            case 2:
                printf("Hourly Worker Selected\n");
                printf("Enter the Hourly Rate: \n");
                scanf("%lf", &hourlyWage);
                printf("Enter the TOTAL hours worked: ");
                scanf("%lf", &totalHoursWorked);
                if(totalHoursWorked < 40){
                    workersPay = hourlyWage * totalHoursWorked;
                }else{
                    hoursOvertime = totalHoursWorked - 40;
                    workersPay = (hourlyWage * 40) + ((hourlyWage*1.5) * hoursOvertime);
                }
                printf("Weekly pay is: $%.2f \n", workersPay);
                ++hWorkers;
            break;
            
            case 3:
                printf("Commission Worker Selected.\n");
                printf("Enter gross weekly sales: ");
                scanf("%lf", &weeklySales);
                workersPay = 250 + (weeklySales * .057);
                printf("Weekly Comission worker made: $%.2f\n", workersPay);
                ++cWorkers;
                break;
                
            case 4:
                printf("Piece Worker Selected. \n Enter number of pieces: ");
                scanf("%d", &pieces);
                printf("Enter wage per piece: ");
                scanf("%lf", &wagePerPiece);
                workersPay = (pieces * wagePerPiece);
                printf("Worker made: $%.2f \n", workersPay);
                ++pWorkers;
            break;
        }
        if(paycode >5 || paycode <1){
            puts("Enter a Paycode between 1-5!\n");
        }
     }
     
     printf("Total number of managers paid          : %d\n", managers);
     printf("Total number of hourly workers paid    : %d\n", hWorkers);
     printf("Total number of commission workers paid: %d\n", cWorkers);
     printf("Total number of pieceworkers paid      : %d\n", pWorkers);    
}

prog3(){

     srand(time(NULL));
     unsigned int sum[13] = {0};

    printf("WELCOM TO THE DICE ROLL PROBABILITY PROGRAM\n\n");
     
     //Array for expected outcome per sum
     unsigned int expected[13] = { 0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
         
         for(unsigned int i = 1; i<=36000; ++i){
             int x = 1 + rand() % 6;
             int y = 1 + rand() % 6;
             ++sum[x + y];
         }
         
     printf("%10s%10s%10s%10s\n", "Sum", "Total", "Expected", "Actual");
     
     for(unsigned int j = 2; j<=12; ++j){
         printf("%10u%10u%9.3f%%%9.3f%%\n", j, sum[j], 100.0 * expected[j] / 36, 100.0 * sum[j] / 36000);
     }    
}

prog4(){
    int i;
    double c;

    printf("WELCOME TO THE TEMPERATURE TABLE PROGRAM\n\n");

//Print headers    
    printf("Fahrenheit          Celsius\n");
    
//Print table entries
    for(i =1; i<=212; ++i){
        c =  5.0 / 9.0 * (i - 32);
        printf("%9d           %.3f\n", i, c);
    }    
}