#ifndef VIDEO_H
#define VIDEO_H

# include <iostream>
# include <string>


using namespace std;


class Video{

private:
  string nombre;
  int id, visitas;
  int next;
  int size;
  int *data;
  int nada;

public:
Video(string _nombre, int _id, int _visitas){
  nombre = _nombre;
  id = _id;
  visitas = _visitas;
}

string getNombre(){return nombre;}

int getID(){return id;}

int getVisitas(){return visitas;}

void showInfo();

void showNombre();

void showNada();

};


void Video::showInfo(){
  cout<< " " << getNombre() << endl;
  cout<< "    ID:" << getID() << endl;
  cout<< "    Video:" << getVisitas() << endl;
}

void Video::showNombre(){
  cout<< " " << getNombre() << endl;

}

void Video::showNada(){
  cout<< " " << endl;

}

#endif