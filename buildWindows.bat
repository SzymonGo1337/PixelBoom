mkdir build
cd build
mkdir res
cd ..
g++ src/*.cpp src/pb/*.cpp src/pb/*.hpp -w -Lvendor/Windows/SFML-2.5.1/lib -Ivendor/Windows/SFML-2.5.1/include -lsfml-graphics -lsfml-system -lsfml-window -lsfml-network -lsfml-audio -o build/app
cp res/* build/res/