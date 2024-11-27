#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list> // Para listas en Linear Probing

enum CollisionResolution { LINEAR_PROBING, QUADRATIC_PROBING };

class HashTable {
private:
    std::vector<std::list<int>> table; // Para Linear Probing
    std::vector<int> tableQP;          // Para Quadratic Probing
    std::vector<bool> occupiedQP;      // Marca si un índice está ocupado (Quadratic Probing)
    int tableSize;
    CollisionResolution collisionResolutionMethod;

    int hashFunction(int key) const;

public:
    HashTable(int size, CollisionResolution method);

    void insert(int key);
    bool search(int key) const;
    void remove(int key);
    void display() const;
};

#endif // HASHTABLE_H
