#include <iostream>

using namespace std;

class Hand {
	int size;
	Card * cards;
public:
	Hand();
	~Hand();
	Hand(const Hand &);
	Hand& operator=(const Hand&);
};

