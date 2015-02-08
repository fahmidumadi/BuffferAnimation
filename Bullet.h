#ifndef BULLET_H
#define BULLET_H

#include "FrameBuffer.h"
#include "DrawingObject.h"
#include "RGBcolor.h"
#include "Point.h"
#include "FrameBuffer.h"
using namespace std;

class Bullet{
	public:
		Bullet(Point start, int dir);
		~Bullet();
		Bullet(const Bullet& B);
		void SetWarna(int R, int G, int B);
		RGBcolor GetWarna();
		Point GetPosition();
		int GetDirection();
		DrawingObject GetGambar();
		
		void Geser(int x, int y);
		void Hapus(FrameBuffer fb);
		void Draw(FrameBuffer fb);
		void ChangeState(FrameBuffer fb);
	private:
		RGBcolor warna;
		RGBcolor warnaLedakan;
		Point position;
		int direction;
		int iterasi;
		DrawingObject gambar;
		bool meledak;
};

#endif