#pragma once
#include "Node.hpp"
#include <string>
namespace ariel
{

struct level_order_iterator : Node
    {
    private:
        Node* node_ptr;
    public:
        level_order_iterator(Node* ptr = nullptr):Node("") {
            node_ptr = ptr;
        }

        const std::string& operator*() const {
            return node_ptr->name;
        } 

        const std::string* operator->() const {
            return &(node_ptr->name);
        }

        level_order_iterator& operator++(){
            node_ptr = node_ptr->next;
            return *this;
        } 

        bool operator == (const level_order_iterator& itr) const{
            return node_ptr == itr.node_ptr;
        }

        bool operator != (const level_order_iterator& itr) const{
            return !(*this == itr);
        }
    
    };
}