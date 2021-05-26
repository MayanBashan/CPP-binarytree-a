
/**
 * Author: Mayan Bashan
 */
#pragma once
using namespace std;

namespace ariel{
    
    template<typename T>
    class BinaryTree{
        private: 
            struct Node{
                    T data;
                    Node* left;
                    Node* right;
                    Node();
                    ~Node();
            };
            Node* root;

        public:
            BinaryTree(){};
            ~BinaryTree(){}
            
            BinaryTree& add_root(T element){
                return *this;
            }
            BinaryTree& add_left(T exist, T element){
                return *this;
            }
            BinaryTree& add_right(T exist, T element){
                return *this;
            }
            friend ostream& operator <<(ostream& output, const BinaryTree& tree){
                return output;
            }
        
            class iterator{
                protected:
                    Node* n;
                public:
                    iterator(Node* ptr = nullptr) : n(ptr) {}
                    bool operator!=(const iterator& other) const{
                        return n!=other.n;
                    }
                    T* operator->() const{
                        return new T();
                    }
                    T& operator*() const{
                        return *(new T());
                    }
                    iterator& operator ++(){
                        return *this;
                    } 
            };
            
            class IteratorPre : public iterator{
                public:
                    IteratorPre(Node* ptr) : iterator(ptr){}
                    IteratorPre& operator ++(){
                        return *this;
                    } 
            };

            class IteratorIn : public iterator{
                public:
                    IteratorIn(Node* ptr) : iterator(ptr){}
                    IteratorIn& operator ++(){
                        return *this;
                    } 
            };

            class IteratorPost : public iterator{
                public:
                    IteratorPost(Node* ptr) : iterator(ptr){}
                    IteratorPost& operator ++(){
                        return *this;
                    } 
            };

            iterator& begin(){
                return *(new iterator(root));
            }
            iterator& end(){ 
                return *(new iterator(root));
            }
            
            IteratorPre& begin_preorder(){
                return *(new IteratorPre(root));
            }
            IteratorPre& end_preorder(){
                return *(new IteratorPre(root));
            }

            IteratorIn& begin_inorder(){
                return *(new IteratorIn(root));
            }
            IteratorIn& end_inorder(){
                return *(new IteratorIn(root));
            }

            IteratorPost& begin_postorder(){ 
                return *(new IteratorPost(root));
            }
            IteratorPost& end_postorder(){
                return *(new IteratorPost(root));
            }
    };
}