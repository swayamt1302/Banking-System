#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Max 50

struct BankAccount {
  char AccountNumber[8];
  int Age, Balance;
  char Gender;
  char dob[11];
  char BankName[Max], AccountHolderName[Max], IFSC[Max];
  char Pan[Max], AAdhar[Max];
  char AccountType;
  char Address[Max];
  char City[Max];
};


