#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
struct TreeNode* root;

//将n个子女节点插入到parent中，修改parent的line,numChildrean和Children
void insert(int type,struct TreeNode* parent,int n,...){
    // printf("insert\n");    
    parent->numChildren = n;
    parent->type = type;
    if(n == 0){
        return;//规约出空串，则行号什么也无效了
    }
    parent->children = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*n);    
    struct TreeNode* tmp = NULL;
    va_list vl;
    va_start(vl,n);
    for(int i = 0;i < n;++i){
        tmp = va_arg(vl,struct TreeNode*);
        if(i == 0){
            parent->line = tmp->line;
        }
        parent->children[i] = tmp;
    }
    va_end(vl);
}