#include "Object.h"
#include <fstream>
#include <iostream>
using namespace std;

Object::Object(string filename, int direction){
	string line;
	int a,b;
	Point titik;
  	ifstream myfile (filename.c_str());
  	if (myfile.is_open()){
    	while ( getline (myfile,line) ){

      		a = atoi(line.substr (0,line.find(",")).c_str());
      		b = atoi(line.substr (line.find(",")+1).c_str());
      		titik.SetAbsis(a);
      		titik.SetOrdinat(b);
      		NTitik.push_back(titik);
    	}
    	shooter = titik;
    	shooter.SetOrdinat(shooter.GetOrdinat() + 6*direction);
    	myfile.close();
  	}
	else cout << "Unable to open file";
	warna.setRGB(255,255,255);
	this->direction = direction;
}
Object::~Object(){

}
void Object::SetWarna(int R, int G, int B){
	warna.setRGB(R,G,B);	
}
void Object::Geser(int x, int y){
	Point currentp;
	for(int i=0; i<NTitik.size();i++){
		NTitik.at(i).SetAbsis(NTitik.at(i).GetAbsis()+x);
		NTitik.at(i).SetOrdinat(NTitik.at(i).GetOrdinat()+y);
	}
	shooter = NTitik.at(0);
}
void Object::Draw(FrameBuffer fb){
	gambar.plotListOfPoint(NTitik,warna,fb);
}
void Object::Hapus(FrameBuffer fb){
	RGBcolor hitam;
	hitam.setRGB(0,0,0);
	gambar.plotListOfPoint(NTitik,hitam,fb);	
}

void Object::SetShooter(Point shooter)
{
	this->shooter = shooter;
}

Point Object::GetShooter()
{
	return shooter;
}

