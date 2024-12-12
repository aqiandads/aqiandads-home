bool Match(char exp[],int n)
{
    LinkStNode *ls;
    InitStack(ls);
    int i=0;
    ElemType e;
    bool flag = true;
    while(i<n &&flag)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            Push(ls,exp[i]);
        }
        if(exp[i]==')')
        {
            if(GetTop(ls,e))
            {
                if(e=='(')
                {
                    Pop(ls,e);
                }else{
                    flag = false;
                }
            }else{
                flag = false;
            }
        }
        if(exp[i]==']')
        {
            if(GetTop(ls,e))
            {
                if(e=='{')
                {
                    Pop(ls,e);
                }else{
                    flag = false;
                }
            }else{
                flag = false;
            }
        }
        if(exp[i]=='}')
        {
            if(GetTop(ls,e))
            {
                if(e=='{')
                {
                    Pop(ls,e);
                }else{
                    flag = false;
                }
            }else{
                flag = false;
            }
        }
        i++;
    }
    if(!StackEmpty(ls))
    {
        flag = false;
    }
    DestroyStack(ls);
    return flag;
}