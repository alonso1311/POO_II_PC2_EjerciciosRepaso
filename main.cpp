#include <iostream>
#include <vector>
#include <set>
#include <deque>
#include <algorithm>
#include <iterator>
#include<cstdarg>

using namespace std;

template <typename CONTAINER>
void print(CONTAINER container) {
    auto bgin = begin(container);
    auto last = end(container);

    for (; bgin != last ; ++bgin) {
        cout << *bgin << " ";
    }
}


//-Ejercicio 1
template <typename T>
T absolute(T& numero){
    return (numero > 0) ? numero : (numero*-1);
}

//-Ejercicio 2
template <typename CONTAINER>
auto split_range(CONTAINER container, int numero){
    int tamano = size(container);
    int tamano_resultados = tamano/numero;
    int modulo = tamano%numero;

    auto inicio = begin(container);
    auto j = begin(container);
    auto last = end(container);
    auto m = next(inicio, tamano_resultados);
    auto tmn = next(inicio, numero);

    for (; inicio != tmn; ++inicio) {
        for (; j != m; ++j) {
            cout << *j << " ";
        }
        m+=2;
        cout << endl;
    }
}

//-Ejercicio 3
template <typename CONTAINER1, typename CONTAINER2>
auto put_sumar_rango(CONTAINER1& container_menor, CONTAINER2& container_mayor) {
    auto bgin1 = begin(container_menor);
    auto bgin2 = begin(container_mayor);
    auto last1 = end(container_menor);
    auto last2 = end(container_mayor);

    CONTAINER2 containerR;

    while (bgin2 != last2) {
        if (bgin1 == last1) {
            bgin1 = begin(container_menor);
            containerR.push_back((*bgin1)+(*bgin2));
        }
        else {
            containerR.push_back((*bgin1)+(*bgin2));
        }
        bgin1++;
        bgin2++;
    }
    return containerR;
}

template <typename CONTAINER1, typename CONTAINER2>
auto sumar_rango(CONTAINER1& container1, CONTAINER2& container2){
    int tamano1 = size(container1);
    int tamano2 = size(container2);

    if (tamano1 < tamano2)
        return put_sumar_rango(container1, container2);

    else if (tamano1 > tamano2)
        return put_sumar_rango(container2, container1);

    else
        return put_sumar_rango(container2, container1);
}

//-Ejercicio 4
template <typename CONTAINER, typename T>
auto delete_items(CONTAINER container, T items) {

}

//-Ejercicio 5
template <typename CONTAINER>
auto delete_duplicated(CONTAINER container) {
    auto bgin = begin(container);
    auto last = end(container);

    sort(bgin, last);
    container.erase(unique(bgin, last), last);
    print(container);
}

//-Ejercicio 6
template<typename CONTAINER>
CONTAINER rotate_range(CONTAINER container, int number) {
    int abs_number = absolute(number);
    CONTAINER containerR;

    if(number > 0)
        rotate(rbegin(container), rbegin(container)+abs_number, rend(container));

    else
        rotate(begin(container), begin(container)+abs_number, end(container));

    for (auto i : container)
        containerR.push_back(i);

    return containerR;
}

//-Ejercicio 7



int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    vector<int> v1 = {10, 20, 30, 40, 50, 60, 70};

    //split_range(v,3);
    //auto v4 = sumar_rango(v, v1);


    vector<int> vd = {10, 20, 10, 20, 30, 40, 10};
    //sort(vd.begin(), vd.end());
    //delete_duplicated(vd);
    /*auto v3 = rotate_range(vd, -2);
      print(v3);*/

    //print(vd);
    vector<int> f = {1};

    return 0;
}