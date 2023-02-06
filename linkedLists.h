#pragma once
#include <iostream>
#include <string>
#include <chrono>

struct Node
{
	int num;
	std::string txt;
	Node* next;
};

void appendNode(int newNum, std::string newText, Node* head)
{
	Node* newNode = new Node();
	newNode->num = newNum;
	newNode->txt = newText;

	Node* iterator = head;

	while (iterator->next != NULL)
	{
		iterator = iterator->next;
	}
	iterator->next = newNode;
}

void insertNode(int newNum, std::string newText,int position, Node** headPtr)
{
	Node* newNode = new Node();
	newNode->num = newNum;
	newNode->txt = newText;

	if (*headPtr != NULL)
	{
		if (position == 0)
		{
			newNode->next = *headPtr;
			*headPtr = newNode;
			return;
		}
		else
		{
			Node* iterator = *headPtr;
			int count = 0;
			while (count < position-1)
			{
				if (iterator->next != NULL)
				{
					iterator = iterator->next;
					count++;
				}
				else
				{
					std::cout << "Out of Range\n";
					return;
				}
			}
			newNode->next = iterator->next;
			iterator->next = newNode;
		}
	}
	else
	{
		std::cout << "Head is NULL\n";
		return;
	}
}

void deleteNode(int position, Node** headPtr)
{
	if (*headPtr == NULL)
	{
		std::cout << "List is Empty\n";
		return;
	}
	else
	{
		if (position == 0)
		{
			Node* temp = *headPtr;
			*headPtr = temp->next;
			delete(temp);
		}
		else
		{
			Node* iterator = *headPtr;
			int count = 0;
			while (count < position-1)
			{
				if (iterator->next != NULL)
				{
					iterator = iterator->next;
					count++;
				}
				else
				{
					std::cout << "Out of Range\n";
					return;
				}
			}
			Node* temp = iterator->next;
			iterator->next = iterator->next->next;
			delete(temp);
		}
	}
}

void replaceNode(int newNum, std::string newText, int position, Node** headPtr)
{
	deleteNode(position, headPtr);
	insertNode(newNum, newText, position, headPtr);
}

void fastReplace(int newNum, std::string newText, int position, Node** headPtr)
{
	if (*headPtr == NULL)
	{
		std::cout << "List is Empty\n";
		return;
	}
	else
	{
		Node* newNode = new Node();
		newNode->num = newNum;
		newNode->txt = newText;

		if (position == 0)
		{
			newNode->next = *headPtr;
			*headPtr = newNode;
			return;
		}
		else
		{
			Node* iterator = *headPtr;
			int count = 0;

			while (count < position-1)
			{
				if (iterator->next != NULL)
				{
					iterator = iterator->next;
					count++;
				}
				else
				{
					std::cout << "Out of Range\n";
					return;
				}
			}
			Node* temp = iterator->next;
			newNode->next = iterator->next->next;
			iterator->next = newNode;
			delete(temp);
		}
	}

}


void showAllNodes(Node* head)
{
	if (head != NULL)
	{
		Node* iterator = head;

		printf("[");
		while (iterator != NULL)
		{
			printf("(%d,%s)", iterator->num, iterator->txt.c_str());
			if (iterator->next == NULL)
			{
				printf("]\n");
			}
			else
			{
				printf(",");
			}
			iterator = iterator->next;
		}
	}
	else
	{
		std::cout << "Head is NULL\n";
	}
}

int getLength(Node* head)
{
	int count = 0;

	Node* iterator = head;

	while (iterator != NULL)
	{
		iterator = iterator->next;
		count++;
	}
	return(count);
}

int findFreq(int snum, Node* head)
{
	int count = 0;
	Node* iterator = head;
	while (iterator != NULL)
	{
		if (iterator->num == snum)
		{
			count++;
		}
		iterator = iterator->next;
	}
	return(count);
}

void showNode(int position, Node* head)
{
	if (head != NULL)
	{
		Node* iterator = head;
		int count = 0;

		while (count < position)
		{
			if (iterator->next!= NULL)
			{
				iterator = iterator->next;
				count++;
			}
			else
			{
				std::cout << "Out of Range\n";
				return;
			}
		}
		printf("(%d,%s)\n", iterator->num, iterator->txt.c_str());
	}
	else
	{
		std::cout << "List is empty\n";
	}
}

void searchNum(int snum, Node* head)
{
	Node* iterator = head;
	while (iterator != NULL)
	{
		if (iterator->num == snum)
		{
			printf("(%d,%s)\n", iterator->num, iterator->txt.c_str());
			return;
		}
		iterator = iterator->next;
	}
	printf("Not found\n");
}

