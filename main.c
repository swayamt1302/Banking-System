
#include "functions.h"
#include "validate.h"

struct BankAccount acc[50];
int counter = 0; 

void acceptAndValidate(char dtype[], char entry[], struct BankAccount *acc) {
  int isValid = 0;
  int iter = 0;
  do 
  {
    if (strcmp(dtype, "char") == 0) 
    {
      char char_input;
      scanf("%c", &char_input);
      isValid = validate_char(char_input, entry);
      if (isValid == 0)
      {
        printf("Enter Valid Input\t");
        getchar();
      }
      else
      {
        if (strcmp(entry, "gen") == 0)
          acc->Gender = char_input;
        else if (strcmp(entry, "atype") == 0)
          acc->AccountType = char_input;
      }
    } 
    else if (strcmp(dtype, "int") == 0) 
    {
      int int_input;
      scanf("%d", &int_input);
      isValid = validate_int(int_input, entry);
      if(isValid == 0)
      {
        printf("Enter Valid Input\t");
        getchar();
      }
      else
      {
        if (strcmp(entry, "bal") == 0)
          acc->Balance = int_input;
      }
    } 
    else if (strcmp(dtype, "str") == 0) 
    {
      char str_input[Max];
      fgets(str_input, Max, stdin);
      str_input[strlen(str_input) - 1] = '\0';
      isValid = validate_str(str_input, entry);
      if (isValid == 0)
        printf("Enter Valid Input\t");
      else
      {
        if (strcmp(entry, "anm") == 0)
          strcpy(acc->AccountHolderName, str_input);
        else if (strcmp(entry, "pan") == 0)
          strcpy(acc->Pan, str_input);
        else if (strcmp(entry, "aadhar") == 0)
          strcpy(acc->AAdhar, str_input);
        else if (strcmp(entry, "bnk") == 0)
          strcpy(acc->BankName, str_input);
        else if (strcmp(entry, "city") == 0)
          strcpy(acc->City, str_input);
        else if (strcmp(entry, "addr") == 0)
          strcpy(acc->Address, str_input);
        else if(strcmp(entry, "dob") == 0)
          strcpy(acc->dob, str_input);
      }
    }
  } while (isValid != 1); 
}
// -----------------------------------------------------------------------------------------------------------------------------------------
void acceptDets() 
{
  printf("Enter the account name : \t");
  acceptAndValidate("str", "anm", &acc[counter]);
  printf("Enter the gender (M/F) : \t");
  acceptAndValidate("char", "gen", &acc[counter]);
  getchar();
  printf("Enter Date of Birth (DD/MM/YYYY) : \t");
  acceptAndValidate("str", "dob", &acc[counter]);
  printf("Enter the bank name : \n 1) ICICI \n 2) Axis \n 3) HDFC \n");
  acceptAndValidate("int", "bnm", &acc[counter]);
  getchar();
  printf("Enter PAN Number : \t");
  acceptAndValidate("str", "pan", &acc[counter]);
  printf("Enter Aadhar Number : \t");
  acceptAndValidate("str", "aadhar", &acc[counter]);
  printf("Enter the account type (Savings(S)/Cuurent(C)) : \t");
  acceptAndValidate("char", "atype", &acc[counter]);
  getchar();
  printf("Enter the address : \t");
  acceptAndValidate("str", "addr", &acc[counter]);
  printf("Enter the city : \t");
  acceptAndValidate("str", "city", &acc[counter]);
  printf("Enter balance : \t");
  acceptAndValidate("int", "bal", &acc[counter]);
  getchar();

  if (strcmp(acc[counter].BankName, "ICICI")) {
    strcpy(acc[counter].IFSC, "ICICI0000");
  } else if (strcmp(acc[counter].BankName, "Axis")) {
    strcpy(acc[counter].IFSC, "AXIS0000");
  } else {
    strcpy(acc[counter].IFSC, "HDFC0000");
  }

  generateAccNo(acc[counter].AccountHolderName, &acc[counter]);
  int age = getAge(acc[counter].dob, &acc[counter]);
  counter += 1;

}

// ----------------------------------------------------------------------------------------------------------------------------------------

void searchAcc()
{
  // printf("Array Length : %d\n", counter);
  int choice;
  char accNo[7];
  int flag = 0;
  char accName[Max];
  char accType;
  do 
  {
    int search  = 0;
    printf("Choose the search criteria : \n");
    printf(" 1. Search by Account Number \n 2) Search by Name\n 3) Search by Account Type\n 0) Exit\n");
    scanf("%d", &choice);
    getchar();
    switch(choice)
    {
      case 1:
        printf("Enter Account Number (Eg : ABC123) : \t");
        fgets(accNo, Max, stdin);
        accNo[strlen(accNo)-1] = '\0';
        if(checkLength(accNo, 6))
        {
          printf("Invalid Account Number !! \n");
          break;
        }
        for(int i = 0;i<counter;i++)
        {
          if(strcmp(acc[i].AccountNumber, accNo) == 0)
          {
            printf("Account Found !! \n");
            printf("Account Number\t Account Name\t Account Type\t Address \t City \t Balance\n ");
            printDets(&acc[i]);
          }
          else
            printf("Account Not Found !! \n");
        }
        break;
      case 2:
        printf("Enter Account Holder Name : \t");
        fgets(accName, Max, stdin);
        accName[strlen(accName)-1] = '\0';
        for(int i = 0;i<counter;i++)
        {
          if(strcmp(acc[i].AccountHolderName, accName) == 0)
          {
            printf("Account Found !! \n");
            printf("Account Number\t Account Name\t Account Type\t Address \t City \t Balance\n ");
            printDets(&acc[i]);
          }
          else
            printf("Account Not Found !! \n");
        }
        break;
      case 3:
        printf("Enter Account Type : \t");
        scanf("%c", &accType);
        getchar();
        for(int i = 0;i<counter;i++)
        {
          if(acc[i].AccountType == accType)
          {
            printf("Account Number\t Account Name\t Account Type\t Address \t City \t Balance\n ");
            printDets(&acc[i]);
          }
             
        }
        break;
      case 0:
        flag = 1;
        break;
    }
  }while(flag == 0);
}

// -------------------------------------------------------------------------------------------------------------------------------------------

void updateDets()
{
  char accNo[7];
  printf("Enter Account Number (Eg : ABC123) : \t");
  fgets(accNo, Max, stdin);
  accNo[strlen(accNo)-1] = '\0';
  if(checkLength(accNo, 6))
    {
      printf("Invalid Account Number !! \n");
      return;
    }
  for(int i=0;i<counter;i++)
  {
    if(strcmp(acc[i].AccountNumber, accNo) == 0)
    {
      printf("Update : \n 1) Address\n 2) City\n 0) Exit\n ");
      int choice;
      scanf("%d", &choice);
      getchar();
      switch(choice)
      {
        case 1:
          printf("Previous Address : \t %s\n", acc[i].Address);
          printf("Enter New Address : \t");
          acceptAndValidate("str", "addr", &acc[i]);
          printf("Address changed successfully...\n");
          break;
        case 2:
          printf("Previous City : \t %s\n", acc[i].City);
          printf("Enter New City : \t");
          acceptAndValidate("str", "city", &acc[i]);
          printf("Address changed successfully...\n");
          break;
        case 0:
          return;
      }
    }
  }
}

// -----------------------------------------------------------------------------------------------------------------------------------------

void checkBalance()
{
    char accNo[7];
    printf("Enter Account Number (Eg : ABC123) : \t");
    fgets(accNo, Max, stdin);
    accNo[strlen(accNo)-1] = '\0';
    if(checkLength(accNo, 6))
      {
        printf("Invalid Account Number !! \n");
        return;
      }
    for(int i=0;i<counter;i++)
    {
      if(strcmp(acc[i].AccountNumber, accNo) == 0)
      {
       printf("Account Number \t Balance \n");
       printf("%s \t %d\n", accNo, acc[i].Balance);
       return;
      }
    }
    printf("Account Not Found...\n");
    return;
}

// ------------------------------------------------------------------------------------------------------------------------------------------

void depositOrWithdraw(int type)
{
  char accNo[7];
  printf("Enter Account Number (Eg : ABC123) : \t");
  fgets(accNo, Max, stdin);
  accNo[strlen(accNo)-1] = '\0';
  if(checkLength(accNo, 6))
    {
      printf("Invalid Account Number !! \n");
      return;
    }
  for(int i=0;i<counter;i++)
    {
      if(strcmp(acc[i].AccountNumber, accNo) == 0)
      {
        int amount;
        if(type == 1)
        {
          printf("Enter Amount to Deposit : \t");
          scanf("%d", &amount);
          getchar();
          acc[i].Balance += amount;
          printf("Deposit Successful...\n");
          return;
        }
        else
        {
          printf("Enter Amount to Withdraw : \t");
          scanf("%d", &amount);
          getchar();
          if(amount > acc[i].Balance)
          {
            printf("Insufficient Balance...\n");
            return;
          }
          else
          {
            acc[i].Balance -= amount;
            printf("Withdraw Successful...");
            return;
          }
        }
      }
    }
}

// ----------------------------------------------------------------------------------------------------------------------------------------------

void transferMoney()
{
  int amnt;
  char senderAccNo[7];
  char receiverAccNo[7];
  printf("Enter Sender's Account Number (Eg : ABC123) : \t");
  fgets(senderAccNo, Max, stdin);
  senderAccNo[strlen(senderAccNo)-1] = '\0';
  if(checkLength(senderAccNo, 6))
  {
    printf("Invalid Account Number !! \n");
    return;
  }
  else
  {
    for(int i=0;i<counter;i++)
      {
        if(strcmp(acc[i].AccountNumber, senderAccNo) == 0)
        {
          printf("Enter Receiver's Account Number (Eg : ABC123) : \t");
          fgets(receiverAccNo, Max, stdin);
          receiverAccNo[strlen(receiverAccNo)-1] = '\0';
          if(checkLength(receiverAccNo, 6))
          {
            printf("Invalid Account Number !! \n");
            return;
          }
          else
          {
            for(int j=0;j<counter;j++)
              {
                if(strcmp(acc[j].AccountNumber, receiverAccNo) == 0)
                {
                  printf("Enter Amount to Transfer : \t");
                  scanf("%d", &amnt);
                  getchar();
                  if(amnt > acc[i].Balance)
                  {
                    printf("Insufficient Balance...");
                    return;
                  }
                  else
                  {
                    acc[i].Balance -= amnt;
                    acc[j].Balance += amnt;
                    printf("Transfer Successful...");
                    return;
                  }
                }
              }
          }
        }
      }
  }
}

// ----------------------------------------------------------------------------------------------------------------------------------------

 
int main() 
{
  int flag = 0;
  int opt;
  do
  {
    printf("Please select an option : \n");
    printf(" 1) Add Bank Account\n 2) Search Bank Account\n 3) Update Account Details\n 4) Check Balance\n");
    printf(" 5) Deposit Money\n 6) Withdraw Money\n 7) Transfer Money\n 0) Exit\n");
    scanf("%d", &opt);
    getchar();
    switch (opt) 
    {
      case 1:
        acceptDets();
        break;
      case 2:
        searchAcc();
        break;
      case 3:
        updateDets();
        break;
      case 4:
        checkBalance();
        break;
      case 5:
        depositOrWithdraw(1);
        break;
      case 6:
        depositOrWithdraw(-1);
        break;
      case 7:
        transferMoney();
        break;
      case 0:
        flag = 1;
        break;
      default:
        printf("Enter valid option\n");
    }
  }while(flag == 0);
  return 0;
}
