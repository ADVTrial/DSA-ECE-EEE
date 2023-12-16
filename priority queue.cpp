/*PRIORITY QUEUE - MAX Number = Highest Priority*/
#include <iostream>
#include <queue>
using namespace std;

void printPriorityQueue(priority_queue<int>& pq) {
    cout << "The priority queue elements are:" << endl;
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int values[n];
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    // Creating a max heap priority queue
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
        pq.push(values[i]);
    }
    printPriorityQueue(pq);
    return 0;
}
