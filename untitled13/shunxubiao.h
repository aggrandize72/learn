#include <stdio.h>
void shunxubiao(){
    int n1,n2;
    printf ("请输入第一个多项式最大次项的次数（不大于10）：");
    scanf ("%d",&n1);
    int a[11]={0},b[11]={0},c[11];
    printf ("请输入常数项：");
    scanf("%d",&a[0]);
    for (int i = 1; i <= n1; ++i) {
        printf ("请输入x的%d次方的系数：",i);
        scanf ("%d",&a[i]);
    }
    printf ("请输入第二个多项式最大次项的次数（不大于10）：");
    scanf ("%d",&n2);
    printf ("请输入常数项：");
    scanf("%d",&b[0]);
    for (int i = 1; i <= n2; ++i) {
        printf ("请输入x的%d次方的系数：",i);
        scanf ("%d",&b[i]);
    }
    printf("多项式为y=%d",a[0]+b[0]);
    int n3 = n1 > n2 ? n1 : n2;
    for (int i = 1; i <= n3; ++i) {
        c[i] = b[i] + a[i];
        if (c[i]){
            printf("+%dx%d", c[i],i);
        }
    }
}