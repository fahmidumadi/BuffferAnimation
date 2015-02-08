#include "FrameBuffer.h"
#include "DrawingObject.h"
#include "RGBcolor.h"
#include "Point.h"
#include "Object.h"
#include "Bullet.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	/* Inisialisasi */
	FrameBuffer frame;
	int selang1 = 300;
	int selang2 = 200;
	vector<Bullet> listOfBullet;
	system("clear");

	Object pesawat("pesawat.txt", 1);
	Object kapal("kapal.txt", -1);	

	pesawat.Draw(frame);
	kapal.Draw(frame);

	int i=0;

	Bullet bullet1(pesawat.GetShooter(),  1);
	bullet1.SetWarna(255, 255, 0);
	listOfBullet.push_back(bullet1);

	Bullet bullet2(kapal.GetShooter(), -1);
	bullet2.SetWarna(255, 0, 255);
	listOfBullet.push_back(bullet2);

	while(i<5000)
	{
		pesawat.Hapus(frame);
		pesawat.Geser(-1, 0);
		pesawat.Draw(frame);

		kapal.Hapus(frame);
		kapal.Geser(1, 0);
		kapal.Draw(frame);
		
		if((i%selang1) == 0)
		{
			Bullet bullet1(pesawat.GetShooter(),  1);
			bullet1.SetWarna(255, 255, 0);
			listOfBullet.push_back(bullet1);
		}

		if((i%selang2) == 0)
		{
			Bullet bullet2(kapal.GetShooter(), -1);
			bullet2.SetWarna(255, 0, 255);
			listOfBullet.push_back(bullet2);
		}

		for(int it = 0; it<(int)listOfBullet.size(); it++)
		{
			listOfBullet[it].ChangeState(frame);
		}
		usleep(10000);
		i++;
	}
	
	cout << "Finish" << endl;
	return 0;
}