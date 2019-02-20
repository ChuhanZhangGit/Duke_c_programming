#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  /*
    month: number of month it's applicable to
    contribution: dollars contributed; if negative
    dollar spent
    rate_of_return
   */
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

double print(int age, double initial, retire_info info){
  int year = age/12;
  int month = age%12;
  for (int i = 1; (i < info.months+1); i++){
    printf("Age %3d month %2d you have $%.2f\n", year, month, initial);
    initial += info.contribution + info.rate_of_return* initial;
    age  += 1;
    year = age/12;
    month = age%12;
  }
  return initial;
}

void retirement(int startAge,
		double initial,
		retire_info working,
		retire_info retired){
  int end_work = startAge + working.months;
  double end_work_saving = print(startAge, initial, working);
  print(end_work, end_work_saving, retired);
}

int main(void){
  retire_info working;
  retire_info retired;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = .045/12;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = .01/12;
  
  retirement(327, 21345, working, retired);
  return EXIT_SUCCESS;
}


  
