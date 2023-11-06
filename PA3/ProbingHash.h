#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

// Can be used for tracking lazy deletion for each element in your table
enum EntryState {
    EMPTY = 0,
    VALID = 1,
    DELETED = 2
};

template<typename K, typename V>
class ProbingHash : public Hash<K, V> { // derived from Hash
private:
    // Needs a table and a size.
    // Table should be a vector of std::pairs for lazy deletion
    struct HashEntry
    {
        std::pair<K, V> element;
        EntryState info;

        HashEntry(const std::pair<K, V> &e = 0, EntryState i = 0) : element(e), info(i) {}
    };

    vector<HashEntry> probingtable;
    int tableSize;
    int numElements;

public:
    ProbingHash(int n) {
        this->tableSize = n;
        this->numElements = 0;
    }

    ~ProbingHash() {
        this->clear();
    }

    int size() {
        return this->tableSize;
    }

    V operator[](const K& key) {
        std::pair<K, int> tempPair{ key, 0 };
        int currentPos = findPos(tempPair);
        return probingtable[currentPos].element.first;
    }

    bool insert(const std::pair<K, V>& pair) {
        int currentPos = findPos(pair);
        if (isActive(currentPos)) {
            return false;
        }

        probingtable[currentPos] = HashEntry(pair, VALID);
        if (load_factor() >= 0.5) {
            rehash();
        }
        return true;
    }

    void erase(const K& key) {
        std::pair<K, int> tempPair{ key, 0 };
        int currentPos = findPos(tempPair);
        probingtable[currentPos].info = DELETED;
    }

    void clear() {
        if (!this->probingtable.empty()) {
            this->probingtable.clear();
        }
    }

    int bucket_count() {
        return this->numElements;
    }

    float load_factor() {
        return static_cast<float>(bucket_count() / size());
    }

    int findPos(const std::pair<K, V>& pair) {
        int currentPos = myhash(pair.first);

        while (probingtable[currentPos].info != 0 && probingtable[currentPos].element != pair) {
            currentPos++;
        }
        return currentPos;
    }

    bool isActive(int currentPos) {
        return probingtable[currentPos].info == VALID;
    }

private:
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }

    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int hash(const K& key) {
        return key % this->tableSize;
    }

    int myhash(const std::pair<K, V>& pair) {
        int hashValue = hash(pair.first());

        hashValue %= this->probingTable.size();
        if (hashValue < 0) {
            hashValue += this->probingTable.size();
        }
        return hashValue;
    }

    void rehash() {
        std::vector<HashEntry> oldLists = this->probingtable;
        this->tableSize = findNextPrime(2 * tableSize); //Resize the table
        this->probingtable.clear();
        this->numElements = 0;

        for (int i = 0; i < oldLists.size(); i++) {
            insert(oldLists[i].element);
        }
    }

};

#endif //__PROBING_HASH_H


