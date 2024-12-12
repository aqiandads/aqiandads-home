#include<stdio.h>
#include<string.h>

void replace(char *str,char *fstr,char *rstr);

int main(){
  char original_str[] = "iffordowhileelsewhilebreak";
  char search_str[] = "while";
  char replace_str[] = "struct";

  replace(original_str,search_str,replace_str);

  printf("%s\n",original_str);
}

void replace(char *str,char *fstr,char *rstr){
  long int fstr_len = strlen(fstr);
  long int rstr_len = strlen(rstr);

  for(int i = 0;i <= (strlen(str) - fstr_len);i++){
    if(strcmp(str + i,fstr) == 0){
      for(int j = 0;j < rstr_len;j++){
        str[i + j] = rstr[j];
      }
      i += fstr_len - 1;
    }
  }
  printf("%s\n",str);
}