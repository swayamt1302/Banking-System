#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define Max 50

int validate_int(int input, char entry[]) 
{
  if(strcmp(entry, "bal") == 0 && input>0)
    return 1;
  else if(strcmp(entry, "bnk") == 0)
  {
    if(input == 1 || input == 2 || input == 3)
      return 1;
    else
      return 0;
  }
  return 1;
}
// ------------------------------------------------------------------------------------------------------------------------------
int validate_char(char input, char entry[]) 
{
  if (strcmp(entry, "gen") == 0) 
  {
    if (input == 'M' || input == 'F')
      return 1;
    else
      return 0;
  } 
  else if (strcmp(entry, "atype") == 0)
  {
    if (input == 'C' || input == 'S')
      return 1;
    else
      return 0;
  }
  return 0;
}
// -------------------------------------------------------------------------------------------------------------------------
char* strupr(char* str) {
  for(int i = 0; str[i]; i++){
    str[i] = toupper(str[i]);
  }
  return str;
}
// ------------------------------------------------------------------------------------------------------------------------
int validate_str(char input[], char entry[]) 
{
  int num_words = 1;
  if(strcmp(entry, "anm") == 0)
  {
    for (int i = 0; i < strlen(input); i++) 
    {
      if (input[i] == ' ')
        num_words += 1;
      else if(isalpha(input[i]) == 0)
        return 0;
    }
    if(num_words != 3)
      return 0;
  }
  else if(strcmp(entry, "pan") == 0)
  {
    if(strlen(input) != 10)
      return 0;
    for(int i=0;i<5;i++)
    {
      if(isalpha(input[i]) == 0)
        return 0;
    }
    for(int i=5;i<9;i++)
    {
      if(isdigit(input[i]) == 0)
        return 0;
    }
    if(isalpha(input[9]) == 0)
      return 0;
  }
  else if(strcmp(entry, "aadhar") == 0)
  {
    if(strlen(input) != 12)
      return 0;    
    for(int i=0;i<strlen(input);i++)
    {
      if(isdigit(input[i]) == 0)
        return 0;
    }
  }
  else if(strcmp(entry, "cty") == 0 || strcmp(entry, "addr") == 0)
  {
    if(strlen(input) > 0)
      return 1;
    else
      return 0;
  }
  else if(strcmp(entry, "dob") == 0)
  {
    for(int i=0;i<10;i++)
      {
          if(input[i] == '/' && i != 2 && i != 5)
            return 0;
          else if(i!=2 && i!=5 && isdigit(input[i]) == 0)
            return 0;
      }

    int age;
    char year[5];
    for(int i=0;i<5;i++)
      {
        year[i] = input[i+6];
      }
    age = 2023 - atoi(year);
    if(age < 18)
    {
      printf("Age cannot be less than 18 !!\n");
      return 0;
    }
    return 1;
  }
  return 1;
}
// ----------------------------------------------------------------------------------------------------------------------------------------