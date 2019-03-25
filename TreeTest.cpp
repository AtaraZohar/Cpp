/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
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
  threetree.insert(3);
  threetree.insert(7);
  threetree.insert(9);
  threetree.insert(11);
  threetree.insert(1);
  threetree.insert(8);
  threetree.insert(2);
  threetree.insert(5);
  threetree.insert(6);   
  
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

  .CHECK_EQUAL (threetree.size(), 9)
  .CHECK_EQUAL (threetree.root(), 3)
  .CHECK_EQUAL (threetree.parent(9), 7)
  .CHECK_EQUAL (threetree.parent(2), 1)
  .CHECK_EQUAL (threetree.parent(threetree.parent(2)), 3)
  .CHECK_EQUAL (threetree.left(9), 8)
  .CHECK_THROWS(threetree.insert(14))
  .CHECK_THROWS(threetree.insert(4))
  .CHECK_EQUAL (threetree.size(), 11)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_EQUAL (threetree.size(), 10)
  .CHECK_OK    (emptytree.remove(3))
  .CHECK_EQUAL (threetree.root(), 2)
  .CHECK_EQUAL (threetree.right(5), 6)
  .CHECK_EQUAL (emptytree.contains(3), false)
  .CHECK_EQUAL (emptytree.contains(2), true)
  .CHECK_THROWS(threetree.insert(12))
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_EQUAL (threetree.size(), 11)
  .CHECK_EQUAL (threetree.right(threetree.right(7)), 11)
  .CHECK_OK    (threetree.print())
  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}