#include "HashTable.h"

// Constructor
HashTable::HashTable(int size, CollisionResolution method)
    : tableSize(size), collisionResolutionMethod(method) {
    if (method == LINEAR_PROBING) {
        table.resize(tableSize); // Inicializa listas vacías para Linear Probing
    } else if (method == QUADRATIC_PROBING) {
        tableQP.resize(tableSize, -1);      // Inicializa con -1 (vacío)
        occupiedQP.resize(tableSize, false); // Ningún índice está ocupado inicialmente
    }
}

// Función de hash simple
int HashTable::hashFunction(int key) const {
    return key % tableSize;
}

// Inserta un elemento en la tabla
void HashTable::insert(int key) {
    if (collisionResolutionMethod == LINEAR_PROBING) {
        int index = hashFunction(key);
        table[index].push_back(key); // Inserta en la lista del índice correspondiente
    } else if (collisionResolutionMethod == QUADRATIC_PROBING) {
        int index = hashFunction(key);
        int i = 0;

        while (occupiedQP[(index + i * i) % tableSize]) {
            i++; // Busca el siguiente índice disponible usando Quadratic Probing
        }
        int probeIndex = (index + i * i) % tableSize;
        tableQP[probeIndex] = key;
        occupiedQP[probeIndex] = true;
    }
}

// Busca un elemento en la tabla
bool HashTable::search(int key) const {
    if (collisionResolutionMethod == LINEAR_PROBING) {
        int index = hashFunction(key);
        for (int value : table[index]) {
            if (value == key) {
                return true;
            }
        }
    } else if (collisionResolutionMethod == QUADRATIC_PROBING) {
        int index = hashFunction(key);
        int i = 0;

        while (occupiedQP[(index + i * i) % tableSize]) {
            int probeIndex = (index + i * i) % tableSize;
            if (tableQP[probeIndex] == key) {
                return true;
            }
            i++;
        }
    }
    return false;
}

// Elimina un elemento de la tabla
void HashTable::remove(int key) {
    if (collisionResolutionMethod == LINEAR_PROBING) {
        int index = hashFunction(key);
        table[index].remove(key); // Elimina el elemento de la lista
    } else if (collisionResolutionMethod == QUADRATIC_PROBING) {
        int index = hashFunction(key);
        int i = 0;

        while (occupiedQP[(index + i * i) % tableSize]) {
            int probeIndex = (index + i * i) % tableSize;
            if (tableQP[probeIndex] == key) {
                tableQP[probeIndex] = -1; // Marca como vacío
                occupiedQP[probeIndex] = false;
                return;
            }
            i++;
        }
    }
}

// Muestra la tabla hash
void HashTable::display() const {
    if (collisionResolutionMethod == LINEAR_PROBING) {
        for (int i = 0; i < tableSize; ++i) {
            std::cout << "Indice " << i << ": ";
            for (int value : table[i]) {
                std::cout << value << " -> ";
            }
            std::cout << "nullptr\n";
        }
    } else if (collisionResolutionMethod == QUADRATIC_PROBING) {
        for (int i = 0; i < tableSize; ++i) {
            std::cout << "Indice " << i << ": ";
            if (occupiedQP[i]) {
                std::cout << tableQP[i];
            } else {
                std::cout << "Vacio";
            }
            std::cout << "\n";
        }
    }
}
