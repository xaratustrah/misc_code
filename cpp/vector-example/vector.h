#include "masterexamination.h"

#ifndef __VECTOR_H__
#define __VECTOR_H__

template <class X>
class Vector
{
	X* content;
	Vector *next, *previous;
	bool deleteAll;
	Vector( Vector* previous );
public:
	Vector();
	~Vector();
	void Add( X* obj );
	X* Get( int index );
	void Del( int index );
	int Length();
	friend class Vector;
};

template <class X>
Vector<X>::Vector()
{
	this->previous = NULL;
	this->next = NULL;
	this->content = NULL;
	deleteAll = true;
}

template <class X>
Vector<X>::Vector( Vector* previous )
{
	this->previous = previous;
	this->next = NULL;
	this->content = NULL;
	deleteAll = true;
}

template <class X>
Vector<X>::~Vector()
{
	if( deleteAll )
	{
		Vector *tmp = this;
		while( tmp->next != NULL )
		{
			Vector *tmp2 = tmp;
			
			while( tmp2->next != NULL )
				tmp2 = tmp2->next;

		
			tmp2->deleteAll = false;
			delete (tmp2->content);
			Vector *tmpPrev = tmp2->previous;
			tmpPrev->next = NULL;
			delete tmp2;
		}
	}
}

template <class X>
void Vector<X>::Add( X* obj )
{
	Vector *tmp = this;
	while( tmp->next != NULL )
		tmp = tmp->next;
	tmp->next = new Vector( tmp );
	Vector *tmpNext = tmp->next;
	tmpNext->content = obj;

	//tmp->next->content = obj;
};

template <class X>
X* Vector<X>::Get( int index )
{
	Vector* tmp = next;
	if( tmp == NULL )
	{
		cout << "throw 111 \n";
		throw "No such Element";
	}
	for( int i = 0; i < index; i++ )
	{
		if( tmp != NULL )
			tmp = tmp->next;
		else
		{
			cout << "throw 222 \n";
			throw "No such element";
		}
	}
	return tmp->content;
}

template <class X>
void Vector<X>::Del( int index )
{
	Vector* tmp = next;
	if( tmp == NULL )
	{
		cout << "throw 111 \n";
		throw "No such Element";
	}
	for( int i = 0; i < index; i++ )
	{
		if( tmp != NULL )
			tmp = tmp->next;
		else
		{
			cout << "throw 222 \n";
			throw "No such element";
		}
	}
	
	Vector *tmpPrev = tmp->previous;
	tmpPrev->next = tmp->next;
	
	tmp->deleteAll = false;
	delete tmp;
}

template <class X>
int Vector<X>::Length()
{
	int result = 0;
	Vector *tmp = this;
	while( tmp->next != NULL )
	{
		tmp = tmp->next;
		result++;
	}
	return result;
}

#endif
