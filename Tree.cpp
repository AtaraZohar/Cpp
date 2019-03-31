     #include "Tree.hpp"
     #define TRUE 1
     #define FALSE 0
     
//    ariel::class node
using namespace ariel;
    void ariel::Tree::insert(int i){
         if(Tree::contains(i)==FALSE){
           if (Tree::size() ==0){
                  Tree::treesize++;
              node* newHead=new node(i);
              Tree::head = newHead;
              Tree::head->setParent(0);
          }
           else{
                  Tree::treesize++;
              if (i> Tree::head->getValue()){
                   
                   insert(i,Tree::head->getRight(),Tree::head);
              }
              else{
                     insert(i,Tree::head->getLeft(),Tree::head);
              }
            }
      }
      else{
           std::__throw_bad_exception ();
      } 
      }
    void ariel::Tree::insert(int i,node* newHead,node* nodeParent){
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

    int ariel::Tree::size(){
        return Tree::treesize;
    }
    bool ariel::Tree::contains(int i){
         if(Tree::treesize == 0){
              return FALSE;
         }
         if( Tree::head->getValue() == i){
                     return TRUE;
                }
           else{
                     if(Tree::head->getValue() < i)
                     {
                          return contains(i, Tree::head->getRight());
                     }
                    else{
                         return contains(i, Tree::head->getLeft());  
                    }
                }
         return FALSE;
    }
    

    int ariel::Tree::contains(int i,node* newHead){
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

    int ariel::Tree::root(){
         return Tree::head->getValue();
    }
    int ariel::Tree::parent(int i){
          if (Tree::contains(i) == FALSE){
               std::__throw_bad_exception();
               }
           else{
               if(Tree::head->getValue()== i){
                         return 0;
               }
                else{
                         if(Tree::head->getValue()>i)
                           return  parent( i,Tree::head->getLeft());
                         else{
                            return  parent( i,Tree::head->getRight());
                         }
                    }
               }
              std::__throw_bad_exception();  
    }

     int ariel::Tree::parent(int i,node* newHead){
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
     
    int ariel::Tree::left(int i){
           if(Tree::contains(i)==TRUE){
                if( Tree::head->getValue() == i){
                     if(Tree::head->getLeft()!=NULL){
                     return Tree::head->getLeft()->getValue();
                     }
                     else{std::__throw_bad_exception ();}
                }
                     if(Tree::head->getValue() < i)
                     {
                     return left(i, Tree::head->getRight());
                     }
                       return left(i, Tree::head->getLeft());
           }
           else{
                std::__throw_bad_exception ();
           }

            
}

int ariel::Tree::left(int i,node* newHead)
{
     int ans=0;
      if(newHead->getValue() == i){     
            if(Tree::head->getLeft()!=NULL){

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

    int ariel::Tree::right(int i){
        if(Tree::contains(i)==TRUE){
                if( Tree::head->getValue() == i){
                     if(Tree::head->getRight()!=NULL){
                     return Tree::head->getRight()->getValue();
                     }
                     else{std::__throw_bad_exception ();}  
                }
                else{
                     if(Tree::head->getValue() < i)
                     {
                     return right(i, Tree::head->getRight());
                     }
                    else{
                      return right(i, Tree::head->getLeft());
                    }
                }
           }
          std::__throw_bad_exception ();//לזרוק חריגה
    }

    int ariel::Tree::right(int i,node* newHead){
         int ans=0;
      if(newHead->getValue() == i){
           if(Tree::head->getRight()!=NULL){
                ans= newHead->getRight()->getValue();
                return ans;
            }
            else{ std::__throw_bad_exception ();}
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
void ariel::Tree::remove (int i){
        if ( Tree::head == NULL)
        {
             std::__throw_bad_exception ();
        }
    else if (Tree::contains(i)== false)
        {
             std::__throw_bad_exception ();
        }
        else
        {
            node *temp=head;
            head=deleteNode(temp,i);
            treesize--;
        }
        
    }

 node* ariel::Tree::deleteNode( node* root, int key) 
{ 
    // base case 
    if (root == NULL) 
    return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->getValue()) 
        root->setLeft( deleteNode(root->getLeft(), key)); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->getValue()) 
        root->setRight( deleteNode(root->getRight(), key)); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->getLeft() == NULL) 
        { 
            node *temp = root->getRight(); 
            delete root; 
            return temp; 
        } 
        else if (root->getRight() == NULL) 
        { 
            node *temp = root->getLeft(); 
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
     node* current = n;
    /* loop down to find the leftmost leaf */
    while (current->getLeft() != NULL) 
        current = current->getLeft(); 
  
    return current; 
}

void::ariel::Tree::destroy(node* currentNode){
      if (currentNode != NULL)	{
        destroy(currentNode->getLeft());
        currentNode->setLeft(NULL);
        destroy(currentNode->getRight());
        currentNode->setLeft(NULL);
	delete currentNode;
      }
    
}
 void ariel::Tree::print(){ 
        node *p=Tree::head; 
        printTree(p);
    }
void ariel::Tree::printTree(node *head) {
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

