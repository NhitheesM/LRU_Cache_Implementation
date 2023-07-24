# LRU_Cache_Implementation

The project is an implementation of an LRU (Least Recently Used) Cache in C++. An LRU Cache is a data structure that maintains a limited number of key-value pairs and automatically removes the least recently used entry when the capacity is reached.

The LRUCache class is implemented using a combination of a doubly linked list and a hash map (unordered_map in C++). The doubly linked list is used to keep track of the order in which elements are accessed, with the most recently accessed element at the front (head) and the least recently accessed element at the back (tail). The hash map is used to efficiently retrieve elements by their keys.

The LRUCache class provides three main functionalities:
1. Constructor: Initializes the LRUCache with the given capacity.
2. get(key): Retrieves the value associated with the given key from the cache. If the key is present, it moves the corresponding node to the front of the list (indicating it was most recently accessed). If the key is not found, it returns -1.
3. put(key, value): Inserts a new key-value pair into the cache. If the key already exists, it updates the value and moves the corresponding node to the front. If the cache reaches its capacity, it removes the least recently used element from the cache and inserts the new element at the front.

The program also includes a simple command-line interface to interact with the LRUCache. The user can continuously put and get key-value pairs into the cache until they choose to quit by entering 'q'. The interface prompts the user to choose between putting a key-value pair ('p'), getting a value for a given key ('g'), or quitting the program ('q').

Overall, the LRUCache implementation efficiently manages a limited amount of data by keeping the most frequently used items at the front and evicting the least used items when necessary. It demonstrates how a common caching strategy can be effectively implemented using data structures like doubly linked lists and hash maps in C++.
