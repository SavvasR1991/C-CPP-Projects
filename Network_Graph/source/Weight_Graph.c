#pragma warning(disable : 4996).

#include "Weight_Graph.h"
#include "Visualization_Functions.h"


graph_n* insert(const char * nodeName) {

	spaceCounter = spaceCounter + 2;
	printColorMessage(blue,"WGR-IN Insert new node to graph: %s \n", nodeName);

	graph_n* newNode;
	newNode = search(nodeName);
	if(newNode == NULL){
		newNode = malloc(sizeof * newNode);
		if (newNode != NULL)
		{
			newNode->totalWeights = 0;
			newNode->totalConnectionsHead =NULL;
			newNode->totalConnectionsCurrent = NULL;
			newNode->nextN = NULL;
			newNode->name = (char*)malloc((strlen(nodeName) + 1) * sizeof(char));
			if (newNode->name != NULL)
			{
				strcpy(newNode->name, nodeName);
				if (head == NULL) {
					head = newNode;
					head->peviousN = NULL;
					current = head;
				}
				else {
					current->nextN = newNode;
					newNode->peviousN = current;
					current = newNode;
				}
				printColorMessage(green,"WGR-IN Insert new node to graph: \"%s\" . Success\n", current->name);
				spaceCounter = spaceCounter - 2;
				printf("\n");
				return current;
			}
			else {
				printColorMessage(red,"WGR-IN ERROR_2.Cannot allocate memory for new node name. Insert new node to graph FAIL.\n");
			}
		}
		else {
			printColorMessage(red,"WGR-IN ERROR_1.Cannot allocate memory for new node. Insert new node to graph FAIL.\n");
		}
	}
	else {
		printColorMessage(yellow,"WGR-IN Warning. Node \"%s\" already exists. Nothing to insert \n", nodeName);
		spaceCounter = spaceCounter - 2;
		printf("\n");
		return newNode;

	}
	spaceCounter = spaceCounter - 2;
	printf("\n");
	return NULL;
}

bool insertWeight(const char* node1Name, const char* node2Name,int weight) {
	spaceCounter = spaceCounter + 2;
	graph_n* node1;
	graph_n* node2;
	printColorMessage(blue,"WGR-INW Insert Weight: \"%d\" between [\"%s\",\"%s\"] nodes \n", weight, node1Name, node2Name);
	node1 = insert(node1Name);
	node2 = insert(node2Name);
	graph_c* newConnection;
	graph_c* tempConnection;
	graph_c* previousConnection;

	if (node1 != NULL && node2 != NULL) {
		newConnection = malloc(sizeof * newConnection);
		if (newConnection != NULL) {
			newConnection->weight = weight;
			newConnection->next = NULL;
			newConnection->connection = node2;

			if (node1->totalConnectionsHead == NULL) {
				node1->totalConnectionsHead = newConnection;
				node1->totalConnectionsHead->next = NULL;
				node1->totalConnectionsCurrent = node1->totalConnectionsHead;
			}
			else {
				node1->totalConnectionsCurrent->next = newConnection;
				node1->totalConnectionsCurrent = newConnection;
			}
			printColorMessage(green,"WGR-INW Insert Weight: \"%d\" between [\"%s\",\"%s\"] nodes . Success \n", weight, node1Name, node2Name);
			spaceCounter = spaceCounter - 2;
			return true;
		}
		else {
			printColorMessage(red,"WGR-INW ERROR_1. Insert Weight: \"%d\" between [\"%s\",\"%s\"] nodes .Cannot allocate new memory FAILED \n", weight, node1Name, node2Name);
		}
	}
	else {
		printColorMessage(red,"WGR-INW ERROR_2. Insert Weight: \"%d\" between [\"%s\",\"%s\"] nodes . Cannot allocate memory for new nodes. FAILED \n", weight, node1Name, node2Name);
	}
	spaceCounter = spaceCounter - 2;
	return false;
}

bool deleteNode() {
	return false;

}

bool deleteWeight() {

	return false;
}

bool deleteGraph() {
	return false;

}
bool modify() {

	return false;
}

bool receiving() {

	return false;
}

bool circlefind() {

	return false;
}

bool findcircles() {

	return false;
}

bool traceflow() {

	return false;
}

bool printGraph() {
	spaceCounter = spaceCounter + 2;
	temp = head;
	int connectionCounter = 1;
	int nodeCounter = 1;
	graph_c* tempConnection;
	printColorMessage(blue,"WGR-PR Printing Graph Nodes\n");
	if (head != NULL) {

		while (temp != NULL) {
			printColorMessage(green,"  -(%d): \"%s\" \n", nodeCounter, temp->name);
			nodeCounter++;
			if (temp->totalConnectionsHead != NULL) {
				tempConnection = temp->totalConnectionsHead;
				while (tempConnection != NULL) {

					printColorMessage(green,"       - [%d] Connection \"%s\" with Weight: %d\n", connectionCounter, tempConnection->connection->name, tempConnection->weight);
					connectionCounter++;
					tempConnection = tempConnection->next;
				}
				connectionCounter = 1;
			}
			else {
				printColorMessage(magenta,"       - No connections\n");
			}
			temp = temp->nextN;
		}
	}
	else {
		printColorMessage(yellow,"----WGR-PR Warning. Graph is empty\n");

	}
	spaceCounter = spaceCounter - 2;
	printf("\n");
	return true;

}

graph_n* search(const char *nodeName) {
	spaceCounter = spaceCounter + 2;
	temp = head;
	printColorMessage(blue,"WGR-SR Search Graph Node: %s \n",nodeName);
	if (head != NULL) {

		while (temp != NULL) {
			if (strcmp(temp->name,nodeName)==0) {
				printColorMessage(green,"WGR-SR %s found\n", nodeName);
				spaceCounter = spaceCounter - 2;
				return temp;
			}
			else {

				temp = temp->nextN;
			}
		}
		printColorMessage(magenta,"WGR-SR %s not found\n", nodeName);
	}
	else {
		printColorMessage(yellow,"WGR-SR Warning. Graph is empty\n");
	}
	spaceCounter = spaceCounter - 2;
	return NULL;
}

bool exit() {

	deleteGraph();

	return false;
}


