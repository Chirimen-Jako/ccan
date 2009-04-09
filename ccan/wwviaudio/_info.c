#include <stdio.h>
#include <string.h>
#include "config.h"

/**
 * wwviaudio - realtime playback and mixing of 16 bit signed PCM audio data.
 *
 * wwviaudio provides a set of functions for realtime playback and mixing
 * of audio samples, e.g. music, sound effects, etc. as in a video game.
 *
 * Example:
 *
 *      something along these lines:
 *
 *      if (wwviaudio_initialize_portaudio() != 0)
 *              bail_out_and_die();
 *
 *      You would probably use #defines or enums rather than bare ints...
 *      wwviaudio_read_ogg_clip(1, "mysound1.ogg");
 *      wwviaudio_read_ogg_clip(2, "mysound2.ogg");
 *      wwviaudio_read_ogg_clip(3, "mysound3.ogg");
 *      wwviaudio_read_ogg_clip(4, "mymusic.ogg");
 *
 *       ...
 *
 *      wwviaudio_play_music(4); <-- begins playing music in background, returns immediately 
 *
 *      while (program isn't done) {
 *              do_stuff();
 *              if (something happened)
 *                      wwviaudio_add_sound(1);
 *              if (something else happened)
 *                      wwviaudio_add_sound(2);
 *              time_passes();
 *      }
 *      
 *      wwviaudio_cancel_all_sounds();
 *      wwviaduio_stop_portaudio();
 *
 * Licence: LGPL (2 or any later version)
 *
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;

	if (strcmp(argv[1], "depends") == 0) {
		printf("ccan/ogg_to_pcm\n"
		       "libvorbis\n"
		       "portaudio\n");
		return 0;
	}

	if (strcmp(argv[1], "libs") == 0) {
		printf("vorbisfile\n"
		       "portaudio\n");
		return 0;
	}
	return 1;
}
