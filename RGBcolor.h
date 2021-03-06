#ifndef RGBCOLOR_H
#define RGBCOLOR_H

class RGBcolor {
	private:
		int red, green, blue;
	public:
		RGBcolor();
		~RGBcolor();
		RGBcolor(const RGBcolor& RGB);
		void setRed(int new_red);
		void setGreen(int new_green);
		void setBlue(int new_blue);
		void setRGB(int new_red,int new_green,int new_blue);
		int getRed();
		int getGreen();
		int getBlue();
};

#endif