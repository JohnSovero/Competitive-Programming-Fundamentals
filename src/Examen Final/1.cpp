#include <iostream>
#include <unordered_map>
#include <string>
#include <bits/stdc++.h>

using namespace std;

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
    TrieNode *getTrieNode()
    {
        return root;
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
    int countTelephone(string word)
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

        return current->children.size();
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

int main()
{
    int t;
    do
    {
        cin >> t;
    } while (t < 0 || t > 50);
    vector<string> identificadores;
    int search1, search2;
    cin >> search1 >> search2;
    identificadores.push_back(to_string(search1));
    identificadores.push_back(to_string(search2));
    Trie trie;
    set<string> st;
    // Recorrer la cantidad de casos
    for (int i = 0; i < t; i++)
    {
        int n;
        // Validacion de la cantidad de lineas de numero de telefono
        do
        {
            cin >> n;
        } while (n < 0 || n > 5000);
        for (int i = 0; i < n; i++)
        {
            char add;
            int id1, id2, id3;
            // Validacion de que se ingrese la letra a
            do
            {
                cin >> add;
            } while (add != 'a');
            string telephone;
            // Validacion de que el numero de telefono no se repita
            do
            {
                cin >> id1 >> id2 >> id3;
                telephone = to_string(id1) + to_string(id2) + to_string(id3);
            } while (st.find(telephone) != st.end());
            trie.insert(telephone);
        }
        // Mostrar la cantidad de numeros de telefono que contiene el identificador
        cout << trie.countTelephone(identificadores[i]) << endl;
    }
    return 0;
}