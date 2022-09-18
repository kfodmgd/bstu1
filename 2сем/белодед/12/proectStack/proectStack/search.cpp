#include "add.h"
using namespace std;
int m=0;
Node* search(Node* t, int k){
Node* rc = t;
if (t != NULL) {
	if (k < t->data) {
		if (k == t->data) {
			m++;
		}
		rc = search(t->left, k);
	}
	else {
		if (k == t->data) {
			m++;
			rc = search(t->left, k);
		}
		rc = search(t->right, k);
	}

}
else {
	cout << "Количество найденных лементов равных введённому значению:" << m << endl;
}
return rc;
}