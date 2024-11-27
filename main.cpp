#include "HashTable.h"

int main() {
    int tableSize = 10;

    // Linear Probing
    HashTable hashTableLinear(tableSize, LINEAR_PROBING);
    std::cout << "=== LINEAR PROBING ===\n";
    hashTableLinear.insert(5);
    hashTableLinear.insert(15);
    hashTableLinear.insert(25); // Colisión con 5 y 15
    hashTableLinear.insert(35); // Colisión con los anteriores
    hashTableLinear.display();

    std::cout << "\nBuscar 25 en Linear Probing: "
              << (hashTableLinear.search(25) ? "Encontrado" : "No encontrado") << "\n";

    hashTableLinear.remove(15);
    std::cout << "\nDespués de eliminar 15 en Linear Probing:\n";
    hashTableLinear.display();

    // Quadratic Probing
    HashTable hashTableQuadratic(tableSize, QUADRATIC_PROBING);
    std::cout << "\n=== QUADRATIC PROBING ===\n";
    hashTableQuadratic.insert(5);
    hashTableQuadratic.insert(15);
    hashTableQuadratic.insert(25); // Colisión con 5 y 15
    hashTableQuadratic.insert(35); // Colisión con los anteriores
    hashTableQuadratic.display();

    std::cout << "\nBuscar 25 en Quadratic Probing: "
              << (hashTableQuadratic.search(25) ? "Encontrado" : "No encontrado") << "\n";

    hashTableQuadratic.remove(15);
    std::cout << "\nDespues de eliminar 15 en Quadratic Probing:\n";
    hashTableQuadratic.display();

    return 0;
}
