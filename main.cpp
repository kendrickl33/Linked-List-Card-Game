#include <iostream>
#include <fstream>
#include <string>

#include "cards.h"


using namespace std;

void alicePrint(char suit, char digit);
void bobPrint(char suit, char digit);

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  CardBST alice, bob;

  while (getline (cardFile1, line) && (line.length() > 0)){
	char a = line[0];
	char b;
	if(line.length() == 4){
		b = 't';
	}else{
		b = line[2];
	}
	alice.insert(a,b);
  }
  cardFile1.close();

  while (getline (cardFile2, line) && (line.length() > 0)){
	char a = line[0];
	char b;
	if(line.length() == 4){
		b = 't';
	}else{
		b = line[2];
	}
	bob.insert(a,b);

  }
  cardFile2.close();
  
  bool gameRunning = true;
  int turn = 0;  
  char aliceSuit = alice.findMinSuit();
  char aliceDigit = alice.findMinDigit();
  char bobSuit = bob.findMaxSuit();
  char bobDigit = bob.findMaxDigit();
  char aliceSuit2;
  char aliceDigit2;
  char bobDigit2;
  char bobSuit2;
	
  while(gameRunning){
	if(aliceSuit == 'f' && aliceDigit == 'f'){
		break;
	}
	if(bobSuit == 'f' && bobDigit == 'f'){
		break;
	}
	if(turn == 0){
		if(bob.contains(aliceSuit, aliceDigit)){
			aliceSuit2 =  alice.findSucSuit(aliceSuit,aliceDigit);
			aliceDigit2 = alice.findSucDigit(aliceSuit,aliceDigit);
			bob.remove(aliceSuit,aliceDigit);
			alice.remove(aliceSuit,aliceDigit);
		     	alicePrint(aliceSuit,aliceDigit);
			aliceSuit = aliceSuit2;
			aliceDigit = aliceDigit2;
			turn = 1;	
  		}else{
			aliceSuit2 =  alice.findSucSuit(aliceSuit,aliceDigit);
			aliceDigit2 = alice.findSucDigit(aliceSuit,aliceDigit);
			aliceSuit = aliceSuit2;
			aliceDigit = aliceDigit2;
		}			
	}else if(turn == 1){
		if(alice.contains(bobSuit, bobDigit)){
			bobSuit2 = bob.findPreSuit(bobSuit,bobDigit);
			bobDigit2 = bob.findPreDigit(bobSuit,bobDigit);
		 	alice.remove(bobSuit,bobDigit);
			bob.remove(bobSuit,bobDigit);
		        bobPrint(bobSuit,bobDigit);
			bobSuit = bobSuit2;
			bobDigit = bobDigit2;
			

			turn = 0;
		}else{
			bobSuit2 = bob.findPreSuit(bobSuit,bobDigit);
			bobDigit2 = bob.findPreDigit(bobSuit,bobDigit);
			bobSuit = bobSuit2;
			bobDigit = bobDigit2;

		}
	}
  }
  cout << endl;
  cout << "Alice's cards:" << endl;
  alice.printInOrder();
  cout << endl;
  cout << "Bob's cards:" << endl;
  bob.printInOrder();
	 
  return 0;
}

void alicePrint(char suit, char digit){
	cout << "Alice picked matching card " << suit;
	if(digit == 't'){
		cout << " 10" << endl;
	}else{
		cout << " " << digit << endl;
	}
	
}

void bobPrint(char suit, char digit){
	cout << "Bob picked matching card " << suit;
	if(digit == 't'){
		cout << " 10" << endl;
	}else{
		cout << " " << digit << endl;
	}
	
} 
