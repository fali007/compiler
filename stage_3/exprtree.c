#include<stdio.h>
int var_array[26];
int regct=0;
int label_ct=0;

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

struct label_node* head;
void typecheck(struct tnode *t){  
  switch(t->nodetype){
   case NODE_EX:
            if((t->left->type!=INTEGER) || (t->right->type!=INTEGER)){
                  yyerror("Type mismatch...Expected integer");
                  exit(1);
                  
                }
                break;
   case N_EQ:
   case N_NE:
   case N_GE:
   case N_GT:
   case N_LE:
   case N_LT:
                
        if((t->left->type!=INTEGER) || (t->right->type!=INTEGER)){
                  yyerror("Type mismatch...Expected integer for boolean operaion");
                  exit(1);
                  
                }
                break;
  case NODE_IF:
  case NODE_WHILE:
        if(t->left->type!=BOOLE){
           yyerror("Type mismatch...Expected boolean type");
                  exit(1);
        } 
        break;
  case NODE_REPEAT:
  case NODE_DOWHILE:
        if(t->right->type!=BOOLE){
           yyerror("Type mismatch...Expected boolean type");
                  exit(1);
        } 
        break;
                        
  case NODE_WRITE:
        if((t->left->type != INTEGER)){
            yyerror("Invalid argument type to Write() function");
                exit(1);
        }
            break; 
  case NODE_ASSGN:
        if((t->left->type != INTEGER)){
            yyerror("LHS of '=' operator expect integer type");
            exit(1);  
        } 
        if((t->right->type != INTEGER)){
            yyerror("RHS of '=' operator expect integer type");
            exit(1);  
        }           
  }
}

struct tnode* createTree(int val,int type,char* varname,int nodetype,struct tnode *l,struct tnode *m,struct tnode *r){
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
    temp->left = l;
    temp->right = r;
    temp->mid =m;
    typecheck(temp);
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
        case NODE_CONN:
               if(t->left!=NULL){
                 lval= evaluate(t->left);
                 }
               if(t->right!=NULL){
                  rval=evaluate(t->right);
                  return rval;
                  }  
            break;
        case NODE_VAR:
            varct=*(t->varname)-'a';
            return var_array[varct];
            break;
        case NODE_ASSGN:
            varct=*(t->left->varname)-'a';
            rval=evaluate(t->right);
            var_array[varct]=rval;
            return rval;
            break;          
        case NODE_CONSTANT:
               return t->val;
               break;   
        case NODE_EX:
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
       case NODE_READ:
             varct=*(t->left->varname)-'a';
             scanf("%d",&var_array[varct]);
             return var_array[varct];
             break;
       case NODE_WRITE:                        
           //  varct=*(t->varname)-'a';
             rval=evaluate(t->left);
             printf("%d\n",rval);
             return rval;
             break;
    }
}

void label_insert(struct label_node **head,int break_val,int cont_val){
  struct label_node *temp;
  temp=(struct label_node*)malloc(sizeof(struct label_node));
  temp->break_label_val=break_val;
  temp->continue_label_val=cont_val;
  temp->next=*head;
  *head=temp;
}
int label_pop(struct label_node **head){
    if(*head==NULL){
        return -1; 
    }
    else{
        int temp=(*head)->break_label_val;
        *head=(*head)->next;
        return temp;
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
    case 8:
    printf("N_GT\n");
    break;
    case 9:
    printf("N_GE\n");
    break;
    case 10:
    printf("N_GT\n");
    break;
    case 11:
    printf("N_GT\n");
    break;
    case 12:
    printf("N_GT\n");
    break;
    case 13:
    printf("N_GT\n");
    break;
    case 14:
    printf("NODE_IF\n");
    break;
    case 15:
    printf("NODE_WHILE\n");
    break;
    case 16:
    printf("NODE_DOWHILE\n");
    break;
    case 17:
    printf("NODE_REPEAT\n");
    break;
    case 18:
    printf("NODE_BREAK\n");
    break;
    case 19:
    printf("NODE_CONTINUE\n");
    break;
    case 20:
    printf("NODE_BRKP\n");
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

int getReg(){
  if(regct<20)
  return regct++;
  else{
  printf("Out of Registers..\n"); 
  exit(1);
  }
}

void freeReg(){
  if(regct>0)
    regct--;
}

reg_index codeGen( struct tnode *t) {
  int x,y,z;
  int l,m,n;
  int label1=0;
  int label2=0;
  int label3=0;
  switch(t->nodetype){
    case NODE_READ:                //considering only one small letter var and assigning in top of stack..........
        x=getReg();
        int stackpos;
        stackpos=4096+(*(t->left->varname))-'a';
        backup_stack(x,0);
        xos_call("Read",-1,stackpos,x);
        restore_stack(x,x-1);
        return x;
        break;
    case NODE_WRITE:
        //int stackpos=4096+(t->varname)-'a';
        x=getReg();
        printf(" \n\nwirte %d\n\n",x);
        //x=5;
        l=codeGen(t->left);
        backup_stack(x,0);
        xos_call("Write",-2,l,x); //function to generate machine executable........................
        restore_stack(x,x-1);
        freeReg();
        return x;
        break;
    case NODE_CONSTANT:
        x=getReg();
        fprintf(xsm_file,"MOV R%d, %d\n",x,t->val);
        return x;
        break;  
    case NODE_CONN:
        if(t->left){
            l= codeGen(t->left);
            freeReg();
            
            }       
        if(t->right){   
            l= codeGen(t->right);
            freeReg();
            
            }
            return l;
            break;
    case NODE_VAR:
            x=4096+*(t->varname)-'a';
            y=getReg();
            fprintf(xsm_file,"MOV R%d, [%d]\n",y,x);
            return y;
            break;
    case NODE_ASSGN:
    //printf("assgn inside\n");
    //printf("dfdfdfd %c",*(t->left->varname));
            m=codeGen(t->right);
            x=4096+*((t->left)->varname)-'a';
            fprintf(xsm_file,"MOV [%d],R%d\n",x,m);
            return m;
            break;                            
    case NODE_EX:
         l=codeGen(t->left);
         m=codeGen(t->right);
         switch(*(t->varname)){
         
            case '+':
                 fprintf(xsm_file,"ADD R%d, R%d\n",l,m);
                 freeReg();
                 break;
            case '-':        
                 fprintf(xsm_file,"SUB R%d, R%d\n",l,m);
                     freeReg();
                     break;
            case '*':
                 fprintf(xsm_file,"MUL R%d, R%d\n",l,m);
                     freeReg();
                     break;
            case '/':
                 fprintf(xsm_file,"DIV R%d, R%d\n",l,m);
                 freeReg();
                 break;
         }
         return l;
         break;
    case N_EQ:
        l=codeGen(t->left);
        m=codeGen(t->right);
        fprintf(xsm_file,"EQ R%d, R%d\n",l,m);
        freeReg();
        return l;
        break;
    case N_NE:
        l=codeGen(t->left);
        m=codeGen(t->right);
        fprintf(xsm_file,"NE R%d, R%d\n",l,m);
        freeReg();
        return l;
        break; 
    case N_GT:
        l=codeGen(t->left);
        m=codeGen(t->right);
        fprintf(xsm_file,"GT R%d, R%d\n",l,m);
        freeReg();
        return l;
        break; 
    case N_GE:
        l=codeGen(t->left);
        m=codeGen(t->right);
        fprintf(xsm_file,"GE R%d, R%d\n",l,m);
        freeReg();
        return l;
        break; 
    case N_LT:
        l=codeGen(t->left);
        m=codeGen(t->right);
        fprintf(xsm_file,"LT R%d, R%d\n",l,m);
        freeReg();
        return l;
        break; 
    case N_LE:
        l=codeGen(t->left);
        m=codeGen(t->right);
        fprintf(xsm_file,"LE R%d, R%d\n",l,m);
        freeReg();
        return l;
        break;                                           
    case NODE_IF:
        label1=getLabel();
        l=codeGen(t->left);
        fprintf(xsm_file,"JZ R%d, L%d\n",l,label1);
        freeReg();
        m=codeGen(t->mid); 
        if(t->right!=NULL){
            label2=getLabel();
            fprintf(xsm_file,"JZ R%d, L%d\n",l,label2);
            }         
        fprintf(xsm_file,"L%d:\n",label1);
        if(t->right!=NULL){
            freeReg();
            m=codeGen(t->right);
            fprintf(xsm_file,"L%d:\n",label2);
            } 
        return m;
        break;
    case NODE_WHILE:
         label1=getLabel();         
         label2=getLabel();
         label_insert(&head,label2,label1);
         fprintf(xsm_file,"L%d:\n",label1);
         l=codeGen(t->left);
         fprintf(xsm_file,"JZ R%d, L%d\n",l,label2);
         m=codeGen(t->right);
         freeReg();
         fprintf(xsm_file,"JMP L%d\n",label1);
         fprintf(xsm_file,"L%d:\n",label2);
         return l;
         break;
      case N_BRKP:
            x=getReg();
            fprintf(xsm_file,"BRKP\n");
            return x;
            
      case N_BREAK:
            x=getReg();
            z=label_pop(&head);
            fprintf(xsm_file,"JMP L%d\n",z);
            return x;
            
        
      case N_CONTINUE: 
            x=getReg();
            int z=head->continue_label_val;
            fprintf(xsm_file,"JMP L%d\n",z);
            return x;  
      case NODE_DOWHILE:
                label1=getLabel();
                label2=getLabel();
                label3=getLabel();
                label_insert(&head,label3,label1);
                fprintf(xsm_file,"L%d:\n",label1);
                l=codeGen(t->left);
                freeReg();
                fprintf(xsm_file,"L%d:\n",label2);
                m=codeGen(t->right);
                fprintf(xsm_file,"JNZ R%d, L%d\n",m,label1);
                fprintf(xsm_file,"L%d:\n",label3);
                return m;
                break;  
    case NODE_REPEAT:
                label1=getLabel();
                label2=getLabel();
                label3=getLabel();
                label_insert(&head,label3,label1);
                fprintf(xsm_file,"L%d:\n",label1);
                l=codeGen(t->left);
                freeReg();
                fprintf(xsm_file,"L%d:\n",label2);
                m=codeGen(t->right);
                fprintf(xsm_file,"JZ R%d, L%d\n",m,label1);
                fprintf(xsm_file,"L%d:\n",label3);
                return m;
                break;               
 }      

}

void xos_call(char *arg,int file_handler,int var_pos,int p ){
    fprintf(xsm_file,"MOV R%d, \"%s\"\n",p,arg);
    fprintf(xsm_file,"PUSH R%d\n",p);
    fprintf(xsm_file,"MOV R%d, %d\n",p,file_handler);
    fprintf(xsm_file,"PUSH R%d\n",p);
    if(arg[0]=='R')
        fprintf(xsm_file,"MOV R%d, %d\n",p,var_pos);
    if(arg[0]=='R')
        fprintf(xsm_file,"PUSH R%d\n",p);
    else
        fprintf(xsm_file,"PUSH R%d\n",var_pos);
        fprintf(xsm_file,"PUSH R0\n");
        fprintf(xsm_file,"PUSH R0\n");
        fprintf(xsm_file,"CALL 0\n");
        fprintf(xsm_file,"POP R%d\n",p);
        fprintf(xsm_file,"POP R0\n");
        fprintf(xsm_file,"POP R0\n");
        fprintf(xsm_file,"POP R0\n");
        fprintf(xsm_file,"POP R0\n");
}

void backup_stack(int p,int i){
  if(p==i)
     return ;
  fprintf(xsm_file,"PUSH R%d\n",i);
  i++;
  backup_stack(p,i);   
}
void restore_stack(int p,int i){
  if(i<=0)
    return ;
    i--;
  fprintf(xsm_file,"POP R%d\n",i);
  restore_stack(p,i);   
}

int getLabel(){
return label_ct++;
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

void header_printer(){
fprintf(xsm_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n ",0,2056,0,0,0,0,0,0); 
fprintf(xsm_file, "BRKP\n");
fprintf(xsm_file, "MOV SP, 4121\n");
}

void answer_storer(){
  fprintf(xsm_file, "MOV SP, 4095\n");
  fprintf(xsm_file, "PUSH R%d\n",regct);
  fprintf(xsm_file, "INT 10\n");
}

void stack_adjust(){
    fprintf(xsm_file, "MOV SP,5020 \n");
}