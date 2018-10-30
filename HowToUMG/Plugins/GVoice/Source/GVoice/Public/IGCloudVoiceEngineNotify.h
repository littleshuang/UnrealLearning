/*******************************************************************************\
** File: IGCloudVoiceEngineNotify.h
** Module: GVoice
** Version: 1.0
** Author: CZ
\*******************************************************************************/

#ifndef _GCloud_GVoice_IGCloudVoiceNotify_h
#define _GCloud_GVoice_IGCloudVoiceNotify_h

#include "GCloudVoiceErrno.h"

namespace GCloud
{
    namespace GVoice
    {
        /**
         * IGCloudVoiceNotify is a notify for voice engine. You should implemtation it to get the message.
         */
        class GCLOUD_VOICE_API IGCloudVoiceNotify
        {
        public:
            virtual ~IGCloudVoiceNotify() {};
            
        public:
            // Real-Time Callback
            /**
             * Callback when JoinXxxRoom successful or failed.
             *
             * @param code : a GCloudVoiceCompleteCode code . You should check this first.
             * @param roomName : name of your joining, should be 0-9A-Za-Z._- and less than 127 bytes
             * @param memberID : if success, return the memberID
             */
            virtual void OnJoinRoom(CompleteCode code, const char *roomName, int memberID) = 0;
            
            /**
             * Callback when dropped from the room
             *
             * @param code : a GCloudVoiceCompleteCode code . You should check this first.
             * @param roomName : name of your joining, should be 0-9A-Za-Z._- and less than 127 bytes
             * @param memberID : if success, return the memberID
             */
            virtual void OnStatusUpdate(CompleteCode status, const char *roomName, int memberID) = 0;
            
            /**
             * Callback when QuitRoom successful or failed.
             *
             * @param code : a GCloudVoiceCompleteCode code . You should check this first.
             * @param roomName : name of your joining, should be 0-9A-Za-Z._- and less than 127 bytes
             */
            virtual void OnQuitRoom(CompleteCode code, const char *roomName) = 0;
            
            /**
             ** Deprecate from GVoice 1.1.14
             * Callback when someone saied or silence in the same room.
             *
             * @param count: count of members who's status has changed.
             * @param members: a int array composed of [memberid_0, status,memberid_1, status ... memberid_2*count, status]
             * here, status could be 0, 1, 2. 0 meets silence and 1/2 means saying
             */
            virtual void OnMemberVoice    (const unsigned int *members, int count) = 0;
            
            
            /**
             * Callback when someone saied or silence in the same room.
             *
             * @param roomName: name of the room.
             * @param member: the member's ID
             * @param status : status could be 0, 1, 2. 0 meets silence and 1/2 means saying
             */
            virtual void OnMemberVoice (const char *roomName, unsigned int member, int status) = 0;
            
            // Voice Message Callback
            /**
             * Callback when upload voice file successful or failed.
             *
             * @param code: a GCloudVoiceCompleteCode code . You should check this first.
             * @param filePath: file to upload
             * @param fileID: if success ,get back the id for the file.
             */
            virtual void OnUploadFile(CompleteCode code, const char *filePath, const char *fileID) = 0;
            
            /**
             * Callback when download voice file successful or failed.
             *
             * @param code: a GCloudVoiceCompleteCode code . You should check this first.
             * @param filePath: file to download to .
             * @param fileID: if success ,get back the id for the file.
             */
            virtual void OnDownloadFile(CompleteCode code, const char *filePath, const char *fileID) = 0;
            
            /**
             * Callback when finish a voice file play end.
             *
             * @param code: a GCloudVoiceCompleteCode code . You should check this first.
             * @param filePath: file had been plaied.
             */
            virtual void OnPlayRecordedFile(CompleteCode code,const char *filePath) = 0;
            
            /**
             * Callback when query message key successful or failed.
             *
             * @param code: a GCloudVoiceCompleteCode code . You should check this first.
             */
            virtual void OnApplyMessageKey(CompleteCode code) = 0;
            
            // Translate
            /**
             * Callback when translate voice to text successful or failed.
             *
             * @param code: a GCloudVoiceCompleteCode code . You should check this first.
             * @param fileID : file to translate
             * @param result : the destination text of the destination language.
             */
            virtual void OnSpeechToText(CompleteCode code, const char *fileID, const char *result) = 0;
            
            /**
             * Callback when client is using microphone recording audio
             *
             * @param pAudioData : audio data pointer
             * @param nDataLength : audio data length
             * @param result : void
             */
            virtual void OnRecording(const unsigned char* audioData, unsigned int dataLength) = 0;
            
            /**
             * Callback when translate voice to text successful or failed.
             */
            virtual void OnStreamSpeechToText(CompleteCode code, int error, const char *result, const char *voicePath) = 0;
            
            /**
             * Callback when change to another role
             */
            virtual void OnRoleChanged(CompleteCode code, const char *roomName, int memberID, int role) = 0;
            
            /**
             * event Callback. e.g. the device connect Event,the device disconcet Event
             */
            virtual void OnEvent(Event event, const char * info) = 0;
        };

    } // endof namespace GVoice
} // endof namespace GCloud
#endif /* _GCloud_GVoice_IGCloudVoiceNotify_h */
