#include<stdio.h>
#include<string.h>

typedef struct couple{
        char name[10];
        int id;
} couple;

typedef struct tuple{
        char name[10];
        char type[10];
        int id;
} tuple;

// Uniform Symbol Table
tuple UST[50];
int UST_size = 0;

// Identifier Description tabe
tuple IDT[50];
int IDT_size = 0;

// Literal tabe
tuple LT[50];
int LT_size = 0;

// Keyword Table
couple KT[50];
int KT_size = 0;

// Terminal Table
couple TT[50];
int TT_size = 0;

// keywords, operators and terminals
char keywords[32][20] = {"auto","int","const","short","break","long","continue","signed","double","struct",
                                "float","unsigned","else","switch","for","void","case","register","default","sizeof",
                                "char","return","do","static","enum","typedef","goto","volatile","extern","union",
                                "if","while"};

char operators[35][5] = {"+","-","*","/","%","++","--","==","!=",">",
                                        "<",">=","<=","&&","||","!","&","|","^","~",
                                        "<<",">>","=","+=","-=","*=","/=","%=","<<=",">>=",
                                        "&=","^=","|=", ",", "."};
                                        
char terminals[8][2] = {"(",")","[","]","{","}",";",":"};

// methods to check if words are keyworks, operators or terminals

int is_keyword(char *key){
        int i;
        for(i=0; i<32; i++){
                if(strcmp(key, keywords[i]) == 0)
                        return 1;
        }
        return 0;
}

int is_operator(char *key){
        int i;
        for(i=0; i<35; i++){
                if(strcmp(key, operators[i]) == 0)
                        return 1;
        }
        return 0;
}

int is_terminal(char *key){
        int i;
        for(i=0; i<8; i++){
                if(strcmp(key, terminals[i]) == 0)
                        return 1;
        }
        return 0;
}

int is_literal(char *key){
        int len = strlen(key);
        if((key[0] == '\'' && key[len-1] == '\'')  && len>1)
                return 1;
                
        return 0;
}

// methods to insert int tables
void insert(char *key){
        if(strlen(key)==0)
                return;        
        
        if(is_keyword(key)){
                strcpy(UST[UST_size].name, key);
                strcpy(UST[UST_size].type, "KEY");
                UST[UST_size].id = UST_size;
                UST_size++;
                
                strcpy(KT[KT_size].name, key);
                KT[KT_size].id = KT_size;
                KT_size++;
        }
        else if(is_terminal(key)){
                strcpy(UST[UST_size].name, key);
                strcpy(UST[UST_size].type, "TER");
                UST[UST_size].id = UST_size;
                UST_size++;
                
                strcpy(TT[TT_size].name, key);
                TT[TT_size].id = TT_size;
                TT_size++;
        }
        else if(is_operator(key)){
                strcpy(UST[UST_size].name, key);
                strcpy(UST[UST_size].type, "OPR");
                UST[UST_size].id = UST_size;
                UST_size++;
        }
        else if(is_literal(key)){
                strcpy(UST[UST_size].name, key);
                strcpy(UST[UST_size].type, "LIT");
                UST[UST_size].id = UST_size;
                UST_size++;
                
                strcpy(LT[LT_size].name, key);
                LT[LT_size].id = LT_size;
                LT_size++;
        }
        else{
                strcpy(UST[UST_size].name, key);
                strcpy(UST[UST_size].type, "IDN");
                UST[UST_size].id = UST_size;
                UST_size++;
                
                strcpy(IDT[IDT_size].name, key);
                strcpy(IDT[IDT_size].type, "var");
                IDT[IDT_size].id = IDT_size;
                IDT_size++;
        }
}


// File pointer
FILE *fp;


// Display tables

void display_UST(){
        printf("\n UST....\n");
        int i;
        for(i=0; i<UST_size-1; i++)
                printf("id = %d    \tname = %s \t\t\ttype = %s\n", UST[i].id, UST[i].name, UST[i].type);
}
void display_IDT(){
        printf("\n IDT....\n");
        int i;
        for(i=0; i<IDT_size-1; i++)
                printf("id = %d    \tname = %s \t\t\ttype = %s\n", IDT[i].id, IDT[i].name, IDT[i].type);
}
void display_KT(){
        printf("\n KT....\n");
        int i;
        for(i=0; i<KT_size; i++)
                printf("id = %d    \tname = %s\n", KT[i].id, KT[i].name);
}
void display_TT(){
        printf("\n TT....\n");
        int i;
        for(i=0; i<TT_size; i++)
                printf("id = %d    \tname = %s\n", TT[i].id, TT[i].name);
}
void display_LT(){
        printf("\n LT....\n");
        int i;
        for(i=0; i<LT_size; i++)
                printf("id = %d    \tname = %s\n", LT[i].id, LT[i].name);
}


// Read input file
void read(){
        char temp [30];
        int temp_size = 0;
        
        while(!feof(fp)){
                char ch = fgetc(fp);
                char buff[2];
                buff[0] = ch; buff[1] = '\0';
                
                while((ch != ' ' && ch != '\n' && ch != '\t') && !feof(fp)){
                        if(is_operator(buff) || is_terminal(buff)){
                                temp[temp_size] = '\0';
                                insert(temp);
                                insert(buff);
                                temp[0] = '\0';
                                temp_size = 0;
                                break;
                        }
                        if(is_literal(temp)){
                                insert(temp);
                                temp[0] = '\0';
                                temp_size = 0;
                        }
                        temp[temp_size] = ch;
                        temp[temp_size+1] = '\0';
                        temp_size++;
                        
                        ch = fgetc(fp);
                }
                temp[temp_size] = '\0';
                
                insert(temp);
                temp_size = 0;
        }
}


void main(){
        fp = fopen("input.txt", "r");
        read();
        
        display_UST();
        display_IDT();
        display_LT();
        display_KT();
        display_TT();
}




