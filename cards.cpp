#include "cards.h"

#include <iostream>

using namespace std;

CardBST::CardBST() : root(0) { }

CardBST::~CardBST(){
	clear(root);
}	

bool CardBST::cardEqual(int suit1, int digit1, int suit2, int digit2){
        if(suit1 == suit2 && digit1 == digit2){
		return true;	
	}
	return false;
}


bool CardBST::cardLess(int suit1, int digit1, int suit2, int digit2){
	if(suit1 < suit2){
		return true;
	}else if(suit1 == suit2){
		if(digit1 < digit2){
			return true;
		}
	}
	return false;
}


bool CardBST::cardMore(int suit1, int digit1, int suit2, int digit2){
	if(suit1 > suit2){
		return true;
	}else if(suit1 == suit2){
		if(digit1 > digit2){
			return true;
		}
	}
	return false;

}

void CardBST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}


void CardBST::printInOrder() const {
    printInOrder(root);
}
void CardBST::printInOrder(Node *n) const {
    if(n){
	printInOrder(n->left);
	if(n->digit == 't'){
		cout << n->suit << " " << "10" << endl;
	}else{
		cout << n->suit << " " << n->digit << endl;
	}
	printInOrder(n->right);
    }
}

int CardBST::count() const {
    return count(root);
}

int CardBST::count(Node *n) const {
    if(n == NULL){
	return 0;	
    }else{
	return 1 + count(n->left) + count(n->right);
    }
}

int CardBST::suitToInt(char suit){
	if(suit == 'c'){
		return 1;
	}else if(suit == 'd'){
		return 2;
	}else if(suit == 's'){
		return 3;
	}else if(suit == 'h'){
		return 4;
	}
	return 0;
}

int CardBST::digitToInt(char digit){
	if(digit == 'j'){
		return 11;
	}else if(digit == 'q'){
		return 12;
	}else if(digit == 'k'){
		return 13;
	}else if(digit == 'a'){
		return 1;
	}else if(digit == 't'){
		return 10;
	}else{
		return digit - '0';
	}
	return 0;
}

bool CardBST::insert(char suit, char digit) {
    
      if (!root) {
    		root = new Node(suit, digit);
    		return true;
      }else{
		
      	        return insert(suit, digit, root);
      }
}

bool CardBST::insert(char suit, char digit, Node *n) {
    int suitInt = suitToInt(suit);
    int digitInt = digitToInt(digit);
  
    if(cardEqual(suitInt,digitInt, n->suitInt,n->digitInt)){
	return false;	
    } 
  
    if (cardLess(suitInt,digitInt, n->suitInt, n->digitInt)) {
	if (n->left){
	    return insert(suit, digit, n->left);
	}else{
	    n->left = new Node(suit, digit);
	    n->left->parent = n;
	    return true;
	}
    }else {
	if (n->right){
	    return insert(suit, digit, n->right);
	}else {
	    n->right = new Node(suit, digit);
	    n->right->parent = n;
	    return true;
	}
    }
}


CardBST::Node* CardBST::getNode(char suit,char digit, Node* n){
    int suitInt = suitToInt(suit);
    int digitInt = digitToInt(digit);
	
    if(n == nullptr){
	return nullptr;
    }else if(cardEqual(n->suitInt,n->digitInt,suitInt,digitInt)){
	return n;
    }else if(cardLess(n->suitInt,n->digitInt,suitInt,digitInt)){
	return getNode(suit, digit, n->right);	
    }else{
 	return getNode(suit, digit, n->left);
    }

}



bool CardBST::contains(char suit, char digit) {
   Node * temp = this->getNode(suit, digit, root);
   if(temp == nullptr){
   	return false;
   }else{
	return true;
   }
}

CardBST::Node* CardBST::findMax(Node* n){
	Node * curr = root;
	while(curr->right){
		curr = curr->right;
	}
	return curr;
	
}

CardBST::Node* CardBST::findMin(Node * n){
	Node * curr = root;
	while(curr->left){
		curr = curr->left;
	}	
	return curr;
}

char CardBST::findMaxSuit(){
	Node * temp = this->findMax(root);
	return temp->suit;	
}

char CardBST::findMaxDigit(){
	Node * temp = this->findMax(root);
	return temp->digit;	
}

char CardBST::findMinSuit(){
	Node * temp = this->findMin(root);
	return temp->suit;	
}

char CardBST::findMinDigit(){
	Node * temp = this->findMin(root);
	return temp->digit;	
}


CardBST::Node* CardBST::getPreNode(char suit, char digit){
    Node * temp = getNode(suit, digit, root);
    if(root == nullptr){
	return nullptr;	
    }
    if(temp == nullptr){
	return nullptr;	
    }
    if(temp->left){
	Node * n = temp->left;
	while(n->right){
		if(n->right == NULL){
			return n;
		}
		n = n->right;
	}	
	return n;
    }else{
	Node * k = temp->parent;
	while(k){
		if(cardLess(k->suitInt, k->digitInt, temp->suitInt, temp->digitInt)){
			return k;
		}
		k = k->parent;
	}
    }
    return NULL;

}


CardBST::Node* CardBST::getSucNode(char suit, char digit){
    Node * temp = getNode(suit, digit, root);
    if(root == nullptr){
	return nullptr;	
    }
    if(temp == nullptr){
	return nullptr;	
    }
    if(temp->right){
	Node * n = temp->right;
	while(n->left){
		if(n->left == nullptr){
			return n;
		}
		n = n->left;
	}	
	return n;
    }else{
	Node * k = temp->parent;
	while(k){
		if(cardMore(k->suitInt, k->digitInt, temp->suitInt, temp->digitInt)){
			return k;
		}
		k = k->parent;
	}
    }
    return nullptr;
}

char CardBST::findPreSuit(char suit, char digit){
	Node * temp  = this->getPreNode(suit, digit);
	if(temp == nullptr){
		return  'f';
	}
	return temp->suit;	

}

char CardBST::findPreDigit(char suit, char digit){
	Node * temp  = this->getPreNode(suit, digit);
	if(temp == nullptr){
		return 'f';
	}
	return temp->digit;

}

char CardBST::findSucSuit(char suit, char digit) {
	Node * temp  = this->getSucNode(suit, digit);
	if(temp == nullptr){
		return 'f';		
	}
	return temp->suit;	
	
}


char CardBST::findSucDigit(char suit, char digit) {
	Node * temp  = this->getSucNode(suit, digit);
	if(temp  == nullptr){
		return 'f';  		
	}
	return temp->digit;	
}


bool CardBST::remove(char suit, char digit){
	Node * curr = this->getNode(suit,digit,root);
	Node * suc = nullptr;
	
	if(curr->left == nullptr && curr->right == nullptr){
		if(curr == root){
			delete curr;
			root = nullptr;
		}else{
			if(cardLess(curr->suitInt, curr->digitInt,curr->parent->suitInt,curr->parent->digitInt)){
				curr->parent->left = nullptr;
			}else{
				curr->parent->right = nullptr;
			}
			delete curr;
		}
	}else if(curr->left && curr->right){
		suc = this->getSucNode(curr->suit,curr->digit);
		char suit2 = suc->suit;
		char digit2 = suc->digit;
		int suitInt2 = suc->suitInt;
		int digitInt2 = suc->digitInt;
		remove(suit2, digit2);
		curr->suit = suit2;
		curr->digit = digit2;
		curr->suitInt = suitInt2;
		curr->digitInt = digitInt2;
		
	}else if(curr->left || curr->right){
		if(curr == root){
			if(curr->left){
				root = curr->left;
				root->parent = nullptr;
			}else{
				root = curr->right;
				root->parent = nullptr;
			}
			delete curr;
		}else{
			Node* temp = curr->left;
			if(curr->right != nullptr){
				temp = curr->right;
				
			}
			if(curr->parent->left == curr){
				temp->parent = curr->parent;
				curr->parent->left = temp;
				
	
			}
			if(curr->parent->right == curr){
				temp->parent = curr->parent;
				curr->parent->right = temp;
			}
			delete curr;
		}
	}
	return true;
}
