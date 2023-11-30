#include <iostream>
#include <fstream>
#include "video.h"
#include "archivo.h"
#include <vector>
#include <stack>

using namespace std;

int main() {
  Archivo archivo;
  vector<Video> videos;
  vector<Video> reproduccion;
  vector<Video> sorted_videos;
  stack<Video> miPila;
  stack<Video> mostrarPila;
  videos = archivo.CargaArchivo("Contenido.csv");
  int op;
  int agrega = 0;
  string borra = "";
  string consulta = "";
  string consulta2 = "";




  cout<<"\n=================================================="<<endl;
  cout<<"                     Contenido"<<endl;
  cout<<"==================================================\n"<<endl;

  for(int i = 0; i < videos.size(); i++){
    cout<< i + 1 <<")"; videos[i].showInfo(); cout<<endl;
  }

  while(true){
    videos = archivo.CargaArchivo("Contenido.csv");
    cout<<"=================================================="<<endl;
    cout<<"                     Opciones"<<endl;
    cout<<"=================================================="<<endl;
     cout<<"\n¿Que te gustaria hacer? :\n"<<endl;
     cout<<"\n1)Mostrar datos de CSV\n2)Sortear visitas de menor a mayor \n3)Sortear visitas de mayor  a menor \n4)Crear una pila //Agregar cancion a la lista de reproducción \n5)Consultar ultimo valor de la pila\n6)Mostrar lista de reproduccion/ pila\n7)Agregar dato a CSV\n8)Consultar información CSV\n9)Consultar información de la pila\n\n0)Cerrar programa"<<endl;


    cout<<"\nRespuesta:";cin>>op;
    system("clear");

    cout<<"=================================================="<<endl;

    if (op == 1){

      for(int i = 0; i < videos.size(); i++){
        cout<< i + 1 <<")"; videos[i].showInfo(); cout<<endl;
      }

    }
    else if (op == 2){
      sorted_videos = archivo.shellSortLess(videos);

        for (int i = 0; i < sorted_videos.size(); i++) {
            cout<< i + 1 <<")"; sorted_videos[i].showInfo();
      }

    }
    else if (op == 3){
      sorted_videos = archivo.shellSortMore(videos);


        for (int i = 0; i < sorted_videos.size(); i++) {
          cout<< i + 1 <<")"; sorted_videos[i].showInfo();
      } 

    }
    else if (op == 4){
      for (int i = 0; i < videos.size(); i++) {
        cout<< i + 1 << ")"; videos[i].showInfo();}

      cout<<"\nDame el numero de la canción que quieres agregar a la pila: ";cin>>agrega;
      cout<<"\n";
      miPila.push(videos[agrega -1]);
      if (!miPila.empty()) {

      cout<<"\nVideo agregado: \n";
      cout << miPila.top().getNombre() << endl;
      }
    }
    else if (op == 5) {
      if (!miPila.empty()) { // Verificar si la pila no está vacía
        cout << "\nEl último video agregado es: \n\n";
        cout << miPila.top().getNombre();
        cout << "\n\n¿Te gustaría borrarlo? (Y/N): ";
        cin >> borra;

        if (borra == "Y") {
            miPila.pop();
            cout << "\n\nVideo eliminado.\n\n";
        } else {
            cout << "\nNo se borró nada\n";
        }
      } else {
        cout << "La pila está vacía, no hay videos para borrar." << endl;
      }
    }
    else if (op == 6){
      
      cout << "\nContenido de la pila:\n" << endl;
        printStack(miPila);
      cout << "\n";
      
      }
    else if (op == 7){
      string nombre;
      int id = 0;
      float visitas = 0;
      cout << "Creacion de dato" << endl;
      cout << "Nombre Ejemplo(NOMBRE): " << endl;
      cin >> nombre;
      cout << "ID: Ejemplo(1234...)" << endl;
      cin >> id;
      cout << "Visitas Ejemplo(1234...): " << endl;
      cin >> visitas;
      addData(nombre, id, visitas);
    }
    else if (op == 8){

      for(int i = 0; i < videos.size(); i++){
        cout<< i + 1 <<")"; videos[i].showInfo(); cout<<endl;
      }

      cout << "\nDame el nombre consultar informacion de video en el CSV";cin>>consulta;
      for(int i = 0; i < videos.size(); i++){
      if(videos[i].getNombre() == consulta){
        cout<< i + 1 <<")"; videos[i].showInfo(); cout<<endl;
      }
      }

    }
    else if (op == 9){

      cout << "\nContenido de la pila:\n" << endl;
        printStack(miPila);
      cout << "\n";

      if (!miPila.empty()) { // Verificar si la pila no está vacía
          mostrarPila = miPila;
          int numVideosEncontrados = 0;

          for (int i = 0; i < mostrarPila.size(); i++) {
              if (mostrarPila.top().getNombre() != consulta2) {
                  mostrarPila.pop();
              }
          }

          if (!mostrarPila.empty()) { // Verificar si la pila después del bucle no está vacía
              mostrarPila.top().showInfo();
              numVideosEncontrados++;
          }

          if (numVideosEncontrados == 0) {
              cout << "No se encontraron videos con el nombre: " << consulta2 << endl;
          }
      } else {
          cout << "La pila está vacía, no hay videos para consultar." << endl;
      }

    }
      
    else if (op == 0){

      break;
      
    }else{
      cout << "\n¡¡¡Se ingreso un valor incorrecto, trate de nuevo¡¡¡\n" << endl;
    }


  }

};
