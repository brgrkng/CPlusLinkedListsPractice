#include "linkedLists.h"

int main()
{

	Node* A = new Node();
	A->num = 0;
	A->txt = "first";
	appendNode(1, "second", A);
	appendNode(2, "third", A);
	appendNode(2, "third", A);
	appendNode(2, "third", A);
	appendNode(3, "fourth", A);
	appendNode(4, "fifth", A);
	appendNode(4, "fifth", A);
	appendNode(4, "fifth", A);
	appendNode(4, "fifth", A);
	appendNode(4, "fifth", A);
	appendNode(4, "fifth", A);


	showAllNodes(A);

	//auto start = std::chrono::high_resolution_clock::now();
	replaceNode(3, "CUM", 3, &A);
	//auto stop = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

	//std::cout << "Time taken : " << duration.count() << " nanoseconds\n";

	showAllNodes(A);

	searchNum(50, A);


	return 0;
}