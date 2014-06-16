//
//  main.c
//  Matrix_Multiplication
//
//  Created by ptbsare on 14-6-5.
//  Copyright (c) 2014年 ptbsare. All rights reserved.
//

#include "header.h"
int main(int argc, const char * argv[])
{

    // insert code here...
    struct data *p1;
    //struct data *p2;
    //struct data *p3;
    //struct data *p4;
    //p=create_array(30);
    //p1=get_array();
    //p2=get_array();
    //p3=multi_arrray(p1, p2);
    //p2=copy_arrary(p1);
    //print_array(p2);
    //modify_array(p2, 3, 5.6);
    //print_array(p2);
    //printf("%lg\n",value_array(p2,3));
    //print_matrix(create_matrix(3, 2));
    p1=create_matrix(10, 10);
    //struct data *p2=p1;
    //p2=create_matrix(100, 3);
    //p3=copy_matrix(p2);
    //p1=get_matrix();
    //p2=get_matrix();
    //p4=multi_matrix(p1, p2);
    //print_matrix(p1);
    //printf("\n");
    //print_matrix(p2);
    //printf("\n");
    //print_matrix(p3);
    //print_matrix(p4);
    //print_matrix(init_u0_matrix(p1, 5));
    ///print_matrix(recur_matrix(init_u0_matrix(p1, 5), 100));
    //print_matrix(recur_matrix(init_u0_matrix(p1, 5), 1));
    //modify_matrix(p1, 10, 10, 1.25);
    //print_matrix(p2);
    //printf("\n%lg\n",value_matrix(p1, 1, 10));
    print_matrix(multi_sparse_matrix());
    //printf("Hello, World!\n");
    //getchar();
    return 0;
}

