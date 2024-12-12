(1).A,D均合法,B,C不合法
(2).

bool judge(char str[],int n)
{
    int i=0;
    ElemType x;
    LinkStNode *ls;
    bool flag = true;
    InitStack(ls);
    while(i<n && flag)
    {
        if(str[i] == 'I')
        {
            Push(ls,str[i]);
        }else{
            if(str[i] == 'O')
            {
                if(StackEmpty(ls))
                {
                    flag = false;
                }else{
                    Pop(ls,x);
                }
            }else{
                flag = false;
            }
            i++;
        }
    }
    if(!StackEmpty(ls)){
        flag = false;
    }
    DestroyStack(ls);
    return flag;
}