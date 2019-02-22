//defining constants
#define NODE_EX 1
#define NODE_ASSGN 2
#define NODE_CONN 3
#define NODE_CONSTANT 4
#define NODE_READ 5
#define NODE_VAR 6
#define NODE_WRITE 7
#define N_GT 8
#define N_GE 9 
#define N_LT 10
#define N_LE 11 
#define N_EQ 12 
#define N_NE 13
#define NODE_IF 14
#define NODE_WHILE 15
#define NODE_DOWHILE 16
#define NODE_REPEAT 17
#define N_BREAK 18
#define N_CONTINUE 19
#define N_BRKP 20
#define INTEGER 1
#define BOOLE 2	 
#define reg_index int;
#define l_node struct label_node;
FILE *yyin;
struct tnode* createTree(int val,int type,char* varname,int nodetype,struct tnode *left,struct tnode *middle,struct tnode *right);
void inorder(struct tnode *t);
void tnode_print(struct tnode *t);
int getReg();
void freeReg();
void header_printer();
void answer_storer();	
FILE *xsm_file;
typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left,*mid,*right;	//left and right branches   
}tnode;
struct label_node
{
  int break_label_val;
  int continue_label_val;
  struct label_node* next;

};	
/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int n);
	
/*Make a tnode with opertor, left and right branches set*/
//ruct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);
	
/*To evaluate an expression tree*/
int evaluate(struct tnode *t);
reg_index codeGen( struct tnode *t);

void xos_call(char *arg,int file_handler,int var_pos,int p );
void backup_stack(int p,int i);
void answer_storer();
int label_pop(struct label_node **head);
void label_insert(struct label_node **head,int,int);
void restore_stack(int p,int i);