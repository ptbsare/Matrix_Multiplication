//
//  functions.c
//  Matrix_Multiplication
//
//  Created by ptbsare on 14-6-5.
//  Copyright (c) 2014年 ptbsare. All rights reserved.
//

struct data *create_array(int n)
{
    int i;
    struct data *p1;
    struct data *p2;
    struct data *p3;
    p1=(struct data *)malloc((sizeof(struct data)));
    p2=p1;
    p3=p1;
    p1->x=n;
    for(i=1;i<=n;i++)
    {
        p2=p1;
        p1=(struct data *)malloc(sizeof(struct data));
        p1->x=i;
        p2->next=p1;
    }
    return p3;
}
void print_array(struct data *p)
{
    int i;
    int n=p->x;
    for(i=1;i<=n;i++)
    {
        p=p->next;
        printf("%lg ",p->value);
    }
    printf("\n");
}
struct data *multi_arrray(struct data *p1,struct data *p2)
{
    int i;
    int n=p1->x<=p2->x?p1->x:p2->x;
    struct data *p3;
    struct data *p4;
    p3=create_array(n);
    p4=p3;
    for(i=1;i<=n;i++)
    {
        p1=p1->next;
        p2=p2->next;
        p3=p3->next;
        p3->value=p1->value*p2->value;
    }
    return p4;
}
struct data *get_array()
{
    int n;
    int i;
    struct data *p;
    struct data *p1;
    printf("Input the n of array: ");
    scanf("%d",&n);
    p=create_array(n);
    p1=p;
    for(i=1;i<=n;i++)
    {
        p=p->next;
        printf("Input the value of number %d : ",i);
        scanf("%lf",&(p->value));
    }
    return p1;
}
struct data *copy_arrary(struct data *p)
{
    int i;
    int n=p->x;
    struct data *p1;
    struct data *p2;
    p1=create_array(n);
    p2=p1;
    for(i=1;i<=n;i++)
    {
        p=p->next;
        p1=p1->next;
        p1->value=p->value;
    }
    return p2;
}
double value_array(struct data *p,int n)
{
    int i;
    if(n>p->x)exit(0);
    for(i=1;i<=n;i++)
    {
        p=p->next;
    }
    return p->value;
}
int modify_array(struct data *p,int n,double value)
{
    int i;
    if(n>p->x)exit(-1);
    for(i=1;i<=n;i++)
    {
        p=p->next;
    }
    p->value=value;
    return 0;
}
struct data *create_matrix(int m,int n)
{
    int i;
    struct data *p1,*p2,*p3;
    p1=(struct data *)malloc(sizeof(struct data));
    p1->x=m;
    p1->y=n;
    p2=p1;
    p3=p1;
    for(i=1;i<=m*n;i++)
    {
        p2=p1;
        p1=(struct data *)malloc(sizeof(struct data));
        p1->x=(i-1)/n+1;
        p1->y=(i%n==0?n:i%n);
        p2->next=p1;
    }
    return p3;
}
void print_matrix(struct data *p)
{
    int j,k;
    int m=p->x;
    int n=p->y;
    for(j=1;j<=m;j++)
    {
        for(k=1;k<=n;k++)
        {
            p=p->next;
            printf("%lg ",p->value);
        }
        printf("\n");
    }
}
double value_matrix(struct data *p,int x,int y)
{
    int j,k;
    int m=p->x;
    int n=p->y;
    for(j=1;j<=m;j++)
    {
        for(k=1;k<=n;k++)
        {
            p=p->next;
            if(p->x==x&&p->y==y)
            {
                return p->value;
            }
        }
    }
    return p->value;
}
int modify_matrix(struct data *p,int x,int y,double value)
{
    if(x>p->x||y>p->y)exit(0);
    int j,k;
    int m=p->x;
    int n=p->y;
    for(j=1;j<=m;j++)
    {
        for(k=1;k<=n;k++)
        {
            p=p->next;
            if((p->x==x)&&(p->y==y))
            {
                p->value=value;
                return 0;
            }
        }
    }
    return 0;
}
struct data *get_matrix()
{
    int m,n;
    int j,k;
    struct data *p;
    struct data *p1;
    printf("Input the m of array: ");
    scanf("%d",&m);
    printf("Input the n of array: ");
    scanf("%d",&n);
    p=create_matrix(m, n);
    p1=p;
    for(j=1;j<=m;j++)
    {
        for(k=1;k<=n;k++)
        {
            p=p->next;
            scanf("%lf",&p->value);
        }
    }
    return p1;
}
struct data *copy_matrix(struct data *p)
{
    int m,n;
    int j,k;
    m=p->x;
    n=p->y;
    struct data *p1;
    struct data *p2;
    p1=create_matrix(m, n);
    p2=p1;
    for(j=1;j<=m;j++)
    {
        for(k=1;k<=n;k++)
        {
            p=p->next;
            p1=p1->next;
            p1->value=p->value;
        }
    }
    return p2;
}
struct data *multi_matrix(struct data *p1,struct data *p2)
{
    double value=0;
    if(p1->y!=p2->x)return NULL;
    struct data *p3,*p4,*p5;
    int m=p1->x;
    int n=p2->y;
    int j,k;
    int i;
    p3=create_matrix(m, n);
    p4=p3;
    p5=p3;
    for(j=1;j<=m;j++)
    {
        for(k=1;k<=n;k++)
        {
            p3=p3->next;
            for(i=1;i<=p1->y;i++)
            {
                value+=value_matrix(p1, j, i)*value_matrix(p2, i, k);
            }
            modify_matrix(p4, j, k, value);
            value=0;
        }
    }
    return p5;
}
struct data *recur_matrix(struct data *p,int q)
{
    int m=p->x;
    int n=p->y;
    int j,k;
    int i;
    struct data *p1=copy_matrix(p);
    struct data *p2=copy_matrix(p);
    struct data *p3;
    //struct data *p4,*p5;
    for (i=1; i<=q; i++)
    {
        p3=p1;
        p1=p2;
        p2=p3;
        for(j=2;j<=m-1;j++)
        {
            for(k=2;k<=n-1;k++)
            {
                modify_matrix(p2, j, k, (value_matrix(p1, j-1, k)+value_matrix(p1, j, k-1)+value_matrix(p1, j+1, k)+value_matrix(p1, j, k+1))/4);
            }
        }
    }
    return p2;
}
struct data *init_u0_matrix(struct data *p,double u0)
{
    int m=p->y;
    int i;
    struct data *p1=copy_matrix(p);
    struct data *p2=p1;
    for (i=1; i<=m; i++)
    {
        p1=p1->next;
        p1->value=u0;
    }
    return p2;
}
struct data *get_sparse_matrix()
{
    int m,n;
    int x,y;
    double v;
    printf("Input the M of the M*N matrix : ");
    scanf("%d",&m);
    printf("Input the N of the M*N matrix : ");
    scanf("%d",&n);
    struct data *p=create_matrix(m, n);
    struct data *p1=p;
    while(1)
    {
        printf("Input x y and the value at A(x,y) (Input 0 0 0 to exit input) - x y v : ");
        scanf("%d %d %lf",&x,&y,&v);
        if(x==0&&y==0&v==0)return p1;
        modify_matrix(p1, x, y, v);
    }
    
}
struct data *multi_sparse_matrix()
{
    printf("Matrix 1 \n");
    struct data *p1=get_sparse_matrix();
    printf("Matrix 2 \n");
    struct data *p2=get_sparse_matrix();
    printf("Matrix 1 * Matrix 2 \n");
    if(!(p1->y==p2->x))return NULL;
    return multi_matrix(p1, p2);
}