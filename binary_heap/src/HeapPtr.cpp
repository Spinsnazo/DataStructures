#include "HeapPtr.h"


HeapPtr::HeapPtr()
{
    root = NULL;
    size = 0;
}

HeapPtr::~HeapPtr()
{
    if(root!=NULL)
    {
        std::queue<HeapNode*>que;
        que.push(root);
        while(!que.empty())
        {
            HeapNode* current = que.front();
            if(current->left_child!=NULL) que.push(current->left_child);
            if(current->right_child!=NULL) que.push(current->right_child);
            que.pop();
            delete current;
        }
    }
}

void HeapPtr::add(int n)
{

    HeapNode *neww = new HeapNode;

    neww->parent=NULL;
    neww->left_child=NULL;
    neww->right_child=NULL;
    neww->value = n;

    if(root==NULL)
    {
        root = neww;
        return;
    }
    else
    {
        // I'm using a queue to find a free place for a new node
        std::queue<HeapNode*>que;
        que.push(root);

        while(!que.empty())
        {
            HeapNode* current = que.front();
            que.pop();
            if(current->left_child == NULL)
            {
                current->left_child = neww;
                neww->parent = current;
                break;
            }
            else if(current->right_child == NULL)
            {
                current->right_child = neww;
                neww->parent = current;
                break;
            }
            que.push(current->left_child);
            que.push(current->right_child);
        }
        heapify_up(neww);
    }
}

int HeapPtr::del(HeapNode* node)
{
    HeapNode *last = find_last();
    if(last==NULL) return -1;
    bool is_last = false;
    if(last==node) is_last=true;
    int data = node->value;
    node->value = last->value;
    if(last->parent->left_child == last) last->parent->left_child = NULL;
    else last->parent->right_child = NULL;
    delete last;
    if(!is_last)
    {
        if(node->parent!=NULL && node->parent->value < node->value) heapify_up(node);
        else heapify_down(node);
    }
    return data;
}

void HeapPtr::heapify_up(HeapNode* node)
{
    if(node!=NULL)
    {
        while(node->parent != NULL &&  node->value > node->parent->value)
        {
            std::swap(node->value, node->parent->value);
            node = node->parent;
        }
    }
}

void HeapPtr::heapify_down(HeapNode* node)
{
    while(node!=NULL && (node->left_child!=NULL || node->right_child!=NULL))
    {
        HeapNode* max = node;
        if(node->right_child!=NULL && node->right_child->value > node->value)  max = node->right_child;
        if(node->left_child!=NULL && node->left_child->value > max->value)
            max = node->left_child;
        if(node==max) return;
        std::swap(node->value, max->value);
        node = max;
    }
}

HeapNode* HeapPtr::find_last()
{
    // An algorithm with a queue - I'm finding the last element
    std::queue<HeapNode*> que;
    if(root==NULL) return NULL;
    que.push(root);
    HeapNode* last = NULL;
    while(!que.empty())
    {
        last = que.front();
        if(last->left_child!=NULL) que.push(last->left_child);
        if(last->right_child!=NULL) que.push(last->right_child);
        que.pop();
    }
    return last;
}

void HeapPtr::print_heap()
{
    std::queue<HeapNode*>que;
    if(root==NULL) return;
    que.push(root);
    while(!que.empty())
    {
        HeapNode* current = que.front();
        que.pop();
        std::cout<<current->value<<", ";
        if(current->left_child!=NULL) que.push(current->left_child);
        if(current->right_child!=NULL) que.push(current->right_child);
    }
    std::cout<<"\n";
}

void HeapPtr::heapify_sort(int arr[], int size_arr)
{
    if(size_arr<=1) return;
    HeapPtr sorting;
    // Create a heap based on an array
    for(int i=size_arr-1; i>-1; i--)
        sorting.add(arr[i]);
    for(int i=size_arr-1; i>0; i--)
    {
        arr[i] = sorting.root->value;
        HeapNode* last = sorting.find_last();
        std::swap(sorting.root->value, last->value);
        sorting.del(last);
        sorting.heapify_down(sorting.root);
    }
    arr[0] = sorting.root->value;

}
