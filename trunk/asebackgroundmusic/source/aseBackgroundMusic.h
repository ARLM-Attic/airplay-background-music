#pragma once

#include <s3eExt_BackgroundMusic.h>

void aseBackgroundMusicInit();
void aseBackgroundMusicTerminate();

/**
 * Retrieves an integer property for the Background Music module.
 * @param property property to get.
 * @return
 *  - The value of the requested property if property is valid.
 *  - -1 if the property is not valid.\n
 *    Call @ref s3eAudioGetError() to retrieve an error code. This will return:\n
 *    @ref S3E_DEVICE_ERR_PARAM if @e property is not valid.
 * @see s3eBackgroundMusicProperty
 * @see s3eBackgroundMusicSetInt
 *
 * @par Required Header Files
 * s3eExt_BackgroundMusic.h
 */
int32 aseBackgroundMusicGetInt(s3eBackgroundMusicProperty prop);

/**
 * Returns S3E_TRUE if the BackgroundMusic extension is available.
 */
s3eBool aseExtBackgroundMusicAvailable();



/**
 * Attempts to launch an API for selecting music item(s) to play.  On an iPhone/iPod this launches the standard iPod GUI.
 * If the user cancelled the selection or there was an error this will return S3E_RESULT_ERROR.
 * @param allowMultipleItems allow user to queue up multiple music items.
 */
s3eResult aseBackgroundMusicPickMusicItems(s3eBool allowMultipleItems);

/**
 * Sets an integer property for the Background Music module.
 * @param property property to set.
 * @param value New value for property.
 * @return
 * - @ref S3E_RESULT_SUCCESS if no error occurred.
 * - @ref S3E_RESULT_ERROR if the operation failed.\n
 *         Call s3eDeviceGetError() to retrieve an error code.
 *         This will return:
 *   - @ref S3E_FILE_ERR_PARAM if @e session is invalid or @e property is invalid or @e value is invalid.
 * @see s3eBackgroundMusicProperty
 * @see s3eBackgroundMusicGetInt
 *
 * @par Required Header Files
 * s3eExt_BackgroundMusic.h
 */
s3eResult aseBackgroundMusicSetInt(s3eBackgroundMusicProperty property, int32 value);


/**
 * Plays media items from the current playback queue, resuming paused playback if possible.
 */
s3eResult aseBackgroundMusicPlay();

/**
 * Pauses any current background Music playback.
 */
s3eResult aseBackgroundMusicPause();

/**
 * Stops any current background Music playback.
 */
s3eResult aseBackgroundMusicStop();

/**
 * Returns the current s3eBackgroundMusicItem if there is one.
 * Note paused, interrupted or stopped items DO NOT return NULL.
 *
 * The item pointed to is immutable. To change the item currently playing
 * use s3eBackgroundMusicSetPlaybackQueueWithCollection(). It is not possible
 * to query the content of the current playlist beyond the item that is
 * currently playing, however this can be managed manually in an application
 * by keeping track of what items are queued and which playback controls are
 * called.
 */
struct s3eBackgroundMusicItem* aseBackgroundMusicGetCurrentItem();
