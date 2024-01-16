#include "structure.h"


void generateAccNo(char accName[], struct BankAccount *acc)
{
  char acc_no[7];
  // printf("%s",accName);
  acc_no[0] = accName[0];
  int counter = 1;
  for(int i=1;i<strlen(accName)-1;i++)
    {
      if(accName[i] == ' ')
      {
        acc_no[counter] = accName[i+1];
        counter++;
      }
    }
  for(int i=3;i<6;i++)
  {
    int rNum = rand() % 10;
    char num = rNum + '0';
    acc_no[i] = num;
  }
  acc_no[6] = '\0';
  printf("Account Number generated successfully !! \n %s \n", acc_no);
  strcpy(acc->AccountNumber, acc_no);
}

// -------------------------------------------------------------------------------------------------------------------------------------------------

void printDets(struct BankAccount *acc)
{
  printf("%s \t %s\t %c \t %s \t %s \t %d\n", acc->AccountNumber, acc->AccountHolderName, acc->AccountType, acc->Address, acc->City, acc->Balance);
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------

int checkLength(char input[], int len)
{
  if(strlen(input) != len)
    return 1;
  else
    return 0;
}

// --------------------------------------------------------------------------------------------------------------------------------------------------

int getAge(char dob[], struct BankAccount *acc)
{
  int age;
  char year[5];
  for(int i=0;i<5;i++)
    {
      year[i] = dob[i+6];
    }
  age = 2023 - atoi(year);
  return age;
}


