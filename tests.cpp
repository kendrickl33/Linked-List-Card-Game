#include <iostream>
#include <fstream>
#include <string>

#include"cards.cpp"

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
  //Read each file
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
  char aliceSuit = alice.findMinSuit();
  char aliceDigit = alice.findMinDigit();
  char bobSuit = bob.findMaxSuit();
  char bobDigit = bob.findMaxDigit();
  char aliceSuit2;
  char aliceDigit2;
  int turn =  1;

  alice.remove('c','a');
 
  while(turn < 5){
	aliceSuit2 = aliceSuit;
	aliceSuit = alice.findSucSuit(aliceSuit,aliceDigit);
	aliceDigit = alice.findSucDigit(aliceSuit2,aliceDigit);
	cout << "suc: " << aliceSuit << " " << aliceDigit << endl;
	turn++;	
  }
  
  alice.remove('h','9');
 while(turn < 5){
	aliceSuit2 = aliceSuit;
	aliceSuit = alice.findSucSuit(aliceSuit,aliceDigit);
	aliceDigit = alice.findSucDigit(aliceSuit2,aliceDigit);
	cout << "suc: " << aliceSuit << " " << aliceDigit << endl;
	turn++;	
  }
  

  alice.remove('c','3');
 while(turn < 5){
	aliceSuit2 = aliceSuit;
	aliceSuit = alice.findSucSuit(aliceSuit,aliceDigit);
	aliceDigit = alice.findSucDigit(aliceSuit2,aliceDigit);
	cout << "suc: " << aliceSuit << " " << aliceDigit << endl;
	turn++;	
  }
  

  alice.remove('s','q');
 while(turn < 5){
	aliceSuit2 = aliceSuit;
	aliceSuit = alice.findSucSuit(aliceSuit,aliceDigit);
	aliceDigit = alice.findSucDigit(aliceSuit2,aliceDigit);
	cout << "suc: " << aliceSuit << " " << aliceDigit << endl;
	turn++;	
  }
  

 
 alice.remove('c','4');
 while(turn < 5){
	aliceSuit2 = aliceSuit;
	aliceSuit = alice.findSucSuit(aliceSuit,aliceDigit);
	aliceDigit = alice.findSucDigit(aliceSuit2,aliceDigit);
	cout << "suc: " << aliceSuit << " " << aliceDigit << endl;
	turn++;	
  }
  

  alice.remove('s','t');
 while(turn < 5){
	aliceSuit2 = aliceSuit;
	aliceSuit = alice.findSucSuit(aliceSuit,aliceDigit);
	aliceDigit = alice.findSucDigit(aliceSuit2,aliceDigit);
	cout << "suc: " << aliceSuit << " " << aliceDigit << endl;
	turn++;	
  }
  


  cout << endl;
  alice.printInOrder();
 
	
}
void alicePrint(char suit, char digit){
	cout << "Alice picked matching card " << suit;
	if(digit == 't'){
		cout << " 10";	
	}else{
		cout << " " << digit << endl;
	}
	
}

void bobPrint(char suit, char digit){
	cout << "Bob picked matching card " << suit;
	if(digit == 't'){
		cout << " 10";	
	}else{
		cout << " " << digit << endl;
	}
	
}	
