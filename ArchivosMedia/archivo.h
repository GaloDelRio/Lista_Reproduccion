#ifndef ARCHIVO.H
#define ARCHIVO.H

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "video.h"
#include "stack.h"
#include <stack>
using namespace std;


class Archivo{
private:
  void swap(vector<Video> &, int i, int j);

public:
  vector<Video> shellSortLess(vector<Video> );
  vector<Video> shellSortMore(vector<Video> );
  vector<Video> CargaArchivo(const string &name);
  void writeData(vector<Video>);
  void clearData(vector <Video>);
  void printstack(stack <Video>);
  void buscarPorNombre(vector<Video> , string);

};

void Archivo::writeData(vector<Video> inventory){
  ofstream outfile("Contenido.csv");


    outfile << "Nombre,ID,Visitas" << endl;
    for (int i = 0; i < inventory.size(); i++){
      if (i == inventory.size() - 1){
        outfile << inventory[i].getNombre() << ",";
        outfile << inventory[i].getID() << ",";
        outfile << inventory[i].getVisitas();
      } else {
        outfile << inventory[i].getNombre() << ",";
        outfile << inventory[i].getID() << ",";
        outfile << inventory[i].getVisitas() << endl;
      }
    }
}

void Archivo::clearData(vector<Video> inventory){
    ofstream outfile("Inventory.csv");
    outfile << "Name,Quantity,Price";
}

void Archivo::swap(vector<Video> &v, int i, int j){
  Video aux = v[i];
  v[i] = v[j];
  v[j] = aux;
} 

vector<Video> Archivo::shellSortLess(vector<Video> v) {
 vector<Video> sorted_v = v;
 int gap = sorted_v.size() / 2;

 while (gap > 0) {
    for (int i = gap; i < sorted_v.size(); i++) {
      for (int j = i; j >= gap; j -= gap) {
        if (sorted_v[j].getVisitas() < sorted_v[j - gap].getVisitas()) {
          swap(sorted_v, j, j - gap);
        } else {
          break;
        }
      }
    }
    gap /= 2;
 }
  return sorted_v;
}

vector<Video> Archivo::shellSortMore(vector<Video> v) {
    vector<Video> sorted_v = v;
    int gap = sorted_v.size() / 2;

    while (gap > 0) {
        for (int i = gap; i < sorted_v.size(); i++) {
            for (int j = i; j >= gap; j -= gap) {
                if (sorted_v[j].getVisitas() > sorted_v[j -gap].getVisitas()) {
                    swap(sorted_v, j, j - gap);
                } else {
                    break;
                }
            }
        }
        gap /= 2;
    }
    return sorted_v;
}

vector<Video> Archivo::CargaArchivo(const string &name){
  ifstream File(name);
  string nombre;
  int id;
  int visitas;
  string skipline;
  vector<Video> videos;

  if(File.is_open())
{

    getline(File, skipline);

    while (File.good())
    {

      string temp;
      getline(File, nombre, ',');

      getline(File, temp, ',');
      id = stoi(temp);

      getline(File, temp, '\n');
      visitas = stoi(temp);

      Video aux(nombre, id, visitas);
      videos.push_back(aux);          
    }
}
else
{
    cout << "Error Message!" << endl;
}
File.close();
return videos;
}

void addData(string nombre, int id, int visitas) {
  ofstream File("Contenido.csv", ios::app);
  File << endl << nombre << "," << id << "," << visitas;
  File.close();
}


void printStack(stack<Video> s) {
    if(s.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    stack<Video> temp;

    while(!s.empty()) {
        string top = s.top().getNombre();
        cout << top << " ";
        temp.push(s.top());
        s.pop();
    }

    while(!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}
 
void buscarPorNombre(vector<Video> videos, string nombreBuscado){
    for(int i = 0; i < videos.size(); i++){
        if(videos[i].getNombre() == nombreBuscado){
            return videos[i].showInfo();
        }
    }
}

#endif