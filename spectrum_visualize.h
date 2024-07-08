#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <cmath>
#include <complex>
#include <valarray>

using namespace std;

#define PI 3.1415926535897f
typedef complex<double> base;
typedef valarray<complex<double> > CArray;
typedef complex<double> Complex;

#define BUFFER_SIZE 16384

class Spectrum_visualize
{
public:
    Spectrum_visualize(const string& fileName);
    ~Spectrum_visualize();

    void take_samples_and_hammingWindow();
    void update(float dt);
    void draw(sf::RenderWindow& window);
    void update_vertex_array();
    void play();

private:

    float* _hammingWindow;// [BUFFER_SIZE] ;
    vector<base> _samples;
    int _samplesRate;
    sf::SoundBuffer _sound_buffer;
    sf::Sound _sound;

    CArray bins;

    sf::VertexArray VA1;
 
};

