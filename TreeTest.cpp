/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <stdlib.h>  
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  ariel::Tree exampletree;
  exampletree.insert(3);
  exampletree.insert(7);
  exampletree.insert(9);
  exampletree.insert(11);
  exampletree.insert(1);
  exampletree.insert(8);
  exampletree.insert(2);
  exampletree.insert(5);
  exampletree.insert(6);   
  
  ariel::Tree mytree;  

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())

  .CHECK_EQUAL (exampletree.size(), 9)
  .CHECK_EQUAL (exampletree.root(), 3)
  .CHECK_EQUAL (exampletree.parent(9), 7)
  .CHECK_EQUAL (exampletree.parent(2), 1)
  .CHECK_EQUAL (exampletree.parent(threetree.parent(2)), 3)
  .CHECK_EQUAL (exampletree.left(9), 8)
  .CHECK_THROWS(exampletree.insert(14))
  .CHECK_THROWS(exampletree.insert(4))
  .CHECK_EQUAL (exampletree.size(), 11)
  .CHECK_OK    (exampletree.remove(5))
  .CHECK_EQUAL (exampletree.contains(5), false)
  .CHECK_EQUAL (exampletree.size(), 10)
  .CHECK_OK    (exampletree.remove(3))
  .CHECK_EQUAL (exampletree.root(), 2)
  .CHECK_EQUAL (exampletree.right(5), 6)
  .CHECK_EQUAL (exampletree.contains(3), false)
  .CHECK_EQUAL (exampletree.contains(2), true)
  .CHECK_THROWS(exampletree.insert(12))
  .CHECK_THROWS(exampletree.insert(3))
  .CHECK_EQUAL (exampletree.size(), 11)
  .CHECK_EQUAL (exampletree.right(threetree.right(7)), 11)
  .CHECK_EQUAL (exampletree.parent(12), 14)
  .CHECK_EQUAL (exampletree.parent(9), 8)
  .CHECK_EQUAL (exampletree.left(7), 4)
  .CHECK_EQUAL (exampletree.left(2), 1)
  .CHECK_EQUAL (exampletree.right(4), 6)
  .CHECK_EQUAL (exampletree.right(9), 11)
   .print();
 
  for (int i=0; i<=100; i++){
     int temp = rand() % 100; 
     if(mytree.contains(temp)==false){
       mytree.insert(temp);
       tc.CHECK_EQUAL (mytree.contains(temp), true);
       mytree.remove(temp);
      tc.CHECK_EQUAL (mytree.contains(temp), false);
     }
     else{
          mytree.remove(temp);
         tc.CHECK_EQUAL (mytree.contains(temp), false);
     }
   
  }
  tc.CHECK_EQUAL (mytree.size(), 0);
  
 
 tc.print();  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}