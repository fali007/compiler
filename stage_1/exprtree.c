#include<stdio.h>
struct tnode* makeLeafNode(int n){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}
/*void preorder(struct tnode *tnode)
{
    if(tnode->op!=NULL)
      printf("%c",*tnode->op);
     else
     printf("%d",tnode->val);
      
  preorder(tnode->left);
  preorder(tnode->right);

}*/

int evaluate(struct tnode *t){
    if(t->op == NULL){
      //  printf("%d\n",t->val);
        return t->val;
    }
    else{
        switch(*(t->op)){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
    }
}

int getReg(){
    if(nextReg==21){
        printf("register overflow");
        return nextReg++;
    }
    else{
        return nextReg++;
    }
}

void freeReg(){
    nextReg--;
}

int codegen(struct tnode* root, FILE* fout)
{  

    if(root->op == NULL)
    {
        int reg = getReg();
        fprintf(fout,"MOV R%d, %d\n",reg,root->val);
        return reg;
    }
    int leftReg = codegen(root->left,fout);
    int rightReg = codegen(root->right,fout);
    switch(*(root->op))
    {
        case '+' : fprintf(fout,"ADD R%d, R%d\n",leftReg,rightReg); freeReg(); break;
        case '-' : fprintf(fout,"SUB R%d, R%d\n",leftReg,rightReg); freeReg(); break;
        case '*' : fprintf(fout,"MUL R%d, R%d\n",leftReg,rightReg); freeReg(); break;
        case '/' : fprintf(fout,"DIV R%d, R%d\n",leftReg,rightReg); freeReg(); break;
    }
    return leftReg;

}

void initialize(FILE* fout)
{

    fprintf(fout,"0\n2056\n0\n0\n0\n0\n0\n0\n");
}

void storeReg0(FILE *fout, char static_var)
{ 
    int address = 4096 + static_var - 'a';
    fprintf(fout,"MOV [%d], R0\n",address);
}

void print_static_var(FILE *fout, char static_var)
{ 

    int address = 4096 + static_var - 'a';
    fprintf(fout,"MOV R1, \"Write\"\n");
    fprintf(fout,"PUSH R1\n");
    fprintf(fout,"MOV R1,-2\n");
    fprintf(fout,"PUSH R1\n");
    fprintf(fout,"MOV R0,[%d]\n",address);
    fprintf(fout,"PUSH R0\n");
    fprintf(fout,"PUSH R0\n");
    fprintf(fout,"PUSH R0\n");
    fprintf(fout,"CALL 0\n");
    fprintf(fout,"POP R0\n");
    fprintf(fout,"POP R0\n");
    fprintf(fout,"POP R0\n");
    fprintf(fout,"POP R0\n");
    fprintf(fout,"POP R0\n");
}