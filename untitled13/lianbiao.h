#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int xishu;
    int cishu;
    struct node* next;
}node;

void lianbiao(){
    node *p1 = (node*)malloc(sizeof(node*)), *p2 = (node*)malloc(sizeof(node*)),*q1,*q2;
    node *head1=p1,*head2=p2;
    int n1,n2;
    printf("请输入第一个多项式的最大次数：");
    scanf("%d",&n1);
    printf ("请输入常数项系数：");
    scanf("%d",&p1->xishu);
    p1->cishu = 0;
    for (int i = 1; i <= n1 ; ++i) {
        q1 =(node*)malloc(sizeof(node*));
        printf ("请输入x的%d次方的系数：",i);
        scanf("%d",&q1->xishu);
        q1->cishu = i;
        p1->next = q1;
        p1 = p1->next;
    }
    printf("请输入第二个多项式的最大次数：");
    scanf("%d",&n2);
    printf ("请输入常数项系数：");
    scanf("%d",&p2->xishu);
    p2->cishu = 0;
    for (int i = 1; i <= n2 ; ++i) {
        q2 =(node*)malloc(sizeof(node*));
        printf ("请输入x的%d次方的系数：",i);
        scanf("%d",&q2->xishu);
        q2->cishu = i;
        p2->next = q2;
        p2 = p2->next;
    }
    node *print;
    printf("多项式为y=%d",head1->xishu + head2->xishu);
    for (int i = 1; head1->next||head2->next; ++i) {
        print =(node*)malloc(sizeof(node*));
        int h1=0,h2=0;
        if(head1->next) {
            head1 = head1->next;
            h1 = head1->xishu;
        }
        if(head2->next) {
            head2 = head2->next;
            h2 = head2->xishu;
        }
        print->xishu = h1 + h2;
        if (print->xishu){
            printf("+%dx%d", print->xishu,i);
        }
    }
}
