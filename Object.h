#ifndef OBJECT_H
#define OBJECT_H

#include "FrameBuffer.h"
#include "DrawingObject.h"
#include "RGBcolor.h"
#include "Point.h"
#include <string>
#include <vector>
using namespace std;

class Object{
	public:
		Object(string filename, int direction);
		~Object();
		void SetWarna(int R, int G, int B);
		void Geser(int x, int y);
		void Draw(FrameBuffer fb);
		void Hapus(FrameBuffer fb);
		void SetShooter(Point shooter);
		Point GetShooter();
	
	private:
		RGBcolor warna;
		vector<Point> NTitik;
		Point shooter;
		DrawingObject gambar;
		int direction;
};

#endif