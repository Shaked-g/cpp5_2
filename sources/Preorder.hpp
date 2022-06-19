#pragma once
#include "Node.hpp"
#include <string>

namespace ariel
{

    struct preorder_iterator : Node
    {
    private:
        Node* node_ptr;
        static Node* next_pre_order(Node * curr_node);
        static void reset_visited_nodes(Node *root);
    public:

        preorder_iterator(Node* ptr = nullptr):Node(""){
            node_ptr = ptr;
        }

        bool operator!=(const preorder_iterator& itr) const{
            return !(*this == itr);
        };
        
        const std::string& operator*() const {
            return node_ptr->name;
        }

        bool operator==(const preorder_iterator& itr) const{
            return node_ptr == itr.node_ptr;
        }

        const std::string* operator->() const {
            return &(node_ptr->name);
        }

        preorder_iterator& operator++();

    
    };
}