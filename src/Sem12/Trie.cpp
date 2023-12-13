#include <iostream>
#include <unordered_map>
using namespace std;

// Clase para representar un nodo del Trie
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TrieNode()
    {
        isEndOfWord = false;
    }
};

// Clase para el Trie
class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserta una palabra en el Trie
    void insert(string word)
    {
        TrieNode *current = root;

        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
            {
                current->children[c] = new TrieNode();
            }

            current = current->children[c];
        }

        current->isEndOfWord = true;
    }

    // Busca una palabra en el Trie
    bool search(string word)
    {
        TrieNode *current = root;

        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
            {
                return false;
            }

            current = current->children[c];
        }

        return current->isEndOfWord;
    }

    // Verifica si una palabra es un prefijo en el Trie
    bool startsWith(string prefix)
    {
        TrieNode *current = root;

        for (char c : prefix)
        {
            if (current->children.find(c) == current->children.end())
            {
                return false;
            }

            current = current->children[c];
        }

        return true;
    }
};

// Ejemplo de uso del Trie
int main()
{
    Trie trie;

    trie.insert("hola");
    trie.insert("adios");
    trie.insert("hogar");

    cout << "¿La palabra 'hola' está en el Trie? " << (trie.search("hola") ? "Sí" : "No") << endl;
    cout << "¿La palabra 'adios' está en el Trie? " << (trie.search("adios") ? "Sí" : "No") << endl;
    cout << "¿La palabra 'hogar' está en el Trie? " << (trie.search("hogar") ? "Sí" : "No") << endl;
    cout << "¿La palabra 'home' está en el Trie? " << (trie.search("home") ? "Sí" : "No") << endl;

    cout << "¿El prefijo 'ho' existe en el Trie? " << (trie.startsWith("ho") ? "Sí" : "No") << endl;
    cout << "¿El prefijo 'he' existe en el Trie? " << (trie.startsWith("he") ? "Sí" : "No") << endl;

    return 0;
}
