#include "Bullet.h"

Bullet::Bullet(Point start, int dir)
{
	position = start;
	direction = dir;
	meledak = false;
}

Bullet::~Bullet()
{

}

Bullet::Bullet(const Bullet& B) {
	warna = B.warna;
	position = B.position;
	direction = B.direction;
	gambar = B.gambar;
}

void Bullet::SetWarna(int R, int G, int B)
{
	warna.setRGB(R, G, B);
}

RGBcolor Bullet::GetWarna()
{
	return warna;
}

Point Bullet::GetPosition()
{
	return position;
}

int Bullet::GetDirection()
{
	return direction;
}

DrawingObject Bullet::GetGambar()
{
	return gambar;
}

void Bullet::Geser(int x, int y)
{
	position.SetAbsis(position.GetAbsis() + x);
	position.SetOrdinat(position.GetOrdinat() + y);	
}

void Bullet::Hapus(FrameBuffer fb)
{
	RGBcolor hitam;
	hitam.setRGB(0,0,0);
	gambar.plotCircle(position, 5, hitam, fb);
}

void Bullet::Draw(FrameBuffer fb)
{
	gambar.plotCircle(position, 5, warna, fb);
}

void Bullet::ChangeState(FrameBuffer fb)
{
	if((position.GetOrdinat() < 50) || (position.GetOrdinat() > 750) || (iterasi > 64))
	{
		Hapus(fb);
	}
	else
	{
		Hapus(fb);

		if(!fb.isBlack(position.GetAbsis(),position.GetOrdinat()+direction*5))
		{
			meledak = true;
			iterasi = 0;
		}

		if(meledak)
		{
			iterasi++;
			if(iterasi <= 32)
			{
				warnaLedakan.setRed(255);
				warnaLedakan.setBlue(0);
				warnaLedakan.setGreen(255-iterasi*7);
				gambar.plotCircle(position, (iterasi%32), warnaLedakan, fb);
			}
			else
			{
				warnaLedakan.setRed(0);
				warnaLedakan.setBlue(0);
				warnaLedakan.setGreen(0);
				gambar.plotCircle(position, (iterasi%32), warnaLedakan, fb);
			}
		}
		else
		{
			Geser(0, direction);
			Draw(fb);
		}
	}
}