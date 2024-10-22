/*******************************************************************************\
 ** File: IGCloudVoiceExtension.h
 ** Module: GVoice
 ** Version: 1.0
 ** Author: CZ
 \*******************************************************************************/

#ifndef _GCloud_GVoice_IGCloudVoiceExtension_h
#define _GCloud_GVoice_IGCloudVoiceExtension_h

#include "GCloudVoiceErrno.h"

namespace GCloud
{
    namespace GVoice
    {
        class IGCloudVoiceEngine;
        /**
         * Extension API for voice engine
         */
        class IGCloudVoiceEngineExtension
        {
        public:
            /**
             * Don't play voice of the member.
             *
             * @param roomName: the room to join, should be less than 127byte, composed by alpha.
             * @param member : member to forbid
             * @param bEnable : do forbid if it is true
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo ForbidMemberVoice(int member, bool enable, const char *roomName="") = 0;
            
            /**
             * Open Voice Engine's logcat
             *
             * @param enable: open logcat if it is true
             */
            virtual void EnableLog(bool enable) = 0;
            
            /**
             * Get micphone's volume
             *
             * @return : micphone's volume , if return value>0, means you have said something capture by micphone
             */
            virtual int GetMicLevel(bool fadeOut=true) = 0;
            
            /**
             * Get speaker's volume
             *
             * @return : speaker's volume, value is equal you Call SetSpeakerVolume param value
             */
            virtual int GetSpeakerLevel() = 0;

            /**
             * set sepaker's volume
             *
             * @param vol: setspeakervolume,
             * Android & IOS, value range is 0-800, 100 means original voice volume, 50 means only 1/2 original voice volume, 200 means double original voice volume
             * Windows value range is 0x0-0xFFFF, suggested value bigger than 0xff00, then you can hear you speaker sound
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo SetSpeakerVolume(int volume) = 0;
            
            /**
             * Test wheather microphone is available
             *
             * @return : if success return GCLOUD_VOICE_SUCC, , means have detect micphone device,failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo TestMic() = 0;
            
            /**
             * Get voice message's info
             *
             * @param filepath: file path should be "sdcard/your_dir/your_file_name" be sure to use "/" not "\"
             * @param bytes: on return for file's size
             * @param sendons: on return for voice's length
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo GetFileParam(const char *filepath, unsigned int* bytes, float *seconds) = 0;
            
            /**
             * Capture microphone audio data by IGCloudVoiceNotify::OnRecording
             *
             * @param bCapture : true/false - start/stop capturing audio data
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo CaptureMicrophoneData(bool capture) = 0;

            /*
            * Detect whether you're speaking or just keep microphone opened
            * return bool value for the speaking state
            */
            virtual bool IsSpeaking()const = 0;

        public:
            /**
             * YOU SHOULD NOT INVOKE THIS ONE.
             */
            virtual int invoke ( unsigned int cmd,unsigned int param1,  unsigned int param2, unsigned int *output ) = 0;
        };
    } // end of GVoice
} // end of GCloud


#endif /* _GCloud_GVoice_IGCloudVoiceExtension_h */
