#ifndef WEIGHT_GRAPH_H
#define WEIGHT_GRAPH_H

#include <stdbool.h> 
#include <stdio.h>
#include <string.h>

typedef struct GraphNodeConnections {

	struct GraphNodeStruct* connection;
	struct GraphNodeConnections* next;
	int weight;

}graph_c;


typedef struct GraphNodeStruct {

	int totalWeights;
	char* name;
	struct GraphNodeConnections* totalConnectionsHead;
	struct GraphNodeConnections* totalConnectionsCurrent;

	struct GraphNodeStruct* nextN;
	struct GraphNodeStruct* peviousN;

}graph_n;

static graph_n* head = NULL;

static graph_n* current = NULL;

static graph_n* temp = NULL;


graph_n* insert(const char*);

bool insertWeight(const char*, const char*,int);

bool deleteNode();

bool deleteWeight();

bool modify();
	
bool receiving();
	
bool circlefind();
	
bool findcircles();

bool traceflow();

bool printGraph();

graph_n* search(const char*);
	
bool exit();



#endif