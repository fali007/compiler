#include<stdio.h>
int var_array[26];
int g=0;
/*
struct tnode* makeLeafNode(int n){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(int val,int type,char* c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}
*/
/*void preorder(struct tnode *tnode)
{
    if(tnode->op!=NULL)
      printf("%c",*tnode->op);
     else
     printf("%d",tnode->val);
      
  preorder(tnode->left);
  preorder(tnode->right);

}*/

struct tnode* createTree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val=val;
    temp->type=type;
    temp->nodetype=nodetype;
    if(varname!=NULL){
        temp->varname=(char*)malloc(sizeof(char));
        *(temp->varname)=varname;
    }
    else{
        temp->varname=NULL;
    }
    temp->left=l;
    temp->right=r;
    return temp;
}

/*
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
*/

int evaluate(struct tnode* t){
    int lval,rval;
    int varct;
    switch((t->nodetype)){
        case CONN:
            if(t->left!=NULL){
                lval=evaluate(t->left);
            }
            if(t->right!=NULL){
                rval=evaluate(t->right);
                return rval;
            }
        break;
        case VAR:
            varct=*(t->varname)-'a';
            return var_array[varct];
        break;
        case ASSGN:
            varct=*(t->left->varname)-'a';
            rval=evaluate(t->right);
            var_array[varct]=rval;
            return rval;
        break;
        case CONSTANT:
            return t->val;
        break;
        case EX:
            switch(*(t->varname)){
            case '+' : return evaluate(t->left) + evaluate(t->right);
                       break;
            case '-' : return evaluate(t->left) - evaluate(t->right);
                       break;
            case '*' : return evaluate(t->left) * evaluate(t->right);
                       break;
            case '/' : return evaluate(t->left) / evaluate(t->right);
                       break;
        }
        case READ:
            varct=*(t->left->varname)-'a';
            scanf("%d",&var_array[varct]);
            return var_array[varct];
        break;
        case WRITE:
            rval=evaluate(t->left);
            printf("%d\n",rval);
            return rval;
        break;
    }
}

void tnode_print(struct tnode *t){
  printf("\n[");
  printf("val %d\n",t->val);
  printf("type %d\n",t->type);
  printf("nodetype %d\n",t->nodetype);
  switch(t->nodetype){
  case 1:
    printf("EXPR\n");
    break;
    case 2:
    printf("ASSGN\n");
    break;
    case 3:
    printf("CONN\n");
    break;
    case 4:
    printf("CONSTANT\n");
    break;
    case 5:
    printf("READ\n");
    break;
    case 6:
    printf("VAR\n");
    break;
    case 7:
    printf("WRITE\n");
    break;
   
  }
  
  if(t->varname!=NULL)
    printf("varname %c\n",*(t->varname));
    printf("]\n");
}

void inorder(struct tnode *t){
  if(t==NULL)
    return;
  inorder(t->left);
  tnode_print(t);
  inorder(t->right);

}

int getreg(){
    if(g==21){
        printf("register overflow");
        return g++;
    }
    else{
        return g++;
    }
}

void freereg(){
    g--;
}

/*
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
*/

reg_index codeGen( struct tnode *t) {
  int x,y,z;
  int l,m,n;
   
 switch(t->nodetype){
 
          
    case READ:                //considering only one small letter var and assigning in top of stack..........
        x=getreg();
        int stackpos;
        stackpos=4096+(*(t->left->varname))-'a';
        fprintf(xsm_fl,"MOV R%d, \"%s\"\n",x,"Read");
            fprintf(xsm_fl,"PUSH R%d\n",x);
            fprintf(xsm_fl,"MOV R%d, %d\n",x,-1);
            fprintf(xsm_fl,"PUSH R%d\n",x);
            fprintf(xsm_fl,"MOV R%d, %d\n",x,stackpos);
                   fprintf(xsm_fl,"PUSH R%d\n",x);
                    fprintf(xsm_fl,"PUSH R0\n");
            fprintf(xsm_fl,"PUSH R0\n");
            fprintf(xsm_fl,"CALL 0\n");
            fprintf(xsm_fl,"POP R%d\n",x);
            fprintf(xsm_fl,"POP R0\n");
            fprintf(xsm_fl,"POP R0\n");
            fprintf(xsm_fl,"POP R0\n");
            fprintf(xsm_fl,"POP R0\n");     
        return x;
        break;
    case WRITE:
        x=getreg();
        l=codeGen(t->left);
        fprintf(xsm_fl,"MOV R%d, \"%s\"\n",x,"Write");
            fprintf(xsm_fl,"PUSH R%d\n",x);
            fprintf(xsm_fl,"MOV R%d, %d\n",x,-2);
            fprintf(xsm_fl,"PUSH R%d\n",x);
                    fprintf(xsm_fl,"PUSH R%d\n",l);
                    fprintf(xsm_fl,"PUSH R0\n");
            fprintf(xsm_fl,"PUSH R0\n");
            fprintf(xsm_fl,"CALL 0\n");
            fprintf(xsm_fl,"POP R%d\n",x);
            fprintf(xsm_fl,"POP R0\n");
            fprintf(xsm_fl,"POP R0\n");
            fprintf(xsm_fl,"POP R0\n");
            fprintf(xsm_fl,"POP R0\n");
        freereg();
        return x;
        break;
    case CONSTANT:
        x=getreg();
                fprintf(xsm_fl,"MOV R%d, %d\n",x,t->val);
        return x;
        break;  
    case CONN:
        if(t->left)
            {
            l= codeGen(t->left);
            freereg();
            
            }       
        if(t->right)
            {   
            l= codeGen(t->right);
            freereg();          
            }
            return l;
            break;
    case VAR:
            x=4096+*(t->varname)-'a';
            y=getreg();
            fprintf(xsm_fl,"MOV R%d, [%d]\n",y,x);
            return y;
            break;
    case ASSGN:
            m=codeGen(t->right);
                x=4096+*((t->left)->varname)-'a';
            fprintf(xsm_fl,"MOV [%d],R%d\n",x,m);
            return m;
            break;                            
    case EX:
         l=codeGen(t->left);
         m=codeGen(t->right);
         switch(*(t->varname)){
         
            case '+':
                 fprintf(xsm_fl,"ADD R%d, R%d\n",l,m);
                 freereg();
                 break;
            case '-':        
                 fprintf(xsm_fl,"SUB R%d, R%d\n",l,m);
                     freereg();
                     break;
            case '*':
                 fprintf(xsm_fl,"MUL R%d, R%d\n",l,m);
                     freereg();
                     break;
            case '/':
                 fprintf(xsm_fl,"DIV R%d, R%d\n",l,m);
                 freereg();
                 break;
         }
         return l;
         break;   
 }

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