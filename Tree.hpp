#include <iostream> 
using std::cout, std::endl;

namespace ariel {
class node{
   private:
      int value;
      node* right;
      node* left;
       node* parent;
   public:
      node(int v){//constructor
         value=v;
         right=0;
         left=0;
         parent=0;
      }
  
      node* getRight(){
         return right;
      }
       node* getLeft(){
         return left;
      }
      void setLeft(node* newLeft){
         left=newLeft;
      } 
       void setRight(node* newRight){
         right=newRight;
      }
       void setValue(int newValue){
         value=newValue;
      }
        void setParent(node* p){
         this->parent=p;
      }
         node* getParent(){
         return parent;
      }
        int getValue(){
         return value;
      }
};

   class Tree{

      private:
         //int treesize;
         node* head;

         void insert(int i,node* newRoot,node* nodeParent);
         int  left(int i,node* newHead);
         int  right(int i,node* newHead);
         int  contains(int i,node* newHead);
         int parent(int i,node* newHead);
         void printTree(node *head);
         node* deleteNode( node* root, int key);
         node* minValueNode(node* node);
      public:
         int treesize;
         
         Tree(){//constructor
            this->treesize=0;
            this->head=0;
         }
       ~Tree(){//distructor
             destroy(head);
       }
      void destroy(node* currentNode);

 
         void setSize(){
            treesize =treesize+1;
         }
         void insert(int i);
         void remove(int i);
         int size();
         bool contains(int i);
         int root();
         int parent(int i);
         int left(int i);
         int right(int i);
         void print();
   };
}
