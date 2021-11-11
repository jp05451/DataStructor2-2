#include <iostream>
using namespace std;

template<int T>
class treeNode
{
public:
    treeNode *parentNode = nullptr;
    T data;
    treeNode *nextNode[2] = {nullptr};

    treeNode(T inputData) { data = inputData; }
    treeNode(treeNode *parent, T input)
    {
        parentNode = parent;
        data = input;
    }

    void printNode()
    {
        // cout << data;
        // cout << "(";
        printf("%d(", data);
        if (nextNode[0] != nullptr)
        {
            nextNode[0]->printNode();
        }
        //cout << ")(";
        printf(")(");
        if (nextNode[1] != nullptr)
        {
            nextNode[1]->printNode();
        }
        //cout << ")";
        printf(")");
    }

    // void add(T input)
    // {
    //     if (input <= data)
    //     {
    //         if (nextNode[0] == nullptr)
    //         {
    //             treeNode *newNode = new treeNode(this, input);
    //             nextNode[0] = newNode;
    //         }
    //         else
    //         {
    //             nextNode[0]->add(input);
    //         }
    //         return;
    //     }
    //     if (input > data)
    //     {
    //         if (nextNode[1] == nullptr)
    //         {
    //             treeNode *newNode = new treeNode(this, input);
    //             nextNode[1] = newNode;
    //             return;
    //         }
    //         else
    //         {
    //             nextNode[1]->add(input);
    //         }
    //     }
    // }

    void add(T inputData)
    {
        treeNode *preNode = this;
        treeNode *lastNode = this;
        //while (lastNode != nullptr)
        while (lastNode != nullptr)
        {
            if (inputData <= preNode->data)
            {
                lastNode = preNode->nextNode[0];
            }
            else
            {
                lastNode = preNode->nextNode[1];
            }
            if (lastNode == nullptr)
            {
                break;
            }
            else
            {
                preNode = lastNode;
            }
        }
        if (inputData <= preNode->data)
        {
            preNode->nextNode[0] = new treeNode(preNode, inputData);
        }
        else
        {
            preNode->nextNode[1] = new treeNode(preNode, inputData);
        }
    }

    // void removeNode(T deleteData)
    // {
    //     int remove;
    //     treeNode *deleteNode;

    //     //find the deleteNode
    //     if (deleteData <= data)
    //     {
    //         remove = 0;
    //         deleteNode = nextNode[0];
    //     }
    //     else
    //     {
    //         remove = 1;
    //         deleteNode = nextNode[1];
    //     }

    //     //delete Node
    //     if (deleteNode->nextNode[0] == nullptr && deleteNode->nextNode[1] == nullptr)
    //     //have no child node
    //     {
    //         delete deleteNode;
    //         nextNode[remove] = nullptr;
    //         return;
    //     }
    //     else if (deleteNode->nextNode[0] != nullptr && deleteNode->nextNode[1] != nullptr)
    //     //have two child node
    //     {
    //         if (deleteNode->nextNode[0]->nextNode[1] == nullptr)
    //         //don't have left child's right child
    //         {
    //             deleteNode->data = deleteNode->nextNode[0]->data;
    //             deleteNode->removeNode(deleteNode->data);
    //         }
    //         else
    //         //have left child's right child
    //         {
    //             treeNode *finalNode = deleteNode->nextNode[0]->findRightLeaf();
    //             deleteNode->data = finalNode->nextNode[1]->data;
    //             finalNode->removeNode(finalNode->nextNode[1]->data);
    //         }
    //         return;
    //     }
    //     else
    //     // only have one child
    //     {
    //         if (deleteNode->nextNode[0] != nullptr)
    //         //have left child
    //         {
    //             //deletNode->data = deletNode->nextNode[0]->data;
    //             nextNode[remove] = deleteNode->nextNode[0];
    //             // deleteNode->removeNode(deleteNode->nextNode[0]->data);
    //         }
    //         else
    //         //have right child
    //         {
    //             nextNode[remove] = deleteNode->nextNode[1];
    //         }
    //         delete deleteNode;
    //     }
    // }

    void removeNode(T deleteData)
    {
        int remove;
        treeNode *deleteNode;

        //find the deleteNode
        if (deleteData <= data)
        {
            remove = 0;
            deleteNode = nextNode[0];
        }
        else
        {
            remove = 1;
            deleteNode = nextNode[1];
        }

        //delete Node
        if (deleteNode->nextNode[0] == nullptr && deleteNode->nextNode[1] == nullptr)
        //have no child node
        {
            delete deleteNode;
            nextNode[remove] = nullptr;
            return;
        }
        else if (deleteNode->nextNode[0] != nullptr && deleteNode->nextNode[1] != nullptr)
        //have two child node
        {
            if (deleteNode->nextNode[0]->nextNode[1] == nullptr)
            //don't have left child's right child
            {
                deleteNode->data = deleteNode->nextNode[0]->data;
                deleteNode->removeNode(deleteNode->data);
            }
            else
            //have left child's right child
            {
                treeNode *finalNode = deleteNode->nextNode[0]->findRightLeaf();
                deleteNode->data = finalNode->nextNode[1]->data;
                finalNode->removeNode(finalNode->nextNode[1]->data);
            }
            return;
        }
        else
        // only have one child
        {
            if (deleteNode->nextNode[0] != nullptr)
            //have left child
            {
                //deletNode->data = deletNode->nextNode[0]->data;
                nextNode[remove] = deleteNode->nextNode[0];
                // deleteNode->removeNode(deleteNode->nextNode[0]->data);
            }
            else
            //have right child
            {
                nextNode[remove] = deleteNode->nextNode[1];
            }
            delete deleteNode;
        }
    }

    // treeNode *findParent(T searchData)
    // {
    //     if (searchData <= data)
    //     {
    //         if (nextNode[0] != nullptr)
    //         {
    //             if (nextNode[0]->data == searchData)
    //             {
    //                 return this;
    //             }
    //             else
    //             {
    //                 return nextNode[0]->findParent(searchData);
    //             }
    //         }
    //         else
    //         {
    //             return nullptr;
    //         }
    //     }
    //     else
    //     {
    //         if (nextNode[1] != nullptr)
    //         {
    //             if (nextNode[1]->data == searchData)
    //             {
    //                 return this;
    //             }
    //             else
    //             {
    //                 return nextNode[1]->findParent(searchData);
    //             }
    //         }
    //         else
    //         {
    //             return nullptr;
    //         }
    //     }
    // }

    treeNode *findParent(T searchData)
    {
        treeNode *tempNode = this;
        while (tempNode != nullptr)
        {
            if (searchData <= tempNode->data)
            {
                if (tempNode->nextNode[0] != nullptr)
                {
                    if (tempNode->nextNode[0]->data == searchData)
                    {
                        return tempNode;
                    }
                    else
                    {
                        tempNode = tempNode->nextNode[0];
                    }
                }
                else
                {
                    return nullptr;
                }
            }
            else
            {
                if (tempNode->nextNode[1] != nullptr)
                {
                    if (tempNode->nextNode[1]->data == searchData)
                    {
                        return tempNode;
                    }
                    else
                    {
                        tempNode = tempNode->nextNode[1];
                    }
                }
                else
                {
                    return nullptr;
                }
            }
        }
    }

    // treeNode *findRightLeaf()
    // {
    //     if (nextNode[1]->nextNode[1] == nullptr)
    //     {
    //         return this;
    //     }
    //     return nextNode[1]->findRightLeaf();
    // }

    treeNode *findRightLeaf()
    {
        treeNode *tempNode = this;
        while (tempNode->nextNode[1]->nextNode[1] != nullptr)
        {
            tempNode = tempNode->nextNode[1];
        }
        return tempNode;
    }

    void destroyNode()
    {
        for (int i = 0; i < 2; i++)
        {
            if (nextNode[i] != nullptr)
            {
                if (nextNode[i]->nextNode[0] != nullptr || nextNode[i]->nextNode[1] != nullptr)
                {
                    nextNode[i]->destroyNode();
                }
                if (nextNode[i]->nextNode[0] == nullptr && nextNode[i]->nextNode[1] == nullptr)
                //last Node of the tree
                {
                    delete nextNode[i];
                    nextNode[i] = nullptr;
                }
            }
        }
    }
};