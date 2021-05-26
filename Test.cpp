/**
 * Unit tests for Binary Tree Exercise
 * AUTHOR: Mayan Bashan
 * Date: 2021-05
 */
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "doctest.h"
#include "BinaryTree.hpp"

using namespace std;
using namespace ariel;


    /*                     a   
                       /        \
                      b          k
                    /   \      /    \
                   c     j    l      m
                 /   \                \
                d     g                n 
               / \   / \              /  \
              e  f  h   i            o    p
              
        Preorder of this tree is: {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'}
    */
    TEST_CASE("Preorder"){
        std::vector<char> expected_preorder = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};
        BinaryTree<char> char_tree;

        // Add elements while tree have no root
        CHECK_THROWS(char_tree.add_right('b','c'));
        CHECK_THROWS(char_tree.add_left('c','b'));

        // Add root
        char_tree.add_root('k');
        CHECK(*(char_tree.begin_preorder()) == 'k');
        char_tree.add_root('a'); // now root is 10 instead of 1000

        // Fill tree
        CHECK(*(char_tree.begin_preorder()) == 'a');
        CHECK_NOTHROW(char_tree.add_left('a','b')
                               .add_left('b','c')
                               .add_left('c','d')
                               .add_left('d','e')
                               .add_right('d','f')
                               .add_right('c','g')
                               .add_left('g','h')
                               .add_right('g','i')
                               .add_right('b','j')
                               .add_right('a','k')
                               .add_left('k','l')
                               .add_right('k','m')
                               .add_right('m','n')
                               .add_left('n','o')
                               .add_right('n','p'));
        std::vector<char> preorder;
        CHECK(*(char_tree.begin_preorder()) == 'a');
        for (auto it=char_tree.begin_preorder(); it!=char_tree.end_preorder(); ++it) {
            preorder.push_back(*it);
        }
        CHECK_EQ(expected_preorder, preorder);  
    }

 
    /*                     10                                       
                       /        \ 
                      8          12
                    /   \      /    \
                   4     9    11    13
                 /   \                \
                2     6                15 
               / \   / \              /  \
              1  3  5   7            14   16     
              
        Inorder of this tree is: {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}
    */
    TEST_CASE("Inorder"){
        std::vector<int> expected_inorder = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
        BinaryTree<int> int_tree;

        // Add elements while tree have no root
        CHECK_THROWS(int_tree.add_right(10,1));
        CHECK_THROWS(int_tree.add_left(10,1));

        // Add root
        int_tree.add_root(1000);
        CHECK(*(int_tree.begin_inorder()) == 1000);
        int_tree.add_root(10); // now root is 10 instead of 1000
        CHECK(*(int_tree.begin_inorder()) == 10);

        // Fill tree
        CHECK_NOTHROW(int_tree.add_left(10,8)
                              .add_left(8,4)
                              .add_left(4,2)
                              .add_left(2,1)
                              .add_right(2,3)
                              .add_right(4,6)
                              .add_left(6,5)
                              .add_right(6,7)
                              .add_right(10,12)
                              .add_left(12,11)
                              .add_right(12,13)
                              .add_right(13,15)
                              .add_left(15,14)
                              .add_right(15,16));
        CHECK(*(int_tree.begin_inorder()) == 1);

        std::vector<int> inorder;
        for (auto it=int_tree.begin_inorder(); it!=int_tree.end_inorder(); ++it) {
            inorder.push_back(*it);
        }
        CHECK_EQ(expected_inorder, inorder);
        inorder.clear();

        for (int& element : int_tree){ // should work like inorder
            inorder.push_back(element);
        }
        CHECK_EQ(expected_inorder, inorder);
        inorder.clear();

        int_tree.add_left(2,0); // replace 1 with 0
        CHECK(*(int_tree.begin_inorder()) == 0);
        CHECK(*(int_tree.begin_inorder()) == *(int_tree.begin())); // both should return 0
        int_tree.add_right(0,1);
        CHECK(*(int_tree.begin_inorder()) == 0); // tree beginning is still 0 (according to inorder)
        std::vector<int> expected_inorder2 = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
        for (auto it=int_tree.begin_inorder(); it!=int_tree.end_inorder(); ++it) {
            inorder.push_back(*it);
        }
        CHECK_EQ(expected_inorder2, inorder);
    }   
    

    /*                           "sixteen"   
                            /                  \
                        "nine"              "fifteen"
                        /   \               /       \
                "seven"  "eight"     "ten"    "fourteen"
                /     \                              \   
          "three"      "six"                           "thirteen"   
         /     \       /    \                            /    \
        "one"  "two" "four" "five"                "eleven"    "twelve"
              
        Postorder of this tree is: {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen"}
    */
    TEST_CASE("Postorder"){
        std::vector<string> expected_postorder = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen"};
        BinaryTree<string> string_tree;

        // Add elements while tree have no root
        CHECK_THROWS(string_tree.add_right("zzz","yyy"));
        CHECK_THROWS(string_tree.add_left("xxx","yyy"));

        // Add root
        string_tree.add_root("thirteen");
        CHECK(*(string_tree.begin_postorder()) == "thirteen");
        string_tree.add_root("sixteen"); // now root is sixteen instead of thirteen
        CHECK(*(string_tree.begin_postorder()) == "sixteen");

        // Fill tree
        CHECK_NOTHROW(string_tree.add_left("sixteen","nine")
                                 .add_left("nine","seven")
                                 .add_left("seven","three")
                                 .add_left("three","one")
                                 .add_right("three","two")
                                 .add_right("seven","six")
                                 .add_left("six", "four")
                                 .add_right("six","five")
                                 .add_right("sixteen","fifteen")
                                 .add_left("fifteen","ten")
                                 .add_right("fifteen","fourteen")
                                 .add_right("fourteen","thirteen")
                                 .add_left("thirteen","eleven")
                                 .add_right("thirteen","twelve"));
        std::vector<string> postorder;
        
        for (auto it=string_tree.begin_postorder(); it!=string_tree.end_postorder(); ++it) {
            postorder.push_back(*it);
        }
        CHECK_EQ(expected_postorder, postorder);

        auto itfirst = string_tree.begin_postorder();
        string itfirst_data = *itfirst;
        string itfirst_data_expected = "one";
        CHECK_EQ(itfirst_data, itfirst_data_expected);

        *itfirst = "replaced_one"; // replace data in iterator
        auto itfirst_replaced = string_tree.begin_postorder();
        string itfirs_replaced_data = *itfirst_replaced;
        string  itfirst_replaced_data_expected = "replaced_one";
        CHECK_EQ(itfirs_replaced_data, itfirst_replaced_data_expected);
    }

     TEST_CASE("Random Insertion"){
         BinaryTree<int> tree;
         
        srand(time(NULL));
        for (int i = 1 ; i < 100 ; i++){
            int n = rand() % 2; // either 0 or 1
            if (n == 0){
                CHECK_THROWS(tree.add_left(i, i+1));                
            }
            else{ // n == 1
                CHECK_THROWS(tree.add_right(i,i+1));
            }
        }
        tree.add_root(0);   
        for (int i = 0 ; i < 100 ; i++){
            int n = rand() % 2; // either 0 or 1
            if (n == 0){
                CHECK_NOTHROW(tree.add_left(i, i+1));                
            }
            else{ // n == 1
                CHECK_NOTHROW(tree.add_right(i,i+1));
            }
        }
        // now tree contains all valus between 0 - 100
        tree.add_root(-1); // replace 0 with -1
        CHECK_THROWS(tree.add_left(0,15)); // 0 does not exist in tree anymore
        CHECK_THROWS(tree.add_right(0,15)); // 0 does not ezidst in tree anymore
        CHECK_NOTHROW(tree.add_left(-1,101)); // -1 exists in tree
     }