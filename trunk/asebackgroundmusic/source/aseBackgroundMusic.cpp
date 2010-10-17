#include "aseBackgroundMusic.h"

namespace AirplaySDKExtBackgroundMusic
{
	class IBackgroundMusic
	{
	public:
		virtual ~IBackgroundMusic() {};
		virtual s3eResult BackgroundMusicPickMusicItems(s3eBool allowMultipleItems)=0;
	};

	class Cs3eBackgroundMusic:public IBackgroundMusic
	{
	public:
		Cs3eBackgroundMusic(){};
		virtual ~Cs3eBackgroundMusic() {};
		virtual s3eResult BackgroundMusicPickMusicItems(s3eBool allowMultipleItems)
		{
			return s3eBackgroundMusicPickMusicItems(allowMultipleItems);
		}
	};

	class CCustomBackgroundMusic:public IBackgroundMusic
	{
	public:
		CCustomBackgroundMusic(){};
		virtual ~CCustomBackgroundMusic() {};
		virtual s3eResult BackgroundMusicPickMusicItems(s3eBool allowMultipleItems)
		{
			return S3E_RESULT_ERROR;
		}
	};

	IBackgroundMusic* g_backgroundMusic=0;
}
using namespace AirplaySDKExtBackgroundMusic;
s3eBool aseExtBackgroundMusicAvailable()
{
	if (s3eExtBackgroundMusicAvailable())
		return true;
	return true;
}
void aseBackgroundMusicInit()
{
	if (!g_backgroundMusic)
	{
		if (s3eExtBackgroundMusicAvailable())
			g_backgroundMusic = new Cs3eBackgroundMusic();
		else
			g_backgroundMusic = new CCustomBackgroundMusic();
	}
}
void aseBackgroundMusicTerminate()
{
	if (g_backgroundMusic)
	{
		delete g_backgroundMusic;
		g_backgroundMusic = 0;
	}
}
s3eResult aseBackgroundMusicPickMusicItems(s3eBool allowMultipleItems)
{
	return g_backgroundMusic->BackgroundMusicPickMusicItems(allowMultipleItems);
}