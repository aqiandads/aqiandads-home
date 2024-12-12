#include "preseq.cpp"
bool isSubtree(BTNode *b1,BTNode *b2)
{
    SqString s1=PreOrderSeq(b1);
    SqString s2=PreOrderSeq(b2);
    if(KMPIndex(s1,s2)!=-1)
        return true;
    else
        return false;
}
int main()
{
    BTNode *b1,*b2;
    CreateBTree(b1,"A(B(D,E(,G)),C(,F(H,I)))");
    printf("二叉树b1:");DispBTree(b1);printf("\n");
    CreateBTree(b2,"C(,F(H,I))");
    printf("二叉树b2:");DispBTree(b2);printf("\n");
    if(isSubtree(b1,b2))
        printf("结果：b2是b1的子树\n");
    else
        printf("结果：b2不是b1的子树\n");
    DestroyBTree(b1);DestroyBTree(b2);
    return 1;
}