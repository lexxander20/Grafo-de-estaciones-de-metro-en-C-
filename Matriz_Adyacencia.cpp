#include <bits/stdc++.h>

using namespace std;

class claseMatrizAdyacencia 
{
	public:
		vector<string> nodoLista;
		vector<vector<int>> matrizAdyacencia;
		void reacomodar(size_t nuevoTamano) {
			vector<vector<int>> matrizVieja = matrizAdyacencia;
			matrizAdyacencia = vector<vector<int>> (nuevoTamano, vector<int>(nuevoTamano, 0));
			for (size_t fila = 0;fila < min(nuevoTamano, matrizVieja.size()); fila++) {
				for (size_t columna = 0; columna < min(nuevoTamano, matrizVieja[fila].size()); ++columna) {
					matrizAdyacencia[fila][columna] = matrizVieja[fila][columna];
				}
			}
		}
		vector<string>::iterator buscarNodo(string nombre) {
			return find(nodoLista.begin(), nodoLista.end(), nombre);
		}
		void eliminarNodo(string nombre) {
			auto iterador = find(nodoLista.begin(), nodoLista.end(), nombre);
			if (iterador != nodoLista.end()) {
				int indice = iterador - nodoLista.begin();
				for (auto& fila:matrizAdyacencia) {
					fila.erase(fila.begin() + indice);
				}
				matrizAdyacencia.erase(matrizAdyacencia.begin() + indice);
				nodoLista.erase(iterador);
			} else {
				cout << "El nodo" << nombre << "no existe en el grafo" << endl;
			}
		}
		void insertarNodo(string nombre) {
			if (find(nodoLista.begin(), nodoLista.end(), nombre) == nodoLista.end()) {
				nodoLista.push_back(nombre);
				reacomodar(nodoLista.size());
			}
		}
		void agregarArista(string desde, string hasta) {
			auto hastaNodoIterador = buscarNodo(hasta);
			if (hastaNodoIterador == nodoLista.end()) {
				insertarNodo(hasta);
			}
			auto desdeNodoIterador = buscarNodo(desde);
			if (desdeNodoIterador == nodoLista.end()) {
				insertarNodo(desde);
			}
			int desdeNodoIndice = buscarNodo(desde) - nodoLista.begin();
			int hastaNodoIndice = buscarNodo(hasta) - nodoLista.begin();
			matrizAdyacencia[desdeNodoIndice][hastaNodoIndice] = 1;
		}
		void eliminarArista(string desde, string hasta) {
			auto desdeNodoIterador = buscarNodo(desde);
			if (desdeNodoIterador != nodoLista.end()) {
				auto hastaNodoIterador = buscarNodo(desde);
				if (hastaNodoIterador != nodoLista.end()) {
					int desdeNodoIndice = buscarNodo(desde) - nodoLista.begin();
					int hastaNodoIndice = buscarNodo(hasta) - nodoLista.begin();
					matrizAdyacencia[desdeNodoIndice][hastaNodoIndice] = 0;
				}
			}
		}
		void imprimir() {
			size_t numeroNodos = nodoLista.size();
			int campos = 20;
			cout << setw(campos) << " ";
			for (size_t columna = 0; columna < numeroNodos; ++columna) {
				cout << setw(campos) << nodoLista[columna];
			}
			cout << endl;
			for (size_t fila = 0; fila < numeroNodos; fila++) {
				cout << setw(campos) << nodoLista[fila];
				for (size_t columna = 0; columna < numeroNodos; columna++) {
					cout << setw(campos) << matrizAdyacencia[fila][columna];
				}
				cout << endl;
			}
		}	
};

int main ()
{
	claseMatrizAdyacencia grafo;
	grafo.agregarArista("Osloer_strabe", "Franz-Neuman-Platz");
	grafo.agregarArista("Osloer_strabe", "Pankstrabe");
	grafo.agregarArista("Osloer_strabe", "Nauner_Platz");
	grafo.agregarArista("Nauner_Platz", "Leopoldplatz");
	grafo.agregarArista("Leopoldplatz", "Seestrabe");
	/* grafo.agregarArista("Leopoldplatz", "Wedding");
	grafo.agregarArista("Leopoldplatz", "Amrumer_strabe");
	grafo.agregarArista("Amrumer_strabe", "Westhafen");
	grafo.agregarArista("Westhafen", "Birkenstrabe");
	grafo.agregarArista("Birkenstrabe", "Turmstrabe");
	grafo.agregarArista("Turmstrabe", "Hansaplatz");
	grafo.agregarArista("Turmstrabe", "Zoologischer_Garten");
	grafo.agregarArista("Zoologischer_Garten", "Ernst-Reuter-Platz");
	grafo.agregarArista("Zoologischer_Garten", "Wittenberg-Platz");
	grafo.agregarArista("Zoologischer_Garten", "Kurfusten_damm");
	grafo.agregarArista("Kurfusten_damm", "Uhland-strabe");
	grafo.agregarArista("Kurfusten_damm", "Wittenberg-Platz");
	grafo.agregarArista("Kurfusten_damm", "Spichern_strabe");
	grafo.agregarArista("Spichern_strabe", "Hohenzollernplatz");
	grafo.agregarArista("Spichern_strabe", "Augsburger_Strabe");
	grafo.agregarArista("Spichern_strabe", "Guntzelstrabe");
	grafo.agregarArista("Guntzelstrabe", "Berliner_strabe");
	grafo.agregarArista("Berliner_strabe", "Blisse_strabe");
	grafo.agregarArista("Berliner_strabe", "Bayerischer_Platz");
	grafo.agregarArista("Berliner_strabe", "Bundesplatz");
	grafo.agregarArista("Bundesplatz", "Friedrich");
	grafo.agregarArista("Friedrich", "Walther_platz");
	grafo.agregarArista("Walther_platz", "Scholbstrabe");
	grafo.agregarArista("Scholbstrabe", "Rathaus_Steglitz"); */
	grafo.imprimir();
	return 0;
}
