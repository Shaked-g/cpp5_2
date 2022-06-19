#pragma once
#include "Node.hpp"

 namespace ariel
{
struct reverse_level_order_iterator : Node
    {
    private:
        Node* node_ptr;
    public:
        reverse_level_order_iterator(Node* ptr = nullptr): Node("") {
            node_ptr = ptr;
        }

        const std::string& operator*() const {
            return node_ptr->name;
        }

        bool operator != (const reverse_level_order_iterator& itr) const {
            return !(*this == itr);
        }

        const std::string* operator->() const {
            return &(node_ptr->name);
        }

        
        bool operator == (const reverse_level_order_iterator& itr) const {
            return node_ptr == itr.node_ptr;
        }

        reverse_level_order_iterator& operator++();
    
    };
}