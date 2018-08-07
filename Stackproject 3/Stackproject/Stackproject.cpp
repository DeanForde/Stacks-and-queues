//Includes.
#include "stdafx.h"
#include "Stack.h"
#include "Queue.h"
#include <stddef.h>
#include <iostream>
#include <queue>
#include <deque>

//Standard Library.
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int item;
	int option;
	QueType<int> myQueue;
	StackType<int>myStack;
	myQueue.Enqueue(1);
	myQueue.Enqueue(2);
	myQueue.Enqueue(3);
	myQueue.Enqueue(4);
	myQueue.Enqueue(5);

	do
	{
		cout << "1) clear a queue of its contents. \n";
		cout << "2) add data to the input end of the queue. \n";
		cout << "3) remove data from the output end of the queue(also print each value as it is removed). \n";
		cout << "4) print the contents of the queue. \n";
		cout << "5) reverse the data inside the queue. \n ";
		cout << "6) exit from the application. \n";
		cin >> option;

		switch (option)
		{
		case 1:
			myQueue.MakeEmpty();
			if (myQueue.IsEmpty())
			{
				cout << "Queue is Empty..\n";
			}
			break;
		case 2:
			for (int i = 1; i < 6; i++)
			{
				myQueue.Enqueue(i);
			};
			break;
		case 3:
			if (myQueue.IsEmpty())
			{
				cout << "Queue is empty..\n";
			}
			else
			{
				myQueue.Dequeue(item);
				cout << item << "\n";
			}
			break;
		case 4:
			 myQueue.PrintQueue();
			break;
		case 5:
			int temp;
			while (!myQueue.IsEmpty())
			{
				myQueue.Dequeue(temp);
				myStack.Push(temp);
			}
			while(!myStack.IsEmpty())
			{
				myStack.Pop(temp);
				myQueue.Enqueue(temp);
			}
			cout << "Queue Reversed";
			break;
		case 6:
			exit(1);
			break;
		default:
			cout << "Invalid Option, Try Again...";
			break;
		}
	} while (option != 6);
}


	





