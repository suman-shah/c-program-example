#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct BST{

    int data;
    struct BST *lc;
    struct BST *rc;

}node;

node * newNode(int el){

    node *new = (node*)calloc(1,sizeof(node));

    new->data = el;
    new->lc = NULL;
    new->rc = NULL;

    return new;
}

void insertNode(node **root, int el){

    if((*root) == NULL){
        (*root) = newNode(el);
    }

    else if(el > (*root)->data){
        insertNode(&((*root)->rc), el);
    }
    else{
        insertNode(&((*root)->lc), el);
    }

}

void inorder(node *root){

    if(root != NULL){
        inorder(root->lc);
        printf("%d ",root->data);
        inorder(root->rc);
    }

}

int findMaximum(node *root, int max){

    if(root == NULL){
        return max;
    }
    max = root->data;
    findMaximum(root->rc, max);
    
}

void search(node **root, int el);

void deletion(node **root){

    if((*root)->lc == NULL && (*root)->rc == NULL){     // 0 Children

        (*root) = NULL;
    
    }
    else if(!(*root)->lc || !(*root)->rc){              // 1 Child

        if(!(*root)->lc){
            (*root) = (*root)->rc;
        }
        else{
            (*root) = (*root)->lc;
        }

    }
    else{                                               // 2 Children
        
        int max = findMaximum((*root)->lc, INT_MIN);
        (*root)->data = max;

        search(&((*root)->lc), max);

    }

}

void search(node **root, int el){

    if((*root) == NULL){
        printf("No such element in the BST !!\n");
        return;
    }
    else if(el > (*root)->data){
        search(&((*root)->rc), el);
    }
    else if(el < (*root)->data){
        search(&((*root)->lc), el);
    }
    else{
        deletion(&(*root));
    }

}

int main(){

    node *root = NULL;
    
    int n, el, i, check = 1;
    printf("Number of elements ? ");
    scanf("%d",&n);

    printf("Enter %d elements : ",n);
    for (i = 0; i < n; i++){
        scanf("%d",&el);
        insertNode(&root, el);
    }

    char option;
    printf("\nChoose option : (a) Delete an element from the BST , (b) Print the BST in inorder , (c) Ends the program\n\n");

    while(check){
        scanf(" %c",&option);
        switch(option){
        
            case 'a':
                printf("Enter the element you want to delete : ");
                scanf("%d",&el);
                search(&root, el);
                break;
            case 'b':
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;
            case 'c':
                printf("\n__Program End__\n\n");
                check = 0;
                break;
        }
    }
    
}