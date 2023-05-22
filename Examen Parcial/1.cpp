#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    srand(time(NULL));

    string nombre_torneo;
    getline(cin, nombre_torneo);

    vector<string> jugadores;
    for (int i = 0; i < 2; i++)
    {
        string nombre;
        getline(cin, nombre);
        jugadores.push_back(nombre);
    }

    int n;
    do
    {
        cin >> n;
    } while (n < 5 || n > 15);

    vector<int> puntajes = {0, 3, 10};
    vector<pair<string, int>> encuentro_iz;
    vector<pair<string, int>> encuentro_der;
    for (int i = 0; i < n; i++)
    {

        int random_nombre = rand() % 2 + 1;
        int random_puntaje = rand() % 3;
        int random_puntaje2;

        if (random_puntaje == 1)
            random_puntaje2 = 1;
        else if (random_puntaje == 0)
            random_puntaje2 = 2;
        else
            random_puntaje2 = 0;

        pair<string, int> jugador_puntaje_iz = {jugadores[random_nombre - 1], puntajes[random_puntaje]};
        pair<string, int> jugador_puntaje_der = {jugadores[2 - random_nombre], puntajes[random_puntaje2]};

        encuentro_iz.push_back(jugador_puntaje_iz);
        encuentro_der.push_back(jugador_puntaje_der);
    }
    int puntaje_total_1 = 0;
    int puntaje_total_2 = 0;
    int j1_encuentros_ganados = 0;
    int encuentros_empatados = 0;
    int j2_encuentros_perdidos = 0;
    for (int i = 0; i < encuentro_iz.size(); i++)
    {
        if (encuentro_iz[i].first == jugadores[0])
        {
            puntaje_total_1 += encuentro_iz[i].second;
            puntaje_total_2 += encuentro_der[i].second;
        }
        else
        {
            puntaje_total_1 += encuentro_der[i].second;
            puntaje_total_2 += encuentro_iz[i].second;
        }

        if (encuentro_iz[i].first == jugadores[0] && encuentro_iz[i].second > encuentro_der[i].second)
        {
            j1_encuentros_ganados++;
        }
        else if (encuentro_der[i].first == jugadores[0] && encuentro_der[i].second > encuentro_iz[i].second)
        {
            j1_encuentros_ganados++;
        }

        if (encuentro_iz[i].second == encuentro_der[i].second)
        {
            encuentros_empatados++;
        }

        if (encuentro_iz[i].first == jugadores[1] && encuentro_iz[i].second < encuentro_der[i].second)
        {
            j2_encuentros_perdidos++;
        }
        else if (encuentro_der[i].first == jugadores[1] && encuentro_der[i].second < encuentro_iz[i].second)
        {
            j2_encuentros_perdidos++;
        }
        cout << encuentro_iz[i].first << "-" << encuentro_iz[i].second << "#" << encuentro_der[i].first << "-" << encuentro_der[i].second << endl;
    }

    cout << endl;
    cout << nombre_torneo << endl;
    if (puntaje_total_1 > puntaje_total_2)
    {
        cout << "1. " << jugadores[0] << ", " << puntaje_total_1 << " puntos" << endl;
        cout << "2. " << jugadores[1] << ", " << puntaje_total_2 << " puntos" << endl;
    }
    else if (puntaje_total_2 > puntaje_total_1)
    {
        cout << "1. " << jugadores[1] << ", " << puntaje_total_2 << " puntos" << endl;
        cout << "2. " << jugadores[0] << ", " << puntaje_total_1 << " puntos" << endl;
    }
    else
    {
        cout << "1 y 2. Los dos jugadores empataron en puntajes" << endl;
    }
    cout << "3. " << j1_encuentros_ganados << " encuentros ganados" << endl;
    cout << "4. " << encuentros_empatados << " encuentros empatados" << endl;
    cout << "5. " << j2_encuentros_perdidos << " encuentros perdidos" << endl;

    return 0;
}