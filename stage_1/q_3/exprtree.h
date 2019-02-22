typedef struct tnode{
 int val; //value of for the expression tree
 char *op; //indicates the opertor branch
 struct tnode *left,*right; //left and right branches
 }tnode;
	
/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int n);
	
/*Make a tnode with opertor, left and right branches set*/
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);
	
/*To evaluate an expression tree*/
int evaluate(struct tnode *t);

/*return register*/
int getReg();
static int nextReg=0;

/*free register*/
void freeReg(void);
/*code gen functions*/
int codeGen(struct tnode* root, FILE* fout);
/*initial codes*/
void initialize(FILE* fout);

// void storeReg0(FILE *fout, char static_var);

// void print_static_var(FILE *fout, char static_var);

