     #include "Tree.hpp"
     #define TRUE 1
     #define FALSE 0
     
//    ariel::class node
using namespace ariel;
    void ariel::Tree::insert(int i){//this function put a new value in the tree
         if(Tree::contains(i)==FALSE){//just if the value isent in the tree all ready
           if (Tree::size() ==0){
                  Tree::treesize++;
              node* newHead=new node(i);
              Tree::head = newHead;
              Tree::head->setParent(0);
          }
           else{
                  Tree::treesize++;
              if (i> Tree::head->getValue()){//put the value in the right subtree
                   
                   insert(i,Tree::head->getRight(),Tree::head);
              }
              else{//put the value in the left subtree
                     insert(i,Tree::head->getLeft(),Tree::head);
              }
            }
      }
      else{
           std::__throw_bad_exception ();
      } 
      }

    void ariel::Tree::insert(int i,node* newHead,node* nodeParent){//same code just recusivly
         if(newHead == NULL){
             node* newNode=new node(i);
             newNode->setParent(nodeParent);
              if(i<nodeParent->getValue()){
                   nodeParent->setLeft(newNode);
              }
              else{
                  nodeParent->setRight(newNode);  
              }
            
         }
         else{
              if (i>nodeParent->getValue()){
                   insert(i,nodeParent->getRight(),newHead);
              }
              else{
                 insert(i,nodeParent->getLeft(),newHead);  
              }
         }
    }

    int ariel::Tree::size(){//return the size if the tree
        return Tree::treesize;
    }
    bool ariel::Tree::contains(int i){//chack if a value is in the tree
         if(Tree::treesize == 0){//if the tree is empty
              return FALSE;
         }
         if( Tree::head->getValue() == i){//if we find the number in the tree
                     return TRUE;
                }
           else{
                     if(Tree::head->getValue() < i)//serch the value in the right subtree
                     {
                          return contains(i, Tree::head->getRight());
                     }
                    else{//search the value in the left subtree
                         return contains(i, Tree::head->getLeft());  
                    }
                }
         return FALSE;
    }
    

    int ariel::Tree::contains(int i,node* newHead){//same code just recusivly
     //ans=TRUE;

      if(newHead==NULL){
          return FALSE;
      }
          
      if(newHead->getValue() == i){
           return TRUE;
      }
       if(newHead->getValue() < i){
           return contains(i, newHead->getRight());
       }
       else {
            if(newHead->getValue() > i){
           return contains(i, newHead->getLeft());
             }
       }
        return 0;
}

    int ariel::Tree::root(){//return the root of the tree
         if(Tree::head == NULL){
               std::__throw_bad_exception();
         }
         return Tree::head->getValue();
    }

    int ariel::Tree::parent(int i){// get a value and return the parent of the value
          if (Tree::contains(i) == FALSE){//if the value dosent in the tree
               std::__throw_bad_exception();
               }
           else{
               if(Tree::head->getValue()== i){//if the value is the head and he dosent have a parent
                        std::__throw_bad_exception();
               }
                else{
                         if(Tree::head->getValue()>i)//serch the value in the left subtree
                           return  parent( i,Tree::head->getLeft());
                         else{//serch the value in the right subtree
                            return  parent( i,Tree::head->getRight());
                         }
                    }
               }
              std::__throw_bad_exception();  
    }

     int ariel::Tree::parent(int i,node* newHead){//same code just recusivly
    if(newHead==NULL){
         std::__throw_bad_exception();
    }
    else{
         if(newHead->getValue()== i){
                         return newHead->getParent()->getValue() ;
          }
           else{
                         if(newHead->getValue()>i){
                            return parent( i,newHead->getLeft());
                         }
                         else{
                              return parent( i,newHead->getRight());
                         }
              }
      }
     std::__throw_bad_exception();
 }
     
    int ariel::Tree::left(int i){//get a value and return his left son in the tree
           if(Tree::contains(i)==TRUE){//if the value exist in the tree
                if( Tree::head->getValue() == i){
                     if(Tree::head->getLeft()!=NULL){//chack if there is a son
                     return Tree::head->getLeft()->getValue();
                     }
                     else{std::__throw_bad_exception ();}
                }
                     if(Tree::head->getValue() < i)//serch the value in the left subtree
                     {
                     return left(i, Tree::head->getRight());
                     }//serch the value in the right subtree
                       return left(i, Tree::head->getLeft());
           }
           else{//if the value isent exist in the tree
                std::__throw_bad_exception ();
           }

            
}

int ariel::Tree::left(int i,node* newHead)//same code just recusivly
{
     int ans=0;
      if(newHead->getValue() == i){     
            if(newHead->getLeft()!= NULL){
             ans= newHead->getLeft()->getValue();
           return ans;
            }
            else{ std::__throw_bad_exception ();}
      }
       if(newHead->getValue() < i){
          return left(i, newHead->getRight());
       }
       else {
            if(newHead->getValue() >i){
          return left(i, newHead->getLeft());
          }
       }
       return ans;
    
}

    int ariel::Tree::right(int i){//get a value and return his left son in the tree
        if(Tree::contains(i)==TRUE){//if the value exist in the tree
                if(Tree::head->getValue() == i){
                     if(Tree::head->getRight()!= NULL){//chack if there is a son
                     return Tree::head->getRight()->getValue();
                     }
                     else{
                          std::__throw_bad_exception ();
                          }  
                }
                else{
                     if(Tree::head->getValue() < i)
                     {//serch the value in the right subtree
                     return right(i, Tree::head->getRight());
                     }
                    else{//serch the value in the left subtree
                      return right(i, Tree::head->getLeft());
                    }
                }
           }
          std::__throw_bad_exception ();//לזרוק חריגה
    }

    int ariel::Tree::right(int i,node* newHead){//same code just recusivly
         int ans=0;
      if(newHead->getValue() == i){
           if(newHead->getRight()!= NULL){
                
                ans= newHead->getRight()->getValue();
                return ans;
            }
            else{
                  std::__throw_bad_exception ();
                  }
      }
       if(newHead->getValue()<i){
         return  right(i, newHead->getRight());
       }
       else {
            if(newHead->getValue() >i){
              return right(i, newHead->getLeft());
            }
       }
       return ans;
}
void ariel::Tree::remove (int i){//delete a node from the tree
        if ( Tree::head == NULL)
        {
             std::__throw_bad_exception ();
        }
      if (Tree::contains(i)== FALSE)
        {
             std::__throw_bad_exception ();
        }
        else
        {
            head = deleteNode(head , i); 
            treesize--;
        }
        
    }

 node* ariel::Tree::deleteNode( node* root, int key) 
{ // we got this code from https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
    // base case 
    if (root == NULL) 
    return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->getValue()) 
        root->setLeft( deleteNode(root->getLeft(), key)); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->getValue()){

        root->setRight(deleteNode(root->getRight(), key)); 
    }

  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->getLeft() == NULL) 
        {        
                 node *temp = root->getRight(); 
            if (temp != NULL)
               temp->setParent(root->getParent());
            delete root; 
            return temp; 
        } 
        else if (root->getRight() == NULL) 
        { 
            node *temp = root->getLeft(); 
            if (temp != NULL)
               temp->setParent(root->getParent());
             delete root;
             return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        node* temp = minValueNode(root->getRight()); 
  
        // Copy the inorder successor's content to this node 
        root->setValue(temp->getValue()); 
  
        // Delete the inorder successor 
        root->setRight( deleteNode(root->getRight(), temp->getValue())); 
    } 
    return root; 
} 
 node* Tree::minValueNode(node* n) 
{ 
     if(head == NULL){
          return NULL;
     }
     node* current = n;
    /* loop down to find the leftmost leaf */
    while (current->getLeft() != NULL) 
        current = current->getLeft(); 
  
    return current; 
}

void::ariel::Tree::destroy(node* currentNode){//delete the tree
      if (currentNode != NULL)	{
        destroy(currentNode->getLeft());
        currentNode->setLeft(NULL);
        destroy(currentNode->getRight());
        currentNode->setLeft(NULL);
	delete currentNode;
      }
    
}
 void ariel::Tree::print(){ //print the tree
        node *p=Tree::head; 
        printTree(p);
    }
void ariel::Tree::printTree(node *head) {//found this function from the internet
        if(!head) {
            printf("NULL");
	        return; 
        }
        printf("(");
        printTree(head->getLeft());
        printf(",%d,", head->getValue());
        printTree(head->getRight());
        printf(")"); 
     }
