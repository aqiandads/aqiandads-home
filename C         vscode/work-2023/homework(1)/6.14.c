#include<stdio.h>

int main()
{
    int man,woman,child;
    for(man = 1;man<=30;man++){
        for(woman = 1;woman<=30-man;woman++){
            for(child = 1;child<=30 - man - woman;child++){
                if(3*man + 2*woman + child ==50){
                    printf("%d %d %d\n",man,woman,child);
                }
            }
        }
    }
}
