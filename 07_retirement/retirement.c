#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

struct _balance_info {
  int age;
  double amount;
};
typedef struct _balance_info balance_info;

double updateBalance(double balance, double rate, double contribution){
  balance = (balance*(1+rate))+contribution;
  return balance;
}

balance_info printBalances(balance_info balanceData, retire_info retiring){
  for (int i=0; i<retiring.months; i++){
    printf("Age %3d month %2d you have $%.2lf\n", balanceData.age/12, balanceData.age%12, balanceData.amount);
    balanceData.amount = updateBalance(balanceData.amount, retiring.rate_of_return, retiring.contribution);
    balanceData.age +=1;
  }
}

void retirement(int startAge, //in months
		double initial, //initial savings in dollars
		retire_info working, //info about working
		retire_info retired){ //info about being retired
  balance_info balanceData;
  balanceData.age = startAge;
  balanceData.amount = initial;
  balanceData = printBalances(balanceData, working);
  printBalances(balanceData, retired);
}

int main(void){
  retire_info work;
  work.months = 489;
  work.contribution = 1000;
  work.rate_of_return = 0.045/12;

  retire_info retire;
  retire.months = 384;
  retire.contribution = -4000;
  retire.rate_of_return = .01/12;

  retirement(327, 21345, work, retire);

  return EXIT_SUCCESS;
}
