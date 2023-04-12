#include <iostream>
using namespace std;

template <typename int>
class Cubo{
public:
    int lado;
    int cantidad_veces_a_sumar;

    Cubo(int lado) : lado(lado), cantidad_veces_a_sumar(6) {}
    // Area del cubo = l**2 * 6 = l*l sumado 6 veces = l*l + l*l + l*l + l*l + l*l + l*l
    int hallar_area_recursivo_aux(int cantidad_veces_a_sumar)
    {
        if (cantidad_veces_a_sumar == 0)
            return 0;
        return lado * lado + hallar_area_recursivo_aux(cantidad_veces_a_sumar - 1);
    }
    int hallar_area_recursivo()
    {
        return hallar_area_recursivo_aux(this->cantidad_veces_a_sumar);
    }
    // Volumen del cubo = l**3 = l*l*l
    double hallar_potencia(int base, int exp)
    {
        if (exp == 0)
            return 1;
        else if (exp < 0)
            return 1 / hallar_potencia(base, -exp);
        else
            return base * hallar_potencia(base, exp - 1);
    }
    int hallar_volumen_recursivo()
    {
        return hallar_potencia(lado, 3);
    }
};

int main()
{
    double lado;
    do
    {
        cout << "Ingrese el valor del lado en rango de 1 a 30: ";
        cin >> lado;
    } while (lado < 1 || lado > 30);
    Cubo<int> *cuboINT = new Cubo<int>(lado);
    Cubo<double> *cuboDOUBLE = new Cubo<double>(lado);
    cout << "El area del cubo entero con lado " << int(lado) << " es: " << cuboINT->hallar_area_recursivo() << endl;
    cout << "El area del cubo double con lado " << lado << " es: " << cuboDOUBLE->hallar_area_recursivo() << endl;
    cout << "El volumen del cubo entero con lado " << int(lado) << " es: " << cuboINT->hallar_volumen_recursivo() << endl;
    cout << "El volumen del cubo double con lado " << lado << " es: " << cuboDOUBLE->hallar_volumen_recursivo() << endl;
    return 0;
}