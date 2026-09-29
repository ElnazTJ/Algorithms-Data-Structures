#include <bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    Node* prev;
    Node* next;
    Node(char v = '\0') : val(v), prev(nullptr), next(nullptr) {}
};

int main() {
    // افزایش سرعت ورودی و خروجی برای q = 100,000
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> q)) return 0;

    Node* head = new Node();
    Node* tail = new Node();
    head->next = tail;
    tail->prev = head;

    Node* cursor = head;

    while (q--) {
        string op;
        cin >> op;

        if (op == "+") {
            if (cursor->next != tail) {
                cursor = cursor->next;
            }
        } 
        else if (op == "-") {
            if (cursor != head) {
                cursor = cursor->prev;
            }
        } 
        else if (op == "insert") {
            char c;
            cin >> c;

            Node* newNode = new Node(c);

            newNode->next = cursor->next;
            cursor->next->prev = newNode;
            newNode->prev = cursor;
            cursor->next = newNode;

            cursor = newNode;
        }
    }

    string result = "";
    Node* curr = head->next;
    while (curr != tail) {
        result.push_back(curr->val);
        curr = curr->next;
    }
    cout << result << "\n";

    return 0;
}