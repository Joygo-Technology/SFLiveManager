//
//  SFLibAudioIOManager.h
//  LiveManager
//
//  Created by 朱盛雄 on 16/8/1.
//  Copyright © 2016年 Sunniwell. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "SFLibManagerMarco.h"

typedef NS_ENUM(int, EFFECTTYPE)
{
    EFFECTTYPE_ORI = 0,
    EFFECTTYPE_POPULAR,//流行
    EFFECTTYPE_DANCE,//舞曲
    EFFECTTYPE_BLUES,//布鲁斯
    EFFECTTYPE_CLASSICAL,//经典
    EFFECTTYPE_JAZZ,//爵士
    EFFECTTYPE_SLOW,//慢歌
    EFFECTTYPE_ELECTRONIC,//电子乐
    EFFECTTYPE_ROCK,//摇滚
    EFFECTTYPE_COUNTRY,//乡村
};

@interface AudioPlayoutBufferIndex : NSObject

@property (nonatomic, assign) NSInteger index;

@property (nonatomic, assign) BOOL isUsed;

@end

@interface SFLibAudioIOManager : NSObject

+ (id)sharedInstance;

- (void)startAudioIOEngine;

- (void)startAudioIOEngine:(bool)isVoiceIO;

- (void)stopAudioIOEngine;

- (void)resetAudioIOEngine;

//回声消除模式切换
- (void)switchVoiceIOAudioRecord:(bool)isVoiceIO;

- (void)openAudioRecord;

- (void)openAudioPlay;

- (void)openAudioMutedRecord;

- (void)closeAudioRecord;

- (void)closeAudioPlay;

- (void)closeAudioMutedRecord;

//if playing, return true
- (BOOL)getAudioPlayStatus;

//if recording, return ture
- (BOOL)getAudioRecordStatus;

//
- (BOOL)isPushBufferCompletion;

- (BOOL)setAccomPitch:(int)pitch;

- (int)getAccompPitch;

- (void)accompEffectSet:(EFFECTTYPE)effectType;

- (EFFECTTYPE)getAccompEffect;

@end
