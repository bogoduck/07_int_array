#include "intarray.h"

int main() {

	IntArray *ia1 = new IntArray("A1",10);
	IntArray *ia2 = new IntArray("A2", -10);
	IntArray *ia3 = new IntArray("A3", 9);
	IntArray* ia4 = new IntArray("A4", 29);

	ia1->copy(*ia3);
	ia1->copy(*ia4);

	ia1->getIntbyIndex(10);
	ia1->resize(14);

	ia1->getIntbyIndex(5);
	ia1->setIntbyIndex(15, 34);
	ia1->setIntbyIndex(5, 34);

	ia1->copy(*ia4);
	ia4->getIntbyIndex(5);
	ia4->delIntbyIndex(5);
	ia4->getIntbyIndex(5);

	return 0;
}