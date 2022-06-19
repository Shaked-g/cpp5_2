#pragma once

namespace ariel
{
    struct Node
    {
        std::string name;
        Node* father = nullptr;
        Node* next = nullptr;
        Node* prev = nullptr;
        std::vector<Node*> children;
        int level = -1;
        bool mark = false;
        Node(std::string name) {
            this->name = std::move(name);
        }
    };
}