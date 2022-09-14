#ifndef CARDS_H
#define CARDS_H

#endif

class CardBST{

	public:
		CardBST();
		~CardBST();
		bool insert(char suit, char digit);
		bool contains(char suit, char digit);
		bool remove(char suit, char digit);
		        
		void printInOrder() const;
	 
		int suitToInt(char suit);
		int digitToInt(char digit);
		
		int count() const;
		
		bool cardLess(int suit1, int digit1, int suit2, int digit2);
		bool cardMore(int suit1, int digit1, int suit2, int digit2);
		bool cardEqual(int suit1, int digit1, int suit2, int digit2);
		
		char findMaxSuit();
		char findMaxDigit();
		char findMinSuit();
		char findMinDigit();
	
		char findPreSuit(char suit, char digit) ;
		char findPreDigit(char suit, char digit) ; 
		char findSucSuit(char suit, char digit) ;
		char findSucDigit(char suit, char digit) ;
	
		
	private:
		struct	Node {
			char suit;
			char digit;
			int suitInt;
			int digitInt;
			Node *left, *right, *parent;
			Node(char s, char d){
				suit = s;
				digit = d;
				left = nullptr;
				right =	nullptr;
				parent = nullptr;
				if(s == 'c'){
					suitInt = 1;
				}else if(s == 'd'){
					suitInt = 2;
				}else if(s == 's'){
					suitInt = 3;
				}else if(s == 'h'){
					suitInt = 4;
				}
				if(d == 'j'){
					digitInt = 11;
				}else if(d == 'q'){
					digitInt = 12;
				}else if(d == 'k'){
					digitInt = 13;
				}else if(d == 'a'){
					digitInt = 1;
				}else if(d == 't'){
					digitInt = 10;
				}else{
					digitInt = d - '0';
				}
			}
		};

		Node * root;
				
		void printInOrder(Node *n) const;	
			
		int count(Node * n) const;
		void clear(Node * n);
		bool insert(char suit, char digit, Node * n);
		Node * findMin(Node * n);
		Node * findMax(Node * n);
		Node * getNode(char suit, char digit, Node * n);
		Node * getSucNode(char suit, char digit);
		Node * getPreNode(char suit, char digit);
	
	
};
