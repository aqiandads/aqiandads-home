void Output(BTNode * p)
{
    if (p!= NULL)
    {
        printf("&c", p->data);
        Output(p->lchild);
        Output(p->rchild);
    }
}

void Child(BTNode * b, char x)
{
    if(b!= NULL)
    {
        if(b->data == x)
        {
            if (b->lchild!= NULL)
                Output(b->lchild); 
            if (b->rchild!= NULL)
                Output(b->rchild); 
                return;
        }
        Child(b->lchild,x);
        Child(b->rchild, x);
    }
}