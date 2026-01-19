#include "tree_bag.hpp"
#include <iostream>

tree_bag::node*    tree_bag::copy_node(node* cur)
{
    if (cur == nullptr)
        return (nullptr);
    node *new_node = new node;
    new_node->value = cur->value;
    new_node->left = copy_node(cur->left);
    new_node->right = copy_node(cur->right);
    return (new_node);
}

void    tree_bag::print_node(node* cur)
{
    if (cur == nullptr)
        return ;
    print_node(cur->left);
    std::cout << cur->value << " ";
    print_node(cur->right);
}

void    tree_bag::destroy_node(node* cur)
{
    if (cur == nullptr)
        return ;
    destroy_node(cur->left);
    destroy_node(cur->right);
    delete cur;
}

tree_bag::tree_bag() : tree(nullptr) {}

tree_bag::tree_bag(const tree_bag& other)
{
    tree = copy_node(other.tree);
}

tree_bag&  tree_bag::operator=(const tree_bag& other)
{
    if (this == &other)
        return (*this);
    destroy_node(this->tree);
    this->tree = copy_node(other.tree);
    return (*this);
}

tree_bag::~tree_bag()
{
    destroy_node(tree);
}

void    tree_bag::insert(int num)
{
    node    *new_node = new node;
    new_node->value = num;
    new_node->left = nullptr;
    new_node->right = nullptr;
    if (tree == nullptr)
        tree = new_node;
    else
    {
        node *cur = tree;
        while (1)
        {
            if (cur->value > num)
            {
                if (cur->left == nullptr)
                {
                    cur->left = new_node;
                    break ;
                }   
                else
                    cur = cur->left;
            }
            else if (cur->value < num)
            {
                if (cur->right == nullptr)
                {
                    cur->right = new_node;
                    break ;
                }
                else
                    cur = cur->right;
            }
            else
            {
                delete new_node;
                break ;
            }
        }
    }
}

void    tree_bag::insert(int *data, int count)
{
    for (int i = 0; i < count; i++)
        insert(data[i]);
}

void    tree_bag::print() const
{
    print_node(tree);
    std::cout << std::endl;
}

void    tree_bag::clear()
{
    destroy_node(tree);
    tree = nullptr;
}