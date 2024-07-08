Sound Frequency Visualization using SFML and FFT 

System Requirements: 
SFML 2.5.1

main, spectrum_visualizer compiled and linked to SFML library 
On my machine: 
g++ -c spectrum_visualize.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include 
g++ -c main.cpp -I/usr/local/Cellar/sfml/2.5.1_1/include
g++ -main.o spectrum_visualizer.o -L/usr/local/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -o soundVis 


How to run it: 
./soundVis 
Program will prompt for a file name (.wav) to visualize

A SFML window will generate amplitude and frequency data from the given .wav
The amplitude and frequency are calculated by the mfft (Fast Fourier Transform) 
The data is then plotted using SFML graphics, which consistently update at 60 FPS