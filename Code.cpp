#include <iostream>
#include <unordered_map>

class LRUCache
{
    struct Node
    {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> mp;
    Node *head;
    Node *tail;

public:
    LRUCache(int capacity) : capacity(capacity), head(nullptr), tail(nullptr) {}

    int get(int key)
    {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            moveToHead(temp);
            return temp->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            temp->value = value;
            moveToHead(temp);
        } else {
            if (mp.size() >= capacity) {
                Node* temp = removeTail();
                mp.erase(temp->key);
                delete temp;
            }
            Node* node = new Node(key, value);
            mp[key] = node;
            addToHead(node);
        }
    }

private:
    void addToHead(Node* node)
    {
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    void removeNode(Node* node)
    {
        if (node == head) {
            head = node->next;
        } else if (node == tail) {
            tail = node->prev;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
    }

    void moveToHead(Node* node)
    {
        removeNode(node);
        addToHead(node);
    }

    Node* removeTail()
    {
        Node* temp = tail;
        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            head = tail = nullptr;
        }
        return temp;
    }
};

int main()
{
    int capacity;
    std::cout << "Enter the capacity of the LRUCache: ";
    std::cin >> capacity;

    LRUCache cache(capacity);

    char choice;
    do {
        std::cout << "Enter 'p' for put, 'g' for get, or 'q' to quit: ";
        std::cin >> choice;

        if (choice == 'p') {
            int key, value;
            std::cout << "Enter the key and value to put: ";
            std::cin >> key >> value;
            cache.put(key, value);
        } else if (choice == 'g') {
            int key;
            std::cout << "Enter the key to get: ";
            std::cin >> key;
            int value = cache.get(key);
            if (value != -1) {
                std::cout << "Value for key " << key << ": " << value << std::endl;
            } else {
                std::cout << "Key not found!" << std::endl;
            }
        }
    } while (choice != 'q');

    return 0;
}
