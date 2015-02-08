all:
	g++ -o tes main.cpp DrawingObject.cpp FrameBuffer.cpp Point.cpp RGBcolor.cpp Object.cpp Bullet.cpp
	
runkapal:
	./tes
