#include <stdio.h>
#include "Weight_Graph.h"



int main(int argc, char* argv[]) {


	insert("savvas");
	insert("savvas");
	insert("asdsasavvas");
	insert("asdsadsavvsas");
	insert("savvasdddddd");
	insert("savvassss");
	insert("aa");
	printGraph();


	insertWeight("savvas", "aaaaaaaaaaaaasavvas", 100);
	insertWeight("savvas", "fffff", 10045);
	printGraph();

	insertWeight("savvas", "aa", 45);
	insertWeight("savvas", "aa", 45);

	insertWeight("aa", "aassss", 45);

	printGraph();

	return 0;

};