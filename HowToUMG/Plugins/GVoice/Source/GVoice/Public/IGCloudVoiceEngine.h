/*******************************************************************************\
 ** File: IGCloudVoiceEngine.h
 ** Module: GVoice
 ** Version: 1.0
 ** Author: CZ 
 **
 **  Copyright © 2016年 apollo. All rights reserved.
 \*******************************************************************************/

#ifndef _GCloud_GVoice_IGCloudVoiceEngine_h
#define _GCloud_GVoice_IGCloudVoiceEngine_h

#include <stdint.h>
#include <stdlib.h>
#include <string.h>


#include "IGCloudVoiceEngineNotify.h"
#include "IGCloudVoiceExtension.h"




typedef void (*GVoiceLogFunc) (const char *str);

namespace GCloud
{
    namespace GVoice
    {
        class IGCloudVoiceEngine : public IGCloudVoiceEngineExtension
        {
        public:
            
            /**
             * Destination language to translate to.
             */
            enum Language
            {
                kLanguageChina       = 0,
                kLanguageKorean      = 1,
                kLanguageEnglish     = 2,
                kLanguageJapanese    = 3,
            };
            
            /**
             * Mode of voice engine.
             *
             * You should set to one first.
             */
            enum Mode
            {
                kModeRealTime = 0, // realtime mode for TeamRoom or NationalRoom
                kModeMessages,     // voice message mode
                kModeTranslation,  // speach to text mode
                kModeRSTT, // real-time speach to text mode
            };
            /**
             * Mode of voice effects.
             *
             * You should set to one first.
             */
            enum SoundEffects
            {
                kSoundEffectsRevbChurch     = 0,
                kSoundEffectsRevbTheater    = 1,
                kSoundEffectsHell           = 2,
                kSoundEffectsRobot1         = 3,
                kSoundEffectsMaleToFemale   = 4,
                kSoundEffectsFemaleToMale   = 5,
                kSoundEffectsDrunk          = 6,
                kSoundEffectsPapiJiang      = 7,
                kSoundEffectsSquirrel       = 8,
                kSoundEffectsNoEffect       = 9,
            };
            
            /**
             * Member's role for National Room.
             */
            enum MemberRole
            {
                kMemberRoleAnchor = 1, // member who can open microphone and say
                kMemberRoleAudience,   // member who can only hear anchor's voice
            };
            
            /**
             * Set the server address, just used for foreign game,such as Korea, Europe...
             *
             * @param URL: url of server
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo SetServerInfo(const char * URL) = 0;
            
            /**
             * Set your app's info such as appID/appKey.
             *
             * @param appID : your game ID from gcloud.qq.com
             * @param appKey : your game key from gcloud.qq.com
             * @param openID : player's openID from QQ or Wechat. or a unit role ID.
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo SetAppInfo(const char *appID,const char *appKey, const char *openID) = 0;

            /**
             * Init the voice engine.
             *
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo Init() = 0;
            
            /**
             * Set the notify to engine.
             *
             * @param notify: the notify
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo SetNotify(IGCloudVoiceNotify *notify) = 0;
            
            /**
             * Set the mode for engine.
             *
             * @param mode: mode to set
             *              RealTime:    realtime mode for TeamRoom or NationalRoom
             *              Messages:    voice message mode
             *              Translation: speach to text mode
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo SetMode(Mode mode) = 0;
            
            /**
             * Trigger engine's callback.
             *
             * You should invoke poll on your loop. such as onUpdate() in cocos2dx
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo Poll() = 0;
            
            /**
             * The Application's Pause.
             *
             * When your app pause such as goto backend you should invoke this
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo Pause() = 0;
            
            /**
             * The Application's Resume.
             *
             * When your app reuse such as come back from  backend you should invoke this
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo Resume() = 0;
            
            
            //Real-Time Voice API
        public:
            /**
             * Join in team room.
             *
             * @param roomName: the room to join, should be less than 127byte, composed by alpha.
             * @param msTimeout: time for join, it is micro second. value range[5000, 60000]
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo JoinTeamRoom(const char *roomName, int msTimeout = 10000) = 0;
            

            /**
             * Join in a LBS room.
             *
             * @param roomName: the room to join, should be less than 127byte, composed by alpha.
             * @param msTimeout: time for join, it is micro second. value range[5000, 60000]
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo JoinRangeRoom(const char *roomName, int msTimeout = 10000) = 0;
            
            /**
             * Update your coordinate
             *
             * @param roomName: the room to update, should be less than 127byte, composed by alpha.
             * @param x: the x coordinate
             * @param y: the y coordinate
             * @param z: the z coordinate
             * @param r: the audience's radius
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo UpdateCoordinate(const char *roomName, int64_t x, int64_t y, int64_t z, int64_t r) = 0;
            
            /**
             * Join in a national room.
             *
             * @param roomName: the room to join, should be less than 127byte, composed by alpha.
             * @param role : a GCloudVoiceMemberRole value illustrate wheather can send voice data.
             * @param msTimeout: time for join, it is micro second. value range[5000, 60000]
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo JoinNationalRoom(const char *roomName, MemberRole role, int msTimeout = 10000) = 0;
            
            
            /**
             * Join in a FM room.
             *
             * @param roomID: the room to join, should be less than 127byte, composed by alpha.
             * @param msTimeout: time for join, it is micro second. value range[5000, 60000]
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             */
            virtual ErrorNo JoinFMRoom(const char *roomID, int msTimeout = 10000) = 0;
            
            /**
             * Quit the voice room.
             *
             * @param roomName: the room to join, should be less than 127byte, composed by alpha.
             * @param msTimeout: time for quit, it is micro second.value range[5000, 60000]
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo QuitRoom(const char *roomName, int msTimeout = 10000) = 0;
            
            /**
             * Change member's role in the room
             *
             * @param roomName: the room to change, should be less than 127byte, composed by alpha.
             * @param role: member's role for change to
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo ChangeRole(MemberRole role, const char *roomName="") = 0;
            
            /**
             * Open player's micro phone  and begin to send player's voice data.
             *
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo OpenMic() = 0;
            
            /**
             * Close players's micro phone and stop to send player's voice data.
             *
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo CloseMic() = 0;
            
            /**
             * Open player's speaker and begin recvie voice data from the net .
             *
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo OpenSpeaker() = 0;
            
            /**
             * Close player's speaker and stop to recive voice data from the net.
             *
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo CloseSpeaker() = 0;
            
            /**
             * enable a client join in multi rooms.
             *
             * this may cause higher bitrate
             *
             * @param enable : ture for open and false for close
             * @return if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             */
            virtual ErrorNo EnableMultiRoom(bool enable) = 0;
            
            /**
             * Close or Open microphone for the room
             *
             * @param roomName : the room
             * @param enable : ture for open and false for close
             * @return if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             */
            virtual ErrorNo EnableRoomMicrophone(const char *roomName, bool enable) = 0;
            
            /**
             * Close or Open speaker for the room
             *
             * @param roomName : the room
             * @param enable : ture for open and false for close
             * @return if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             */
            virtual ErrorNo EnableRoomSpeaker(const char *roomName, bool enable) = 0;
            
            //Messages Voice API
        public:
            /**
             * Apply the key for voice message.
             *
             * @param msTimeout: time for apply, it is micro second.value range[5000, 60000]
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo ApplyMessageKey(int msTimeout = 10000) = 0;
            
            /**
             * Limit the max voice message's last time.
             *
             * @param msTime : message's largest time in micro second.value range[1000, 2*60*1000]
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo SetMaxMessageLength(int msTime) = 0;
            
            /**
             * Open player's microphone and record player's voice.
             *
             * @param filePath: voice data to store. file path should be such as:"your_dir/your_file_name" be sure to use "/" not "\"
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo StartRecording(const char * filePath, bool notVoip = false) = 0;
            
            /**
             * Stop player's microphone and stop record player's voice.
             *
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo StopRecording () = 0;
            
            
            /**
             * Upload player's voice message file to the net.
             *
             * @param filePath: voice data to upload. file path should be such as "your_dir/your_file_name" be sure to use "/" not "\"
             * @param msTimeout: time for upload, it is micro second.value range[5000, 60000]
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo UploadRecordedFile(const char * filePath, int msTimeout = 60000, bool permanent = false) = 0;
            
            /**
             * Download other players' voice message.
             *
             * @param fileID : file to be download
             * @param filePath: voice data to store. file path should be such as "your_dir/your_file_name" be sure to use "/" not "\"
             * @param msTimeout: time for download, it is micro second.value range[5000, 60000]
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo DownloadRecordedFile (const char *fileID, const char * downloadFilePath, int msTimeout = 60000, bool permanent = false) = 0;
            
            /**
             * Play local voice message file.
             *
             * @param filePath: voice data to play. file path should be such as:"your_dir/your_file_name" be sure to use "/" not "\"
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo PlayRecordedFile (const char * downloadFilePath) = 0;
            
            /**
             * Stop play the file.
             *
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo StopPlayFile () = 0;


            virtual ErrorNo  EnableSpeakerOn(bool enable) = 0;
            
        public:
            /**
             * Translate voice data to text.
             *
             * @param fileID : file to be translate
             * @param msTimeout : timeout for translate
             * @param language: a GCloudLanguage indicate which language to be translate
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo SpeechToText(const char *fileID, int msTimeout = 60000,  Language language = kLanguageChina) = 0;
            
            
        public: // if needed
            virtual ErrorNo JoinTeamRoom(const char *roomName, const char *token, int timestamp, int msTimeout = 10000) = 0;
            
            
            virtual ErrorNo JoinNationalRoom(const char *roomName, MemberRole role, const char *token, int timestamp, int msTimeout = 10000) = 0;
            
            virtual ErrorNo ApplyMessageKey(const char *token, int timestamp, int msTimeout = 10000) = 0;
            
            virtual ErrorNo SpeechToText(const char *fileID, const char *token, int timestamp, int msTimeout = 60000,  Language language = kLanguageChina) = 0;

        public:
            virtual ErrorNo StartBlueTooth() = 0;
            virtual ErrorNo StopBlueTooth() =0;
            virtual void DeviceEventNotify(int eventId, const char *info)=0;
            
            virtual ErrorNo    SetMicVolume(int volume) = 0;
            /*
                this function sets sound effects mode
                @param:mode : kSoundEffectsRevbChurch for reveb church effect
                            : kSoundEffectsRevbTheater for reveb theater effect
                            : kSoundEffectsHell for voice from hell effect
                            : kSoundEffectsRobot1 for robot voice effect
                            : kSoundEffectsMaleToFemale for voice from male to female effect
                            : kSoundEffectsFemaleToMale for voice from female to male effect
                            : kSoundEffectsDrunk for drunk voice effect
                            : kSoundEffectsPapiJiang for Chinese papi-Jiang voice effect
                            : kSoundEffectsSquirrel for squrrel voice effect
                            : kSoundEffectsNoEffect for NO voice effect
                @result:GCLOUD_VOICE_SUCC for succ,otherwise failed
            */
            virtual ErrorNo    SetVoiceEffects(SoundEffects mode) = 0;

            virtual int    EnableReverb(bool enable) = 0;

            /*
                mode: 0~3
            */
            virtual int    SetReverbMode(int mode) = 0;

            /*
                result : 0 : women   1: men  2:no people   -1 :error
            */
            
            virtual int    GetVoiceIdentify() = 0;

            virtual void SetHeadSetState(bool state) =0;

            virtual void SetBluetoothState(bool state) =0;

            virtual DeviceState  GetAudioDeviceConnectionState() = 0;

        public:
            virtual ErrorNo SetBGMPath(const char * path) =0;
            virtual ErrorNo StartBGMPlay() =0;
            virtual ErrorNo SetBGMVol(int volume) =0;
            virtual ErrorNo StopBGMPlay() =0;
            virtual ErrorNo PauseBGMPlay() =0;
            virtual ErrorNo ResumeBGMPlay() =0;
            virtual ErrorNo EnableNativeBGMPlay(bool enable) =0;
            virtual int GetBGMPlayState() =0;

            virtual ErrorNo SetBitRate(int bitrate) = 0;

        /*
            return 0 or 1;  0 : no howling   1: have howling
        */
            virtual int  GetHwState() = 0;
            
            
            /**
             * Set if it is datafree.
             *
             * @param enable: true enable datafree
             * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see ErrorNo
             * @see : ErrorNo
             */
            virtual ErrorNo SetDataFree(bool enable) = 0;

            virtual ErrorNo SetLogCallBack(GVoiceLogFunc logFunc) = 0;
            
        };
        
        /**
         * Get the voice engine instance.
         *
         * @return : the voice instance on success, or NULL on failed.
         */
        extern "C" GCLOUD_VOICE_API IGCloudVoiceEngine *GetVoiceEngine();

                /**
         * Get the voice engine instance, diff from GetVoiceEngine, if voiceengine not create it will return null
         *
         * @return : the voice instance or NULL.
         */
        extern "C" GCLOUD_VOICE_API IGCloudVoiceEngine *GetVoiceEngine_OrNull();
        
        
    } // endof namespace GVoice
} // endof namespace GCloud

#endif /* _GCloud_GVoice_IGCloudVoiceEngine_h */
