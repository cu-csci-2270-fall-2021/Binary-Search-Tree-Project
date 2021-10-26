#include "MovieTree.hpp"
#include <iostream>
#include <fstream>


using namespace std;
/* ------------------------Starter Code function---------- */
LLMovieNode* getLLMovieNode(int r, std::string t, int y, float q)
{
	LLMovieNode* lmn =new LLMovieNode();
	lmn->ranking = r;
	lmn->title=t;
	lmn->year =y;
	lmn->rating =q;
	lmn->next =NULL;
	return lmn;
}

void preorderTraversalHelper(TreeNode * root) {
	if (root == NULL) 
    {
		return;
	}
    cout << root->titleChar << " ";
    preorderTraversalHelper(root->leftChild);
    preorderTraversalHelper(root->rightChild);
}

void MovieTree::preorderTraversal() {
	preorderTraversalHelper(root);
	cout << endl;
}

TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchCharNode(char key)
{
    return searchCharHelper(root, key);
}

/* --------------------------Constructor---------------------------- */
MovieTree::MovieTree()
{
	
    root = NULL;
}

/* --------------------------Destructor---------------------------- */
void destroyTreeNode(TreeNode* currNode) {
    if (currNode != NULL) {
        destroyTreeNode(currNode->leftChild);
        destroyTreeNode(currNode->rightChild);

        LLMovieNode* curr = currNode->head;
        LLMovieNode* prev = NULL;
        while (curr != NULL) {
            prev = curr;
            curr = curr->next;
            currNode->operator delete(prev);
        }
        delete currNode;
        currNode = NULL;
    }
}

MovieTree::~MovieTree()
{
	//TODO
    destroyTreeNode(root);
}

/* -------------------------showMovieCollection----------------------------- */
void showMovieHelper(TreeNode* currNode) {
    if (currNode != NULL) {
        showMovieHelper(currNode->leftChild);
        if (currNode->head != NULL) {
            cout << "Movies starting with letter: " << currNode->titleChar << endl;
            LLMovieNode* curr = currNode->head;

            while (curr != NULL) {
                cout << " >> " << curr->title << " " << curr->rating << endl;
                curr = curr->next;
            }
        }
        showMovieHelper(currNode->rightChild);
    }
}

void MovieTree::showMovieCollection()
{
	//TODO
    showMovieHelper(root);
}

/* --------------------------insertMovie---------------------------- */
TreeNode* insertMovieHelper(TreeNode* currNode, TreeNode* prev, TreeNode* found, LLMovieNode* temp) {
    if (found == NULL) {
        if (currNode == NULL) {
            TreeNode* tempNode = new TreeNode;
            tempNode->leftChild = NULL;
            tempNode->rightChild = NULL;
            tempNode->parent = prev;
            tempNode->titleChar = temp->title[0];
            tempNode->head = temp;
            temp->next = NULL;
            
            return tempNode;
        } else if (currNode->titleChar > temp->title[0]) {
            currNode->leftChild = insertMovieHelper(currNode->leftChild, currNode, NULL, temp);
        } else if (currNode->titleChar < temp->title[0]) {
            currNode->rightChild = insertMovieHelper(currNode->rightChild, currNode, NULL, temp);
        }

        return currNode;
    } else {
        LLMovieNode* looper = found->head;
        LLMovieNode* prevLooper = found->head;

        while (looper != NULL) {
            if (looper->title.compare(temp->title) > 0) {
                if (looper == found->head) {
                    temp->next = found->head;
                    found->head = temp;
                    return currNode;
                } else {
                    LLMovieNode* temporary = looper;
                    prevLooper->next = temp;
                    temp->next = temporary;
                    return currNode;
                }
            }
            prevLooper = looper;
            looper = looper->next;
        }
        prevLooper->next = temp;
        temp->next = NULL;

        return currNode;
    }
}

void MovieTree::insertMovie(int ranking, string title, int year, float rating)
{
	//TODO
    LLMovieNode* temp = new LLMovieNode;
    temp->ranking = ranking;
    temp->title = title;
    temp->year = year;
    temp->rating = rating;

    root = insertMovieHelper(root, root, searchCharNode(temp->title[0]), temp);
}

/* ------------------------removeMovieRecord------------------------------ */
void MovieTree::removeMovieRecord(std::string title)
{
	//TODO
    TreeNode* found = searchCharNode(title[0]);

    if (found != NULL) {
        LLMovieNode* curr = found->head;
        LLMovieNode* prev = NULL;
        
        while (curr != NULL) {
            if (curr->title == title) {
                LLMovieNode* temp = curr->next;
                delete curr;
                curr = NULL;
                if (prev == NULL) {
                    found->head = temp;
                } else {
                    prev->next = temp;
                }
                return;
            }

            prev = curr;
            curr = curr->next;
        }

        cout << "Movie not found."<< endl;
    } else {
        cout << "Movie not found."<< endl;
    }
}

/* --------------------------leftRotation---------------------------- */
void MovieTree::leftRotation(TreeNode* curr) {
   //TODO
    TreeNode* right = curr->rightChild;

    if (right == NULL) {
        return;
    } else if (curr == root) {
        curr->rightChild = right->leftChild;
        curr->parent = right;
        right->leftChild = curr;
        right->parent = NULL;
        root = right;
    } else {
        TreeNode* temp = curr->parent;
        bool isLeftChild;

        if (temp->leftChild == curr) {
            isLeftChild = true;
        } else {
            isLeftChild = false;
        }

        curr->rightChild = right->leftChild;
        curr->parent = right;
        right->leftChild = curr;
        right->parent = temp;
        
        if (isLeftChild) {
            temp->leftChild = right;
        } else {
            temp->rightChild = right;
        }
    }
}
