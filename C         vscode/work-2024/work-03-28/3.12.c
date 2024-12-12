void Reverse(SqQueue *&qu)
{
    ElemType e;
    SqStack *st;
    InitStack(st);
    while(!QueueEmpty(qu))
    {
        deQueue(qu,e);
        Push(st,e);
    }
    InitQueue(qu);
    while(!StackEmpty(st))
    {
        Pop(st,e);
        enQueue(qu,e);
    }
    DestroyStack(st);
}