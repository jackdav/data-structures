#include <iostream>

using namespace std;

struct queue_node {
	int data;
	queue_node* next = NULL;
};

class mo_queue {
	private:
		queue_node* head;
	public:
		mo_queue() {
			head = NULL;
		}
		void mo_push(int data) {
			if (head == NULL) {
				queue_node* cur = new queue_node;
				cur->data = data;
				head = cur;
			}
			else {
				queue_node* travel = head;
				while (travel->next != NULL) {
					travel = travel->next;
				}
				travel->next = new queue_node;
				travel->next->data = data;
			}
		}
		void mo_pop() {
			head = head->next;
		}
		bool mo_empty() {
			if (head == NULL) {
				return true;
			}
			else {
				return false;
			}
		}
		int mo_front() {
			return head->data;
		}
};

int main() {
	mo_queue q;
	q.mo_push(7);
	q.mo_pop();
	cout << q.mo_empty() << endl;
	q.mo_push(8);
	cout << q.mo_front() << endl;
	q.mo_push(182);
	q.mo_push(234);
	cout << q.mo_front() << endl;
	q.mo_pop();
	cout << q.mo_front() << endl;
	return 0;
}