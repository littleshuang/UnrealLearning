/*******************************************************************************\
 ** File: GCloudVoiceErrno.h
 ** Module: GVoice
 ** Version: 1.0
 ** Author: CZ
 \*******************************************************************************/

#ifndef _GCloud_GVoice_GCloudVoiceErrno_h
#define _GCloud_GVoice_GCloudVoiceErrno_h

#if defined(WIN32) || defined(_WIN32)
    #ifdef GCLOUD_VOICE_EXPORTS
        #define GCLOUD_VOICE_API __declspec(dllexport)
    #else
        #define GCLOUD_VOICE_API __declspec(dllimport)
    #endif
#else
    #if defined __ANDROID__
        #define GCLOUD_VOICE_API __attribute__ ((visibility ("default")))
    #else
        #define GCLOUD_VOICE_API
    #endif
#endif

namespace GCloud
{
    namespace GVoice
    {
        enum ErrorNo
        {
            kErrorNoSucc           = 0, //0, no error
            
            //common base err
            kErrorNoParamNULL         = 0x1001, //4097, some param is null
            kErrorNoNeedSetAppInfo    = 0x1002, //4098, you should call SetAppInfo first before call other api
            kErrorNoInitErr           = 0x1003, //4099, Init Erro
            kErrorNoRecordingErr      = 0x1004, //4100, now is recording, can't do other operator
            kErrorNoPollBuffErr       = 0x1005, //4101, poll buffer is not enough or null
            kErrorNoModeStateErr      = 0x1006, //4102, call some api, but the mode is not correct, maybe you shoud call SetMode first and correct
            kErrorNoParamInvalid      = 0x1007, //4103, some param is null or value is invalid for our request, used right param and make sure is value range is correct by our comment
            kErrorNoOpenFileErr       = 0x1008,   //4104, open a file err
            kErrorNoNeedInit          = 0x1009,   //4105, you should call Init before do this operator
            kErrorNoEngineErr         = 0x100A,   //4106, you have not get engine instance, this common in use c# api, but not get gcloudvoice instance first
            kErrorNoPollMsgParseErr = 0x100B,   //4107, this common in c# api, parse poll msg err
            kErrorNoPollMsgNo        = 0x100C,   //4108, poll, no msg to update


            //realtime err
            kErrorNoRealtimeStateErr        = 0x2001,   //8193, call some realtime api, but state err, such as OpenMic but you have not Join Room first
            kErrorNoJoinErr                 = 0x2002,   //8194, join room failed
            kErrorNoQuitRoomNameErr         = 0x2003,   //8195, quit room err, the quit roomname not equal join roomname
            kErrorNoOpenMicNotAnchorErr     = 0x2004,//8196, open mic in bigroom,but not anchor role
            kErrorNoCreateRoomErr           = 0x2005, // 8197, create room error
            kErrorNoNoRoom                  = 0x2006, // 8198, no such room
            kErrorNoQuitRoomErr             = 0x2007, //8199, quit room error
            kErrorNoAlreadyInTheRoom        = 0x2008, // 8200, already in the room which in JoinXxxxRoom

            //message err
            kErrorNoAuthKeyErr              = 0x3001,   //12289, apply authkey api error
            kErrorNoPathAccessErr           = 0x3002,   //12290, the path can not access ,may be path file not exists or deny to access
            kErrorNoPermissionMicErr        = 0x3003, //12291, you have not right to access micphone in android
            kErrorNoNeedAuthKey             = 0x3004, //12292,you have not get authkey, call ApplyMessageKey first
            kErrorNoUploadErr               = 0x3005, //12293, upload file err
            kErrorNoHttpBusy                = 0x3006, //12294, http is busy,maybe the last upload/download not finish.
            kErrorNoDownloadErr             = 0x3007, //12295, download file err
            kErrorNoSpeakerErr              = 0x3008,   //12296, open or close speaker tve error
            kErrorNoTVEPlaySoundErr         = 0x3009,   //12297, tve play file error
            kErrorNoAuthing                 = 0x300a,   // 12298, Already in applying auth key processing
            kErrorNoLimit                   = 0x300b,   //12299, upload limit

            kErrorNoInternalTVEErr          = 0x5001, //20481, internal TVE err, our used
            kErrorNoInternalVisitErr        = 0x5002, //20482, internal Not TVE err, out used
            kErrorNoInternalUsed            = 0x5003, //20483, internal used, you should not get this err num
            
            kErrorNoBadServer               = 0x06001, // 24577, bad server address,should be "udp://capi.xxx.xxx.com"
            
            kErrorNoSTTing                  =  0x07001, // 28673, Already in speach to text processing
            
            kErrorNoChangeRole              = 0x08001, // 32769, change role error
            kErrorNoChangingRole            = 0x08002, // 32770, is in changing role
            kErrorNoNotInRoom               = 0x08003, // 32771, no in room
            kErrorNoCoordinate              = 0x09001, // 36865, sync coordinate error
            kErrorNoSmallRoomName           = 0x09002, // 36866, query with a small roomname
        };
    
        enum CompleteCode
        {
            kCompleteCodeJoinRoomSucc = 1, //join room succ
            kCompleteCodeJoinRoomTimeout,  //join room timeout
            kCompleteCodeJoinRoomSVRErr,  //communication with svr occur some err, such as err data recv from svr
            kCompleteCodeJoinRoomUnknown, //reserved, our internal unknow err

            kCompleteCodeNetErr,  //net err,may be can't connect to network

            kCompleteCodeQuitRoomSucc, //quitroom succ, if you have join room succ first, quit room will alway return succ

            kCompleteCodeMessageKeyAppliedSucc,  //apply message authkey succ
            kCompleteCodeMessageKeyAppliedTimeout, //apply message authkey timeout
            kCompleteCodeMessageKeyAppliedSVRErr,  //communication with svr occur some err, such as err data recv from svr
            kCompleteCodeMessageKeyAppliedUnknown,  //reserved,  our internal unknow err

            kCompleteCodeUploadRecordDone,  //upload record file succ
            kCompleteCodeUploadRecordError,  //upload record file occur error
            kCompleteCodeDownloadRecordDone, //download record file succ
            kCompleteCodeDownloadRecordError, //download record file occur error

            kCompleteCodeSTTSucc, // speech to text successful
            kCompleteCodeSTTTimeout, // speech to text with timeout
            kCompleteCodeSTTAPIErr, // server's error
            
            kCompleteCodeRSTTSucc, // speech to text successful
            kCompleteCodeRSTTTimeout, // speech to text with timeout
            kCompleteCodeRSTTAPIErr, // server's error
            
            kCompleteCodePlayFileDone,  //the record file played end
            
            kCompleteCodeRoomOffline, // Dropped from the room
            kCompleteCodeUnknown,
            kCompleteCodeRoleSucc,    // Change Role Success
            kCompleteCodeRoleTimeout, // Change Role with tiemout
            kCompleteCodeRoleMaxAnchor, // To much Anchor
            kCompleteCodeRoleNoChange, // The same role
            kCompleteCodeRoleSvrErr, // server's error
            
            kCompleteCodeRSTTRetry, // need retry stt
        };
    
        /**
         * Event of GCloudVoice.
         *
         */
        enum Event
        {
            kEventNoDeviceConnected             = 0, // not any device is connected
            kEventHeadsetDisconnected           = 10, // a headset device is connected
            kEventHeadsetConnected              = 11, // a headset device is disconnected
            kEventBluetoothHeadsetDisconnected  = 20, // a bluetooth device is connected
            kEventBluetoothHeadsetConnected     = 21, // a bluetooth device is disconnected
            kEventMicStateOpenSucc              = 30, // open microphone
            kEventMicStateOpenErr               = 31, // open microphone
            kEventMicStateNoOpen                = 32, // close micrphone
            kEventSpeakerStateOpenSucc          = 40, // open speaker
            kEventSpeakerStateOpenErr           = 41, // open speaker error
            kEventSpeakerStateNoOpen            = 42, // close speaker
        };
    
        /**
         * Event of GCloudVoice.
         *
         */
        enum DeviceState
        {
            kDeviceStateUnconnected             = 0, // not any audio device is connected
            kDeviceStateWriteHeadsetConnected   = 1, // have a wiredheadset device is connected
            kDeviceStateBluetoothConnected      = 2, // have a bluetooth device is disconnected
        };
        
    } // endof namespace GVoice
} // endof namespace GCloud

#endif /* _GCloud_GVoice_GCloudVoiceErrno_h */
