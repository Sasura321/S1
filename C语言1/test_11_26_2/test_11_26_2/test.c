create_tree.c

 #include "head.h"
 typedef  int DataType;

 typedef struct tree{
 DataType num;
 struct tree *left_child;
 struct tree *right_child;
 }node;

 node * init_tree(void)
 {
 node *root = (node *)malloc(sizeof(node));
 (node *)memset(root, 0x00, sizeof(node));

 root->left_child = NULL;
 root->right_child = NULL;

 return root;
 }

 void insert_tree(node **root)
 {
 static node *last_node = NULL;

 if(*root != NULL){
 fprintf(stderr, "%s\012", "Here is not empty !");
 return;
 }
 node *rt = (node *)calloc(1, sizeof(node));
 *root = rt;
 if(!last_node){
 system("color 0C");
 fprintf(stderr, "%s\012", "\"The data inserted into the root node .\"");
 Sleep(2000);
 system("color 0A");
 }
 printf("Enter to insert data :");
 while(scanf("%d", &rt->num) == 0){
 fflush(stdin);
 fprintf(stderr, "%s", "Illegal input and input again :");
 }
 rt->left_child = NULL;
 rt->right_child = NULL;

 system("color 0C");
 fprintf(stderr, "%s", "\n\t-----------------------------------------\n");
 fprintf(stderr, "%s\n", "\t1.insert left_child  2.insert right_child\n\
 3.insert brother     0.end_insert");
 fprintf(stderr, "%s", "\t-----------------------------------------\n\n");
 Sleep(3000);
 system("color 0A");
 int choose;
 lb: fprintf(stderr, "%s", "Please select a :");
 while(scanf("%d", &choose) == 0){
 fflush(stdin);
 fprintf(stderr, "%s", "Illegal input and input again :");
 }
 if(choose > 3 || choose < 0){
 fprintf(stderr, "%s", "There is no this option.\012");
 goto lb;
 } 

 switch(choose){
 case 1:{
 last_node = rt;
 insert_tree(&rt->left_child);
 }break;

 case 2:{
 last_node = rt;
 insert_tree(&rt->right_child);
 }break;

 case 3:{
 if(last_node != NULL){
 if(last_node->left_child != NULL && last_node->right_child != NULL)
 fprintf(stderr, "%s", "Have no place to insert .\012");

 else if(last_node->left_child == NULL)
 insert_tree(&last_node->left_child);

 else
 insert_tree(&last_node->right_child);
 }

 }break;
 case 4:{

 }break;

 case 0:
 return;
 }

 }

 void preorder(node **p)
 {
 if(*p == NULL)
 return;
 fprintf(stderr, "%d ",(*p)->num);
 preorder(&(*p)->left_child);
 preorder(&(*p)->right_child);

 }

 void inorder(node **p)
 {
 if(*p == NULL)
 return;
 inorder(&(*p)->left_child);
 fprintf(stderr, "%d ",(*p)->num);
 inorder(&(*p)->right_child);

 }

 void postorder(node **p)
 {
 if(*p == NULL)
 return;
 inorder(&(*p)->left_child);
 inorder(&(*p)->right_child);
 fprintf(stderr, "%d ",(*p)->num);

 }

 void show(node **root)
 {
 node *p = *root;
 char order;
 fflush(stdin);
 lb2:system("color 0C");
 fprintf(stderr, "%s", "\n\t--------------------------------------\n");
 fprintf(stderr, "%s", "\tb:PreOrder i:Inorder a:PostOrder e:end\012");
 fprintf(stderr, "%s", "\t--------------------------------------\n\n");
 Sleep(3000);
 system("color 0A");
 fprintf(stderr, "%s", "Choose the way to traverse :");
 while(scanf("%c", &order) != '\n'){
 fflush(stdin);
 switch(order){
 case 'b':
 fprintf(stderr, "%s", "For the former sequence traversal results:");
 preorder(&p);
 fprintf(stderr, "%c", '\012');
 goto lb2;
 break;

 case 'i':
 fprintf(stderr, "%s", "In order to traverse the results :");
 inorder(&p);
 fprintf(stderr, "%c", '\012');
 goto lb2;
 break;

 case 'a':
 fprintf(stderr, "%s", "After the sequence traversal results for: \
 ");
 postorder(&p);
 fprintf(stderr, "%c", '\012');
 goto lb2;
 break;

 case 'e':
 return;

 default:{
 fprintf(stderr, "%s", "There is no this option.\012");
 goto lb2;
 }
 }

 }

 }

 node * creat_tree(void)
 {
 node *root = init_tree();
 insert_tree(&root->left_child);
 show(&root->left_child);

 return root;
 }



 main.c

 #include "head.h"

 int main(int argc, char *argv[])
 {
 system("title Binary tree basic implementation and operation ");
 system("mode con  lines=20 cols=60");

 node *root = creat_tree();

 return 0;
 }


 head.h

 #ifndef _HEAD_H
 #define _HEAD_H
 #include <stdio.h>
 #include <malloc.h>
 #include <string.h>
 #include <windows.h>

 typedef struct tree node;
 node * creat_tree(void);
 #endif
