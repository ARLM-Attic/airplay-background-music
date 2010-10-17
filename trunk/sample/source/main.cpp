#include <s3e.h>
#include <IwGx.h>
#include <IwUI.h>
#include <aseBackgroundMusic.h>

//-----------------------------------------------------------------------------
// Main global function
//-----------------------------------------------------------------------------
int main()
{
	IwGxInit();
	IwResManagerInit();
	aseBackgroundMusicInit();

	IwGxSetColClear(0xff, 0xff, 0xff, 0xff);
	IwGxPrintSetColour(128, 128, 128);

	CIwResGroup* music = IwGetResManager()->LoadGroup("main.group");

	//Set the default style sheet
    CIwResource* pResource = IwGetResManager()->GetResNamed("iwui", IW_UI_RESTYPE_STYLESHEET);
    IwGetUIStyleManager()->SetStylesheet(IwSafeCast<CIwUIStylesheet*>(pResource));



	aseBackgroundMusicPickMusicItems(false);

	while (1)
	{
		s3eDeviceYield(0);
		s3eKeyboardUpdate();
		s3ePointerUpdate();

		bool result = true;
		if	(
			(result == false) ||
			(s3eKeyboardGetState(s3eKeyEsc) & S3E_KEY_STATE_DOWN) ||
			(s3eKeyboardGetState(s3eKeyAbsBSK) & S3E_KEY_STATE_DOWN) ||
			(s3eDeviceCheckQuitRequest())
			)
			break;

		//Update the controller (this will generate control events etc.)
		IwGetUIController()->Update();
    
		//Update the view (this will do animations etc.) Airplay SDK's example framework has a fixed 
		//framerate of 20fps, so we pass that duration to the update function.
		IwGetUIView()->Update(1000/20);

		IwGxClear(IW_GX_COLOUR_BUFFER_F | IW_GX_DEPTH_BUFFER_F);
	}

	aseBackgroundMusicTerminate();
	IwResManagerTerminate();
	IwGxTerminate();
	return 0;
}