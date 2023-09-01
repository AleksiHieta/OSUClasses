#include <iostream>
#include <cmath>
#include <sys/time.h>
#include <cstdlib>

using std::cout;
using std::endl;
using namespace std;

int fib_iter(int r)
{
	int a = 0, b = 1, c;
	
	if (r==0)
		return 0;
	else if (r==1)
		return 1;
	else{
		for (int x=1; x <= (r - 1); x++){
			c = a + b;
			a = b;
			b = c;

		}
	return c;
	}
}

int fib_recurs(int r)
{
	if (r==0)
		return 0;
	else if (r==1)
		return 1;
	else 
		return fib_recurs(r-1)+fib_recurs(r-2);
}

int main()
{
	int r;
	
	cout << "\nEnter the term number of the sequence: ";
	cin >> r;

//	cout << fib_iter(r) << endl;
//	cout << fib_recurs(r) << endl;
	
/*	typedef struct timeval time;
	time stop, start; 
	gettimeofday(&start, NULL);
	//function
	cout << fib_iter(r) << endl;
	//Time
	gettimeofday(&stop, NULL);
	if(stop.tv_sec > start.tv_sec)
		cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
	else
		cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;
*/
	typedef struct timeval time;
	time stop, start; 
	gettimeofday(&start, NULL);
	//function 	
	cout << fib_recurs(r) << endl;
	//Time
	gettimeofday(&stop, NULL);
	if(stop.tv_sec > start.tv_sec)
		cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
	else
		cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;

	

	return 0;
}

