/*******************************************************************************\
** GCloudVoice:GVoice.h Objective-C API for GCloudVoice
** Created by CZ  on 23/05/2017
**
**  Copyright © 2017 gcloud. All rights reserved.
\*******************************************************************************/

#ifndef _GCloud_GVoice_GCloudVoice_h
#define _GCloud_GVoice_GCloudVoice_h

#ifdef __APPLE__
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, GCVErrorNo) {
    kErrorNoSucc           = 0, //0, no error
    
    //common base err
    kErrorNoParamNULL         = 0x1001,    //4097, some param is null
    kErrorNoNeedSetAppInfo    = 0x1002,    //4098, you should call SetAppInfo first before call other api
    kErrorNoInitErr           = 0x1003,    //4099, Init Erro
    kErrorNoRecordingErr      = 0x1004,    //4100, now is recording, can't do other operator
    kErrorNoPollBuffErr       = 0x1005,    //4101, poll buffer is not enough or null
    kErrorNoModeStateErr      = 0x1006,    //4102, call some api, but the mode is not correct, maybe you shoud call SetMode first and correct
    kErrorNoParamInvalid      = 0x1007,    //4103, some param is null or value is invalid for our request, used right param and make sure is value range is correct by our comment
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
    kErrorNoPermissionMicErr        = 0x3003,    //12291, you have not right to access micphone in android
    kErrorNoNeedAuthKey             = 0x3004,    //12292,you have not get authkey, call ApplyMessageKey first
    kErrorNoUploadErr               = 0x3005,    //12293, upload file err
    kErrorNoHttpBusy                = 0x3006,    //12294, http is busy,maybe the last upload/download not finish.
    kErrorNoDownloadErr             = 0x3007,    //12295, download file err
    kErrorNoSpeakerErr              = 0x3008,   //12296, open or close speaker tve error
    kErrorNoTVEPlaySoundErr         = 0x3009,   //12297, tve play file error
    kErrorNoAuthing                 = 0x300a,   // 12298, Already in applying auth key processing
    kErrorNoLimit                   = 0x300b,   //12299, upload limit
    
    kErrorNoInternalTVEErr          = 0x5001,        //20481, internal TVE err, our used
    kErrorNoInternalVisitErr        = 0x5002,    //20482, internal Not TVE err, out used
    kErrorNoInternalUsed            = 0x5003, //20483, internal used, you should not get this err num
    
    kErrorNoBadServer               = 0x06001, // 24577, bad server address,should be "udp://capi.xxx.xxx.com"
    
    kErrorNoSTTing                  =  0x07001, // 28673, Already in speach to text processing
    
    kErrorNoChangeRole              = 0x08001, // 32769, change role error
    kErrorNoChangingRole            = 0x08002, // 32770, is in changing role
    kErrorNoNotInRoom               = 0x08003, // 32771, no in room
    kErrorNoCoordinate              = 0x09001, // 36865, sync coordinate error
    kErrorNoSmallRoomName           = 0x09002, // 36866, query with a small roomname
};


typedef NS_ENUM(NSUInteger, GCVCompleteCode) {
    kCompleteCodeJoinRoomSucc = 1,    //join room succ
    kCompleteCodeJoinRoomTimeout,  //join room timeout
    kCompleteCodeJoinRoomSVRErr,  //communication with svr occur some err, such as err data recv from svr
    kCompleteCodeJoinRoomUnknown, //reserved, our internal unknow err
    
    kCompleteCodeNetErr,  //net err,may be can't connect to network
    
    kCompleteCodeQuitRoomSucc, //quitroom succ, if you have join room succ first, quit room will alway return succ
    
    kCompleteCodeMessageKeyAppliedSucc,  //apply message authkey succ
    kCompleteCodeMessageKeyAppliedTimeout,        //apply message authkey timeout
    kCompleteCodeMessageKeyAppliedSVRErr,  //communication with svr occur some err, such as err data recv from svr
    kCompleteCodeMessageKeyAppliedUnknown,  //reserved,  our internal unknow err
    
    kCompleteCodeUploadRecordDone,  //upload record file succ
    kCompleteCodeUploadRecordError,  //upload record file occur error
    kCompleteCodeDownloadRecordDone,    //download record file succ
    kCompleteCodeDownloadRecordError,    //download record file occur error
    
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
 * Destination language to translate to.
 */

typedef NS_ENUM(NSUInteger, GCVLanguage) {
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
typedef NS_ENUM(NSUInteger, GCVMode) {
    kModeRealTime = 0, // realtime mode for TeamRoom or NationalRoom
    kModeMessages,     // voice message mode
    kModeTranslation,  // speach to text mode
    kModeRSTT, // real-time speach to text mode
};

/**
 * Member's role for National Room.
 */
typedef NS_ENUM(NSUInteger, GCVMemberRole) {
    kMemberRoleAnchor = 1, // member who can open microphone and say
    kMemberRoleAudience,   // member who can only hear anchor's voice
};


//Voice Effects Mode
typedef NS_ENUM(NSUInteger, GCVSoundEffects) {
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
 * Event of GCloudVoice.
 *
 */
typedef NS_ENUM(NSUInteger, GCVEvent) {
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
typedef NS_ENUM(NSUInteger, GCVDeviceState) {
    kDeviceStateUnconnected             = 0, // not any audio device is connected
    kDeviceStateWriteHeadsetConnected   = 1, // have a wiredheadset device is connected
    kDeviceStateBluetoothConnected      = 2, // have a bluetooth device is disconnected
};


@protocol GCVVoiceEngineDelegate <NSObject>


/**
 * Callback when JoinXxxRoom successful or failed.
 *
 * @param code : a GCloudVoiceCompleteCode code . You should check this first.
 * @param roomName : name of your joining, should be 0-9A-Za-Z._- and less than 127 bytes
 * @param memberID : if success, return the memberID
 */
- (void) onJoinRoom:(GCVCompleteCode) code withRoomName: (NSString *_Nullable)roomName andMemberID:(NSUInteger) memberID;

/**
 * Callback when dropped from the room
 *
 * @param code : a GCloudVoiceCompleteCode code . You should check this first.
 * @param roomName : name of your joining, should be 0-9A-Za-Z._- and less than 127 bytes
 * @param memberID : if success, return the memberID
 */
- (void) onStatusUpdate:(GCVCompleteCode) status withRoomName: (NSString *)roomName andMemberID:(NSUInteger) memberID;

/**
 * Callback when QuitRoom successful or failed.
 *
 * @param code : a GCloudVoiceCompleteCode code . You should check this first.
 * @param roomName : name of your joining, should be 0-9A-Za-Z._- and less than 127 bytes
 */
- (void) onQuitRoom:(GCVCompleteCode) code withRoomName: (NSString *)roomName;

/**
 * Callback when someone saied or silence in the same room.
 *
 * @param count: count of members who's status has changed.
 * @param members: a int array composed of [memberid_0, status,memberid_1, status ... memberid_2*count, status]
 * here, status could be 0, 1, 2. 0 meets silence and 1/2 means saying
 */
- (void) onMemberVoice:	(NSArray *)members withCount: (NSInteger) count;



/**
 * Callback when someone saied or silence in the same room.
 *
 * @param roomName: name of the room.
 * @param member: the member's ID
 * @param status : status could be 0, 1, 2. 0 meets silence and 1/2 means saying
 */
- (void) onMemberVoice:(NSString *)roomName	member:(NSUInteger)member withStatus: (NSInteger) status;

// Voice Message Callback
/**
 * Callback when upload voice file successful or failed.
 *
 * @param code: a GCloudVoiceCompleteCode code . You should check this first.
 * @param filePath: file to upload
 * @param fileID: if success ,get back the id for the file.
 */
- (void) onUploadFile: (GCVCompleteCode) code withFilePath: (NSString *)filePath andFileID:(NSString *)fileID ;

/**
 * Callback when download voice file successful or failed.
 *
 * @param code: a GCloudVoiceCompleteCode code . You should check this first.
 * @param filePath: file to download to .
 * @param fileID: if success ,get back the id for the file.
 */
- (void) onDownloadFile: (GCVCompleteCode) code  withFilePath: (NSString *)filePath andFileID:(NSString *)fileID;

/**
 * Callback when finish a voice file play end.
 *
 * @param code: a GCloudVoiceCompleteCode code . You should check this first.
 * @param filePath: file had been plaied.
 */
- (void) onPlayRecordedFile:(GCVCompleteCode) code withFilePath: (NSString *)filePath;

/**
 * Callback when query message key successful or failed.
 *
 * @param code: a GCloudVoiceCompleteCode code . You should check this first.
 */
- (void) onApplyMessageKey:(GCVCompleteCode) code;

// Translate
/**
 * Callback when translate voice to text successful or failed.
 *
 * @param code: a GCloudVoiceCompleteCode code . You should check this first.
 * @param fileID : file to translate
 * @param result : the destination text of the destination language.
 */
- (void) onSpeechToText:(GCVCompleteCode) code withFileID:(NSString *)fileID andResult:(NSString *)result;

/**
 * Callback when client is using microphone recording audio
 *
 * @param pAudioData : audio data pointer
 * @param nDataLength : audio data length
 * @param result : void
 */
- (void) onRecording:(const unsigned char* _Nullable) pAudioData withLength: (unsigned int) nDataLength;


/**
 * Callback when translate voice to text successful or failed.
 */
- (void) onStreamSpeechToText:(GCVCompleteCode) code withError:(NSUInteger) error andResult:(NSString *)result forPath:(NSString *)voicePath;

/**
 * Callback when change to another role
 */
- (void) onRoleChanged:(GCVCompleteCode) code inRoom:(NSString *)roomName withMember:(NSUInteger) memberID forRole:(GCVMemberRole) role;

/**
 * event Callback
 */
- (void) onEvent:(GCVEvent) event forInfo:(NSString *) info;

@end

@interface GCVVoiceEngine : NSObject
+ (GCVVoiceEngine* _Nullable) sharedInstance;

@property (nonatomic, weak, nullable) id <GCVVoiceEngineDelegate> delegate;


/**
 * Set the server address, just used for foreign game,such as Korea, Europe...
 *
 * @param URL: url of server
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) setServerInfo:(NSString *) URL;

/**
 * Set your app's info such as appID/appKey.
 *
 * @param appID : your game ID from gcloud.qq.com
 * @param appKey : your game key from gcloud.qq.com
 * @param openID : player's openID from QQ or Wechat. or a unit role ID.
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) setAppInfo:(NSString *) appID withKey: (NSString *)appKey andOpenID:(NSString *)openID;

/**
 * Init the voice engine.
 *
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) initEngine;

/**
 * Set the mode for engine.
 *
 * @param mode: mode to set
 *              RealTime:    realtime mode for TeamRoom or NationalRoom
 *              Messages:    voice message mode
 *              Translation: speach to text mode
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) setMode:(GCVMode) mode;

/**
 * Trigger engine's callback.
 *
 * You should invoke poll on your loop. such as onUpdate() in cocos2dx
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) poll;

/**
 * The Application's Pause.
 *
 * When your app pause such as goto backend you should invoke this
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) pause;

/**
 * The Application's Resume.
 *
 * When your app reuse such as come back from  backend you should invoke this
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) resume;


#pragma mark Real-Time Voice API
/**
 * Join in team room.
 *
 * @param roomName: the room to join, should be less than 127byte, composed by alpha.
 * @param msTimeout: time for join, it is micro second. value range[5000, 60000]
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) joinTeamRoom:(NSString *)roomName timeout: (NSInteger) msTimeout;

/**
 * Join in a LBS room.
 *
 * @param roomName: the room to join, should be less than 127byte, composed by alpha.
 * @param msTimeout: time for join, it is micro second. value range[5000, 60000]
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) joinRangeRoom:(NSString *)roomName timeout: (NSInteger) msTimeout;

/**
 * Update your coordinate
 *
 * @param x: the x coordinate
 * @param y: the y coordinate
 * @param z: the z coordinate
 * @param r: the audience's radius
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) updateCoordinate:(NSString *)roomName x:(NSInteger) x  y:(NSInteger) y  z:(NSInteger) z r:(NSInteger) r ;


/**
 * Join in a national room.
 *
 * @param roomName: the room to join, should be less than 127byte, composed by alpha.
 * @param role : a GCloudVoiceMemberRole value illustrate wheather can send voice data.
 * @param msTimeout: time for join, it is micro second. value range[5000, 60000]
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) joinNationalRoom:(NSString *)roomName role: (GCVMemberRole) role timeout: (NSInteger) msTimeout;


/**
 * Join in a FM room.
 *
 * @param roomName: the room to join, should be less than 127byte, composed by alpha.
 * @param msTimeout: time for join, it is micro second. value range[5000, 60000]
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 */
- (GCVErrorNo) joinFMRoom:(NSString *)roomName timeout:(NSInteger) msTimeout;

/**
 * Change member's role in the room
 *
 * @param role: member's role for change to
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) ChangeRole:(GCVMemberRole) role inRoom:(NSString *)roomName;
- (GCVErrorNo) ChangeRole:(GCVMemberRole) role ;

/**
 * Quit the voice room.
 *
 * @param roomName: the room to join, should be less than 127byte, composed by alpha.
 * @param msTimeout: time for quit, it is micro second.value range[5000, 60000]
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) quitRoom:(NSString *)roomName timeout:(NSInteger) msTimeout ;

/**
 * Open player's micro phone  and begin to send player's voice data.
 *
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) openMic;

/**
 * Close players's micro phone and stop to send player's voice data.
 *
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) closeMic;

/**
 * Open player's speaker and begin recvie voice data from the net .
 *
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) openSpeaker;

/**
 * Close player's speaker and stop to recive voice data from the net.
 *
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) closeSpeaker;


/**
 * Close or Open microphone for the room
 *
 * @param roomName : the room
 * @param enable : ture for open and false for close
 * @return if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 */
- (GCVErrorNo) enableRoomMicrophone:(NSString *) roomName enable:(BOOL) enable;

/**
 * Close or Open speaker for the room
 *
 * @param roomName : the room
 * @param enable : ture for open and false for close
 * @return if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 */
- (GCVErrorNo) enableRoomSpeaker:(NSString *) roomName enable:(BOOL) enable;


/**
 * enable a client join in multi rooms.
 *
 * this may cause higher bitrate
 *
 * @param enable : ture for open and false for close
 * @return if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 */
- (GCVErrorNo) enableMultiRoom:(BOOL) enable;

#pragma mark  Messages Voice API
/**
 * Apply the key for voice message.
 *
 * @param msTimeout: time for apply, it is micro second.value range[5000, 60000]
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) applyMessageKey:(NSInteger) msTimeout;

/**
 * Limit the max voice message's last time.
 *
 * @param msTime : message's largest time in micro second.value range[1000, 2*60*1000]
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) setMaxMessageLength:(NSInteger) msTime;

/**
 * Open player's microphone and record player's voice.
 *
 * @param filePath: voice data to store. file path should be such as:"your_dir/your_file_name" be sure to use "/" not "\"
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) startRecording:(NSString *) filePath;


/**
 * Open player's microphone and record player's voice.
 *
 * @param filePath: voice data to store. file path should be such as:"your_dir/your_file_name" be sure to use "/" not "\"
 * @param bOptim : true flag means recording audio not enter voip mode
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) startRecording:(NSString *) filePath bOptim : (BOOL) bOptim;

/**
 * Stop player's microphone and stop record player's voice.
 *
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) stopRecording;

/**
 * Upload player's voice message file to the net.
 *
 * @param filePath: voice data to upload. file path should be such as "your_dir/your_file_name" be sure to use "/" not "\"
 * @param msTimeout: time for upload, it is micro second.value range[5000, 60000]
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) uploadRecordedFile:(NSString *) filePath timeout: (NSInteger) msTimeout ;

/**
 * Download other players' voice message.
 *
 * @param fileID : file to be download
 * @param filePath: voice data to store. file path should be such as "your_dir/your_file_name" be sure to use "/" not "\"
 * @param msTimeout: time for download, it is micro second.value range[5000, 60000]
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) downloadRecordedFile:(NSString *)fileID filePath:(NSString *) downloadFilePath timeout: (NSInteger) msTimeout ;

/**
 * Upload player's voice message file to the net.
 *
 * @param filePath: voice data to upload. file path should be such as "your_dir/your_file_name" be sure to use "/" not "\"
 * @param msTimeout: time for upload, it is micro second.value range[5000, 60000]
 * @param bPermanent: download a file for long term storage in server
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) uploadRecordedFile:(NSString *) filePath timeout: (NSInteger) msTimeout fileProperty: (BOOL) bPermanent;

/**
 * Download other players' voice message.
 *
 * @param fileID : file to be download
 * @param filePath: voice data to store. file path should be such as "your_dir/your_file_name" be sure to use "/" not "\"
 * @param msTimeout: time for download, it is micro second.value range[5000, 60000]
 * @param bPermanent: download a file for long term storage in server
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) downloadRecordedFile:(NSString *)fileID filePath:(NSString *) downloadFilePath timeout: (NSInteger) msTimeout fileProperty: (BOOL) bPermanent;

/**
 * Play local voice message file.
 *
 * @param filePath: voice data to play. file path should be such as:"your_dir/your_file_name" be sure to use "/" not "\"
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) playRecordedFile:(NSString *) downloadFilePath;

/**
 * Stop play the file.
 *
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) stopPlayFile;


- (GCVErrorNo)  enableSpeakerOn:(BOOL) bEnable;

/**
 * Translate voice data to text.
 *
 * @param fileID : file to be translate
 * @param msTimeout : timeout for translate
 * @param language: a GCloudLanguage indicate which language to be translate
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) speechToText:(NSString *)fileID timeout:(NSInteger) msTimeout language:(GCVLanguage) language ;


#pragma mark if need
- (GCVErrorNo) joinTeamRoom:(NSString *)roomName token: (NSString *)token timestamp:(NSInteger) timestamp timeout:(NSInteger) msTimeout;


- (GCVErrorNo) joinNationalRoom:(NSString *)roomName role: (GCVMemberRole) role token: (NSString *)token timestamp: (NSInteger) timestamp timeout: (NSInteger) msTimeout ;

- (GCVErrorNo) applyMessageKey:(NSString *)token timestamp:(NSInteger) timestamp timeout:(NSInteger) msTimeout;

- (GCVErrorNo) speechToText:(NSString *)fileID token:(NSString *)token timestamp:(NSInteger) timestamp timeout:(NSInteger) msTimeout  language:(GCVLanguage) language ;

- (GCVErrorNo) startBlueTooth ;
- (GCVErrorNo) stopBlueTooth ;

#pragma mark Extension

/**
 * Don't play voice of the member.
 *
 * @param member : member to forbid
 * @param bEnable : do forbid if it is false
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) forbidMemberVoice:(NSInteger) member enable:(BOOL) bEnable inRoom:(NSString *)roomName ;

/**
 * Open Voice Engine's logcat
 *
 * @param enable: open logcat if it is true
 */
- (void) enableLog:(BOOL) enable;

/**
 * Get micphone's volume
 *
 * @return : micphone's volume , if return value>0, means you have said something capture by micphone
 */
- (int) getMicLevel:(BOOL) fadeOut;

/**
 * Get speaker's volume
 *
 * @return : speaker's volume, value is equal you Call SetSpeakerVolume param value
 */
- (int) getSpeakerLevel;

/**
 * set sepaker's volume
 *
 * @param vol: setspeakervolume,
 * Android & IOS, value range is 0-800, 100 means original voice volume, 50 means only 1/2 original voice volume, 200 means double original voice volume
 * Windows value range is 0x0-0xFFFF, suggested value bigger than 0xff00, then you can hear you speaker sound
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) setSpeakerVolume:(NSInteger) vol;

/**
 * Test wheather microphone is available
 *
 * @return : if success return GCLOUD_VOICE_SUCC, , means have detect micphone device,failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) testMic;

/**
 * Get voice message's info
 *
 * @param filepath: file path should be "sdcard/your_dir/your_file_name" be sure to use "/" not "\"
 * @param bytes: on return for file's size
 * @param sendons: on return for voice's length
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) getFileParam:(const char *_Nullable)filepath data:(unsigned int* _Nullable) bytes time:(float * _Nullable)seconds;

/**
 * Capture microphone audio data by IGCloudVoiceNotify::OnRecording
 *
 * @param bCapture : true/false - start/stop capturing audio data
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) captureMicrophoneData:(BOOL) bCapture;

/*
* control audio volume
* @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
- (BOOL) isSpeaking;

 * SetVoiceEffects
 *
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
- (GCVErrorNo) SetVoiceEffects:(GCVSoundEffects) mode;

/*
* control audio volume
* @param : 100 means same as it has been recorded, 50 means half volume, 200 means double volume
* @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
*/
- (int) setMicVolume:(NSInteger)volume;

/**
 * YOU SHOULD NOT INVOKE THIS ONE.
 */
- (int) invoke: (unsigned int)    nCmd
          arg1: (unsigned int)    nParam1
          arg2: (unsigned int)    nParam2
          arg3: (unsigned int *_Nullable)pOutput;


/*
* set BGM Play file
* @param : file address
* @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
*/
- (GCVErrorNo) SetBGMPath:(NSString *) pPath;

/*
* start BGM Play 
* @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
*/
-(GCVErrorNo) StartBGMPlay;

/*
* set BGM Play Volume
* @param : play volume ,normal value is 100,more than 100 the sound loud,less 100 sound soft
* @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
*/
-(GCVErrorNo) SetBGMVol:(NSInteger)nvol;

/*
* stop BGM Play
* @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
*/
-(GCVErrorNo) StopBGMPlay;

/*
* pause BGM Play
* @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
*/
-(GCVErrorNo) PauseBGMPlay;

/*
* resume BGM Play
* @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
*/
-(GCVErrorNo) ResumeBGMPlay;

/*
* native can listen BGM Play
* param: bEnable: true   native can listen BGM Play
*		: false  native can not listen BGM Play
* default is enable true
* @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
*/
-(GCVErrorNo) EnableNativeBGMPlay:(BOOL)bEnable;

/*
* get BGM Playing state
* @return : if BGM Playing return 0,if BGM play end return 1
*/
-(int) GetBGMPlayState;

/*
* set bitrate for encode
* @param : bitrate, you want set value, default value is 32000
* @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
*/

-(GCVErrorNo) SetBitRate:(NSInteger)bitrate;

/**
 * Set if it is datafree.
 *
 * @param enable: true enable datafree
 * @return : if success return GCLOUD_VOICE_SUCC, failed return other errno @see GCVErrorNo
 * @see : GCVErrorNo
 */
-(GCVErrorNo) SetDataFree:(BOOL) enable;

/*
* get howling state
* @return : if howling happen return 1,else return 0
*/
-(int) GetBGMPlayState;

/*
 * get the device connection state
 * @return :  return the device connection state, @see GCloudVoiceDeviceState
 */
-(GCVDeviceState) getAudioDeviceConnectionState;

@end

#endif /* __APPLE__ */
#endif /* _GCloud_GVoice_GCloudVoice_h */
