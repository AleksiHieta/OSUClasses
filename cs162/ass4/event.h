//event.h

#ifndef EVENT 
#define EVENT

#include <iostream>

using namespace std;

class Event {
	char thang;
	bool there;
public:
	Event();
//	virtual void set_symbol();
	virtual char get_symbol();
	virtual bool is_shot() = 0;
	bool is_there();
	void set_there(bool);
	virtual char get_event() = 0;
	virtual void get_percept() = 0;
};

#endif
