#include <iostream>
using namespace std;

class MP3Player {
	int volume;
public:
	void setVolume(int level);
	int getVolume();

};

int main(int argc, char const *argv[])
{
	MP3Player player;
	player.volume = 20; ]
	player.setVolume(60);
	cout << player.getVolume() << endl;
	return 0;
}