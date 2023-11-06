/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

 // Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K, V> {
private:
    vector<list<pair<K, V>>> chainingTable;
    int tableSize;
    int numElements;
   
public:
    ChainingHash(int n) {
        this->tableSize = n;
        this->numElements = 0;
    }

    ~ChainingHash() {
        this->clear();
    }

    int size() {
        return this->tableSize;
    }

    V operator[](const K& key) {
        //std::vector<std::list<pair<K, V>>>::iterator<std::list<std::pair<K, V>>> VectorItr;
        //std::list<std::pair<K, V>>::iterator<std::pair<K, V>> ListItr;
        for (std::vector<std::list<pair<K, V>>>::iterator<std::list<std::pair<K, V>>> VectorItr = chainingTable.begin(); VectorItr != chainingTable.end(); ++VectorItr) {
            std::list<std::pair<K, V>> tempList = VectorItr;
            for (std::list<std::pair<K, V>>::iterator<std::pair<K, V>> ListItr = tempList.begin(); ListItr != tempList.end(); ++ListItr) {
                std::pair<K, V> tempPair = ListItr;
                if (tempPair.first() == key) {
                    return tempPair.second();
                }
            }
        }
        return -1;
    }

    bool insert(const std::pair<K, V>& pair) {
        std::list<std::pair<K, V>>& HashList = chainingTable[myhash(pair)];
        if (std::find(HashList.begin(), HashList.end(), pair) != HashList.end()) {
            return false;
        }
        HashList.push_back(pair);
        this->numElements++;

        if (load_factor() >= 0.75) {
            rehash();
        }
        return true;
    }

    void erase(const K& key) {
        V placeHolder = NULL;
        std::pair<K, V> tempPair{ key, placeHolder };
        std::list<std::pair<K, V>>& HashList = chainingTable[myhash(tempPair)]; //The hash function doesn't need a value to establish an index
        //std::list<std::pair<K, V>>::iterator<std::pair<K, V>> itr;
        for (std::list<std::pair<K, V>>::iterator<std::pair<K, V>> itr = HashList.begin(); itr != HashList.end(); ++itr) {
            std::pair<K, V> tempPair = itr;
            if (tempPair.first == key) {
                HashList.erase(itr);
            }
        }
    }

    void clear() {
        if (!chainingTable.empty()) {
            chainingTable.clear();
        }
    }

    int bucket_count() {
        return this->numElements;
    }

    float load_factor() {
       return static_cast<float>(bucket_count() / size());
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

    /*
    int hash(const K& key) {
        return key % tableSize;
    }
    */
    

    int hash(int key) {
        return key % this->tableSize;
    }

    int myhash(const std::pair<K, V>& pair) {
        int hashValue = hash(pair.first());

        hashValue %= chainingTable.size();
        if (hashValue < 0) {
            hashValue += chainingTable.size();
        }
        return hashValue;
    }

    void rehash() {
        std::vector<std::list<std::pair<K, V>>> oldLists = chainingTable; //Saves the old contents
        this->tableSize = findNextPrime(2 * tableSize); //Resize the table
        chainingTable.clear(); //Clear its original contents
        this->numElements = 0; //Reset the number of elements to zero

        for (int i = 0; i < oldLists.size(); i++) { //Reinserts the old contents with the newly sized table
            std::list<std::pair<K, V>>::iterator<std::pair<K, V>> itr = oldLists[i].begin();
            while (itr != oldLists[i].end()) {
                insert(*itr++);
            }
        }
    }
};

#endif //__CHAINING_HASH_H


