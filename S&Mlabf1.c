#include<stdio.h>
#include <math.h>
#include <time.h>

double U_Random();
int possion();


void main ()
{
    int cust_no[20],i,j;

int p[20],at[20],iat[20];

printf("\nCustomer No.\tInterarrival Time\tArrival Time\n");

iat[0]=0;at[0]=0;
for(j=1;j<20;j++){
     p[j] =possion();
  iat[j]=p[j];
  at[j]=at[j-1]+iat[j];
}
for(j=0;j<20;j++)
printf ("\t%d\t\t%d\t\t%d\n",j+1,iat[j],at[j]);
printf("\nThe Random Number Using Poisson Distribution\n ");
for(j=1;j<20;j++)
printf ("%d\t",p[j]);
}



int possion()/* generates a random number with a Poisson distribution. Lamda is the average number */
{
int Lambda =1, k =1;
long double p = 1.0;
long double l = exp(-Lambda);/* it is defined as long double for precision, and exp (-Lambda) is a decimal near 0 */
//printf ("%.12f\n", l );
while (p>= l)
        {
double u = U_Random();
p*= u;
k++;

    }

return k;
}

double U_Random()/* generates a 0 ~ Random number between 1 */
{
double f;
f= (float) (rand ()%10 );
return f/10;
}
