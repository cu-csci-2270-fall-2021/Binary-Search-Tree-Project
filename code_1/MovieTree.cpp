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
MovieTree::~MovieTree()
{
	//TODO
}

/* -------------------------showMovieCollection----------------------------- */
void MovieTree::showMovieCollection()
{
	//TODO
}

/* --------------------------insertMovie---------------------------- */
void MovieTree::insertMovie(int ranking, string title, int year, float rating)
{
	//TODO
    root = NULL;
}

/* ------------------------removeMovieRecord------------------------------ */
void MovieTree::removeMovieRecord(std::string title)
{
	//TODO
}

/* --------------------------leftRotation---------------------------- */
void MovieTree::leftRotation(TreeNode* curr) {
   //TODO
}
