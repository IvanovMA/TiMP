#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
/** \func struct List */
struct List
{
	int value;
	List *pNext;
	List *pPrev;
};
List *head; 

/** \func void addpos(int newvalue, int position) */
void addpos(int newvalue, int position)
{
	List  *node = new List; 
	node->value = newvalue;
	if ((head == NULL))
	{
		node->pNext = node; 
		node->pPrev = node;
		head = node; /
	}
	else
	{
		List *p = head;
		for (int i = position; i > 0; i--)
		{
			p = p->pNext;
		}
		p->pPrev->pNext = node;
		node->pPrev = p->pPrev;
		node->pNext = p; 
		p->pPrev = node;
	}
}

/** \func void Delete(int position) */
void Delete(int position)
{
	if (head == NULL) 
		{ 
		cout << "\nÏóñòîé ñïèñîê\n"; 
		}
	if (head->pNext == head) 
	{
		delete head;
		head = NULL;
	}
	else
	{
		List *_del = head;
		for (int i = position; i>0; i--) _del = _del->pNext;
		if (_del == head) head = _del->pNext;
		_del->pPrev->pNext = _del->pNext;
		_del->pNext->pPrev = _del->pPrev;
		delete _del;
	}
}

/** \func int Get(int position) */
int Get(int position)
{
	int ch;
	if (head == NULL) { cout << "\nÑïèñîê ïóñò\n\n"; return 0; }
	else
	{
		List *_get = head;
		for (int i = position; i > 0; i--) _get = _get->pNext;
		ch = _get->value;
	}
	return ch;
}

/** \func int main() */
/*int main()
{
	int numact, pos, val;
	int k = 0;
	int exit[20];
	char str[64];
	char *act = new char[64];
	setlocale(LC_CTYPE, "rus");
	cout << "ñïèñîê :" << endl;
	cout << "âõîä :" << endl;
	fstream fin;
	fin.open("text.txt", ios::in);
	if (fin.is_open())
	{
		fin.getline(str, 64);
		cout << str << endl;
		numact = atoi(str);
		for (int i = 0; i < numact; i++)
		{
			fin.getline(str, 64);
			cout << str << endl;
			act = strtok(str, " ");
			if (!strcmp(act, "add"))
			{
				pos = atoi(strtok(NULL, " "));
				val = atoi(strtok(NULL, " "));
				addpos(val, pos);
			}
			if (!strcmp(act, "del"))
			{
				pos = atoi(strtok(NULL, " "));
				Delete(pos);
			}
			if (!strcmp(act, "get"))
			{
				pos = atoi(strtok(NULL, " "));
				exit[k] = GetElement(pos);
				k++;
			}
		}
	}
	fin.close();
	cout << endl << "âûõîä :" << endl;
	for (int i = 0; i < k; i++)
		cout << exit[i] << endl;
	system("pause");
	return 0;
}*/
