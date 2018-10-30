/*******************************************************************************\
** File: GCloudVoiceVersion.h
** Module: GVoice
** Version: 1.0
** Author: CZ
\*******************************************************************************/

#ifndef _GCloud_GVoice_GCloudVoiceVersion_h
#define _GCloud_GVoice_GCloudVoiceVersion_h

#define GCLOUD_VOICE_VERSION "1.0.10.183740"

namespace GCloud
{
    namespace GVoice
    {
        enum Ver
        {
            kVerMajor = 1,
            kVerMinor = 0,
            kVerFix   = 0,

            kVerSVN   = 183740,

            kVerBufLen = 1024,
        };

        const char * gvoice_get_version();
    }
}
#endif /* _GCloud_GVoice_GCloudVoiceVersion_h */
