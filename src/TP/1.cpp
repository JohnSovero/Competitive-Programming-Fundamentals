#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cctype>

using namespace std;

int main()
{
    // Crear un conjunto de palabras distintas
    set<string> palabras_distintas;

    //Leer el texto desde un archivo de texto
    ifstream archivo("texto.txt");
    string texto;

    // Procesar el archivo palabra por palabra
    while (getline(archivo, texto))
    {
        cout << "TEXTO: " << texto << endl;
        string palabra = "";
        for (int i = 0; i <= texto.length(); i++)
        {
            if (isalnum(texto[i]))
            {
                palabra += texto[i];
            }
            else
            {
                if (!palabra.empty())
                {
                    palabras_distintas.insert(palabra);
                    palabra.clear();
                }
            }
        }
    }
    // Mostrar la cantidad de palabras distintas
    cout << "El texto contiene " << palabras_distintas.size() << " palabras distintas." << endl;

    return 0;
}
