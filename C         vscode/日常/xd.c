#include<stdio.h>
#include<stdlib.h>

int xian3(int a[]){
    int sum,sun,answer;
    sum = a[0]*a[4]*a[8] + a[1]*a[5]*a[6] + a[2]*a[3]*a[7];
    sun = a[0]*a[5]*a[7] + a[1]*a[3]*a[8] + a[2]*a[4]*a[6];
    answer = sum - sun;
    return answer;
}

int main()
{
    printf("“ヾ(≧▽≦*)o” 想宝酱,你好呀！\n\n");

    int flag = 1;
    while (flag == 1) {
        int a[9],b[4][4],n;
        printf("需要计算几阶行列式: ");
        scanf("%d",&n);
        printf("请输入数据:\n");
        if(n==3)
        {
            int i;
            for(i = 0;i < 9;i++)
            {
                scanf("%d",&a[i]);
            }
            int answer = xian3(a);
            printf("计算结果: %d",answer);
        }
        if(n==4)
        {

            int i,j;
            int answer1,answer2,answer3,answer4,result;
            for(i = 0;i < 4;i++)
            {
                for(j = 0;j < 4;j++)
                {
                    scanf("%d",&b[i][j]);
                }
            } 
            for(i = 0,n = 0;i < 4;i++){
                if(i != 0)
                {
                    for(j = 0;j < 4;j++)
                    {
                        if(j != 0)
                        {
                            a[n] = b[i][j];
                            n++;
                        }
                    }
                }
            }
            
            answer1 = xian3(a);
            answer1 = b[0][0] * answer1;

            for(i = 0,n = 0;i < 4;i++){
                if(i != 1)
                {
                    for(j = 0;j < 4;j++)
                    {
                        if(j != 0)
                        {
                            a[n] = b[i][j];
                            n++;
                        }
                    }
                }
            }
            
            answer2 = xian3(a);
            answer2 = b[1][0] * answer2;

            for(i = 0,n = 0;i < 4;i++){
                if(i != 2)
                {
                    for(j = 0;j < 4;j++)
                    {
                        if(j != 0)
                        {
                            a[n] = b[i][j];
                            n++;
                        }
                    }
                }
            }
            
            answer3 = xian3(a);
            answer3 = b[2][0] * answer3;

            for(i = 0,n = 0;i < 4;i++){
                if(i != 3)
                {
                    for(j = 0;j < 4;j++)
                    {
                        if(j != 0)
                        {
                            a[n] = b[i][j];
                            n++;
                        }
                    }
                }
            }
            
            answer4 = xian3(a);
            answer4 = b[3][0] * answer4;

            result = answer1 - answer2 + answer3 - answer4;
            printf("计算结果:%d",result);
        }
        
        printf("\n");
        printf ("请输入您的选择(1:继续 ; 2:退出): ");
        scanf("%d", &flag);
        printf("\n");
    }
    return 0;
}