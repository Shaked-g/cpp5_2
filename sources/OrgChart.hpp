#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "levelOrder.hpp"
#include "PreOrder.hpp"
#include "ReverseLevelOrder.hpp"
#include "Node.hpp"

namespace ariel
{

    class OrgChart : public level_order_iterator, public reverse_level_order_iterator, public preorder_iterator
    {
    private:

        std::vector<Node*> levelOrderData;

        Node *root;

        Node *LastLevel; // start of the last level

        Node* findNode(const std::string &name);
    public:
        OrgChart(){
            root = nullptr;
            LastLevel = nullptr;
        }
        OrgChart (const OrgChart &other);
        OrgChart (OrgChart && other) = delete; // no move copy operations
        OrgChart& operator = (OrgChart && other) = delete; // no move assign 
        OrgChart& operator = (const OrgChart& other);
        OrgChart& add_root (const std::string &name);
        OrgChart& add_sub (const std::string &father, const std::string &name);
        ~OrgChart ();
        void checkIfEmpty();

        level_order_iterator end(){
            checkIfEmpty();
            return level_order_iterator(nullptr);
        }

        level_order_iterator begin();

        level_order_iterator begin_level_order(){
            return begin();
        }

        level_order_iterator end_level_order(){
            return end();
        }

        // wrong name in Demo fix
        reverse_level_order_iterator reverse_order(){
            return end_reverse_order();
        }

        reverse_level_order_iterator begin_reverse_order(){
            checkIfEmpty();
            return reverse_level_order_iterator(LastLevel);
        }

        reverse_level_order_iterator end_reverse_order(){
            checkIfEmpty();
            return reverse_level_order_iterator(nullptr);
        }

        preorder_iterator end_preorder(){
            checkIfEmpty();
            return preorder_iterator(nullptr);
        }

        preorder_iterator begin_preorder(){
            checkIfEmpty();
            return preorder_iterator((root));
        }
        
        friend std::ostream& operator << (std::ostream& output, const OrgChart& chart);    
    };

}